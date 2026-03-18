#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<int> chk(msg.size(), 0);

    unordered_map<string, int> m;
    int index = 1;
    for (; index <= 26; index++)
    {
        string s(1, (char)(index + 'A' - 1));
        m[s] = index;
    }

    for (int i = 0; i < msg.size(); i++)
    {
        if (chk[i]) continue;

        int curIndex = -1;
        for (int j = 1; i + j - 1 < msg.size(); j++)
        {
            string curStr = msg.substr(i, j);

            auto it = m.find(curStr);
            if (it == m.end())
            {
                m[curStr] = index++;
                break;
            }
            else
            {
                chk[i + j - 1] = 1;
                curIndex = it->second;
            }
        }
        answer.emplace_back(curIndex);
    }

    return answer;
}