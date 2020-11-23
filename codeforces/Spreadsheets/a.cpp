// Copyright (C) 2017 by iamslash
// http://codeforces.com/problemset/problem/1/B

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <regex>

int get_num(const std::string& s) {
  int r = 0;
  int div = 1;
  for (int i = s.size() - 1; i >= 0; --i, div *= 26) {
    int n = s[i] - 'A' + 1;
    // printf("  %c %d\n", s[i], n);
    r += (n * div);
  }
  return r;
}

std::string get_str(int n) {
  std::string r = "";
  int div = n;
  int mod;
  while (true) {
    n = div - 1;
    div = n / 26;  // 2
    mod = n % 26;  // 3
    r.insert(0, 1, 'A' + mod);
    // printf("%s\n", r);
    if (div == 0)
      break;
  }
  return r;
}

// BC23
std::string get_numeration_1(const std::string row,
                             const std::string col) {
  char buf[128];
  // R23C55
  snprintf(buf, sizeof(buf), "R%sC%d", row.c_str(), get_num(col));
  return buf;
}

// R23C55
std::string get_numeration_2(const std::string row,
                             const std::string col) {
  char buf[128];
  // BC23
  snprintf(buf, sizeof(buf), "%s%s",
           get_str(atoi(col.c_str())).c_str(),
           row.c_str());
  return buf;
}

int main() {
  std::regex re0("[A-Z][0-9]+");
  std::regex re1("R[0-9]+C[0-9]+");
  std::regex renum("[0-9]+");
  std::regex restr("[A-Z]+");
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    char buf[128];
    scanf("%s", buf);
    std::string msg = buf;

    std::smatch mresult;
    std::string row;
    std::string col;

    std::string r;
    if (std::regex_match(msg, re1)) {
      while (std::regex_search(msg, mresult, renum)) {
        if (row.size() == 0)
          row = mresult[0];
        else
          col = mresult[0];
        msg = mresult.suffix().str();
      }
      // printf("  %s %s\n", row.c_str(), col.c_str());
      r = get_numeration_2(row, col);

    } else {
      std::regex_search(msg, mresult, restr);
      col = mresult[0];
      std::regex_search(msg, mresult, renum);
      row = mresult[0];
      r = get_numeration_1(row, col);
    }
    printf("%s\n", r.c_str());
  }
  // R228C494
  // printf("%s\n", get_str(494).c_str());
  // printf("%s\n", get_str(26).c_str());
  // printf("%s\n", get_str(27).c_str());
  // printf("%d\n", get_num("BC"));

  return 0;
}
