//               i
// internationalization
// i12iz4n
//     j

// 4ms 100.00% 10MB 5.26%
// O(N) O(1)
class Solution {
 public:
  bool validWordAbbreviation(std::string word, std::string abbr) {
    int i = 0, j = 0, m = word.size(), n = abbr.size(); 
    while (i < m && j < n) {
      if (abbr[j] < '1' || abbr[j] > '9') {
        if (word[i++] != abbr[j++])
          return false;
      } else {
        std::string s;
        while (j < n && abbr[j] >= '0' && abbr[j] <= '9')
          s += abbr[j++];
        i += std::stoi(s);
      }
//printf("%d %d\n", i, j);
    }
    return (i == m && j == n) ? true : false;
  }
};

