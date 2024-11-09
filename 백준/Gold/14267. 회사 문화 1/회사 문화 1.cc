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
#define INTMAX 2147483647
using namespace std;

int n, m;
int arr[100001];
vector<int> kokai[100001];

void DFS(int index) {
	for (int i = 0; i < kokai[index].size(); i++) {
		arr[kokai[index][i]] += arr[index];
		DFS(kokai[index][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a != -1)kokai[a].push_back(i);
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a] += b;
	}

	DFS(1);

	for (int i = 1; i <= n; i++)cout << arr[i] << ' ';
}