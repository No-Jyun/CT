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
vector<int> edges[1001];
int visitT[1001];
int result[2500];
int returnT[1001];
int dfsT = 1;
bool isC;

void DFS(int index) {
	if (isC)return;

	for (int i = 0; i < edges[index].size(); i++) {
		int toI = edges[index][i];

		if (!visitT[toI]) {
			visitT[toI] = dfsT++;
			DFS(toI);
			result[dfsT] = toI;
			returnT[toI] = dfsT++;
		}
		else {
			if (!returnT[toI]) {
				isC = true;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b, c = 0;
		cin >> a;
		for (int i = 1; i <= a; i++) {
			cin >> b;
			if (c) edges[c].push_back(b);
			c = b;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!visitT[i]) {
			visitT[i] = dfsT++;
			DFS(i);
			result[dfsT] = i;
			returnT[i] = dfsT++;
		}
	}

	fill(visitT, visitT + n + 1, -1);
	if (isC)cout << 0;
	else {
		for (int i = 2400; i >= 1; i--) {
			if (result[i]) {
				cout << result[i] << '\n';
				visitT[result[i]] = 1;
			}
			else {
				if (i <= n && !visitT[i])
					cout << i << '\n';
			}
		}
	}
}