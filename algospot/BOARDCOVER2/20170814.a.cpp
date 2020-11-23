//https://algospot.com/judge/problem/read/BOARDCOVER2

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <queue>

using namespace std;

int H_BOARD, W_BOARD, H_BLOCK, W_BLOCK;

vector<vector<pair<int, int> > > v_rotations;
int block_size;

int covered[10][10];
int best;


bool correct(int y, int x)
{
	return !(y < 0 || y >= H_BOARD || x < 0 || x >= W_BOARD);
}

// (y, x)를 왼쪽 위칸으로 해서 주어진 블록을 delta=1이면 놓고, -1이면 없앤다.
// 블록을 놓을때 이미 놓인 블록이나 검은 칸과 겹치면 거짓을 아니면 참을 반환한다.
bool set(int y, int x, const vector<pair<int, int> >& block, int delta)
{
    if(delta == 1)
	{
		for(int i=0; i < block.size(); i++)
		{
			int Y = y + block[i].first;
			int X = x + block[i].second;

			if(!correct(Y,X) || covered[Y][X])
				return false;
		}
	}
	
	for(int i=0; i < block.size(); i++)
		covered[y + block[i].first][x + block[i].second] = delta == 1;

	return true;
}

// placed: 지금까지 놓은 블록의 수
void search(int placed)
{
    int y = -1, x = -1;
    for(int i=0; i<H_BOARD; ++i)
    {
        for(int j=0; j<W_BOARD; ++j)
        {
            if (covered[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    // base condition
    if (y == -1)
    {
        best = max(best, placed);
        return;
    }

    // 이칸을 덮는다.
    for (int i=0; i<v_rotations.size(); ++i)
    {
        if (set(y, x, v_rotations[i], 1))
            search(placed+1);
        set(y, x, v_rotations[i], -1);
    }

    // 이 칸을 덮지 않고 '막아'둔다.
    covered[y][x] = 1;
    search(placed);
    covered[y][x] = 0;
}

int solve(const vector<string>& v_board)
{

    best = 0;
    for(int i=0; i<H_BOARD; ++i)
        for(int j=0; j<W_BOARD; ++j)
            covered[i][j] = (v_board[i][j] == '#' ? 1 : 0);
    search(0);
    return best;
}

// 2차원 배열 v을 시계방향으로 90도 돌린 결과를 반환한다.
vector<string> rotate(const vector<string>& v)
{
    vector<string> r(v[0].size(), string(v.size(), ' '));
    for(int i=0; i<v.size(); ++i)
        for(int j=0; j<v[0].size(); ++j)
            r[j][v.size()-i-1] = v[i][j];
    return r;
}

// block의 네 가지 회전 형태를 만들고 이들을 상대 좌표의 목록으로 반환한다.
void generate_rotations(vector<string> block)
{
    v_rotations.clear();
    v_rotations.resize(4);

    for(int rot=0; rot<4; ++rot)
    {
        int origin_y = -1;
        int origin_x = -1;

        for(int i=0; i<block.size(); ++i)
        {
            for(int j=0; j<block[i].size(); ++j)
            {
                if (block[i][j] == '#')
                {
                    if (origin_y == -1)
                    {
                        // 가장 윗줄 맨 왼쪽에 있는 칸이 '원점'이 된다.
                        origin_y = i;
                        origin_x = j;
                    }
                    // 각 칸의 위치를 원점으로 부터의 상대좌표로 표현한다.
                    v_rotations[rot].push_back(
                        make_pair(i - origin_y,
                                  j - origin_x));
                }
            }
        }
        // 블록을 시계방향으로 90도 회전한다.
        block = rotate(block);
    }

    // 네가지 회전 형태 중 중복이 있을 경우 이를 제거한다.
    sort(v_rotations.begin(), v_rotations.end());
    v_rotations.erase(
        unique(v_rotations.begin(), v_rotations.end()),
        v_rotations.end());
    // 블록이 몇 칸 짜리인지 저장해 둔다.
    block_size = v_rotations[0].size();
}

void dump(const vector<string> & v)
{
    printf("=====\n");

    for(int i=0; i<v.size(); ++i)
    {
        printf("%s\n", v[i].c_str());
    }
    printf("=====\n");
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &H_BOARD);
        scanf("%d", &W_BOARD);
        scanf("%d", &H_BLOCK);
        scanf("%d", &W_BLOCK);

        vector<string> v_board;
        vector<string> v_block;

        for(int i=0; i<H_BOARD; ++i)
        {
            char buf[16] = {0,};
            scanf("%s", buf);
            v_board.push_back(buf);
        }

        for(int i=0; i<H_BLOCK; ++i)
        {
            char buf[16] = {0,};
            scanf("%s", buf);
            v_block.push_back(buf);
        }
        
        generate_rotations(v_block);
        printf("%d\n", solve(v_board));
        
    }


    return 0;
}
