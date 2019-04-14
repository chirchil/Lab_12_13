#pragma once
#ifndef Ex_H
#define Ex_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Subj.h"


using namespace std;
class Subjects;


class Exams
{
private: 
	int val;
	Subjects *subject;
public:
	Exams()
	{
		val = 0;
		subject = NULL;
	}
	static vector<Subjects> listsubj;
	static void SubjOut()
	{
		for (int i = 0; i < (Exams::listsubj.end() - Exams::listsubj.begin()); i++)
			cout << Exams::listsubj[i];
	}
	static Subjects* FindSubj(string s_name)
	{
		for (int i = 0; i < (listsubj.end() - listsubj.begin()); i++)
		{
			if (Exams::listsubj[i] == s_name)
				return &Exams::listsubj[i];
		}
		return NULL;
	}
	int getVal() { return val; }
	void setVal(int inp_val) { val = inp_val; }
	void setSubj(Subjects *inp_subj) { subject = inp_subj; }
	bool operator==(string inp_name) { return(*subject == inp_name); }
	bool Read(ifstream &f);
	friend ostream& operator<<(ostream & f, Exams &data);
	void AddData();
	bool operator==(Exams& st) { return(val == st.getVal()); }
	bool operator!=(Exams& st) { return(val != st.getVal()); }
	bool operator>(Exams& st) { return(val>st.getVal()); }
	bool operator<(Exams& st) { return(val < st.getVal()); }

	
};

#endif