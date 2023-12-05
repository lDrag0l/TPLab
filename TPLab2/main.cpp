#include <iostream>
#include "Keeper.h"
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void menu() {
    cout << "1. Add an Group" << endl <<
        "2. Show a list of Group" << endl <<
        "3. Delete Group" << endl <<
        "4. Edit Group" << endl <<
        "5. Get student with grade > 4.0" << endl <<
        "6. Save data" << endl <<
        "7. Load data" << endl <<
        "0. Exit" << endl <<
        "Select the menu item: ";
}

void task_1_run() {
    Keeper* keeper;
    keeper = new Keeper;

    int input_point = 1;
    int input_number;
    string input_string, passKey;
    while (input_point != 0) {
        menu();
        cin >> input_point;
        system("cls");
        switch (input_point) {
        case 1:
            Group * new_Sign;
            new_Sign = new Group();
            new_Sign->edit();
            keeper->add(new_Sign);
            break;
        case 2:
            cout << "\033[94mCount Group: " << keeper->get_len() << "\033[0m" << endl;
            keeper->show();
            break;
        case 3:
            cout << "Enter index of Group to remove: ";
            cin >> input_number;
            keeper->remove(input_number);
            break;
        case 4:
            cout << "Enter index of Group to edit: ";
            cin >> input_number;
            keeper->edit(input_number);
            break;
        case 5:
            keeper->getByGrade();
            break;
        case 6:
            keeper->save();
            break;
        case 7:
            keeper->load();
            break;
        default:
            break;
        }
        cout << "Press any key to continue...";
        _getch();
        system("cls");
    }
    keeper->~Keeper();
    cout << "Program shutdown by user.";
}


int task_2_run() {
    cout << "Enter file name to check: ";
    string file_name = "input.txt";
    cin >> file_name;
    ifstream file;
    try {
        file.open(file_name);
        if (!file)
            throw runtime_error("Error while opening file " + file_name + " to load data.");
    }
    catch (const exception& e) {
        cout << "\033[91m" << e.what() << "\033[0m";
        return 0;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string word1, word2;
        while (iss >> word1) {
            if (iss >> word2)
                cout << word2 << " " << word1 << " ";
            else
                cout << word1;
        }
        cout << endl;
    }
    file.close();
    cout << "Press any key to exit...";
    _getch();
    return 0;
}


int main() {
    int task = 2;
    cout << "chouse task (1/2): ";
    cin >> task;
    if (task == 1) {
        task_1_run();
    }
    else {
        task_2_run();
    }
    return 0;
}