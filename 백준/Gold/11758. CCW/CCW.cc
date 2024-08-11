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
using namespace std;

int x[3];
int y[3];
pair<int, int> vectorA, vectorB;
int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}

	vectorA.first = x[1] - x[0]; vectorA.second = y[1] - y[0];
	vectorB.first = x[2] - x[1]; vectorB.second = y[2] - y[1];

	a = vectorA.second;
	b = -vectorA.first;

	int result = a * vectorB.first + b * vectorB.second;
	if (result == 0)cout << 0;
	else if (result > 0)cout << -1;
	else cout << 1;
}