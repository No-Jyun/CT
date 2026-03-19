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

vector<vector<int>> v;
vector<int> can;
int result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int result = 1;
	int nowstT = v[0][0];
	int nowendT = v[0][1];
	for (int i = 1; i < v.size(); i++) {
		int stT = v[i][0];
		int endT = v[i][1];

		if (endT < nowendT) { 
			nowendT = endT;
			nowstT = stT;
		}
		else if (stT >= nowendT) {
			result++;
			nowstT = stT;
			nowendT = endT;
		}
	}
	cout << result;
}