#include "Menu.h"
#include <string> 
#include <iostream> 
#include <fstream>
#include "Employee.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

void Menu::main_menu() {
	while (exit == 1)
	{
		switch (show_options())
		{
		case 1:
			show_all_persons();
			break;
		case 2:
			change_data();
			break;
		case 3:
			add_new();
			break;
		case 4:
			save_to_file();
			break;
		case 5:
			load_from_file();
			break;
		case 6:
			delete_person();
			break;
		case 7:
			average();
			break;
		default:
			exit_from_programm();
			break;
		}
	}
}
void Menu::average()
{
	double a;
	cout << "\nEnter mark" << endl;
	cin >> a;
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to show.";
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			if ((list[i]->avermark(a)) == true) list[i]->show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
}
int Menu::show_options() {
	int c1;
	cout << "\nWhat do you want to do?" << endl;
	cout << "1 - Show all humans" << endl;
	cout << "2 - Change human's data" << endl;
	cout << "3 - Add new human" << endl;
	cout << "4 - Save all changes to the file" << endl;
	cout << "5 - Load data from the file" << endl;
	cout << "6 - Delete a human" << endl;
	//To work correctly, you need to enter a real number, with two numbers after the dot
	cout << "7 - Output of students with the entered average ball" << endl;
	cout << "0 - Exit" << endl;
	cout << "-> ";
	cin >> c1;
	return c1;
}
void Menu::show_all_persons()
{
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to show.";
		}
		for (int i = 0; i < list.get_size(); i++)
		{
			cout << "_" << endl;
			cout << i + 1 << "|";
			list[i]->show();
		}
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::change_data()
{
	int c2, c3;
	try
	{
		cout << "What human do you want to change (from 1 to " << list.get_size() << ")?" <<
			endl;
		cin >> c2;
		if ((c2 < 1) || (c2 > list.get_size()))
		{
			throw "Incorrect number!";
		}
		list[c2 - 1]->show();
		cout << "What string do you want to change?" << endl;
		cout << "-> ";
		cin >> c3;
		cin.ignore(32767, '\n');
		cout << "What do you want to put in this string?" << endl;
		cout << "-> ";
		if (c3 == 5)
		{
			bool fl = false;
			while (fl == false)
			{
				try
				{
					getline(cin, redact);
					//float f = stof(redact);
					fl = true;
				}
				catch (...)
				{
					cout << "Enter the number" << endl;
				}
			}
			list[c2 - 1]->redact_str(c3, redact);
		}
		else
		{
			getline(cin, redact);
			list[c2 - 1]->redact_str(c3, redact);
			cout << "The string was redacted." << endl;
		}
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::add_new()
{
	int c2;
	cout << "\nWhat person do you want to add?" << endl;
	cout << "1 - Student" << endl;
	cout << "2 - Teacher" << endl;
	cout << "3 - Employee" << endl;
	cout << "0 - Go back" << endl;
	cout << "-> ";
	cin >> c2;
	switch (c2)
	{
	case 1:
		Student * student;
		student = new Student;
		persons = student;
		student->rewrite();
		list.insert(persons);
		cout << "The new person was added." << endl;
		break;
	case 2:
		Teacher * teacher;
		teacher = new Teacher;
		persons = teacher;
		teacher->rewrite();
		list.insert(persons);
		cout << "The new person was added." << endl;
		break;
	case 3:
		Employee * emp;
		emp = new Employee;
		persons = emp;
		emp->rewrite();
		list.insert(persons);
		cout << "The new human was added." << endl;
		break;
	default:
		break;
	}
}
void Menu::save_to_file()
{
	try
	{
		if (list.get_size() == 0)
		{
			throw "There's nothing to save.";
		}
		list.save();
		cout << "The data was saved to the file." << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::load_from_file()
{
	try
	{
		list.load();
		cout << "The data was loaded from file." << endl;
	}
	catch (const char* ex) { cout << ex << endl; }
}
void Menu::delete_person()
{
	int c2;
	cout << "What person do you want to change (from 1 to " << list.get_size() << ")?" << endl;
	for (int i = 0; i < list.get_size(); i++)
	{
		cout << "_" << endl;
		cout << i + 1 << "|";
		list[i]->show();
	}
	cout << "-> ";
	cin >> c2;
	c2 = list.get_size() - c2 + 1;
	try {
		if ((c2 < 1) || (c2 > list.get_size()))
		{
			throw "Incorrect number!";
		}
		list.remove(c2 - 1);
		cout << "The chosen person was deleted." << endl;
	}
	catch (const char* i)
	{
		cout << i << endl;
	}

}
void Menu::exit_from_programm()
{
	exit = 0;
}