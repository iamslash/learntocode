# Abstract

rabin karp 알고리즘에 대해 정리한다.

# References

* [Rabin-Karp Algorithm for Pattern Searching @ geeksforgeeks](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
* [Rabin- Karp's Algorithm | Longest Duplicate Substring | Leetcode Day 19 | June Challenge](https://www.youtube.com/watch?v=lZwXyVzuyhk)
* [Longest Duplicate Substring Solution @ leetcode](https://leetcode.com/problems/longest-duplicate-substring/solution/)

# Problem

문자열 `H` 에서 길이가 `len` 이고 두번 중복되는 문자열을 구하라.

# Idea

예를 들어 다음과 같이 `"leetcodecookies"` 에서 길이가 2 개인 문자열들 중 중복된 것을 찾아보자.
`unordered_hash<int, vector<int>> hash` 를 선언하여 `{hash-value: [index,...]}` 를 저장한다.
길이가 2 인 sliding window 를 만들고 한칸씩 이동하면서 검색한다. `hash-value` 는 제거된 문자와 추가된 문자를 이용하여
[rolling hash](/fundamentals/hash/rollinghash/README.md) 를 만들어 저장한다.

```
      ___
   H: l e e t c o d e c o o k i e s      
hash: {"le"}
        ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee"}
          ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et",}
            ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et", "tc"}
              ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et", "tc", "co"}
                ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et", "tc", "co", "od"}
                  ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et", "tc", "co", "od", "de"}
                    ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et", "tc", "co", "od", "de", "ec"}
                      ___
   H: l e e t c o d e c o o k i e s
hash: {"le", "ee", "et", "tc", "co", "od", "de", "ec"}
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
