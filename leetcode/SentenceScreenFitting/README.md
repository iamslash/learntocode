# Problem

[Sentence Screen Fitting](https://leetcode.com/problems/sentence-screen-fitting/)

행과 열을 의미하는 숫자 `H, W` 와 문자열의 모음 `S[]` 가 주어진다.  `H
X W` 크기의 스크린에 `S[]` 를 몇번 채울 수 있는지 구하라. 채울 수 있는
경우의 수를 구하는 것이 아님을 유의하자.

# Idea

`s[]` 를 공백을 구분자로 하나의 문자열 `s` 로 만들자. 그리고 가장 뒤에
공백을 추가한다. 다음은 `S[] = {'a', 'bcd', 'e'}` 일 때 `s` 를
무한대로 늘어뜨려놓은 것이다.

```
a bcd e a bcd e a bcd e a bcd e ...
```

`H=3, W=6` 일 때 `W` 를 표현하는 인덱스 `012345` 를 앞서 언급한
무한대의 `s` 에 `H` 만큼 다음과 같이 배치한다.

```
a bcd e a bcd e a bcd e a bcd e ...
012345
      012345
          012345
```

무한대의 `s` 를 인덱스 `i` 를 이용하여 순회한다. `012345` 를
모두 배치하고 나면 `i` 는 `16` 이다. 이것을 `8 (s.size())`
으로 나누면 몫이 답이다. 따라서 답은 2 이다.

# Implementation

* [c++11](a.cpp)
* [go](a.go)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
