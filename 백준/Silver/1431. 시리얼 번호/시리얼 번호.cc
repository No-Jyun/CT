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

int StrSum(string& a) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '1' && a[i] <= '9')sum += a[i] - '0';
	}
	return sum;
}

bool Cmp(string a, string b) {
	if (a.length() == b.length()) {
		int sumA = 0, sumB = 0;
		sumA = StrSum(a);
		sumB = StrSum(b);

		if (sumA == sumB) return a < b;
		else return sumA < sumB;
	}
	else return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), Cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}