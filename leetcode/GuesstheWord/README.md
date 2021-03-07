# Problem

> [Guess the Word](https://leetcode.com/problems/guess-the-word/)

단어들의 리스트 `W` 가 주어졌다. 이들 중 하나의 단어가 정답 `s` 라고
하자. `master.guess(string a)` 는 `a` 와 `s` 가 얼만큼 같은지
리턴한다. 즉 위치를 순회하면서 같은 음절의 개수를
리턴한다. `master.guess()` 가 10 번 호출될 때 반드시 6 을 리턴하도록
`findSecretWord` 를 구현하는 문제이다.

# Idea

`master.guess(a)` 를 10 번 수행해야 한다. 그때 인자로 넘겨지는 `a` 가
`s` 와 유사하도록 `a` 를 잘 고르자. 

예를 들어 `a` 를 랜덤하게 `W` 에서 하나 고른다. 그리고 `r =
master.guess(a)` 를 수행한다. `W` 에서 `a` 와 `r` 만큼 똑같은
문자열들을 추출한다.  그리고 이것을 `W2` 에 삽입한다. `W = W2` 하고
나서 처음부터 다시 반복한다. `W` 는 점점 줄어들 것이다.

랜덤을 사용하지 않고 해결해보자. `W[]` 의 각 단어들간에 서로 유사한
정도가 가장 높은 것 `a` 를 고른다. `a` 는 답의 후보중 하나이다. `a` 을 고르는 요령은 다음과 같다. 

* 먼저 `freqlist = []` 를 선언한다. `freqlist[i][c]` 는 `i-th` 번째 자리에 존재하는 문자 `c` 의 출연횟수이다.
  * 예를 들어 `wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]` 의 경우 `freqlist[]` 는 다음과 같다.

    ```py
    >>> freqlist = [Counter(w[i] for w in W) for i in range(6)]
    >>> pprint.pprint(freqlist)
    [Counter({'a': 2, 'c': 1, 'e': 1}),
    Counter({'c': 2, 'i': 1, 'b': 1}),
    Counter({'c': 2, 'b': 1, 'o': 1}),
    Counter({'k': 1, 'a': 1, 'w': 1, 'c': 1}),
    Counter({'z': 4}),
    Counter({'z': 4})]
    ```

`a` 가 꼭 답이라는 보장은 없다. 단지 `i-th` 자리에 오는 문자열의 개수가 클 수록 답의 후보가 될 확률이 높은 것이다. `a` 를 고르는 것은 `W` 를 줄이기 위해 필요한 기준을 정하는 과정이다. 무엇을 골라도 상관없다. 어차피 다음에 수행하는 과정을 통해 `W[]` 가 줄어든다.

그리고 `r = master.guess(a)` 를 수행한다.  `W[]` 에서 `a` 와 `r` 의 개수만큼 똑같은 문자열들이 답의 후보들이다. 그것들을 다시 `W[]` 에 삽입한다. 그리고 처음부터 다시 반복한다. `W[]` 는 점점 줄어들 것이다.

`r == 6` 이면 반복을 종료한다. 답을 찾은 것이다.

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complextiy

```
O(N) O(N)
```
