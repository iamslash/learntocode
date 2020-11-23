# Problem

[Find K-Length Substrings With No Repeated Characters](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/)

# Idea

문자열 `S` 와 숫자 `K` 가 주어진다. `S` 의 서로다른 문자열로 이루어진
`K` 길이의 `subarray` 의 개수를 구하는 문제이다.

두개의 인덱스 `i, j` 를 이용하여 슬라이드를 만들고 `S` 를 순회한다.
`int ans = 0` 을 선언하여 답을 저장한다.  `vector<int> cnts(26)` 을
선언하여 문자별 개수를 저장한다.  그리고 `int unicnt = 0` 를 선언하여
슬라이드 안의 문자들중 서로다른 것의 개수를 저장한다. 슬라이드가
이동할 때 `unicnt == K` 이면 `ans` 를 하나 증가한다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
