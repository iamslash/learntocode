#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>      
#include <iomanip>
#include <string>
#include <vector>
#include <functional>
#include <limits>

//...

using namespace std;

int main(){
    
    double ar_min_avg_costs[1000] = {0,};
    int ar_costs[1000] = {0,};
    //int ar_days[1000] = {0,};

    int C;
    cin >> C;

    int N; // 6
    int L; // 3

    for(int n=0; n<C; ++n)
    {
         scanf("%d", &N);
         scanf("%d", &L);
         for (int y=0; y<N; ++y)
             scanf("%d", &ar_costs[y]); 

         //
        double f_min_avg = numeric_limits<double>::max();

        for (int i=0; i<N-L+1; ++i)
        {
            //
            double f_sum = 0;
            int j       = 0;

            // sum costs with team members - 1 
            for (j=i; j<i+L-1; ++j)
                f_sum += ar_costs[j];

            // sum costs with extended team members
            for (int k=i+L-1; k<N; ++k)
            {

                f_sum += ar_costs[k];

                int n_len   = k-i+1;
                double f_avg = f_sum / n_len;
                
                //cout << i << ' ' << j << endl;
                //cout << i << ' ' << j << ' ' << k << ' ' << n_len << endl;

                if (f_avg < f_min_avg)
                    f_min_avg = f_avg;
            }
        }

        ar_min_avg_costs[n] = f_min_avg;
    }

    for (int n=0; n<C; ++n)
    {
        cout << fixed << setprecision( 11 ) << ar_min_avg_costs[n] << endl;
    }

  
    return 0;
}
