# Problem

[Largest Multiple of Three](https://leetcode.com/problems/largest-multiple-of-three/)

수열 `D[]` 가 주어진다. `D[]` 를 조합해서 3 의 배수중 가장 큰 수를
구하라.

# Idea

`vector<int> digitCnt(10)` 를 선언하여 각 자리수의 발생 횟수를
저장한다. 

어떤 수 num 의 구성원들을 모두 더해서 3 으로 나누어 떨어지면 3 의
배수가 된다. 이때 3 으로 나누어 나머지가 1 이 되면 3 의 배수가 될 때
까지 `1, 4, 7` 의 숫자를 순서대로 제거해 본다. 만약 3 으로 나누어
나머지가 2 가 된다면 3 의 배수가 될 때까지 `2 5 8` 의 숫자를 순서대로
제거해 본다. 숫자를 제거할 때 마다 `digitCnt` 를 업데이트한다.

모든 반복을 마친 후 큰 수부터 조립하여 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
