// Copyright (C) 2017 by iamslash

#include <bits/stdc++.h>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

long long largestRectangle(vector <int> h) {
  // Complete this function
  int max_area = 0;
  stack<int> s;
  h.insert(h.begin(), -1);
  h.push_back(0);
  s.push(0);

  for (int r = 1; r < h.size(); ++r) {
    printf("%d\n", r);
    while (h[s.top()] > h[r]) {
      int i = s.top(); s.pop();
      int l = s.top();
      int area = (r - l - 1) * (long long)h[i];
      max_area = max(max_area, area);
      printf("  l: %2d, r: %2d, area: %2ld, max: %2ld\n", l, r, area, max_area);
    }
    s.push(r);
  }

  return max_area;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}

// 2 1 5 6 2 3
// 10
