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

bool Cmp(pair<int,string> a, pair<int, string> b) {
	if (a.first == b.first) {
		if (a.second.length() == b.second.length()) return a.second < b.second;
		else return a.second.length() > b.second.length();
	}
	else return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> v;
	vector<pair<int, string>> tmp;

	int n;
	int m;
	cin >> n >> m;
	while (n--) {
		string s;
		cin >> s;
		
		if (s.length() >= m) {
			auto pt = v.insert({ s,1 });
			if (!pt.second) {
				pt.first->second++;
			}
		}
	}

	for (auto it : v) {
		tmp.push_back({ it.second,it.first });
	}
	
	sort(tmp.begin(), tmp.end(), Cmp);

	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i].second << '\n';
	}
}