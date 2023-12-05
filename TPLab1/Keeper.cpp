#include "Keeper.h"
#include <string> 
#include <iostream> 
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Person.h"
#include "Employee.h"


using namespace std;
Keeper::Keeper() : size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) { this->size = size; }
Keeper::~Keeper() {
	if (head != NULL)
	{
		El* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Person();
			delete(buffer);
		}
		head->data->~Person();
		delete(head);
	}
}
Person* Keeper::operator[] (const int id) {
	if ((id >= size) || id < 0)
	{
		cout << "Incorrect index!" << endl;
		exit(1);
	}
	else
	{
		El* buffer = head;
		for (int i = 0; i < size - id - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->data);
	}
}
int Keeper::get_size() { return size; }
void Keeper::insert(Person* new_data) {
	El* tmp;
	tmp = new El;
	if (size == 0)
	{
		tmp->data = new_data;
		tmp->next = 0;
		++size;
	}
	else
	{
		tmp->data = new_data;
		tmp->next = head;
		++size;
	}
	head = tmp;
}
void Keeper::remove(int id) {
	if ((head != NULL) && (id < size) && (id >= 0))
	{
		El* temp = head, * temp2 = head;
		for (int i = 0; i < id; i++)
		{
			temp2 = temp;
			temp = temp->next;
		}
		if (temp == head)
		{
			head = temp->next;
		}
		else
		{
			temp2->next = temp->next;
		}
		temp->data->~Person();
		delete(temp);
		size--;
	}
}
void Keeper::save() {
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile.is_open())
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	else
	{
		outfile << size << endl;
		outfile.close();
	}
	El* buffer = head;
	for (int i = 0; i < size; i++)
	{
		buffer->data->saving();
		buffer = buffer->next;
	}
}
void Keeper::load() {
	if (size != 0)
	{
		El* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->data->~Person();
			delete(buffer);
		}
		head->data->~Person();
		delete(head);
	}
	ifstream infile;
	int read_size, num_person;
	string a, b, c, d, e;
	string initfile = "data.txt";
	Person* persons;
	infile.open(initfile);
	if (!infile.is_open())
	{
		cout << "Error opening!" << endl;
		exit(1);
	}
	infile >> read_size;
	for (int i = 0; i < read_size; i++)
	{
		infile >> num_person;
		infile.ignore(32767, '\n');
		if (num_person == 1)
		{
			//infile >> a >> b >> c >> d >> e;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Student* student;
			student = new Student;
			student->set_name(a);
			student->set_group(b);
			student->set_spec(c);
			student->set_course(d);
			student->set_mark(e);
			insert(student);
		}
		if (num_person == 2)
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			Teacher* teacher;
			teacher = new Teacher;
			teacher->set_name(a);
			teacher->set_group(b);
			teacher->set_subject(c);
			insert(teacher);
		}
		if (num_person == 3)
		{
			//infile >> a >> b >> c;
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			Employee* emp;
			emp = new Employee;
			emp->set_name(a);
			emp->set_post(b);
			emp->set_number(c);
			emp->set_job(d);
			insert(emp);
		}
	}
}