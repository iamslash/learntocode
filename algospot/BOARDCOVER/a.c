#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void dump(char boards[][20], int H, int W)
{
    printf("=====\n");
    for (int i=0; i<H; ++i)
    {
        for (int j=0; j<W; ++j)
        {
            printf("%c ", boards[i][j]);
        }
        printf("\n");
    }
    printf("=====\n");
}

int get_white_cnt(char boards[][20], int H, int W)
{
    int r = 0;
    
    for (int i=0; i<H; ++i)
    {
        for (int j=0; j<W; ++j)
        {
            if (boards[i][j] == '.')
                r++;
        }
    }

    return r;
}

void set_coords(int n_pattern, int w, int h,
                int * idx_0_x, int * idx_0_y,
                int * idx_1_x, int * idx_1_y,
                int * idx_2_x, int * idx_2_y)
{
    *idx_0_x = w;
    *idx_0_y = h;
    
    switch (n_pattern)
    {
        // .
        //..
        // next : w+1, h
    case 0:
        *idx_1_x = w;
        *idx_1_y = h+1;
        *idx_2_x = w-1;
        *idx_2_y = h+1;
        break;
        // ..
        // .
        // next : w+2, h
    case 1:
        *idx_1_x = w+1;
        *idx_1_y = h;
        *idx_2_x = w;
        *idx_2_y = h+1;
        break;
        // .
        // ..
        // next : w+1, h
    case 2:
        *idx_1_x = w;
        *idx_1_y = h+1;
        *idx_2_x = w+1;
        *idx_2_y = h+1;
        break;
        // ..
        //  .
        // next : w+2, h
    case 3:
        *idx_1_x = w+1;
        *idx_1_y = h;
        *idx_2_x = w+1;
        *idx_2_y = h+1;
        break;
    }

}

bool set_block(char boards[][20], int H, int W, int h, int w, int n_pattern)
{
    int idx_0_x, idx_0_y, idx_1_x, idx_1_y, idx_2_x, idx_2_y; // block dimensions, 3 coordinates

    set_coords(n_pattern, w, h, &idx_0_x, &idx_0_y, &idx_1_x, &idx_1_y, &idx_2_x, &idx_2_y);

    /* printf("@%2d,%2d %2d,%2d %2d,%2d\n", */
    /*           idx_0_y, idx_0_x, */
    /*           idx_1_y, idx_1_x, */
    /*           idx_2_y, idx_2_x);  */
    
    if (idx_0_x < 0 || idx_0_x >= W ||
        idx_0_y < 0 || idx_0_y >= H ||
        idx_1_x < 0 || idx_1_x >= W ||
        idx_1_y < 0 || idx_1_y >= H ||
        idx_2_x < 0 || idx_2_x >= W ||
        idx_2_y < 0 || idx_2_y >= H)
        return false;
    if (boards[idx_0_y][idx_0_x] != '.' ||
        boards[idx_1_y][idx_1_x] != '.' ||
        boards[idx_2_y][idx_2_x] != '.')
        return false;

    // set block '+'
    boards[idx_0_y][idx_0_x] = '+';
    boards[idx_1_y][idx_1_x] = '+';
    boards[idx_2_y][idx_2_x] = '+';

    
    return true;
}

void unset_block(char boards[][20], int h, int w, int n_pattern)
{
    int idx_0_x, idx_0_y, idx_1_x, idx_1_y, idx_2_x, idx_2_y; // block dimensions, 3 coordinates

    set_coords(n_pattern, w, h, &idx_0_x, &idx_0_y, &idx_1_x, &idx_1_y, &idx_2_x, &idx_2_y);

    // set block '+'
    boards[idx_0_y][idx_0_x] = '.';
    boards[idx_1_y][idx_1_x] = '.';
    boards[idx_2_y][idx_2_x] = '.';
}

int result(char boards[][20], int H, int W, int prev_h, int prev_w, int n_white)
{
    /* printf("> [%2d][%2d] %2d\n", prev_h, prev_w, n_white); */
    
    int r = 0;
    int w = prev_w, h = prev_h;
    
    // base condition
    // there is no way 
    if (n_white % 3 != 0)
        return 0;
    // found a way
    if (n_white == 0)
        return 1;

    // recursion
    if (prev_w >= W)
    {
        w  = 0;
        h += 1;
    }
    
    if (h >= H)
        return 0;

    if (set_block(boards, H, W, h, w, 0))
    {
        r += result(boards, H, W, h, w+1, n_white-3);
        unset_block(boards, h, w, 0);
    }

    if (set_block(boards, H, W, h, w, 1))
    {
        r += result(boards, H, W, h, w+1, n_white-3);
        unset_block(boards, h, w, 1);
    }

    if (set_block(boards, H, W, h, w, 2))
    {
        r += result(boards, H, W, h, w+1, n_white-3);
        unset_block(boards, h, w, 2);
    }

    if (set_block(boards, H, W, h, w, 3))
    {
        r += result(boards, H, W, h, w+1, n_white-3);
        unset_block(boards, h, w, 3);
    }

    // there is no matched block
    if (r == 0 && boards[h][w] != '.')
    {
        r += result(boards, H, W, h, w+1, n_white);
    }
    
    //dump(boards, H, W);
    /* printf("> [%2d][%2d] [%2d][%2d] %2d\n", prev_h, prev_w, h, w, n_white); */
    
    
    return r;
}

int main() {
    
    int C; // number of cases
    int H; // height
    int W; // width
    char boards[20][20]; // boards consists of # .

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &H);
        scanf("%d", &W);

        for (int i=0; i<H; ++i)
        {
            scanf("%s", boards[i]);
        }
        /* dump(boards, H, W); */
        /* printf("%2d, %2d [%2d]\n", W, H, get_white_cnt(boards, H, W)); */

        printf("%d\n",
               result(boards, H, W, 0, 0,
                      get_white_cnt(boards, H, W)));
        /* printf("--------------------\n"); */
    }
  
    return 0;
}
