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

int a, b, c;
bool chk[201][201][201];
vector<int> result;

void DFS(int tongA, int tongB, int tongC) {
	if (chk[tongA][tongB][tongC]) return;
	else {
		chk[tongA][tongB][tongC] = 1;
		if (!tongA)result.push_back(tongC);

		int addWater = 0;
		if (tongC) {
			addWater = a - tongA;
			if (addWater && addWater <= tongC)DFS(tongA + addWater, tongB, tongC - addWater);
			if (addWater && addWater > tongC)DFS(tongA + tongC, tongB, 0);

			addWater = b - tongB;
			if (addWater && addWater <= tongC)DFS(tongA, tongB + addWater, tongC - addWater);
			if (addWater && addWater > tongC)DFS(tongA, tongB + tongC, 0);
		}
		if (tongA) {
			addWater = c - tongC;
			if (addWater && addWater <= tongA)DFS(tongA - addWater, tongB, tongC + addWater);
			if (addWater && addWater > tongA)DFS(0, tongB, tongC + tongA);

			addWater = b - tongB;
			if (addWater && addWater <= tongA)DFS(tongA - addWater, tongB + addWater, tongC);
			if (addWater && addWater > tongA)DFS(0, tongB + tongA, tongC);
		}
		if (tongB) {
			addWater = c - tongC;
			if (addWater && addWater <= tongB)DFS(tongA, tongB - addWater, tongC + addWater);
			if (addWater && addWater > tongB)DFS(tongA, 0, tongC + tongB);

			addWater = a - tongA;
			if (addWater && addWater <= tongB)DFS(tongA + addWater, tongB - addWater, tongC);
			if (addWater && addWater > tongB)DFS(tongA + tongB, 0, tongC);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	DFS(0, 0, c);

	sort(result.begin(), result.end());
	int ex = -1;
	for (int it : result) { 
		if (ex != it)cout << it << ' ';
		ex = it;
	}
}