/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <string>

// 4ms 96.77% 10MB 72.55%
class Excel {
 private:
  std::vector<std::vector<int>> m_M;
  std::map<std::pair<int, char>, std::vector<std::string>> m_smp;
 public:
  Excel(int H, char W) {
    m_M = std::vector<std::vector<int>> (H, std::vector<int>(W, 0));
  }

  void set(int r, char c, int v) {
    std::pair<int, char> pr = {r, c};
    if (m_smp.count(pr))
      m_smp.erase(pr);
    m_M[r-1][c-'A'] = v;
  }
    
  int get(int r, char c) {
    std::pair<int, char> pr = {r, c};
    if (m_smp.count(pr))
      return sum(r, c, m_smp[pr]);
    return m_M[r-1][c-'A'];
  }
    
  int sum(int r, char c, std::vector<std::string> V) {
    int sum = 0;
    for (auto& s : V) {
      if (s.find(':') == std::string::npos) {
        char x = s[0];
        int  y = std::stoi(s.substr(1));
        sum += get(y, x);
      } else {
        int pos = s.find(':');
        int ltc = s[0] - 'A';
        int ltr = std::stoi(s.substr(1, pos-1));
        int rbc = s[pos+1] - 'A';
        int rbr = std::stoi(s.substr(pos+2));
        for (int y = ltr; y <= rbr; ++y) {
          for (int x = ltc; x <= rbc; ++x) {
            sum += get(y, x + 'A');
          }
        }
      }
    }

    m_smp[{r, c}] = V;
    return sum;
  }
};

void printn(int n) {
  printf("%d\n", n);
}

int main() {
  
  Excel exl(3, 'C');
  printn(exl.get(1, 'A'));
  exl.set(1, 'A', 1);
  printn(exl.get(1, 'A'));
  // std::istringstream iss("A1");
  // char r;
  // int  c;
  // iss >> r >> c;
  // printf("%c %d\n", r, c);

  // std::istringstream iss("A12:B23");
  // char r0, r1, d;
  // int c0, c1;
  // iss >> r0 >> c0 >> d >> r1 >> c1;
  // printf("%c %d %c %d\n", r0, c0, r1, c1);
  
  return 0;
}
