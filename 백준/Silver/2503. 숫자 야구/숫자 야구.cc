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

string s;
int strike, ball;
vector<string> v;

bool Chk(string t) {
	int stk = 0, bl = 0;
	for (int i = 0; i < 3; i++) {
		if (t[i] == s[i])stk++;
		else {
			for (int j = 0; j < 3; j++) {
				if (i != j && t[i] == s[j])bl++;
			}
		}
	}

	return strike == stk && ball == bl;
}

void PushNum(bool first) {	
	if (first) {
		string t = "000";
		for (int i = 1; i <= 9; i++) {
			t[0] = i + '0';
			for (int j = 1; j <= 9; j++) {
				if (i == j)continue;
				t[1] = j + '0';
				for (int k = 1; k <= 9; k++) {
					if (i == k || j == k)continue;
					t[2] = k + '0';

					if (Chk(t))v.push_back(t);
				}
			}
		}
	}

	else {
		vector<string> tmp;
		for (int i = 0; i < v.size(); i++) {
			if (Chk(v[i]))tmp.push_back(v[i]);
		}
		v = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool first = true;
	int n;
	cin >> n;
	while (n--) {
		cin >> s;
		cin >> strike >> ball;

		PushNum(first);
		first = false;
	}
	cout << v.size();
}