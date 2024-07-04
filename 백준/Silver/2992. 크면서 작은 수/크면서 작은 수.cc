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
vector<char> v;

bool Check() {
	string tmp;
	for (auto it : v)tmp.push_back(it);
	return stoi(s) < stoi(tmp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < s.size(); i++)v.push_back(s[i]);
	sort(v.begin(), v.end());

	bool isPrint = false;
	do {
		isPrint = Check();
	} while (!isPrint && next_permutation(v.begin(), v.end()));

	if (isPrint) for (auto it : v)cout << it;
	else cout << 0;
}