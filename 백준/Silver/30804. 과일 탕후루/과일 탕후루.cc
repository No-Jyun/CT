#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

int n;
int maxim = 1;
vector<int> v;
int chk[200001];

void Test() {
	int head = 0;
	int tail = 1;
	int c = 1;
	chk[v[0]] = 1;
	 
	while (tail <= n - 1) {
		if (v[tail] != v[tail - 1] && !chk[v[tail]] && c == 2) {
			c = 3;
		}
		else if (v[tail] != v[tail - 1] && !chk[v[tail]] && c == 1) {
			c = 2;
		}
		
		if (c == 3) {
			while (1) {
				chk[v[head]]--;
				if (!chk[v[head]]) {
					c = 2;
					head++;
					break;
				}
				head++;
			}
		}

		maxim = max(maxim, tail - head + 1);
		chk[v[tail++]]++;
	}
}

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	Test();
	cout << maxim;
}