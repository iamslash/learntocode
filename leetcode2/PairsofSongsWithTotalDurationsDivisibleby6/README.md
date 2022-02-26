# Problem

[Pairs of Songs With Total Durations Divisible by 60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)

수열 `time[]` 이 주어진다. 서로 합하면 `60` 으로 나누어 떨어지는
짝의 개수를 찾아라.

# Idea

예를 들어 `time = [30,20,150,100,40]` 의 경우를 살펴보자.

```
time: 30 20 150 100 40
      30    150
      20        100
      20            40
```

따라서 답은 `3` 이다.

두 개의 숫자를 찾는 것은 [two sum](/leetcode/TwoSum/README.md) 과 비슷하다. 

`int[] remCnts = new int[60]` 을 선언하고 `60` 으로 나누었을 때 그 나머지에
해당하는 숫자의 개수를 저장한다. 짝을 찾는 것은 그 짝을 구성하는 숫자들의 순서를
신경쓸 필요가 없다. 짝을 구성하는 두번째 숫자를 기준으로 짝을 찾는다면 한번의
순회로 해결할 수 있다. 

```
          i
   time: 30 20 150 100 40
remCnts: 20 30 40
          0  1  0
    ans:  0
```

`int ans = 0` 을 선언하여 답을 저장한다. `time[]` 을 `int t` 로 순회하며
다음을 반복한다.

* `int remA = t % 60` 을 선언하여 `t` 가 저장할 인덱스를 구한다.
* `int remB = (60 - remA) % 60` 을 선언하여 `t` 와 짝이될 숫자들의 개수를 구한다.
* `ans` 에 `t` 와 짝을 이룰 숫자들의 개수를 더한다. 즉, `ans += remCnts[remB]`
  를 저장한다.
* `remCnts[remA]++` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)
* [go](a.go)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
