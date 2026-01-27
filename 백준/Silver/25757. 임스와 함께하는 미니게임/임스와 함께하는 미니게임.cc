#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int n;
char t;
unordered_map<string, int> m;

int StartSolve()
{
	cin >> n >> t;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		m[str]++;
	}
	int num = m.size();

	int gN = 2;
	if (t == 'F')gN = 3;
	if (t == 'O')gN = 4;
	
	return num / (gN - 1);
}

int main()
{
	cout << StartSolve();
}