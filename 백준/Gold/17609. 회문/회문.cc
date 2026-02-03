#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
#define ULL unsigned long long
#define LL long long
#define INTMAX 2147483647
using namespace std;

int n;

int Test2(string& str, int pt1, int pt2)
{
	while (pt1 <= pt2)
	{
		if (str[pt1] == str[pt2])
		{
			pt1++;
			pt2--;
		}
		else
			return 0;
	}
	return 1;
}

int Test(string& str, int pt1, int pt2)
{
	bool isOneCharPassed = false;

	while (pt1 <= pt2)
	{
		if (str[pt1] == str[pt2])
		{
			pt1++;
			pt2--;
		}
		else
		{
			isOneCharPassed = true;
			break;
		}
	}

	if (isOneCharPassed)
	{
		int left = Test2(str, pt1 + 1, pt2);
		int right = Test2(str, pt1, pt2 - 1);

		if (left || right) return 1;
		return 2;
	}

	return 0;
}

int StartSolve()
{
	string str;
	cin >> str;

	return Test(str, 0, str.size() - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while(n--)
		cout << StartSolve() << "\n";
}