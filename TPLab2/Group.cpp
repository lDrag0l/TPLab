#include "Group.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Group::Group() {
    cout << "Group constructor called" << endl;
}
Group::Group(int gNumber, LessonNode* gLesson, StudentNode* gStudent) : number(gNumber), lessons(gLesson), students{gStudent} {
    cout << "Group constructor called" << endl;
}
Group::Group(const Group &gCopy) : number(gCopy.number), lessons(gCopy.lessons), students{gCopy.students} {
    cout << "Group constructor called" << endl;
}
Group::~Group() {
    cout << "Group destructor called" << endl;
}

int Group::getNumber() {
    return number;
};
string Group::getLessons() {
    string lessons_str;
    LessonNode* start = lessons;
    bool first = true;
    if (start == nullptr)
        return " ";
    while (start != nullptr) {
        if (!first)
            lessons_str += ", ";
        first = false;
        lessons_str += start->lesson;
        start = start->next;
    }
    return lessons_str;
}
string Group::getStudents()  {
    string lessons_str;
    StudentNode* start = students;
    if (start == nullptr)
        return " ";
    while (start != nullptr) {
        lessons_str += start->student.printInfo();
        start = start->next;
    }
    return lessons_str;
}
void Group::setNumber(int gNumber) {
    this->number = gNumber;
}
void Group::addLesson(string gLesson) {
    LessonNode* start = lessons;
    auto* new_node = new LessonNode;
    new_node->lesson = gLesson;
    new_node->next = nullptr;
    if (start == nullptr) {
        lessons = new_node;
        return;
    }
    while (start->next != nullptr)
        start = start->next;
    start->next=new_node;
}
void Group::addStudent(Student student) {
    StudentNode * start = students;
    auto* new_node = new StudentNode ;
    new_node->student = student;
    new_node->next = nullptr;
    if (start == nullptr) {
        students = new_node;
        return;
    }
    while (start->next != nullptr)
        start = start->next;
    start->next = new_node;
}
float Group::getAvgGrade() {
    float count = 0;
    float sum = 0;
    StudentNode * start = students;
    if (start == nullptr) {
        return 0;
    }
    while (start != nullptr) {
        sum += start->student.getAvgGrade();
        start = start->next;
        count += 1;
    }
    return sum / count;
}

void Group::removeStudent(int index) {
    if (index >= 0 && students != nullptr) {
        StudentNode * obj_ptr = students;
        StudentNode * tmp_ptr = students;
        for (int i = 0; i < index; i++) {
            if (obj_ptr == nullptr) {
                cout << "No data." << endl;
                return;
            }
            tmp_ptr = obj_ptr;
            obj_ptr = obj_ptr->next;
        }
        if (obj_ptr == students) {
            students = obj_ptr->next;
        }
        else {
            tmp_ptr->next = obj_ptr->next;
        }
        delete(obj_ptr);
    }
    else {
        cout << "No data." << endl;
    }
}

void Group::printInfo() {
    cout << "Group number: " << getNumber() << endl << "Lessons: " << getLessons() << endl << "Avg Grade: " << getAvgGrade() << endl << "Students: " << endl << getStudents();
}
void Group::edit() {
    if (number == -1)
        cout << "Enter number: ";
    else
        cout << "Enter number (current - " << getNumber() << "): ";
    cin >> number;
    if (lessons == nullptr)
        cout << "Enter lessons: ";
    else
        cout << "Add lessons (current - " << getLessons() << "): ";

    string line;
    cin.ignore(32767, '\n');
    getline(cin, line);

    istringstream iss(line);
    string lesn;
    while (iss >> lesn) {
        addLesson(lesn);
    }
    cout << "Enter count of students: ";
    int cnt = 0;
    cin >> cnt;
    while (cnt--) {
        Student stud;
        stud.edit();
        addStudent(stud);
    }
    printInfo();
}
void Group::save() {
    ofstream file;
    string file_name = "Student.txt";
    file.open(file_name, ios::app);
    if (!file) {
        cout << "Error while opening file " << file_name << " to load data.";
        return;
    }
    int lcnt=0;
    LessonNode* start = lessons;
    if (start == nullptr)
        lcnt = 0;
    else
        while (start != nullptr) {
            start = start->next;
            lcnt++;
        }
    file << number << endl;
    if (lcnt){
        start = lessons;
        while (start != nullptr) {
            file << start->lesson << " ";
            start = start->next;
        }
    }
    int scnt=0;
    StudentNode * sstart = students;
    if (sstart == nullptr)
        scnt = 0;
    else
        while (sstart != nullptr) {
            sstart = sstart->next;
            scnt++;
        }
    file << endl << scnt << endl;
    file.close();
    if (scnt){
        sstart = students;
        while (sstart != nullptr) {
            sstart->student.save();
            sstart = sstart->next;
        }
    }
}

StudentNode* Group::getStudentsNode() {
    return students;
}


