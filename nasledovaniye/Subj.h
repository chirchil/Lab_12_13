#pragma once
#ifndef Subj_H
#define Subj_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Subjects
{
private:
	string sb_name;
public: 
	string GetSbName() { return sb_name; }
	bool Read(ifstream &f);
	bool operator==(string inp_name) { return(sb_name == inp_name); }
	friend ostream& operator<<(ostream & f, Subjects &data);
	friend ostream& operator<<(ostream & f, Subjects *data);
	
};

#endif