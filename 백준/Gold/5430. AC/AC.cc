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

string p;
int n;
int arr[100001];
int hIndex;
int tIndex;
bool isRev;

void PushArr(string tmp) {
	string g;
	int index = 1;
	for (int i = 1; i < tmp.size() - 1; i++) {
		if (tmp[i] == ',') {
			arr[index++] = stoi(g);
			g.clear();
		}
		else g.push_back(tmp[i]);
	}
	if (n)arr[index] = stoi(g);
}

void Print() {
	cout << '[';
	if (!isRev) {
		for (int i = hIndex; i <= tIndex; i++) {
			cout << arr[i];
			if (i != tIndex) cout << ',';
		}
	}
	else {
		for (int i = tIndex; i >= hIndex; i--) {
			cout << arr[i];
			if (i != hIndex) cout << ',';
		}
	}
	cout << ']' << '\n';
}

void Start() {
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == 'R') {
			if (isRev)isRev = false;
			else isRev = true;
		}

		else {
			if (hIndex <= tIndex) {
				if (isRev)tIndex--;
				else hIndex++;
			}
			else {
				cout << "error" << '\n';
				return;
			}
		}
	}
	Print();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;

		string tmp;
		cin >> tmp;
		PushArr(tmp);

		hIndex = 1;
		tIndex = n;
		isRev = false;

		Start();
	}
}