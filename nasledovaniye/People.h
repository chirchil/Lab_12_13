#pragma once
#ifndef People_H
#define People_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "Ex.h"
#include "Subj.h"


using namespace std;
class Exams;
class Subjects;

class People
{
protected:
	string name;
	string sex;
	int age;

public:
	People()
	{
		name = "";
		sex = "";
		age = NULL;
		cout << "People constructor" <<endl;
	}
	~People() {

		cout << "People destructor" << endl;
	}
	bool operator==(string inp_name) { return(name == inp_name); }
	bool ReadPeople(ifstream &f);
	friend ostream& operator<<(ostream & f, People &data);
	virtual ostream& PrintData(ostream &f)
	{
		f << "���: " << name << "\n���:" << sex <<  "\n�������: " << age << "\n";
		return f;
	}
	virtual void AddData(string input_name)
	{
		name = input_name;
		cout << "������� ���:";
		cin >> sex;
		cout << "������� �������: ";
		cin >> age;
	}
	
};
class Education
{
protected:
	string prof_name;
	string level;
	int years;
public:
	bool ReadEducation(ifstream &f);

};
class Academic : public People, public Education
{
private:
	Subjects * subjects;
public:
	bool Read(ifstream &f);
	void Delete();
	void AddSubj();
	virtual ostream& PrintData(ostream &f)
	{
		f << "�������������: " << name << "\n���:" << sex << "\n�������: " << age << "\n�������: "  << subjects 
			<< "\n" << "���������: " << prof_name << "\n������: " << level << "\n����� ��������: " << years << "\n"<< "������������������������" << "\n";
		return f;
	}
	virtual void AddData(string input_name)
	{
		name = input_name;
		cout << "������� ���:";
		cin >> sex;
		cout << "������� �������: ";
		cin >> age;
		AddSubj();
	}
};

class Students : public People
{
private:
	int count;
	float average;
	string type;
	vector<Exams> examlist;
public:	
	Students()
	{
		count = 0;
		average = 0;
		cout << "students constructor"<< endl;
	}
	~Students()
		{
			cout << "students destructor"<<endl;
		}	
	virtual void AddData(string input_name)
	{
		name = input_name;
		cout << "������� ���:";
		cin >> sex;
		cout << "������� �������: ";
		cin >> age;
		cout << "������� ����� ��������(Morning/Evening):";
		cin >> type;
		AddEx();
	}
	virtual ostream& PrintData(ostream &f)
	{
		f << "�������: " << name << "\n���:" << sex << "\n��� ��������:" <<type<<  "\n�������: " << age << "\n�������: (" << average << ")\n";
		PrintExamList(f);
		return f;
	}
	ostream& PrintExamList(ostream &f);
	bool Read(ifstream &f);
	void Delete();
	void AddEx();
	void AVG();	
	void Edit();
	void sortVals()
	{
		sort(examlist.begin(), examlist.end());
	}
};
#endif