#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string GetBigger(string aS, string bS) 
{
    string a = aS + bS;
    string b = bS + aS;

    if (a.compare(b) >= 0) return a;
    else return b;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<string, string>> v;

    for (int i = 0; i < numbers.size(); i++)
    {
        string num = to_string(numbers[i]);
        string tripNum = num + num + num;
        v.push_back({ tripNum, num });
    }

    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0 ; i--)
    {
        answer = GetBigger(answer, v[i].second);
    }

    if (answer[0] == '0') answer = "0";

    return answer;
}