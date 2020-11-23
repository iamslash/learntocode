// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <algorithm>

#define NO_OF_CHARS 256

void print_v(const std::vector<int> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n");
}

// The preprocessing function for Boyer Moore's bad character heuristic
std::vector<int> get_bad_char(const std::string& N) {
  int n = N.size();
  std::vector<int> r(NO_OF_CHARS, -1);
  // Fill the actual value of last occurrence of a character
  for (int i = 0; i < n; ++i)
    r[static_cast<int>(N[i])] = i;

  return r;
}

//
std::vector<int> boyermoore_search(const std::string& H,
                                                 const std::string& N) {
  int h = H.size();
  int n = N.size();
  std::vector<int> r;
  //
  std::vector<int> bc = get_bad_char(N);

  int s = 0;  // s is shift of the pattern with respect to text
  while (s <= (h - n)) {
    int j = n - 1;

    while (j >= 0 && N[j] == H[s + j])
      j--;

    // 32: hellomynameisslashmynameisnotfoo
    //  6:      myname
    if (j < 0) {  // if matched
      // printf("\n pattern occurs at shift = %d", s);
      r.push_back(s);
      s += (s + n < h) ? n - bc[H[s + n]] : 1;
    } else {  // if mismatched
      s += std::max(1, j - bc[H[s + j]]);
    }
  }

  return r;
}

int main() {
  std::string h = "hellomynameisslashmynameisnotfoo";
  std::string n = "myname";

  std::vector<int> r = boyermoore_search(h, n);

  printf("%s\n", h.c_str());
  printf("%s\n", n.c_str());
  print_v(r);

  //
  return 0;
}
