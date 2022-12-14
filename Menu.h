#pragma once
#include "Keeper.h"
#include "Sign.h"

template <typename T>
void Menu(T& obj, string s) {
	int menu;
	int index;
	string name;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "1 -> Add a person" << endl;
		cout << "2 -> Delete person" << endl;
		cout << "3 -> Read from the file" << endl;
		cout << "4 -> Save in file" << endl;
		cout << "5 -> Print all info" << endl;
		cout << "6 -> Redact info" << endl;
		cout << "7 -> Exit" << endl;
		cout << "8 -> sort" << endl;
		cout << "9 -> data to sign" << endl;

		cout << "Input num: ";
		cin >> menu;
		switch (menu) {
		case 1: obj.add(); break;

		case 2: obj.print(); cout << "Input smth: "; cin >> index; obj.del(index); system("pause"); break;
		case 3: obj.read(s); system("pause"); break;
		case 4: obj.save(s); system("pause"); break;
		case 5: obj.print(); system("pause"); break;
		case 6: obj.print();  cout << "Input smth: "; cin >> index;  obj.redaction(index); system("pause"); break;
		case 7: flag = 0; break;
		case 8: obj.sort_data(); system("pause"); break;
		case 9: obj.search_sign(); system("pause"); break;
		default: cout << "Error" << endl; system("pause"); break;
		}
	}
}

