#include <iostream>
#include <fstream>
#include "Keeper.h"
#include <string>
#include <sstream>

using namespace std;

Keeper::Keeper() : len(0), head(nullptr) {}
Keeper::Keeper(int len) : head(nullptr) { this->len = len; }
Keeper::Keeper(const Keeper& keeper_copy) {
    this->head = keeper_copy.head;
    this->len = keeper_copy.len;
}
Keeper::~Keeper() {
    clear();
}

void Keeper::clear() {
    if (head != nullptr) {
        Node* obj_ptr;
        while (head != nullptr) {
            obj_ptr = head;
            head = head->next;
        }
    }
    head = nullptr;
}

int Keeper::get_len() {
    return len; 
}

void Keeper::edit(int index) {
    if (index >= 0 && index < len && head != nullptr) {
        Node* obj_ptr = head;
        if (index == 0) {
            obj_ptr->data->edit();
            return;
        }
        for (int i = 0; i < index; i++) {
            obj_ptr = obj_ptr->next;
        }
        obj_ptr->data->edit();
    }
    else {
        cout << "No data." << endl;
    }
}

void Keeper::add(Group* new_data) {
    Node* new_obj = new Node;
    new_obj->data = new_data;
    new_obj->next = nullptr;

    if (head == nullptr || head->data->getNumber() >= new_data->getNumber()) {
        new_obj->next = head;
        head = new_obj;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data->getNumber() <= new_data->getNumber()) {
            current = current->next;
        }
        new_obj->next = current->next;
        current->next = new_obj;
    }
    len++;
}

void Keeper::remove(int index) {
    if (index >= 0 && index < len && head != nullptr) {
        Node* obj_ptr = head;
        Node* tmp_ptr = head;
        for (int i = 0; i < index; i++) {
            tmp_ptr = obj_ptr;
            obj_ptr = obj_ptr->next;
        }
        if (obj_ptr == head) {
            head = obj_ptr->next;
        }
        else {
            tmp_ptr->next = obj_ptr->next;
        }
        obj_ptr->data->~Group();
        delete(obj_ptr);
        len--;
    }
    else {
        cout << "No data." << endl;
    }
}

void Keeper::save() {
    ofstream file;
    string file_name = "Student.txt";
    try {
        file.open(file_name);
        if (!file) {
            throw runtime_error("Error while opening file " + file_name + " to save data.");
        }
    }
    catch (const exception& e) {
        cout << e.what();
        return;
    }
    file << len << endl;
    file.close();
    Node* obj_ptr = head;
    while (obj_ptr != nullptr) {
        obj_ptr->data->save();
        obj_ptr = obj_ptr->next;
    }
    cout << "Saved " << len << " Groups." << endl;

}

void Keeper::load() {
    if (len != 0) { clear(); }
    int input_len;
    int studentsCnt;
    int grade;
    string lesn;
    string inputGroup, inputLessons, inputSurname, inputInitials, inputGrades, studCnt;
    int birthday[3];
    ifstream file;
    string file_name = "Student.txt";
    try {
        file.open(file_name);
        if (!file) {
            throw runtime_error("Error while opening file " + file_name + " to save data.");
        }
    }
    catch (const exception& e) {
        cout <<  e.what() << endl;
        return;
    }
    file >> input_len;
    file.ignore(32767, '\n');
    for (int i = 0; i < input_len; i++) {
        getline(file, inputGroup);
        getline(file, inputLessons);
        auto* new_Group = new Group();
        new_Group->setNumber(stoi(inputGroup));
        istringstream iss(inputLessons);
        while (iss >> lesn)
            new_Group->addLesson(lesn);
        getline(file, studCnt);
        studentsCnt = stoi(studCnt);
        while (studentsCnt--){
            getline(file, inputSurname);
            getline(file, inputInitials);
            getline(file, inputGrades);
            istringstream iss(inputGrades);
            Student student = *new Student();
            student.setSurname(inputSurname);
            student.setInitials(inputInitials);
            while (iss >> grade)
                student.addGrade(grade);
            new_Group->addStudent(student);
        }
        add(new_Group);
    }
    cout << "Loaded  " << len << " Group." << endl;
}

void Keeper::show() {
    if (head != nullptr) {
        Node* obj_ptr = head;
        cout << "0. ";
        obj_ptr->data->printInfo();
        for (int i = 0; i < len - 1; i++) {
            obj_ptr = obj_ptr->next;
            cout <<  i + 1 << ". ";
            obj_ptr->data->printInfo();
        }
    }
    else {
        cout << "No data." << endl;
    }
}

Group* Keeper::operator[](int index) {
    if (index >= 0 && index < len && head != nullptr) {
        Node* obj_ptr = head;
        if (index == 0) {
            obj_ptr->data->edit();
            return nullptr;
        }
        for (int i = 0; i < index; i++) {
            obj_ptr = obj_ptr->next;
        }
        obj_ptr->data->edit();
    }
    cout << "No data." << endl;
    return nullptr;
}

void Keeper::getByGrade() {
    Node* obj_ptr = head;
    StudentNode* students;
    if (head != nullptr) {
        for (int i = 0; i < len; i++) {
            students = obj_ptr->data->getStudentsNode();
            int number = obj_ptr->data->getNumber();
            while (students != nullptr){
                if (students->student.getAvgGrade() > 4)
                    cout << "(" << number << ") " << students->student.printInfo() << endl;
                students = students->next;
            }
            obj_ptr = obj_ptr->next;
        }
    } else {
        cout << "No data";
    }
}
