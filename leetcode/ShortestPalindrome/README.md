# Problem

* [Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)

# Idea

문자열 `H` 가 주어지면 최소한의 문자를 추가해서 회문을 구하는
문제이다.

다음과 같이 `H` 를 거꾸로 한 문자열 `R` 을 왼쪽으로 한칸씩 이동한다.
`H` 와 `R` 이 겹치지 않는 부분이 동일한 `R` 의 위치를 찾는다.
겹치지 않는 `R` 의 부분문자열과 `H` 를 결합하면 답이된다.

```
H: abcd    abcd    abcd    abcd
R: dcba   dcba   dcba   dcba
```

```
H: aacecaaa        aacecaaa
R: aaacecaa       aaacecaa
```

위의 방법은 시간복잡도가 `O(H^2)` 이다. 이것을
[KMP](/fundamentals/string/kmpsearch/README.md) 의 partial match index
array 을 이용하여 최적화 해보자.

겹치는 부분을 찾는 아이디어는 동일하다.  단지 겹치는 부분을 찾는
방법의 시간복잡도를 감소할 수 있다.

먼저 문자열 `S = H + '#' + R` 을 제작한다. 그리고 partial match index
array 을 작성한다. 예를 들어 `H = abcd` 의 경우 `pi[]` 는 다음과 같다.
`R.substr(0, H.size() - pi[n-1]) + H` 가 답이다.

```
   S: a b c d # d c b a
pi[]: 0 0 0 0 0 0 0 0 1

   H:       a b c d
   R: d c b a
```

`R.substr(0, 4 - 1) + H = dcbabcd` 가 답이다.

다음은 `H = aacecaaa` 의 경우 `pi[]` 는 다음과 같다.

```
   S: a a c e c a a a # a a a c e c a a
pi[]: 0 1 0 0 0 1 2 2 0 1 2 2 3 4 5 6 7

   H:   a a c e c a a a
   R: a a a c e c a a
```

`R.substr(0, 8 - 7) + H = aaacecaaa` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(H) O(H)
```
