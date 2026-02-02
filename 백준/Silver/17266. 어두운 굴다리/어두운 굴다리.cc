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

int n, m;
vector<int> v;

int StartSolve()
{
	int ex = 0, now = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> now;

		if (i == 0)
		{
			v.emplace_back(now - 0);
			continue;
		}

		int t = (now - ex) / 2;
		if ((now - ex) % 2) t++;
		v.emplace_back(t);
		ex = now;
	}
	v.emplace_back(n - ex);

	sort(v.begin(), v.end());

	return v[v.size() - 1];
}

int main()
{
	cin >> n >> m;
	cout << StartSolve();
}