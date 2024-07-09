#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int m, result;
string n;
string num;
bool chk[10];

bool isValid() {
	for (int i = 0; i < num.size(); i++) {
		if (chk[num[i] - '0'])return false;
	}
	return true;
}

int main() {
	cin >> n;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		chk[a] = 1;
	}
	result = abs(stoi(n) - 100);

	int len = n.size();
	len == 1 ? len = 1 : len--;

	if (len == 1)num.push_back('0');
	else {
		for (int i = 1; i <= len; i++) {
			if (i == 1)num.push_back('1');
			else num.push_back('0');
		}
	}

	while (len <= n.size() + 1) {
		while (num.size() == len) {
			if (isValid()) {
				result = min(result, abs(stoi(n) - stoi(num)) + (int)num.size());
			}
			num = to_string(stoi(num) + 1);
		}
		len++;
	}

	cout << result;
}