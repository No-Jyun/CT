#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a, b, c;

void StartSolve()
{

	if (a == b && b == c)
	{
		cout << "Equilateral" << "\n";
		return;
	}

	vector<int> v = { a,b,c };

	sort(v.begin(), v.end());

	if (v[0] + v[1] <= v[2])
	{
		cout << "Invalid" << "\n";
		return;
	}

	if (v[0] == v[1] || v[1] == v[2])
	{
		cout << "Isosceles" << "\n";
		return;
	}
	
	cout << "Scalene" << "\n";
}

int main()
{
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0) break;

		StartSolve();
	}
}