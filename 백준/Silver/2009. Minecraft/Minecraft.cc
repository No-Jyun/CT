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
int space[101][101][101];
int h[101][101];
int r[101][101];
int c[101][101];
int th[101][101];
int tr[101][101];
int tc[101][101];

void Print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cout << space[i][j][k];
			}
			cout << '\n';
		}
	}

}

bool Chk() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (space[i][j][k]) {
					th[j][k] = 1;
					tr[i][k] = 1;
					tc[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (th[i][j] != h[i][j])return false;
			if (tr[i][j] != r[i][j])return false;
			if (tc[i][j] != c[i][j])return false;
		}
	}
	return true;
}

void DC() {
	int tmp[101][101];
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (space[i][j][k])tmp[i][j] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tmp[i][j] != c[i][j]) {
				for (int k = 1; k <= n; k++)space[i][j][k] = c[i][j];
			}
		}
	}

}

void DR() {
	int tmp[101][101];
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= n; k++) {
				if (space[i][j][k])tmp[i][k] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (tmp[i][k] != r[i][k]) {
				for (int j = 1; j <= n; j++)space[i][j][k] = r[i][k];
			}
		}
	}
}

void DH() {
	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			if (h[j][k]) {
				for (int i = 1; i <= n; i++)space[i][j][k] = 1;
			}
		}
	}
}

void Input() {
	string tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			h[i][j + 1] = tmp[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			r[i][j + 1] = tmp[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			c[i][j + 1] = tmp[j] - '0';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Input();

	DH();
	DR();
	DC();

	if (Chk()) { 
		cout << "YES" << '\n';
		Print();
	}
	else cout << "NO";
}