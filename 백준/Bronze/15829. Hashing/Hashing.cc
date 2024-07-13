#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int l;
	cin >> l;
	string s;
	cin >> s;
	
	long long hsh = 0;
	for (int i = 0; i < s.length(); i++) {
		long long tmp = s[i] - 96;
		for (int k = 0; k < i; k++) {
			tmp *= 31;
		}
		hsh += tmp;
	}
	cout << hsh;
}