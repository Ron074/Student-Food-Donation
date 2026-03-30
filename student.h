// student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class student {
private:
    int id;
    string name;
    static string* school; // Static pointer to school name

public:
    student(int x, string y);

    void setId(int x);

    void setName(string y);

    int getId();

    string getName();

    friend ostream& operator<<(ostream& os, const student& person);

    static void setSchool(string* s);
};


#endif 

// Donor.h
#ifndef DONOR_H
#define DONOR_H

#include "student.h"

class Donor : public student {
public:
    vector<string> donatedItem; // Vector to store donated items

    Donor(int a, const string b, const vector<string> &items);

    void setDonatedItem(string x);

    vector<string> getDonatedItem() const;

    void insertDonorData();

    void ExtraItem();

    friend ostream& operator<<(ostream& os, Donor& donor);
};

#endif 

// Recipient.h
#ifndef RECIPIENT_H
#define RECIPIENT_H

#include "student.h"

class Recipient : public student {
public:
    Recipient(int a, const string b);

    friend ostream& operator<<(ostream& os, Recipient& recipient);

    void insertRecipientData();
};

#endif 

// Prototypes!!
void Donor_Menu();
void Recipient_Menu();

// Global Variables!!
extern int numDonors;
extern int numRecipients;
extern char anotherItem;
extern std::unique_ptr<std::vector<std::string>> donatedItem;