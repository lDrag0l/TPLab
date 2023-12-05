#include "Teacher.h"
#include <string> 
#include <iostream> 
#include <fstream>


using namespace std;

Teacher::Teacher() { cout << "Constructor Teacher without attributes was called." << endl; }
Teacher::~Teacher() { cout << "Destructor Teacher was called." << endl; }
Teacher::Teacher(const Teacher& Teacher_copy) {
	name = Teacher_copy.name;
	group = Teacher_copy.group;
	subject = Teacher_copy.subject;
	cout << "Constructor copy Teacher was called." << endl;
}
Teacher::Teacher(string name) {
	this->name = name; cout << "Constructor Teacher with attributes was called." << endl;
}
string Teacher::get_name() const { return name; }
void Teacher::set_name(string name_ch) { name = name_ch; }
string Teacher::get_group() const { return group; }
void Teacher::set_group(string group_ch) { group = group_ch; }
string Teacher::get_subject() const { return subject; }
void Teacher::set_subject(string subject_ch) { subject = subject_ch; }
void Teacher::show() {
	cout << "------------------------------------" << endl;
	cout << "Person: TEACHER" << endl;
	cout << "Name: " << name << endl;
	cout << "Groups: " << group << endl;
	cout << "Subjects: " << subject << endl;
	cout << "------------------------------------" << endl;
}
void Teacher::rewrite() {
	cout << "------------------------------------" << endl;
	cout << "Teacher: " << endl;
	cout << "Input new name: ";
	getline(cin, name);
	getline(cin, name);
	cout << "Input new groups: ";
	getline(cin, group);
	cout << "Input new subjects: ";
	getline(cin, subject);
	cout << "------------------------------------" << endl;
}
void Teacher::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening the outfile!" << endl;
		exit(1);
	}
	else
	{
		outfile << 2 << endl << name << endl << group << endl << subject << endl;
		outfile.close();
	}
}
void Teacher::redact_str(int num_str, string red_str) {
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->group = red_str;
		break;
	case 3:
		this->subject = red_str;
		break;
	default:
		cout << "Incorrect number of string!" << endl;
		break;
	}
}