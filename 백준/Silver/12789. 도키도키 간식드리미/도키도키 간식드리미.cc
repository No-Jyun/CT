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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<int> second, first;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		first.push_back(a);
	}

	int nowOrder = 1;
	while (nowOrder <= n) {
		if (!first.empty() && first.front() == nowOrder) {
			nowOrder++;
			first.pop_front();
		}
		else if (!second.empty() && second.front() == nowOrder) {
			nowOrder++;
			second.pop_front();
		}
		else{
			if (first.empty()) {
				cout << "Sad"; return 0;
			}
			second.push_front(first.front());
			first.pop_front();
		}
	}
	cout << "Nice";
}