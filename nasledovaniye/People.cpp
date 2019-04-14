#include "stdafx.h"
#include "People.h"


bool People::ReadPeople(ifstream & f)
{
	try
	{
		f >> name;
		if (name.length() == 0)
			return 1;
		f >> sex;
		if (sex.length() == 0)
			return 1;
		f >> age;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

ostream & operator<<(ostream & f, People & data)
{
	data.PrintData(f);
	return f;
}

bool Academic::Read(ifstream & f)
{
	try
	{
		if (ReadPeople(f))
			return 1;	
		if (ReadEducation(f))
			return 1;
		string namesubj;
		f >> (namesubj);
		if (namesubj.length() == 0)
			return 1;
		subjects = Exams::FindSubj(namesubj);
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

void Academic::Delete()
{
	subjects = NULL;
}

void Academic::AddSubj()
{
	string s;
	cout << "Выберите предмет из списка: ";
	Exams::SubjOut();
	cin >> s;
	do {
		cin >> name;
		subjects = Exams::FindSubj(name);
		if (subjects == NULL)
			cout << "Предмет не найден, попробуйте снова.\n";
	} while (subjects == NULL);
}

bool Students::Read(ifstream & f)
{
	try
	{
		if (ReadPeople(f))
			return 1;
		f >> type;
		if (type.length() == 0)
			return 1;
		f >> count;
		for (int i = 0; i < count; i++)
		{
			Exams new_ex;
			bool flag = new_ex.Read(f);
			if (!flag)
			{
				examlist.push_back(new_ex);
			}
		}
		AVG();
		sortVals();
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

void Students::Delete()
{
	examlist.~vector();
}

void Students::AddEx()
{
	cout << "Введите количество экзаменов: ";
	cin >> count;
	int i = 0; for (i = 0; i < count; i++)
	{
		Exams new_ex;
		new_ex.AddData();
		examlist.push_back(new_ex);
	}
	AVG();
}

ostream & Students::PrintExamList(ostream & f)
{
	for (int i = 0; i < (examlist.end() - examlist.begin()); i++)
		f << examlist[i];
	f << endl;
	return f;
}

void Students::AVG()

{
	float sum = 0;	
	for (int i = 0; i < (examlist.end() - examlist.begin()); i++)
		sum += examlist[i].getVal ();
	average = round((sum / count) * 10) / 10;
}

void Students::Edit()
{
	char a = '0';
	string sname;
	cout << "1.Добавить новый экзамен.\n2.Исправить имеющуюся оценку.\n";
	cout << "Список предметов:\n";
	Exams::SubjOut();
	cout << "Список экзаменов :\n";
	PrintExamList(cout);
	cin >> sname;
	Subjects *subj = new Subjects;
	cout << "Введите название предмета: ";
	do
	{
		cin >> sname;
		subj = Exams::FindSubj(sname);
		if (subj == NULL) cout << "Предмет не найден.\n";
	} while (subj == NULL);
	switch (a) {
	case '1':
	{
		for (int i = 0; i < (examlist.end() - examlist.begin()); i++)
		{
			if (examlist[i] == sname)
			{
				cout << "Экзамен уже сдан.\n";
				return;
			}
		}
		Exams e;
		e.setSubj(subj);
		int val;
		cout << "Оценка за экзамен: ";
		cin >> val;
		e.setVal(val);
		examlist.push_back(e);
		count++;
		break;
	}
	case '2':
	{
		for (int i = 0; i < (examlist.end() - examlist.begin()); i++)
		{
			if (examlist[i] == sname)
			{
				int mark;
				std::cout << "Введите оценку: ";
				std::cin >> mark;
				examlist[i].setVal(mark);
				break;
			}
		}
		std::cout << "Экзамен не найден.\n";
		return;
	}
	}
	AVG();
}

bool Education::ReadEducation(ifstream & f)
{
	try
	{
		f >> prof_name;
		if (prof_name.length() == 0)
			return 1;
		f >> level;
		if (level.length() == 0)
			return 1;
		f >> years;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}
