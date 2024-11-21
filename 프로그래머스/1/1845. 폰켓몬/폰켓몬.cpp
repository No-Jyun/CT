#include <vector>

using namespace std;

int n, m, t;
int type[200001];

int solution(vector<int> nums)
{
    int answer = 0;

    n = nums.size();
    m = n / 2;

    for (int i = 0; i < n; i++) {
        if (!type[nums[i]]) {
            type[nums[i]] = 1;
            t++;
        }
    }

    if (t > m)answer = m;
    else answer = t;

    return answer;
}