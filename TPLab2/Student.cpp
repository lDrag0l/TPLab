#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Student::Student() {
    cout << "Student constructor called" << endl;
}
Student::Student(string sSurname, string sInitials, GradeNode* sGrades) : surname(sSurname), initials(sInitials), grades(sGrades) {
    cout << "Student constructor called" << endl;
}
Student::Student(const Student &sCopy) : surname(sCopy.surname), initials(sCopy.initials), grades(sCopy.grades) {
    cout << "Student constructor called" << endl;
}
Student::~Student() {
    cout << "Student destructor called" << endl;
}

string Student::getGrades() const {
    string grade_str;
    GradeNode* start = grades;
    while (start != nullptr) {
        grade_str += ", " + to_string(start->grade);
        start = start->next;
    }
    return grade_str;
};
string Student::getSurname() const {
    return surname;
}
string Student::getInitials() const {
    return initials;
}
void Student::setInitials(const std::string &sInitials) {
    this->initials = sInitials;
}
void Student::setSurname(const std::string &sSurname) {
    this->surname = sSurname;
}
void Student::addGrade(int grade) {
    GradeNode* start = grades;
    auto* new_node = new GradeNode;
    new_node->grade = grade;
    new_node->next = nullptr;
    if (start == nullptr) {
        grades = new_node;
        return;
    }
    while (start->next != nullptr) 
        start = start->next;
    start->next = new_node;
}
int Student::popGrade() {
    GradeNode* start = grades;
    if (start == nullptr) {
        cout << "No grades" << endl;
        return -1;
    }
    int grade;
    if (start->next == nullptr) {
        grade = start->grade;
        grade = NULL;
        return grade;
    }
    while (start->next->next != nullptr)
        start = start->next;
    grade = start->next->grade;
    start->next = NULL;
    return grade;
}

float Student::getAvgGrade(){
    float count = 0;
    float sum = 0;
    GradeNode* start = grades;
    if (start == nullptr) {
        return 0;
    }
    while (start != nullptr) {
        sum += start->grade;
        start = start->next;
        count += 1;
    }
    return sum / count;
}

string Student::printInfo() {
    return getSurname() + " " +  getInitials() + " - " + to_string(getAvgGrade()) + '\n';
}

void Student::edit() {
    if (surname.empty())
        cout << "Enter surname: ";
    else
        cout << "Enter surname (current - " << getSurname() << "): ";
    cin >> surname;
    if (initials.empty())
        cout << "Enter initials: ";
    else
        cout << "Enter initials (current - " << getInitials() << "): ";
    cin >> initials;
    if (grades == nullptr)
        cout << "Enter grades: ";
    else
        cout << "Add grades (current - " << getGrades() << "): ";
    string line;
    cin.ignore(32767, '\n');
    getline(cin, line);

    istringstream iss(line);
    int gr;
    while (iss >> gr) {
        addGrade(gr);
    }
    cout << printInfo();
}
void Student::save() {
    ofstream file;
    string file_name = "Student.txt";
    file.open(file_name, ios::app);
    if (!file) {
        cout << "Error while opening file " << file_name << " to load data.";
        return;
    }
    int count = 0;
    GradeNode* start = grades;
    if (start == nullptr) {
        count = 0;
    } else {
        while (start != nullptr) {
            start = start->next;
            count++;
        }
    }
    file << surname << endl << initials << endl;
    if (count){
        start = grades;
        while (start != nullptr) {
            file << start->grade << " ";
            start = start->next;
        }
    }
    file << endl;
    file.close();
}

ostream& operator << (std::ostream &os, Student &student){
    return os << student.printInfo();
}

istream& operator>>(istream &is, Student &student) {
    string surname, initials;
    is >> surname >> initials;
    student.setSurname(surname);
    student.setInitials(initials);
    return is;
}

