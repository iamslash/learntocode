#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int get_max_square_size(vector<int> & H, int l, int r)
{

    // base condition
    if (l >= r) return H[l];

    // recursion
    // get left, right max size
    int max_size = 0;
    int idx_mid  = l + (r-l)/2;
    max_size = get_max_square_size(H, l, idx_mid);
    max_size = max(max_size, get_max_square_size(H, idx_mid+1, r));

    // get middle max size
    int l_inner = idx_mid;
    int r_inner = idx_mid+1;
    int h_min = min(H[l_inner], H[r_inner]);;
    int max_size_inner = 2 * h_min;

    // printf("[%d, %d] [%d, %d]\n", l, r, l_inner, r_inner);
    
    while ( l_inner > l || r_inner < r )
    {
        if (r_inner < r && (l_inner == l || H[l_inner-1] < H[r_inner+1] ))
        {
            r_inner++;
            h_min = min(h_min, H[r_inner]);
        }
        else
        {
            l_inner--;
            h_min = min(h_min, H[l_inner]);            
        }
        max_size_inner = max(max_size_inner, (r_inner - l_inner + 1) * h_min);
        //printf("=>[%d, %d] %d * %d\n", l_inner, r_inner, r_inner - l_inner + 1, h_min);
    }
    
    return max(max_size, max_size_inner);
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        vector<int> H;
        scanf("%d", &N);
        for(int n=0; n<N; ++n)
        {
            int h;
            scanf("%d", &h);
            H.push_back(h);
        }

        printf("%d\n", get_max_square_size(H, 0, H.size()-1));
    }
  
    return 0;
}
