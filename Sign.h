#pragma once
#include "Keeper.h"

class Sign {
protected:
	string name;
	string surname;
	string sign;
	int data[3];
public:
	Sign();
	Sign(const Sign& obj);
	~Sign();

	Sign& operator= (const Sign& other);
	void redact(Sign&);
	string sort(Sign&);
	string data_to_sign(Sign&);
	bool search(Sign&, string);
	friend ostream& operator<<(ostream&, Sign&);
	friend istream& operator>>(istream&, Sign&);
	friend ofstream& operator<<(ofstream&, Sign&);
	friend ifstream& operator>>(ifstream&, Sign&);
};

