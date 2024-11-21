#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	sort(phone_book.begin(), phone_book.end());
	map<string, int> m;
	for (int i = 0; i < phone_book.size() && answer; i++) {
		for (int j = 0; j < phone_book[i].length() && answer; j++) {
			string subTmp = phone_book[i].substr(0, j + 1);
			auto it = m.insert({ subTmp,1 });
			if (!it.second)answer = false;
			
			if (j != phone_book[i].length() - 1)m.erase(subTmp);
		}
	}
	return answer;
}