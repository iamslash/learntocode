// Copyright (C) 2018 by iamslash
// https://www.hackerrank.com/challenges/unbounded-knapsack/problem

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int unboundedKnapsack(int k, vector <int> arr) {
  int C[k+1] = {0,};
  int n = arr.size();
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[j] <= i)
        C[i] = max(C[i], arr[j] + C[i-arr[j]]);
    }
  }
  return C[k];
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
      int n;
      int k;
      cin >> n >> k;
      vector<int> arr(n);
      for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
      }
      int result = unboundedKnapsack(k, arr);
      cout << result << endl;
    }
    return 0;
}
