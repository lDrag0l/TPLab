#include "Student.h"
#include <string> 
#include <iostream> 
#include <fstream>


using namespace std;


using namespace std;
Student::Student() { cout << "Constructor Student without attributes was called." << endl; }
Student::~Student() { cout << "Destructor Student was called." << endl; }
Student::Student(const Student& Student_copy) {
	name = Student_copy.name;
	group = Student_copy.group;
	spec = Student_copy.spec;
	course = Student_copy.course;
	mark = Student_copy.mark;
	cout << "Constructor copy Student was called." << endl;
}
Student::Student(string name) {
	this->name = name; cout << "Constructor Student with attributes was called." << endl;
}
string Student::get_name() const { return name; }
void Student::set_name(string name_ch) { name = name_ch; }
string Student::get_group() const { return group; }
void Student::set_group(string group_ch) { group = group_ch; }
string Student::get_spec() const { return spec; }
void Student::set_spec(string spec_ch) { spec = spec_ch; }
string Student::get_course() const { return course; }
void Student::set_course(string course_ch) { course = course_ch; }
string Student::get_mark() const { return mark; }
void Student::set_mark(string mark_ch) { mark = mark_ch; }
void Student::show() {
	cout << "------------------------------------" << endl;
	cout << "Person: Student" << endl;
	cout << "Name: " << name << endl;
	cout << "Group: " << group << endl;
	cout << "Specialization: " << spec << endl;
	cout << "Course: " << course << endl;
	cout << "Mark: " << mark << endl;
	cout << "------------------------------------" << endl;
}
void Student::rewrite() {
	cout << "------------------------------------" << endl;
	cout << "Person: Student" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	getline(cin, name);
	cout << "Input new group: ";
	getline(cin, group);
	cout << "Input new spec: ";
	getline(cin, spec);
	cout << "Input new course: ";
	getline(cin, course);
	cout << "Input new mark: ";
	getline(cin, mark);
	cout << "------------------------------------" << endl;
}
void Student::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening!" << endl;
		exit(1);
	}
	outfile << 1 << endl << name << endl << group << endl << spec << endl << course << endl <<
		mark << endl;
	outfile.close();
}
void Student::redact_str(int num_str, string red_str) {
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->group = red_str;
		break;
	case 3:
		this->spec = red_str;
		break;
	case 4:
		this->course = red_str;
		break;
	case 5:
		this->mark = red_str;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}
bool Student::avermark(double a)
{
	double b;
	b = stof(this->get_mark());
	if (abs(a - b) < 0.0001)
	{
		return true;
	}
	return false;
}