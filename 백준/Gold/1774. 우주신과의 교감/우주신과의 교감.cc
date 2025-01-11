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
#define LL long long
#define INTMAX 2147483647
using namespace std;

struct Union {
	int head = 0;
	vector<int> tail;
	Union() {}
}arr[1001];

int n, m;
double result;
pair<int, int> coord[1001];
priority_queue<vector<LL>> q;

LL Dis(int a, int b) {
	LL x = pow(coord[a].first - coord[b].first, 2);
	LL y = pow(coord[a].second - coord[b].second, 2);
	return x + y;
}

void UnionAdd(int parentA, int parentB) {
	if (parentA != parentB) {
		if (arr[parentA].tail.size() < arr[parentB].tail.size()) {
			for (int i = 0; i < arr[parentA].tail.size(); i++) {
				arr[arr[parentA].tail[i]].head = parentB;
				arr[parentB].tail.push_back(arr[parentA].tail[i]);
			}
			arr[parentA].tail.clear();
			arr[parentA].head = parentB;
			arr[parentB].tail.push_back(parentA);
		}
		else {
			for (int i = 0; i < arr[parentB].tail.size(); i++) {
				arr[arr[parentB].tail[i]].head = parentA;
				arr[parentA].tail.push_back(arr[parentB].tail[i]);
			}
			arr[parentB].tail.clear();
			arr[parentB].head = parentA;
			arr[parentA].tail.push_back(parentB);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i].head = i;
		cin >> coord[i].first >> coord[i].second;
	}
	for (int j = 1; j <= m; j++) {
		int a, b;
		cin >> a >> b;
		UnionAdd(arr[a].head, arr[b].head);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			q.push({ -Dis(i,j),i,j });
		}
	}

	while (!q.empty()) {
		LL nowS = -q.top()[0];
		int iA = arr[q.top()[1]].head;
		int iB = arr[q.top()[2]].head;
		q.pop();

		if (iA != iB) {
			result += sqrt(nowS);
			UnionAdd(iA, iB);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << result;
}