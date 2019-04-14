#include "stdafx.h"
#include "Ex.h"

bool Exams::Read(ifstream & f)
{
	
		string sname;
		f >> (sname);
		if (sname.length() == 0)
			return 1;
		subject = FindSubj(sname);
		f >> (val);
		return 0;
	
}

void Exams::AddData()
{
	cout << "�������� �������: " << endl;
	SubjOut();
	string sname;
	do {
		cin >> sname;
		subject = FindSubj(sname);
		if (subject == NULL) cout << "������� �� ������.\n";			
	} while (subject == NULL);
	cout << "������� ������: ";
	cin >> val;
}

ostream & operator<<(ostream & f, Exams & data)
{
	f << data.subject << "(" << data.val << ")\n";
	return f;
}
