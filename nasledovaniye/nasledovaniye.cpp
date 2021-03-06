// nasledovaniye.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <vector>
#include "Subj.h"
#include "Ex.h"
#include "People.h"

#define subjtxt "subj.txt"
#define studtxt "stud.txt"
#define acadtxt "acad.txt"
#define outinformtxt "outinform.txt"

using namespace std;
vector<Subjects> Exams::listsubj;
template<class T>
void ReadFromFile(vector<T> &a, const char* file)
{
	ifstream fin(file);
	while (fin)
	{
		T info;
		bool flag = info.Read(fin);
		if (!flag)
		{
			a.push_back(info);
		}
	}
	fin.close();
}


template<class T>
void OutList(vector<T> &a)
{
	for (int i = 0; i < (a.end() - a.begin()); i++)
		cout << a[i];
}

template <class T>
T* FindPeople(vector<T> &a, string s_name)
{
	for (int i = 0; i < (a.end() - a.begin()); i++)
	{
		if (a[i] == s_name)
			return &a[i];
	}
	return NULL;
}

template <class T>
void WriteToFile(vector<T>& a)
{
	ofstream fout(outinformtxt);
	for (int i = 0; i < (a.end() - a.begin()); i++)
		fout << a[i];
	fout.close();
}
class Students;
int main()
{
	setlocale(LC_ALL, "");
	char ch;
	string inp_name;
	ReadFromFile(Exams::listsubj, subjtxt);
	vector<Students> st;
	vector<Academic> ac;

	do
	{

		cout << "1. Считать список студентов и список преподавателей из файла." << endl;
		cout << "2. Вывести на экран список студентов." << endl;
		cout << "3. Вывести на экран список преподавателей." << endl;
		cout << "4. Добавить студента. " << endl;
		cout << "5. Добавить преподавателя. " << endl;
		cout << "6. Изменить информацию студента " << endl;
		cout << "7. Удалить студента из списка." << endl;
		cout << "8. Удалить преподавателя из списка." << endl;
		cout << "9. Записать информацию в файл. " << endl;
		cout << "0. Вывести всех людей." << endl;
		cout << "E. Выход." << endl;
		cin >> ch;
		switch (ch)
		{
		case'1': {
			ReadFromFile(st, studtxt);
			
			ReadFromFile(ac, acadtxt);
		}
				 break;
				 
		case'2':
		{
			if (st.empty())
			{
				cout << "Пустой список.\n"; break;
			}
			cout << "Cписок студентов: " << endl;
			
			OutList(st);
		}
		break;
		case'3': {
			if (ac.empty())
			{
				cout << "Пустой список.\n"; break;
			}
			cout << "Cписок преподавателей: " << endl;
			OutList(ac); }
				 break;
		case'4': {
			cout << "Введите имя:";
			cin >> inp_name;
			Students new_st;
			if (FindPeople(st, inp_name) == NULL)
			{
				new_st.AddData(inp_name);
				st.push_back(new_st);
			}
			else
				cout << "Такой студент уже существует.\n"; }
				 break;
		case'5': {
			cout << "Введите имя:";
			cin >> inp_name;
			Academic new_ac;
			if (FindPeople(ac, inp_name) == NULL)
			{
				new_ac.AddData(inp_name);
				ac.push_back(new_ac);
			}
			else
				cout << "Такой преподаватель уже существует.\n"; }
				 break;
		case'6': {
			if (st.empty())
			{
				cout << "Пустой список.\n"; break;
				cout << "Введите имя:\n";
				cin >> inp_name;
				Students *existing = NULL;
				existing = FindPeople(st, inp_name);
				if (existing == NULL)
				{
					cout << "Студент не найден.\n"; break;
				}
				existing->Edit();
			}
			break;
		case'7': {
			if (st.empty())
			{
				cout << "Пустой список.\n"; break;
			}
			cout << "Введите имя c:\n";
			cin >> inp_name;
			for (int i = 0; i < (st.end() - st.begin()); i++)
			{
				if (st[i] == inp_name)
				{
					st[i].Delete();
					st.erase(st.begin() + i);
					break;
				}
			}}
				 break;
		case'8': {
			if (ac.empty())
			{
				cout << "Пустой список.\n"; break;
			}
			cout << "Введите имя:\n";
			cin >> inp_name;
			for (int i = 0; i < (ac.end() - ac.begin()); i++)
			{
				if (ac[i] == inp_name)
				{
					ac[i].Delete();
					ac.erase(ac.begin() + i);
					break;
				}
			}}
				 break;
		case '9': {
			WriteToFile(st);
			WriteToFile(ac); }
				  break;
	/*	case '1':
		{
			People ppl;
			Students stud;
		}
			break;*/
		case'0': {
			{
				if (ac.empty() && st.empty())
				{
					cout << "Пустые списки.\n"; break;
				}
				vector <People*> ppl;
				for (int i = 0; i < (st.end() - st.begin()); i++)
				{
					ppl.push_back(&st[i]);
				}
				for (int i = 0; i < (ac.end() - ac.begin()); i++)
				{
					ppl.push_back(&ac[i]);
				}
				for (int i = 0; i < (ppl.end() - ppl.begin()); i++)
					cout << *ppl[i]; }
			break;
		}

		}
		}
	}
	while (ch != 'E');
	return 0;
}