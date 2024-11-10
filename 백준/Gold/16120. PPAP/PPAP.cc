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
#define INTMAX 2147483647
using namespace std;

string s;
string comppap = "PAPP";
vector<char> arr(1000001);
int indexI = 1;

bool Chk() {
	if (indexI < 4)return false;

	int t = indexI;
	for (int i = 0; i < 4; i++) {
		if (arr[t - i] != comppap[i])return false;
	}
	return true;
}

bool PPAP() {
	if (s == "P")return true;
	if (s.length() <= 3)return false;

	for (int i = 1; i <= s.length(); i++) {
		arr[indexI] = s[i - 1];

		while (Chk()) {
			indexI -= 3;
		}
		indexI++;
	}

	if (indexI == 2)return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;

	if (PPAP())cout << "PPAP";
	else cout << "NP";
}