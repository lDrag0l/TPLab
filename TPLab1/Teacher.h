#pragma once
#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;


class Teacher : public Person {
private:
	string name;
	string group;
	string subject;
public:
	Teacher();
	~Teacher();
	Teacher(const Teacher& Teacher_copy);
	Teacher(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_group() const;
	void set_group(string group_ch);
	string get_subject() const;
	void set_subject(string subject_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool avermark(double a) { return false; };
};
