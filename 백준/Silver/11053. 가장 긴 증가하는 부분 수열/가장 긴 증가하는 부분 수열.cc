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
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int* check = new int[n];
	fill(check, check + n, 1);

	int maxim = 0;
	for (int i = 0; i < n; i++) {
		int tmp = 1;
		for (int k = 0; k < i; k++) {
			if (v[k] < v[i]) { 
				tmp = max(tmp, check[i] + check[k]);
			}
		}
		check[i] = tmp;
		maxim = max(maxim, tmp);
	}
	cout << maxim;
}