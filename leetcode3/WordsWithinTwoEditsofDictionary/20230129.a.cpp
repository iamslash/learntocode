/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 65ms 18.68.68% 15.7MB 32.73%
// brute force
// O(QD) O(Q)
// Q: the number of queries
// D: the number of dictionary
class Solution {
private:
  int difference(const string& a, const string& b) {
    int cnt = 0, n = a.size();
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        cnt++;
      }
    }
    return cnt;
  }
public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> ans;
    for (string query : queries) {
      for (string word : dictionary) {
        if (difference(query, word) <= 2) {
          ans.push_back(query);
          break;
        }
      }
    }
    return ans;
  }
};

// 2ms 99.17% 42.3MB 81.82%
// brute force
// O(QD) O(Q)
class Solution {
    private int difference(String a, String b) {
        int cnt = 0, n = a.length();
        for (int i = 0; i < n; ++i) {
            if (a.charAt(i) != b.charAt(i)) {
                cnt++;
            }
            if (cnt >= 3) {
                return cnt;
            }
        }
        return cnt;
    }
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> ans = new ArrayList<>();
        for (String query : queries) {
            for (String word : dictionary) {
                if (difference(query, word) <= 2) {
                    ans.add(query);
                    break;
                }
            }
        }
        return ans;
    }
}
