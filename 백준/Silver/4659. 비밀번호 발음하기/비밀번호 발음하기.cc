#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool IsMoum(char c)
{
	if (c == 'a')return true;
	if (c == 'e')return true;
	if (c == 'i')return true;
	if (c == 'o')return true;
	if (c == 'u')return true;

	return false;
}

bool HasMoum(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (IsMoum(str[i])) return true;
	}
	return false;
}

bool IsCont(string str)
{
	char exC = str[0];
	for (int i = 1; i < str.size(); i++)
	{
		if (exC == str[i]) 
		{
			if (!(exC == 'e' || exC == 'o'))return true;
		}
		exC = str[i];
	}
	return false;
}

bool IsContChar(string str)
{
	int moumI = 0;
	int moumC = 0;
	int jaumI = 0;
	int jaumC = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (IsMoum(str[i]))
		{
			if (moumC == 0)
				moumC = 1;
			else
			{
				if (moumI + 1 == i)
					moumC++;
				else
					moumC = 1;
			}

			moumI = i;
		}
		else
		{
			if (jaumC == 0)
				jaumC = 1;
			else
			{
				if (jaumI + 1 == i)
					jaumC++;
				else
					jaumC = 1;
			}

			jaumI = i;
		}

		if (moumC == 3 || jaumC == 3)
			return true;
	}
	return false;
}

bool Judge(string str)
{
	if (!HasMoum(str)) return false;

	if (IsContChar(str)) return false;

    if (IsCont(str)) return false;
	
	return true;
}

void StartSolve()
{
	string str;
	while (cin >> str)
	{
		if (str == "end")break;

		if (Judge(str)) cout << "<" << str << "> is acceptable.\n";
		else cout << "<" << str << "> is not acceptable.\n";
	}
}

int main()
{
	StartSolve();
}