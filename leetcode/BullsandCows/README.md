# Problem

> [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)

숫자로만 구성된 문자열 `secret`, `guess` 가 주어진다. `secret` 를
상대에게 불러주고 `guess` 를 받았다. `secret[i] == guess[i]` 이면
`cntBull` 을 증가한다. 서로다른 `i, j` 에 대해 `secret[i] == guess[j]`
이면 `cntCow` 를 증가한다. `String.format("%dA%dB", cntBull, cntCow)`
를 구하라.

# Idea

예를 들어 `secret = "1123", guess = "0111"` 의 경우를 살펴보자.

```
                i
  secret: 1 1 2 3
   guess: 0 1 1 1
  wrongs:-1-1 1 1 0 0 0 0 0 0
 cntBull: 1 
  cntCow: 1
```

`int[] wrongs` 를 선언하여 `0~9` 까지 숫자의 개수를 저장한다.  `int
cntBull = 0` 를 선언하여 `cntBull` 를 저장한다. `int cntCow = 0` 를
선언하여 `cntCow` 를 저장한다.

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `char c = secret.charAt(i)` 를 수행한다.
* `cjar d = guess.charAt(i)` 를 수행한다.
* `c == d` 이면 `cntBull++` 를 수행한다.
* `c != d` 이면 다음을 수행한다.
  * `wrongs[c-'0'] < 0` 이면 위치는 다르지만 `c` 와 같은 숫자가
    이미 발생했다는 의미이다. `cntCow` 를 하나 증가한다. 그리고
    `wrongs[c-'0']` 를 하나 증가한다.
  * `wrongs[d-'0'] > 0` 이면 위치는 다르지만 `d` 와 같은 숫자가
    이미 발생했다는 의미이다. `cntCow` 를 하나 증가한다. 그리고 
    `wrongs[d-'0']` 를 하나 증가한다.

모든 반복을 마치면 `cntBull, cntCow` 를 조합하여 리턴한다. java8 의
경우 `String.format` 보다 `StringBuilder` 를 사용하는 것이 time
complexity 가 좋다.
  
# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
