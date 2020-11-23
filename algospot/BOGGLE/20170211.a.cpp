#include <iostream>
#include <cstring>

using namespace std;

bool is_found_syllable(char cache[][5][5], char board[][6], char word[], int r, int c, int idx)
{
    if (word[idx] == 0) return true;
    if (r < 0 || r >= 5) return false;
    if (c < 0 || c >= 5) return false;

    char& elem = cache[idx][r][c];
    
    if (elem != -1) return elem;
    if (board[r][c] != word[idx]) return elem = false;
    
    return elem =
        is_found_syllable(cache, board, word, r  , c-1, idx+1) ||
        is_found_syllable(cache, board, word, r+1, c-1, idx+1) ||
        is_found_syllable(cache, board, word, r+1, c  , idx+1) ||
        is_found_syllable(cache, board, word, r+1, c+1, idx+1) ||
        is_found_syllable(cache, board, word, r  , c+1, idx+1) ||
        is_found_syllable(cache, board, word, r-1, c+1, idx+1) ||
        is_found_syllable(cache, board, word, r-1, c  , idx+1) ||
        is_found_syllable(cache, board, word, r-1, c-1, idx+1);
}

bool is_found_word(char cache[][5][5], char board[][6], char word[])
{
    int r = 2;
    int c = 2;
    int idx = -1;

    for (int r=0; r<5; ++r)
        for (int c=0; c<5; ++c)
        {
            if (is_found_syllable(cache, board, word, r, c, 0))
                return true;
        }
    return false;
}

int main() {
    
    int C;
    cin >> C;
    int N;

    for(int c=0; c<C; ++c)
    {
        char ar_board[5][6] = {0,}; //

        for (int i=0; i<5; ++i)
            scanf("%s", ar_board[i]);

        scanf("%d", &N);
        
        for (int n=0; n<N; ++n)
        {
            char ar_words[11] = {0,}; // row, colum
            char ar_cache[11][5][5];
            memset(ar_cache, -1, sizeof(ar_cache));
            
            scanf("%s", ar_words);
            
            cout << ar_words
                 << " "
                 << (is_found_word(ar_cache, ar_board, ar_words) ? "YES" : "NO")  
                 << endl;
        }       
    }
  
    return 0;
}
