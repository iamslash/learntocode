//https://algospot.com/judge/problem/read/TICTACTOE

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[19683];

// turn이 한줄을 만들었는가?
bool is_finished(const vector<string>& B, char turn)
{
    int r = false;

    if (
        (turn == B[0][0] && B[0][0] == B[1][1] && B[1][1] == B[2][2]) ||
        (turn == B[0][2] && B[0][2] == B[1][1] && B[1][1] == B[2][0]) ||
        (turn == B[0][0] && B[0][0] == B[0][1] && B[0][1] == B[0][2]) ||
        (turn == B[1][0] && B[1][0] == B[1][1] && B[1][1] == B[1][2]) ||
        (turn == B[2][0] && B[2][0] == B[2][1] && B[2][1] == B[2][2]) ||
        (turn == B[0][0] && B[0][0] == B[1][0] && B[1][0] == B[2][0]) ||
        (turn == B[0][1] && B[0][1] == B[1][1] && B[1][1] == B[2][1]) ||
        (turn == B[0][2] && B[0][2] == B[1][2] && B[1][2] == B[2][2]) )
        r = true;

    return r;
}

int bijection(const vector<string>& board)
{
    int r = 0;

    for(int y=0; y<3; ++y)
    {
        for(int x=0; x<3; ++x)
        {
            r = r * 3;
            if (board[y][x] == 'o')
                r += 1;
            else if (board[y][x] == 'x')
                r += 2;
        }
    }
    
    return r;
}

// 내가 이길 수 있으면 1, 비길 수 있으면 0, 지면 -1
int can_win(vector<string>& board, char turn)
{
    // base condition
    if (is_finished(board, 'o'+'x'-turn)) return -1;

    // memoization
    int& r = cache[bijection(board)];
    if (r != -2) return r;

    // recursion
    int min_val = 2;
    for (int y=0; y<3; ++y)
    {
        for (int x=0; x<3; ++x)
        {
            if (board[y][x] == '.')
            {
                board[y][x] = turn;
                min_val = min(min_val, can_win(board, 'o'+'x'-turn));
                board[y][x] = '.';
            }
        }
    }

    // 플레이 할 수 없거나, 어떻게 해도 비기는 것이 최선인 경우
    if (min_val == 2 || min_val == 0)
        return r = 0;
    // 최선이 상대가 이기는 거라면 난 무조건 지고, 상대가 지는 거라면 난 이긴다.
    return r = -min_val;
}

// who is next turn ???
char whose_turn(vector<string>& board)
{
    int x = 0;
    int o = 0;
    for(int r=0; r<3; ++r)
    {
        for(int c=0; c<3; ++c)
        {
            char e = board[r][c];
            if (e == 'x') ++x;
            else if (e == 'o') ++o;
        }
    }

    //printf(" %d %d\n", x, o);

    if (x == o)
        return 'x';
    return 'o';
}

void print_result(vector<string>& board)
{
    string r = "TIE";

    char turn = whose_turn(board);
    //printf("--> %c\n", turn);
    int n_r = can_win(board, turn);
    //printf("--> %d\n", n_r);

    if (n_r == 1)
        r = turn;
    else if (n_r == -1)
        r = 'o' + 'x' - turn;

    printf("%s\n", r.c_str());
}

void print_board(vector<string>& board)
{
    
    for (int y=0; y<3; ++y)
    {
        printf("> ");
        for (int x=0; x<3; ++x)
        {
            printf("%c", board[y][x]);
        }
        printf("\n");

    }

}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        // init chache
        //memset(cache, -2, sizeof(cache));
        for (int i=0; i<19683; ++i)
            cache[i] = -2;

        // input board
        vector<string> board;

        for(int i=0; i<3; ++i)
        {
            char buf[10] = {0,};
            scanf("%s", buf);
            board.push_back(buf);
        }
        //
        //print_board(board);
        //
        print_result(board);
    }
  
    return 0;
}
