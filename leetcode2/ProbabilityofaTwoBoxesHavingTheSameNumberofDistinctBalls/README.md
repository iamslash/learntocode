# Problem

[Probability of a Two Boxes Having The Same Number of Distinct Balls](https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/)

# Idea

수열 `B[]` 가 주어진다. `B[i]` 는 `i` 색깔 공의 개수를 의미한다.
두개의 상자가 있고 두 상자에 공을 나누어 담는다. 이때 두 상자가 같은
개수의 색을 가졌을 때 확률을 구하는 문제이다.

예를 들어 `B = [1, 1]` 인 경우를 살펴보자. 공은 `1, 1` 이다.

```
PermA: {1, 1}
PermB: {1, 1}
 Prob: 1 / 1 = 1.0 
```

다른 예로 `B = [2, 1, 1]` 인 경우를 살펴보자. 공은 `1, 1, 2, 3` 이다.

```
PermA: {1,1/2,3} {1,1/3,2} {1,2/1,3} {1,2/3,2}
       {1,3/1,2} {1,3/2,1} {2,1/1,3} {2,1/3,1}
       {2,3/1,1} {3,1/1,2} {3,1/2,1} {3,2/1,1}
PermB: {1,2/1,3} {1,2/3,2} {1,3/1,2} {1,3/2,1}
       {2,1/1,3} {2,1/3,1} {3,1/1,3} {2,1/3,1}
 Prob: 8 / 12 = 0.66667
```

PermA 는 다음과 같이 구한다.

```
PermA = num-of-balls ! / prod(B[i]!)
```

PermB 는 다음과 같이 부분문제 `dfs` 를 선언하여
dynamic programming 으로 구한다.

```
dfs(vector<int>& A, vector<int>& a, vector<int>& b, 
    int i, int cntA, int cntB)
    
   a: 첫번째 상자에 담긴 색깔별 공의 개수
   b: 두번째 상자에 담긴 색깔별 공의 개수
cntA: 첫번재 상자의 공의 개수
cntB: 두번째 상자의 공의 개수
```

`PermA/PermB` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(a^a) O(A)
a: cnt of ball
```
