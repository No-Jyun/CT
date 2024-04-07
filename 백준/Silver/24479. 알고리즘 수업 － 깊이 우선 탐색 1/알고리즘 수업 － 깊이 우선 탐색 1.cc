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

int n;
int times = 1;

struct Node {
	int chk = 0;
	priority_queue<int, vector<int>, greater<int>> q;
};

void DFS(int index, vector<Node>& v) {
	if (!v[index].chk) {
		v[index].chk = times++;

		while (!v[index].q.empty()) {
			int next = v[index].q.top();
			v[index].q.pop();

			if (!v[next].chk) DFS(next, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, r;
	cin >> n >> m >> r;
	
	vector<Node> v(n + 1);

	while (m--) {
		int a, b;
		cin >> a >> b;
		
		v[a].q.push(b);
		v[b].q.push(a);
	}

	DFS(r, v);

	for (int i = 1; i <= n; i++) {
		cout << v[i].chk << '\n';
	}
}