#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;

    int targetToSolved = progresses.size();
    int nowSolved = 0;

    while (nowSolved < targetToSolved)
    {
        bool isOkToRelease = true;
        int todayRelease = 0;
        for (int i = nowSolved; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];

            if (progresses[i] >= 100)
            {
                if (isOkToRelease)
                {
                    todayRelease++;
                }
            }
            else
            {
                isOkToRelease = false;
            }
        }
        if (todayRelease != 0)
        {
            answer.emplace_back(todayRelease);
            nowSolved += todayRelease;
        }
    }

    return answer;
}