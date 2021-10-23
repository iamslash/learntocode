# Problem

> [Two Sum](https://leetcode.com/problems/two-sum/)

수열 `I[]` 와 숫자 `T` 가 주어진다. `I` 에서 합이 `T` 가
되는 서로다른 숫자를 구하는 문제이다.

# Idea


맵 `ump` 를 정의하고 `I[]` 를 순회하면서 다음을 반복한다.

> * `T - I[i]` 가 `ump` 에 있으면 빙고
> * 없으면 `ump.insert({T - I[i], i})` 를 수행한다.

모든 반복을 마치면 

# Implementation

* [c++11](a.cpp)
* [python3](a.py)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
