/*
Title of the Assignment:
Develop a C++ program to create a database of student's information system
with required OOP concepts and features.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Student;

class Display {
public:
    inline void showStudent(const Student &s); // Inline function
};

class Student {
private:
    string name, rollNo, cls, division, dob, bloodGroup;
    string address, phone, licenseNo, other;
    static int count; // Static member
    int id;

public:
    // Default Constructor
    Student() {
        name = rollNo = cls = division = dob = bloodGroup = "";
        address = phone = licenseNo = other = "";
        id = ++count;
    }

    // Parameterized Constructor (using this pointer)
    Student(string name, string rollNo, string cls, string division,
            string dob, string bloodGroup, string address, string phone,
            string licenseNo, string other) {
        this->name = name;
        this->rollNo = rollNo;
        this->cls = cls;
        this->division = division;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->address = address;
        this->phone = phone;
        this->licenseNo = licenseNo;
        this->other = other;
        id = ++count;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        rollNo = s.rollNo;
        cls = s.cls;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        phone = s.phone;
        licenseNo = s.licenseNo;
        other = s.other;
        id = ++count;
    }

    // Destructor
    ~Student() {
        cout << "Destructor called for Student ID: " << id << endl;
    }

    // Static Function
    static int getCount() {
        return count;
    }

    // Friend class
    friend class Display;

    // Input function
    void getData() {
        try {
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Roll Number: ";
            getline(cin, rollNo);
            cout << "Enter Class: ";
            getline(cin, cls);
            cout << "Enter Division: ";
            getline(cin, division);
            cout << "Enter Date of Birth (DD/MM/YYYY): ";
            getline(cin, dob);
            cout << "Enter Blood Group: ";
            getline(cin, bloodGroup);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Phone Number: ";
            getline(cin, phone);
            cout << "Enter Driving License No: ";
            getline(cin, licenseNo);
            cout << "Enter Other Info: ";
            getline(cin, other);

            if (phone.length() < 10) {
                throw runtime_error("Phone number must be at least 10 digits.");
            }

        } catch (exception &e) {
            cerr << "Error: " << e.what() << endl;
            // Retry input
            getData();
        }
    }
};

// Initialize static member
int Student::count = 0;

// Inline function definition outside class
inline void Display::showStudent(const Student &s) {
    cout << "\n--- Student ID: " << s.id << " ---\n";
    cout << "Name: " << s.name << endl;
    cout << "Roll No: " << s.rollNo << endl;
    cout << "Class: " << s.cls << endl;
    cout << "Division: " << s.division << endl;
    cout << "DOB: " << s.dob << endl;
    cout << "Blood Group: " << s.bloodGroup << endl;
    cout << "Address: " << s.address << endl;
    cout << "Phone: " << s.phone << endl;
    cout << "License No: " << s.licenseNo << endl;
    cout << "Other Info: " << s.other << endl;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    // Dynamic memory allocation
    Student *students = new Student[n];
    Display d;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Student " << (i + 1) << ":\n";
        students[i].getData();
    }

    cout << "\n====== Student Database ======\n";
    for (int i = 0; i < n; i++) {
        d.showStudent(students[i]);
    }

    cout << "\nTotal Students Created: " << Student::getCount() << endl;

    // Using Copy Constructor
    cout << "\nDemonstrating Copy Constructor:\n";
    Student copyStudent = students[0];
    d.showStudent(copyStudent);

    // Free memory
    delete[] students;

    return 0;
}
