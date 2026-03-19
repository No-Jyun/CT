#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;

    vector<pair<string, string>> v;

    for (int i = 0; i < record.size(); i++)
    {
        int j = 0;
        if (record[i][0] == 'C') j = 7;
        else j = 6;

        string tok;
        string uid;
        for (; j < record[i].size(); j++)
        {
            if (record[i][j] == ' ')
            {
                uid = tok;
                tok.clear();
            }
            else
            {
                tok.push_back(record[i][j]);
            }
        }
        if(record[i][0] != 'L')
            m[uid] = tok;
        else
            uid = tok;

        if(record[i][0] != 'C')
            v.emplace_back(make_pair(record[i], uid));
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first[0] == 'E')
        {
            string tmp = "님이 들어왔습니다.";
            tmp = m[v[i].second] + tmp;
            answer.emplace_back(tmp);
        }
        else 
        {
            string tmp = "님이 나갔습니다.";
            tmp = m[v[i].second] + tmp;
            answer.emplace_back(tmp);
        }
    }

    return answer;
}