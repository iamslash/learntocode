# Problem

[Word Abbreviation](https://leetcode.com/problems/word-abbreviation/)

# Idea

문자열들의 모음 `D[]` 가 주어진다. 중복이 없는 축약된 문자열들을
구하는 문제이다.

우선 다음과 같이 문자열 `s` 의 `i` 번째 부터 축약하는 함수를
제작한다.

```cpp
string getAbbr(string s, int i)
s: 축약의 대상 문자열
i: 축약을 시작할 인덱스
```

예를 들어 `s = abcdefg` 에 대해 `getAbbr` 은 다음과 같이 동작한다.

```
getAbbr("abcdefg", 0) = "a5g"
getAbbr("abcdefg", 1) = "ab4g"
getAbbr("abcdefg", 2) = "abc3g"
getAbbr("abcdefg", 3) = "abcd2g"
getAbbr("abcdefg", 4) = "abcdefg"
```

`abbrs[]` 에 `getAbbr[D[i]]` 를 저장한다. `abbrs[]` 를 인덱스 `i` 를 
이용하여 순회하면서 다음을 반복한다.

0. `while (true)` 동안 다음을 반복한다.
  0. `unordered_set<int> dups` 를 선언한다.
  1. 인덱스 `j = i+1` 를 이용하여 순회하면서 다음을 반복한다.
    0. `abbrs[i] == abbrs[j]` 이면 `dups.insert(j)` 한다.
  2. `dups.empty()` 이면 `break`
  3. `dups.insert(i)` 한다.
  4. `dups[i]` 의 축약시작인덱스를 이전보다 하나 늘려서 `abbrs[]` 에 다시 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```