#pragma once
#include "Person.h"

class Employee : public Person {
private:
	string name;
	string post;
	string number;
	string job;
public:
	Employee();
	~Employee();
	Employee(const Employee& Employee_copy);
	Employee(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_post() const;
	void set_post(string post_ch);
	string get_number() const;
	void set_number(string number_ch);
	string get_job() const;
	void set_job(string job_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool avermark(double a) { return false; };
};