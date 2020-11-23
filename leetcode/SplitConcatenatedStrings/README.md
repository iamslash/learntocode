# Problem

[Split Concatenated Strings](https://leetcode.com/problems/split-concatenated-strings/)

# Idea

문자열의 모음 `V[]` 가 주어진다. 문자열들을 무한히 이어 붙인 문자열들을
만들어 본다. 이때 문자열 `V[i]` 은 그대로 붙일 수 있고 뒤집어서 붙일 수도 있다.
그렇게 만든 무한한 문자열들 중 중간의 한 곳을 끊었을 때 사전순으로
가장 큰 문자열 `best` 를 구하는 문제이다.

예를 들어 `V[] = ("abc" "xyz")` 경우 다음과 같이 무한한 무자열들을
만들 수 있다. `-` 는 문자열이 무한히 반복된다는 의미이다.

```
-abcxyz- -abczyx- -cbaxyz- -cbazyx
```

이들 중 한 곳을 끊었을 때 사전순으로 가장 큰 `best` 는 `cbazyx`
이고 `a` 다음에 끊으면 `best = zyxcba-` 를 얻을 수 있다.

`V[i]` 를 그대로 혹은 뒤집어서 둘 중 사전순으로 큰 문자열을 이어 붙여
`alpha` 를 제작한다. `best = alpha` 를 수행한다. 이후 `best` 갱신을
위해 사용할 중간 문자열 `mid` 를 제작하기 위해 두개의 변수 `beg = 0,
end = 0` 를 선언한다. 인덱스 `i` 를 사용하여 `V[]` 를 순회하며 다음을
반복한다.

0. `s = V[i], t = reverse(s), end += s.size()` 를 수행한다.
1. 문자열 `mid = alpha.substr(end) + alpha.substr(0, beg)` 를 제작한다.
2. 인덱스 `j` 를 이용하여 `s, t` 를 순회하며 다음을 반복한다.
  0. `s[j] >= best[0]` 이면 `best = max(best, s.substr(j) + mid +
     s.substr(0, j))` 를 수행한다.
  1. `t[j] >= best[0]` 이면 `best = max(best, t.substr(j) + mid +
     t.substr(0, t))` 를 수행한다.
3. `beg += s.size()`

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NS) O(NS)
N: count of V
S: count of V[i]
```
