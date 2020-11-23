class Solution {
 private:
   bool isPalindrome(std::string s) {
     int n = s.size();
     int h = (n+1)/2;
     for (int i = 0; i < h; ++i) {
       if (s[i] != s[n-i-1])
         return false;
     }
     return true;
   }
 public:
  bool validWordSquare(std::vector<std::string>& W) {
    int h = W.size();
    int w = W[0].size();
    int mindia = std::min(h, w);
//printf("%d %d %d\n", h, w, mindia);    
    for (int i = 0; i < w+h-1; ++i) {
      int y = std::min(i, h-1);
      int x = std::max(0, i-h+1);
      std::string dia;
      while (y >= 0 && x < w) {
        dia += W[y][x];
        y--;
        x++;
      }
//printf("%s\n", dia.c_str());        
      if (!isPalindrome(dia))
        return false;
    }
    return true;
  }
};