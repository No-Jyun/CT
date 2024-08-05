#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n, m;
vector<int> v[2001];
int chk[2001];
int result;

void DFS(int index) {
	if (chk[index] == 4) { 
		result = 1; 
		return;
	}

	for (int i = 0; i < v[index].size(); i++) {
		if (chk[v[index][i]] == -1) {
			chk[v[index][i]] = chk[index] + 1;
			DFS(v[index][i]);
			chk[v[index][i]] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	fill(chk, chk + n, -1);

	for (int i = 0; i < n; i++) {
		chk[i] = 0;
		DFS(i);
		chk[i] = -1;

		if (result)break;
	}
	cout << result;
}