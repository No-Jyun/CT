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

string a, b;
bool flag;

void DFS(int head, int tail, bool isReverse) {
	if (flag)return;
	if (tail - head + 1 < a.length())return;
	
	if (tail - head + 1 == a.length()) {
		if (isReverse) {
			for (int i = 0; i < a.length(); i++) {
				if (a[i] != b[tail - i])return;
			}
			flag = true;
		}
		else {
			for (int i = 0; i < a.length(); i++) {
				if (a[i] != b[head + i])return;
			}
			flag = true;
		}
		return;
	}

	if (isReverse) {
		if (b[head] == 'A')DFS(head + 1, tail, true);
		if (b[head] == 'B')DFS(head + 1, tail, false);
	}
	else {
		if (b[tail] == 'A')DFS(head, tail - 1, false);
		if (b[tail] == 'B')DFS(head, tail - 1, true);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	int head = 0;
	int tail = b.length() - 1;

	DFS(head, tail, false);

	if (flag)cout << 1;
	else cout << 0;
}