#include <string>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;

    for (auto it : participant) {
        auto itt = m.insert({ it,1 });
        if (!itt.second)m[it]++;
    }

    for (auto it : completion) {
        if (m[it] == 1)m.erase(it);
        else m[it]--;
    }

    for (auto it : m)answer = it.first;

    return answer;
}