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
#define LL long long
#define INTMAX 2147483647
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); i++) {
        schedules[i] += 10;
        if (schedules[i] % 100 >= 60) schedules[i] += 40;
    }

    for (int i = 0; i < schedules.size(); i++) {
        bool isOkay = true;

        for (int d = 0; d < 7 && isOkay; d++) {
            int nowD = d + startday;
            if (nowD == 6 || nowD == 7) continue;
            if (startday == 7 && nowD == 13)continue;

            if (timelogs[i][d] > schedules[i])isOkay = false;
        }
        if (isOkay)answer++;
    }

    return answer;
}