#include "Sign.h"
#include "Keeper.h"

Sign::Sign() {
	cout << " The default constructor of the class was called Sign" << endl;
	name = "No data available";
	surname = "No data available";
	sign = "No data available";
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}


Sign::Sign(const Sign& obj) {
	*this = obj;
}

Sign::~Sign() {
	cout << "The class destructor was called Sign" << endl;
}

Sign& Sign::operator=(const Sign& other) {
	this->name = other.name;
	this->surname = other.surname;
	this->data[0] = other.data[0];
	this->data[1] = other.data[1];
	this->data[2] = other.data[2];
	this->sign = other.sign;
	return *this;
}

ostream& operator<<(ostream& out, Sign& obj) {
	out << "Information about name: " << obj.name << endl;
	out << "Information about surname : " << obj.surname << endl;
	out << "Information about sign: " << obj.sign << endl;
	out << "Information about day born: " << obj.data[0] << endl;
	out << "Information about month born: " << obj.data[1] << endl;
	out << "Information about year born: " << obj.data[2] << endl;
	return out;

}

istream& operator>>(istream& in, Sign& obj) {
	cout << "Input name: ";
	getchar();
	getline(in, obj.name);

	cout << "Input surname : ";
	getline(in, obj.surname);

	cout << "Input information about sign: ";
	getline(in, obj.sign);

	cout << "Input information day born: ";
	while (!(in >> obj.data[0]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}

	cout << "Input information month born: ";
	while (!(in >> obj.data[1]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}
	cout << "Input information year born: ";
	while (!(in >> obj.data[2]))
	{
		if (in.eof())
		{
			throw "eof";
		}
		in.clear(); //Сбрасываем флаг ошибки, если таковая была
		in.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		cout << "Try again: ";
	}




	return in;
}

string Sign::sort(Sign& obj)
{
	string str = to_string(data[2]) + to_string(data[1]) + to_string(data[0]);
	return str;
}

string Sign::data_to_sign(Sign& obj)
{
	if ((data[0] >= 21 && data[1] == 3) || (data[0] <= 20 && data[1] <= 4))
	{
		return "oven";
	}
	else if ((data[0] >= 21 && data[1] == 4) || (data[0] <= 20 && data[1] == 5)) {
		return "telec";
	}
	else if ((data[0] >= 21 && data[1] == 5) || (data[0] <= 21 && data[1] == 6)) {
		return "blisnetc";
	}
	else if ((data[0] >= 22 && data[1] == 6) || (data[0] <= 22 && data[1] == 7)) {
		return "rak";
	}
	else if ((data[0] >= 23 && data[1] == 7) || (data[0] <= 22 && data[1] == 8)) {
		return "lev";
	}
	else if ((data[0] >= 23 && data[1] == 8) || (data[0] <= 22 && data[1] == 9)) {
		return "deva";
	}
	else if ((data[0] >= 23 && data[1] == 9) || (data[0] <= 23 && data[1] == 10)) {
		return "vesi";
	}
	else if ((data[0] >= 24 && data[1] == 10) || (data[0] <= 22 && data[1] == 11)) {
		return "scorpion";
	}
	else if ((data[0] >= 23 && data[1] == 11) || (data[0] <= 21 && data[1] == 12)) {
		return "strelec";
	}
	else if ((data[0] >= 22 && data[1] == 12) || (data[0] <= 20 && data[1] == 1)) {
		return "kozerog";
	}
	else if ((data[0] >= 21 && data[1] == 1) || (data[0] <= 18 && data[1] == 2)) {
		return "vodoley";
	}
	else if ((data[0] >= 19 && data[1] == 2) || (data[0] <= 20 && data[1] == 3)) {
		return "rybi";
	}

}
bool Sign::search(Sign& obj, string sign)
{
	return sign == obj.sign;
}

ofstream& operator<<(ofstream& fout, Sign& obj) {
	fout << obj.name << endl;
	fout << obj.surname << endl;
	fout << obj.sign << endl;
	fout << obj.data[0] << endl;
	fout << obj.data[1] << endl;
	fout  << obj.data[2] << endl;


	return fout;
}

ifstream& operator>>(ifstream& fin, Sign& obj) {

	fin.get();
	getline(fin, obj.name);
	//fin.get();
	getline(fin, obj.surname);
	//fin.get();
	getline(fin, obj.sign);
	fin >> obj.data[0];
	fin >> obj.data[1];
	fin >> obj.data[2];
	fin.get();
	return fin;
}



void Sign::redact(Sign& obj)
{

	int index;
	cout << "What you want to redact (1-5) 6-exit: " << endl;
	cin >> index;
	switch (index)
	{
	case 1:
		cout << "Input  new information about name: ";
		getchar();
		getline(cin, obj.name);
		break;
	case 2:
		cout << "Input  new surname: ";
		cin >> obj.surname;
		break;
	case 3:
		cout << "Input new information about  sign: ";
		cin >> obj.sign;
		break;
	case 4:
		cout << "Input new information about day born: ";
		cin >> obj.data[0];
		cout << "Input new information about  month born: ";
		cin >> obj.data[1];
		cout << "Input new information about  year born: ";
		cin >> obj.data[2];
		break;

	case 6:
		cout << "succesesfuil redact" << endl;
		break;
	default:
		break;
	}

}