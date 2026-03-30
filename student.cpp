#include "student.h"
#include <memory>


// Global Variables!!
std::string* student::school = nullptr;
int numDonors = 0;
int numRecipients = 0;
char anotherItem = 'a';
unique_ptr<vector<string>>donatedItem(new vector<string>); // unique_ptr for dynamic memory allocation

// constructor for student
student::student(int x, std::string y) : id(x), name(y) {}

void student::setId(int x) {
    id = x;
}

void student::setName(std::string y) {
    name = y;
}

int student::getId() {
    return id;
}

std::string student::getName() {
    return name;
}

std::ostream& operator<<(std::ostream& os, const student& person) {
    os << "Name: " << person.name << ", Id: " << person.id;
    return os;
}

void student::setSchool(std::string* s) {
    school = s;
}


// Constructor for Donor
Donor::Donor(int a, const std::string b, const std::vector<std::string>& items) : student(a, b), donatedItem(items) {} // This is object composition where a Donor object is composed of a student (via inheritance) and a vector of donated items

std::ostream& operator<<(std::ostream& os, Donor& donor) {
    os << "Name: " << donor.getName() << ", StudentId: " << donor.getId()
        << ", Donated Item(s): ";
    for (const auto& item : donor.getDonatedItem()) {
        os << item << " ";
    }
    return os;
}

void Donor::setDonatedItem(std::string x) {
    donatedItem.push_back(x);
}

std::vector<std::string> Donor::getDonatedItem() const {
    return donatedItem;
}

void Donor::insertDonorData() {
    std::cout << "\n\nEnter your student ID: ";
    int donorId;
    std::cin >> donorId;
    setId(donorId);

    std::cout << "\nEnter your name: ";
    std::string donorName;
    std::cin >> donorName;
    setName(donorName);

    std::cout << "\nEnter the item you want to donate: ";
    std::string donation;
    std::cin >> donation;
    setDonatedItem(donation);

    std::cin.ignore();
    std::getline(std::cin, donorName);
}

void Donor::ExtraItem() {
    std::cout << "\nEnter the extra item you want to donate: ";
    std::string donation;
    std::cin >> donation;
    setDonatedItem(donation);
}


//Constructor for Recipient
Recipient::Recipient(int a, const std::string b) : student(a, b) {}

std::ostream& operator<<(std::ostream& os, Recipient& recipient) {
    os << "Name: " << recipient.getName() << ", Id: " << recipient.getId();
    return os;
}

void Recipient::insertRecipientData() {
    std::cout << "\n\nEnter your student ID: ";
    int recipientId;
    std::cin >> recipientId;
    setId(recipientId);

    std::cout << "\nEnter your name: ";
    std::string recipientName;
    std::cin >> recipientName;

    setName(recipientName);
    std::cin.ignore();
    std::getline(std::cin, recipientName);
}

