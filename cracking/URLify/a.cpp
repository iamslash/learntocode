// Copyright (C) 2016 by iamslash

// URLify: Write a method to replace all spaces in a string with '%20:
// You may assume that the string has sufficient space at the end to
// hold the additional characters, and that you are given the "true"
// length of the string. (Note: If implementing in Java, please use a
// character array so that you can perform this operation in place.)

// EXAMPLE
// Input: "Mr John Smith " J 13 Output: "Mr%20J ohn%20Smith"

// corner case:
//

#include <string>
#include <algorithm>

// std::string URLify(const std::string& s, int n) {
//   std::string r;

//   // for (auto it = s.begin(); it != s.end(); ++it) {
//   for (int i = 0; i < n; ++i) {
//     if (s[i] == ' ')
//       r += "%20";
//     else 
//       r += s[i];
//   }
//   return r;
// } 


void URLify(char str[], int n) {
    //
  int space_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == ' ')
      space_cnt++;
  }
  //
  int j = n + space_cnt * 2;
  // printf("j is %d\n", j);
  str[j--] = '\0';
  for (int i = n - 1; i >= 0; --i) {
    // printf(" %d\n", i);
    if (str[i] == ' ') {
      // printf(" %d\n", i);
      str[j--] = '0';
      str[j--] = '2';
      str[j--] = '%';
      // printf("!%c%c%c\n", str[j-1], str[j-2], str[j-3]);
    } else {
      str[j--] = str[i];
    }
  }
}

// void URLify(char (&str)[128], int n) {
//   //
//   int space_cnt = 0;
//   for (int i = 0; i < n; ++i) {
//     if (str[i] == ' ')
//       space_cnt++;
//   }
//   //
//   int j = n + space_cnt * 2;
//   // printf("j is %d\n", j);
//   str[j--] = '\0';
//   for (int i = n - 1; i >= 0; --i) {
//     // printf(" %d\n", i);
//     if (str[i] == ' ') {
//       // printf(" %d\n", i);
//       str[j--] = '0';
//       str[j--] = '2';
//       str[j--] = '%';
//       // printf("!%c%c%c\n", str[j-1], str[j-2], str[j-3]);
//     } else {
//       str[j--] = str[i];
//     }
//   }
// }


int main() {
    char s[128] = "Mr John Smith    ";
    printf("%s\n", s);
    URLify(s, 13);
    printf("%s\n", s);

    return 0;
}
