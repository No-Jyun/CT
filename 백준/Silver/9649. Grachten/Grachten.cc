#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (cin.eof())break;

		int upper = a * b;
		int downer = c - b;

		for (int i = 2; i <= downer; i++) {
			while (upper % i == 0 && downer % i == 0) {
				upper /= i;
				downer /= i;
			}
		}
		cout << upper << '/' << downer << '\n';
	}
}