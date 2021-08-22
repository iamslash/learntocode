# Problem

[Minimum Window Substring](https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/838/)

문자열 `s, t` 가 주어진다. `t` 의 모든 문자열들을 포함하는 `s` 의 최소크기
부분문자열을 구하라. 

# Idea

슬라이드의 왼쪽 인덱스를 `l`, 오른쪽 인덱스를 `r` 이라고 하자. `l`,
`r` 을 적당히 움직이면서 문자열 `T` 를 모두 포함하는 가장 작은 크기의
슬라이드를 찾아야 한다.

127 개의 문자들이 발생횟수를 벡터 `v` 에 저장하자. 즉 `v[i] = j` 에서
`i` 는 특정 문자를 `j` 는 발생횟수를 의미한다.  발생횟수라는 것은 `r`
에 의해 점령되었을 때 하나 증가하고 `l` 에 의해 점령되었을 때 하나
감소한다.

문자열 `T` 의 개수를 `cnt` 에 저장하고 문자열 `S` 를 순회할 때 마다
증가 혹은 감소한다. `cnt` 가 `0` 이라는 것은 슬라이드에 `T` 의 모든
문자들이 포함되어 있다는 의미이다.

```
     t: ABC
        l
     s: ADOBECODEBANC
        r
 freqs: A B C D O E N
        1 1 1 0 0 0 0
   cnt: 3
wndIdx:-1
wndLen: M
```

# Implementation

* [java8](MainApp.java)
* [c++11](a.cpp)

# Time Complexity

```
O(N) O(N)
```
