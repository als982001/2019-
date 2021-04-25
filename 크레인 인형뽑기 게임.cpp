#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> box;
    int cur_num = 0;
    int box_num = -1;

    for (int moves_num = 0; moves_num < moves.size(); ++moves_num)
    {
        cur_num = moves[moves_num] - 1; // 이건 board의 열(col) 번호다

        for (int board_row = 0; board_row < board.size(); ++board_row)
        {
            if (board[board_row][cur_num] == 0)
                continue;
            else
            {
                box.push_back(board[board_row][cur_num]);
                board[board_row][cur_num] = 0;
                ++box_num;
                break;
            }
        }

        if (box_num > 0)
        {
            if (box[box_num] == box[box_num - 1])
            {
                box.pop_back();
                box.pop_back();
                answer += 2;
                box_num -= 2;
            }
        }
    }
    return answer;
}

// 밑에 main은 개인 테스트용
/*
int main()
{
    vector<vector<int>> board(5, vector<int>(5));

    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 5; ++c)
        {
            cin >> board[r][c];
        }
    }

    vector<int> moves(8);

    for (int i = 0; i < 8; ++i)
        cin >> moves[i];

   int answer =  solution(board, moves);

   cout << endl << "answer = " << answer << endl;
    return 0;
}
*/