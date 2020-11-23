# Problem

* [Short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)

# Idea

문자열들의 모음 `W[]` 가 주어진다. 문자열의 끝에 `#` 을 추가하는
인코딩했을 때 가장 짧은 인코딩 문자열의 길이를 구하는 문제이다.

예를 들어 `W[] = ("time", "me", "bell")` 의 경우를 살펴보자.  인코딩
문자열을 `time#bell#` 으로 하면 `W[]` 의 시작 문자 인덱스의 배열은 `(0, 2,
5)` 와 같다. 답은 10 이다.

`W[]` 모두 뒤집고 trie 를 만들어 해결할 수 있지만 `unordered_set` 을
이용하면 더욱 간단히 구현할 수 있다.

`unordered_set<string> ust` 에 `W[]` 를 담는다.  그리고 `W[]` 를
순회하면서 각 문자열 `s` 에 대해 다음을 반복한다.

* `w[1..n-1], w[2..n-1], w[3..n-1]` 을 `ust` 에서 제거한다.

`ust` 에 남아있는 문자열들은 `W[]` 의 문자열들의 접미사들이
제거되었다. 충분히 인코딩 문자열이라 할 만하다. `ust` 를 반복하면서 각
문자열의 길이 와 `#` 의 길이를 추가한 것을 누적하여 더하면 답이 된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NW) O(N)
```
