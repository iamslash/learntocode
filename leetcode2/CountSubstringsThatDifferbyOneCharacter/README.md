# Problem

[Count Substrings That Differ by One Character](https://leetcode.com/problems/count-substrings-that-differ-by-one-character/)

문자열 `s, t` 가 주어진다. `s` 의 sub array, `t` 의 sub array 를
짝지어 보자. 두개의 sub array 는 단 하나의 문자만 달라야 한다.
그 짝의 개수를 구하라.

# Idea

`int ans = 0` 을 선언하여 답을 저장한다.

인덱스 `i` 를 `[0..s.size())` 동안 순회하며 다음을 반복한다.
* 인덱스 `j` 를 `[0..t.size())` 동안 순회하며 다음을 반복한다.
  * `int diffCnt = 0` 을 선언하여 서로 다른 문자의 개수를 저장한다.
  * 인덱스 `k` 를 선언하여 `i + k < s.size() && j + k < t.size()` 인
    동안 `k` 를 하나씩 증가하며 다음을 반복한다.
    * `diffCnt` 를 하나 증가한다.
    * `s[i+k] != t[j+k] && diffCnt > 1` 이면 break 하자. 
    * `ans += diffCnt` 를 수행한다.
    
모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3) O(1)
```
