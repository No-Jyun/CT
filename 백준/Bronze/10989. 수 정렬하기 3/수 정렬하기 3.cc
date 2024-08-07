#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int count[10001] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		count[tmp - 1]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (count[i] != 0) {
			for (int k = 0; k < count[i]; k++) {
				cout << i + 1 << '\n';
			}
		}
	}
}