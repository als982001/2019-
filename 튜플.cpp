#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<string> tps(500);

    int tps_num = 0;
    int norder = 0;

    for (int i = 1; i < s.size(); ++i)
    {
        string stemp;
        int norder = 0;

        if (s[i] == '{')
        {
            while (s[i] != '}')
            {
                if (s[i] == ',')
                    ++norder;
                stemp.push_back(s[i]);
                ++i;
            }

            tps[norder] = stemp;
            ++tps_num;
        }
    }

    for (int i = 0; i < tps_num; ++i)
    {
        for (int j = 1; j < tps[i].size(); ++j)
        {
            string stemp;
            int ntemp;

            while ('9' >= tps[i][j] && tps[i][j] >= '0')
            {
                stemp.push_back(tps[i][j++]);
            }

            ntemp = stoi(stemp);

            bool isin = false;

            for (int ans_num = 0; ans_num < answer.size(); ++ans_num)
            {
                if (ntemp == answer[ans_num])
                    isin = true;
            }

            if (!isin)
                answer.push_back(ntemp);
        }
    }

    return answer;
}

// 밑의 main은 개인적으로 검사해보기 위한 main문

/*
int main()
{
    string s;

    cin >> s;

    vector<int> answer = solution(s);

    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << " ";

    return 0;
}

*/