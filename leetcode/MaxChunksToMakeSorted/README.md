# Problem

* [Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted/)

# Idea

수열 `V` 가 주어지면 merge sort 할 수 있는 최대 개수의 파티션들로
 나누었을 때 그 개수를 구하는 문제이다.
 
인덱스 `i` 를 이용하여 `V` 를 순회한다. `V` 는 `[0..n-1]` 의 순열이다.
변수 `maxnum` 을 정의하여 `V[0..i]` 의 최대숫자를 저장한다.  따라서
`V[i] == maxnum` 이면 `V[i]` 는 정렬할 필요가 없으니 하나의 파티션이
될 수 있다. 만약 `V[i] != maxnum` 이면 `V[i]` 는 홀로 파티션이 될 수
없다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
