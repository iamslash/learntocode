// Copyright (C) 2016 by iamslash

// Palindrome Permutation: Given a string, write a function to
// check if it is a permutation of a palindrome. A palindrome is a
// word or phrase that is the same forwards and backwards. A
// permutation is a rearrangement of letters.The palindrome does not
// need to be limited to just dictionary words.

// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat". "atco cta". etc.)

// CORNERCASE
//

#include <string>
#include <algorithm>

int GetCharIdx(char c) {
  int r = c - 'a';
  return r >= 0 ? r : r + 32;
}

bool IsPalindromePermutation(const std::string& s) {
  char alphabet_cnt[26] = {0, };
  // set alphabet_cnt array
  for (int i = 0; i < s.size(); ++i) {
    alphabet_cnt[GetCharIdx(s[i])]++;
  }

  // check odd cnt more than 1
  int odd_cnt = 0;
  for (int i = 0; i < 26; ++i) {
    if (alphabet_cnt[i] % 2 == 1)
      odd_cnt++;
    if (odd_cnt > 1)
      return false;
  }

  return true;
}

int main() {
  std::string s = "Tact Coa";
  std::string s1 = "Tact Coak";
  printf("%s\n", IsPalindromePermutation(s) > 0 ? "True" : "False");
  printf("%s\n", IsPalindromePermutation(s1) > 0 ? "True" : "False");

  return 0;
}
