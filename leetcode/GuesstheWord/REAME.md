# Problem

* [Guess the Word](https://leetcode.com/problems/guess-the-word/)

# Idea

단어들의 리스트 `W` 가 주어졌다. 이들 중 하나의 단어가 정답 `s` 라고
하자. `master.guess(string a)` 는 `a` 와 `s` 가 얼만큼 같은지
리턴한다. 즉 위치를 순회하면서 같은 음절의 개수를
리턴한다. `master.guess()` 가 10 번 호출될 때 반드시 6 을 리턴하도록
`findSecretWord` 를 구현하는 문제이다.

`master.guess(a)` 를 10 번 수행해야 한다. 그때 인자로 넘겨지는 `a` 가
`s` 와 유사하도록 `a` 를 잘 고르자. 

예를 들어 `a` 를 랜덤하게 `W` 에서 하나 고른다. 그리고 `r =
master.guess(a)` 를 수행한다. `W` 에서 `a` 와 `r` 만큼 똑같은
문자열들을 추출한다.  그리고 이것을 `W2` 에 삽입한다. `W = W2` 하고
나서 처음부터 다시 반복한다. `W` 는 점점 줄어들 것이다.

랜덤을 사용하지 않고 해결해보자. `W` 의 각 단어들간에 서로 유사한
정도가 가장 높은 것 `a` 를 고른다. 그리고 `r = master.guess(a)` 를
수행한다.  `W` 에서 `a` 와 `r` 만큼 똑같은 문자열들을 추출한다.
그리고 이것을 `W2` 에 삽입한다. `W = W2` 하고 나서 처음부터 다시
반복한다. `W` 는 점점 줄어들 것이다.

# Implementation

* [c++11](a.cpp)

# Complextiy

```
O(N) O(N)
```
