# Problem

문자열 `H` 가 주어지면 서로 다른 부분문자열의 개수를
구하는 문제이다.

# References

* [Count of distinct substrings of a string using Suffix Array @ geeksforgeeks](https://www.geeksforgeeks.org/count-distinct-substrings-string-using-suffix-array/)

# Idea

길이가 `h` 인 문자열 `H` 의 부분문자열의 개수는 `h(h+1)/2` 이다. 예를 들어 `H = banana` 의 경우 모든 부분 문자열은 다음과 같다.

```
b ba ban bana banan banana
a an ana anan anana
n na nan nana
a an ana
n na
a
```

따라서 모든 부분문자열의 개수는 `1 + 2 + ... + 6 = 6(6+1)/2 = 21` 이다. 

다음은 `H = banana` 의 `sa[], lcp[], substrs` 이다.

| i | `sa[i]` | `H[sa[i]..]` | `lcp[i]` | `substrs` |
|:--|:--------|:-------------|:---------|:----------|
| 0 | 5       | a            | 1        | a         |
| 1 | 3       | ana          | 3        | a an ana  |
| 2 | 1       | anana        | 0        | a an ana anan anana |
| 3 | 0       | banana       | 0        | b ba ban bana banan banana |
| 4 | 4       | na           | 2        | n na |
| 5 | 2       | nana         | 0        | n na nan nana |

위의 표에서 몇개의 부분문자열들은 중복되어 있다.

`h - sa[i]` 에서 `lcp` 를 제거한 후 모두 더하면 답이된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
