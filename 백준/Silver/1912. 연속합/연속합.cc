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
	int result = -1000;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		if (i != 0) {
			int tmpsum = v[i] + v[i - 1];
			if (tmpsum > v[i]) { v[i] = tmpsum; } 
		}
		result = max(result, v[i]);
	}

	cout << result;
}