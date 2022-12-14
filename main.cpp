#include "Keeper.h"
#include "Sign.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool isLimit(char c)
{
    char lim[] = { ' ', '\t', '\n' };
    for (int i = 0; i < sizeof(lim); ++i)
    {
        if (c == lim[i])
            return true;
    }
    return false;
}
void file();
int main() {

    //system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    Keeper<Sign> obj;

    int choce = 0;

    while (true) {
        cout << endl << "Choice" << endl;
        cout << "1 -> 1 zadanie" << endl;
        cout << "2 -> 2 zadanie" << endl;
        cout << "3 -> exit" << endl;
        cin >> choce;

        switch (choce)
        {
        case 1:
            system("cls");
            Menu(obj, "sign.txt");
            break;
        case 2:
            system("cls");
            file();
            break;
        case 3:
            return 0;
        default:
            cout << "invalid input";
            break;
        }
    }

    return 0;
}

void file() {
    ifstream fin1("in.txt", ios::in);

    if (!fin1)
    {
        exit(0);
    }

    int count = 0;
    string word;
    ostringstream sentence;

    while (!fin1.eof())
    {
        char symb;
        while (isLimit(symb = fin1.peek()))
        {
            sentence << symb;
            if (symb == '\n')
                break;
            fin1.seekg(1, ios::cur);
        }

        fin1 >> word;
        sentence << word;
        char last = word[word.size() - 1];
        if ((last == '.') || (last == '!'))
        {
            sentence.str("");
            continue;
        }

        if (last == '?')
        {
            cout << sentence.str();
            sentence.str("");
            ++count;
        }
    }
    ifstream fin("in.txt", ios::in);
    count = 0;

    while (!fin.eof())
    {
        char symb;
        while (isLimit(symb = fin.peek()))
        {
            sentence << symb;
            if (symb == '\n')
                break;
            fin.seekg(1, ios::cur);
        }

        fin >> word;
        sentence << word;
        char last = word[word.size() - 1];
        if ((last == '.') || (last == '?'))
        {
            sentence.str("");
            continue;
        }

        if (last == '!')
        {
            cout << sentence.str();
            sentence.str("");
            ++count;
        }
    }
}