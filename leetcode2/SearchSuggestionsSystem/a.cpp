/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 36ms 97.65% 23.9MB 90.73%
// sort, binary search
// O(NlgN) O(N)
class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    vector<vector<string>> ans;
    auto it = products.begin();
    sort(products.begin(), products.end());
    string word;
    for (char c : searchWord) {
      word += c;
      ans.push_back(vector<string>());
      it = lower_bound(it, products.end(), word);
      for (auto i = 0; i < 3 && (it + i) != products.end(); ++i) {
        string& product = *(it + i);
        if (product.find(word)) {
          break;
        }
        ans.back().push_back(product);
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
