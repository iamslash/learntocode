# Problem

[Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/)

# Idea

두개의 문자열 `a, b` 가 주어진다. `a, b` 각각을 subsequence 로 할 수
있는 최소 길이의 문자열을 구하는 문제이다.

`a, b` 의 [LCS (longest common
subsequence)](/leetcode/LongestCommonSubsequence) `l` 을 구한다.
`a` 의 문자열 중 `l` 에 없는 것들, `b` 의 문자열 중 `l` 에 없는 것들과 `l`
을 이어 붙이면 답이다.

`int i = 0, j = 0` 를 선언하여 `a, b` 각각을 순회하는 인덱스로
사용하자.  `string ans` 를 선언하여 답을 저장하자.  `l` 를 처음부터
끝까지 `char c` 를 이용하여 순회하면서 다음을 반복한다.

* `a[i] != c` 동안 다음을 반복한다.
  * `ans += a[i++]` 를 수행한다.
* `b[j] != c` 동안 다음을 반복한다.
  * `ans += b[j++]` 를 수행한다.
* `ans += c, ++i, ++j` 를 수행한다.

모든 반복을 마치면 지금까지 조리한 `ans`, `a` 의 `i` 번째를 포함한
이후의 문자열과 `b` 의 `j` 번째를 포함한 이후의 문자열을 합한 문자열이
답이다.  즉, `ans + a.substr(i) + b.substr(j)` 가 답이다.

# Implementation

* [c++11](a.cpp)
* [java](Solution.go)
* [python3](a.go)
* [go](a.go)

# Complexity

```
O(MN) O(MN)
```
