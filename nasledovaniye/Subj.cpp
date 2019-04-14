#include "stdafx.h"
#include "Subj.h"

bool Subjects::Read(ifstream & f)
{

	try
	{
		f >> (sb_name);
		if (sb_name.length() == 0) return 1;
		return 0;
	}
	catch (...)
	{
		return 1;
	}
}

ostream & operator<<(ostream & f, Subjects & data)
{
	f << data.sb_name << "\n";
	return f;
}

ostream & operator<<(ostream & f, Subjects * data)
{
	f << data->sb_name;
	return f;
}
