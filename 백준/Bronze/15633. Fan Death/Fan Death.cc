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
	int n;
	int result = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			result += i;
		}
	}

	cout << result * 5 - 24;
}