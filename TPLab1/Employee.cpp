#include "Employee.h"

#include <string> 
#include <iostream> 
#include <fstream>


using namespace std;


Employee::Employee() { cout << "Constructor Employee without attributes was called." << endl; }
Employee::~Employee() { cout << "Destructor Employee was called." << endl; }
Employee::Employee(const Employee& Employee_copy) {
	name = Employee_copy.name;
	post = Employee_copy.post;
	number = Employee_copy.number;
	job = Employee_copy.job;
	cout << "Constructor copy was called." << endl;
}
Employee::Employee(string name) {
	this->name = name;
	cout << "Constructor Employee with attributes was called." << endl;
}
string Employee::get_name() const { return name; }
void Employee::set_name(string name_ch) { name = name_ch; }
string Employee::get_post() const { return post; }
void Employee::set_post(string post_ch) { post = post_ch; }
string Employee::get_number() const { return number; }
void Employee::set_number(string number_ch) { number = number_ch; }
string Employee::get_job() const { return job; }
void Employee::set_job(string job_ch) { job = job_ch; }
void Employee::show() {
	cout << "------------------------------------" << endl;
	cout << "Person: Employee" << endl;
	cout << "Name: " << name << endl;
	cout << "Post: " << post << endl;
	cout << "Phone number: " << number << endl;
	cout << "Responsible area: " << job << endl;
	cout << "------------------------------------" << endl;
}
void Employee::rewrite() {
	cout << "------------------------------------" << endl;
	cout << "Person: Employee" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	getline(cin, name);
	cout << "Input new post: ";
	getline(cin, post);
	cout << "Input new telephone number: ";
	getline(cin, number);
	cout << "Input new area of resnosible: ";
	getline(cin, job);
	cout << "------------------------------------" << endl;
}
void Employee::saving() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile.is_open())
	{
		cout << "Error opening the outfile << endl!";
		exit(1);
	}
	outfile << 3 << endl << name << endl << post << endl << number << endl << job << endl;
	outfile.close();
}
void Employee::redact_str(int num_str, string red_str) {
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->post = red_str;
		break;
	case 3:
		this->number = red_str;
		break;
	case 4:
		this->job = red_str;
		break;
	default:
		cout << "Incorrect number of string!" << endl;
		break;
	}
}