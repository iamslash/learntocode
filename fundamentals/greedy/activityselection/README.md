# Problem

[회의실배정 @ acmicpc.net](https://www.acmicpc.net/problem/1931)

# Idea

greedy algorithm 을 활용하여 풀어보자.

모든 회의들을 시작 시간, 종료 시간의 오름 차순으로 정렬하자. 이때 종료
시간, 시작 시간의 순서대로 우선순위를 설정한다. 이후 정렬된 목록을
순회하면서 겹치지 않은 회의들을 선택한다. 종료시간, 시작시간 순서대로
정렬 했기 때문에 차례 대로 겹치지 않은 회의들을 선택한다면 최대 가능한
회의들을 선택할 수 있다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(NlgN) O(1)
```
