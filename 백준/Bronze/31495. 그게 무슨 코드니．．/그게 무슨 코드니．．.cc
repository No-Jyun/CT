#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string StartSolve(string str)
{
	int num = 0;
	int index1 = -1;
	int index2 = -1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '"')
		{
			num++;
			if (index1 == -1) index1 = i;
			else index2 = i;
		}
	}

	if (str.size() == 0) return "CE";
	if (num < 2) return "CE";
	if (index1 + 1 == index2)return "CE";
	if (str[0] != '"' || str[str.size() - 1] != '"')return "CE";
	return str.substr(index1 + 1, index2 - index1 - 1);
}

int main()
{
	string str;
	getline(cin, str);

	cout << StartSolve(str);
}