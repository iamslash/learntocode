// Copyright (C) 2016 by iamslash

// Is Unique: Implement an algorithm to determine if a string has all
// unique characters. What if you cannot use additional data
// structures?

#include <string>

bool IsUnique(std::string s) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
           if (s[i] == s[j])
               return false;
        }
    }
    return true;
}   

int main() {
    std::string s0 = "ABCDEFG";
    std::string s1 = "ABCDEFA";
    printf("%d : %s\n", IsUnique(s0), s0.c_str());
    printf("%d : %s\n", IsUnique(s1), s1.c_str());

    return 0;
}
