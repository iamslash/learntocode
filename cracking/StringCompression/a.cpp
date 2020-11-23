// Copyright (C) 2016 by iamslash

// String Compression: Implement a method to perform basic string
// compression using the counts of repeated characters. For example,
// the string aabcccccaaa would become a2blc5a3. If the
// "compressed"string would not become smaller than the original
// string, your method should return the original string. You can
// assume the string has only uppercase and lowercase letters (a - z).

// CORNERCASE
// 0. max compressed cnt ?

#include <string>
#include <cstdio>

// what about last character ???
std::string StringCompress(const std::string& a) {
  std::string s = a + '|';
  std::string r;
  int j = 0;
  char b = '\0';
  for (int i = 0; i < s.size(); ++i) {
    if (b != s[i]) {
      if (j != 0) {
        char buf[256] = {0, };
        snprintf(buf, sizeof(buf), "%c%d", b, j);
        r += buf;
      }
      j = 1;
      b = s[i];
    } else {
      ++j;
    }
    // printf("%d %d %c %s\n", i, j, b, r.c_str());
    if (r.size() >= a.size())
      return a;
  }
  
  return r;
}

int main() {
  std::string s0 = "aabcccccaaa";
  printf("%s\n", StringCompress(s0).c_str());

  return 0;
}
