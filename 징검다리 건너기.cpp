#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    // 답안 시작

    //stones.push_back(999);

    bool can_go = true;
    int stones_len = stones.size();
    while (can_go)
    {
        for (int stn = 0; stn < stones.size(); ++stn)
        {
            int distance = 1;

            while (stn < stones_len && stones[stn] <= 0)
            {
                ++distance;
                ++stn;
            }

            if (distance > k)
            {
                can_go = false;
                break;
            }

            if (stn < stones_len)
                --stones[stn];
        }

        if (can_go)
            ++answer;
    }

    // 답안 끝

    return answer;
}

/*
테스트 위해 만든 main문
int main()
{
    vector<int> stones;

    stones.push_back(2);
    stones.push_back(4);
    stones.push_back(5);
    stones.push_back(3);
    stones.push_back(2);
    stones.push_back(1);
    stones.push_back(4);
    stones.push_back(2);
    stones.push_back(5);
    stones.push_back(1);

    int k = 3;

    int answer = solution(stones, k);

    cout << answer << endl;

    return 0;
}
*/