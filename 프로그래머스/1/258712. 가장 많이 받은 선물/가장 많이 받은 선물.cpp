#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>	// abs for float, double
#include <cstdlib> // abs for int, long int
#define ULL unsigned long long
#define INTMAX 2147483647
using namespace std;

int giftCount[51][51];
pair<int, int> giveAndtake[51];
int result[51];

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;

	for (int i = 0; i < gifts.size(); i++) {
		string tmp[2];
		int ia = 0, ib = 0;
		for (int j = 0; j < gifts[i].length(); j++) {
			if (gifts[i][j] != ' ')tmp[1].push_back(gifts[i][j]);
			else {
				tmp[0] = tmp[1];
				tmp[1].clear();
			}
		}

		for (int j = 0; j < friends.size(); j++) {
			if (friends[j] == tmp[0])ia = j;
			if (friends[j] == tmp[1])ib = j;
		}

		giftCount[ia][ib]++;
		giveAndtake[ia].first++;
		giveAndtake[ib].second++;
	}

	for (int i = 0; i < friends.size(); i++) {
		for (int j = i + 1; j < friends.size(); j++) {
			if (giftCount[i][j] != giftCount[j][i]) {
				if (giftCount[i][j] > giftCount[j][i]) result[i]++;
				else result[j]++;
			}
			else {
				int tmpI = giveAndtake[i].first - giveAndtake[i].second;
				int tmpJ = giveAndtake[j].first - giveAndtake[j].second;

				if (tmpI != tmpJ) {
					if (tmpI > tmpJ)result[i]++;
					else result[j]++;
				}
			}
		}
	}

	for (int i = 0; i < friends.size(); i++) {
		answer = max(answer, result[i]);
	}
	return answer;
}