#pragma once
#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

class Student : public Person {
private:
	string name;
	string group;
	string spec;
	string course;
	string mark;
public:
	Student();
	~Student();
	Student(const Student& Student_copy);
	Student(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_group() const;
	void set_group(string group_ch);
	string get_spec() const;
	void set_spec(string spec_ch);
	string get_course() const;
	void set_course(string course_ch);
	string get_mark() const;
	void set_mark(string mark_ch);
	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool avermark(double a);
};