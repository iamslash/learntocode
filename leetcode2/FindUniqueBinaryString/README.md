# Problem

[Find Unique Binary String](https://leetcode.com/problems/find-unique-binary-string/)

문자열의 모음 `nums[]` 가 주어진다. `nums[i]` 의 길이는 같고 `0` 혹은
`1` 로 구성되어 있다. 즉, 이진수로 구성된 문자열이다.  그리고 `nums[]`
는 모두 unique 하며 `nums[i].length == n` 이라고 하자. `n == 2` 이라면
`nums[]` 의 개수는 `2^2 == 4` 가 가능하다. 이것들 중 `nums[]` 에
존재하지 않는 문자를 구하라. 여러개 있다면 아무것이나 리턴해도 된다.

# Idea

예를 들어 `nums = ["01","10"]` 의 경우를 살펴보자.

```
00 01 10 11
   01 10 
```

따라서 답은 `00` 혹은 `11` 이다.

먼저 `StringBuilder sb = new StringBuilder()` 를 선언하여 답을
저장한다.

인덱스 `i, j` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `nums[i][j] == '0'` 이면 `sb.append('1')` 를 수행한다.
  * `nums[i][j] == '1'` 이면 `sb.append('0')` 를 수행한다.

모든 반복을 마치면 `sb.toString()` 이 곧 답이다.

이것을 [Cantor's diagonal argument](https://en.wikipedia.org/wiki/Cantor%27s_diagonal_argument) 이라고 한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
