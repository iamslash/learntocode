# Problem

[Rank Teams by Votes](https://leetcode.com/problems/rank-teams-by-votes/)

# Idea

문자열의 모음 `V[]` 가 주어진다. 팀의 이름은 알파벳 대문자 하나로
표현한다. 사람 `i` 가 팀들에게 점수를 준다. `V[i]` 는 팀들의 이름이
점수의 내림차순으로 배열되어 있다. 모든 사람들이 부여한 점수를
고려했을 때 높은 점수부터 낮은 점수의 순서대로 팀의 이름들을 배열하는
문제이다.

예를 들어 `V = ["WXYZ", "XYZW"]` 를 살펴보자.  `vector<vector<int>> C`
를 선언하여 각 팀별로 등장하는 인덱스를 표기하자.

```
1,0,0,1,W
1,1,0,0,X
0,1,1,0,Y
0,0,1,1,Z
```

이제 `C` 를 내림차순으로 정렬한다.

```
1,1,0,0,X
1,0,0,1,W
0,1,1,0,Y
0,0,1,1,Z
```

답은 곧 "XWYZ" 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NM) O(1)
N: V.size()
M: V[i].size()
```
