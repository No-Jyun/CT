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

int t, n, result;
int arr[100001];
int chk[100001];

void DFS(int index) {
	queue<int> q;
	q.push(index);

	while (!q.empty()) {
		int nowI = q.front();
		q.pop();

		int gotoI = arr[nowI];
		if (!chk[gotoI]) {
			chk[gotoI] = index;
			q.push(gotoI);
		}
		else if (chk[gotoI] == chk[nowI]) {
			chk[gotoI] = 100000000;
			chk[nowI] = 100000000;
			return;
		}
		if (chk[gotoI] == 100000000)return;
		if (chk[gotoI] == -100000000)return;
		if (chk[gotoI] == -1)return;
	}
}

void CountChain(int index) {
	queue<int> q;
	if (chk[arr[index]] == 100000000)q.push(arr[index]);
	else q.push(index);

	while (!q.empty()) {
		int nowI = q.front();
		q.pop();
		result++;
		chk[nowI] = -1;

		int gotoI = arr[nowI];
		if (chk[gotoI] != 100000000) {
			q.push(gotoI);
		}
		else {
			result++;
			chk[gotoI] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (i == arr[i])chk[i] = -100000000;
			else chk[i] = 0;
		}
	
		result = 0;
		for (int i = 1; i <= n; i++) {
			if (!chk[i]) {
				chk[i] = i;
				DFS(i);
			}
			else if (chk[i] == 100000000) {
				CountChain(i);
			}
			else if (chk[i] == -100000000)result++;
		}

		cout << n - result << '\n';
	}
}