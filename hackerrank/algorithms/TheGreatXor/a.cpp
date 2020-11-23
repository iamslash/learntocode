// Copyright (C) 2017 by iamslash

#include <bits/stdc++.h>

using namespace std;

long theGreatXor(long x){
    // Complete this function
    int n_leading_zero_cnt = 0;
    long i = x;
    while (i >= 0) {
        n_leading_zero_cnt++;
        i = i << 1;
    }
    int n_bit_cnt = 8 * sizeof(x) - n_leading_zero_cnt;
    return pow(2, n_bit_cnt) - x - 1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long result = theGreatXor(x);
        cout << result << endl;
    }
    return 0;
}
