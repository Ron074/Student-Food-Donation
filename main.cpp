#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "student.h"

using namespace std;

// Main function -------------
int main() {
    char ch;

    string bmcc = "BMCC";
    student::setSchool(
        &bmcc); // Makes it so that every student created is pointing to BMCC
    do {
        (void)system("clear");
        cout << "\n\n\n Hello"
            << " " << bmcc << " "
            << "student! Are you a donor or a recipient? (Click 1 for donor, 2 "
            "for recipient, 4 to exit)";
        cout << "\n\n\t1.I am a donor";
        cout << "\n\n\t2.I am a recipient";
        cout << "\n\n\t3.Donor and Recipient information";
        cout << "\n\n\t4.Exit";
        cout << "\n\n\nEnter your Choice (1 - 4) ";
        cin >> ch;
        (void)system("clear");
        switch (ch) {
        case '1':
            Donor_Menu();
            break;
        case '2':
            Recipient_Menu();
            break;
        case '3':
            cout << "Number of donors: " << numDonors << endl;
            cout << "Number of recipients: " << numRecipients << endl;
            cout << "Donated Items: ";
            for (const auto& item : *donatedItem) {
                cout << item << ", ";
            }
            break;
        case '4':
            cout << "Exiting Menu, Thank you for time!";
            exit(0);
        }
    } while (ch != '3');
}

void Donor_Menu() {
    int donorId = 0;
    string donorName;

    Donor don(donorId, donorName, *donatedItem);
    don.insertDonorData();
    donatedItem->push_back(don.getDonatedItem().back()); // Add the latest donated item to the global vector

    ofstream donorFile("donors.txt", ios::binary | ios::app);
    if (!donorFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    char correctInfo = 'a';
    cout << "Is the information correct? (y/n): ";
    cin >> correctInfo;
    if (correctInfo == 'N' || correctInfo == 'n')
        Donor_Menu(); // RECURSION!!!!!
    else
        donorFile << don;

    if (correctInfo == 'Y' || correctInfo == 'y') {

        do {
            cout << "\nDo you want to donate another item? (y/n): ";
            cin >> anotherItem;


            // Exception Below
            try {
                // Check if the input is neither 'y' nor 'n'
                if (tolower(anotherItem) != 'y' && tolower(anotherItem) != 'n') {
                    throw runtime_error("Invalid entry. Please select 'y' or 'n'");
                }
            }
            catch (const runtime_error& e) {
                cerr << "Runtime error: " << e.what() << endl;
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(),
                    '\n'); // Ignore invalid input
                cin >> anotherItem;
                continue; // Continue to the next iteration of the loop
            }

            if (tolower(anotherItem) == 'y') {
                don.ExtraItem();
                donorFile << ", " << don.getDonatedItem().back() << ", ";
                donatedItem->push_back(
                    don.getDonatedItem().back()); // Add the latest donated item to the global vector
            }
        } while (tolower(anotherItem) == 'y');
        if (anotherItem == 'n' || anotherItem == 'N')
            donorFile << endl;
        donorFile.close();

        numDonors++;
        cout << don;
        cout << "\n\nNew donor added. Thank you for your contribution! \nPress "
            "Enter key to return to the menu. ";
        cin.ignore();
        cin.get();
    }
}

void Recipient_Menu() {
    int recipientId = 0;
    string recipientName;

    Recipient rep(recipientId, recipientName);
    rep.insertRecipientData();

    ofstream recipientFile("recipients.txt", ios::binary | ios::app);
    if (!recipientFile.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    recipientFile << "Name: " << rep.getName() << " "
        << "StudentId: " << rep.getId() << endl;
    numRecipients++;
    cout << rep;
    cout << "\n\nNew recipient added. We are here for you! \nPress Enter key to "
        "return to the menu. ";
    cin.ignore();
    cin.get();
}