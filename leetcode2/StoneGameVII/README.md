# Problem

[Stone Game VII](https://leetcode.com/problems/stone-game-vii/)

점수의 모음 `S[]` 가 주어진다. Alice 와 Bob 은 한번씩 `S[]` 의 양끝의
점수를 제거하고 남은 점수의 합을 가져간다. Alice 가 먼저 시작하고 둘은
최선을 다해 게임을 한다. 게임이 끝고 나면 두 점수의 차이가 최소가
되도록 해보자. 그 때 점수의 차이를 구하라.

# Idea

Alice, Bob 이 최선을 다해서 게임을 하면 답을 구할 수 있다.

다음과 같은 부분문제를 정의한다.

```
int dfs(C, S, i, j, sum)

return: max difference of score between Alice and Bob
     C: cache of max score for i, j
     i: start index of S
     j: end index of S
   sum: remained sum
```

이때 왼쪽 끝 혹은 오른쪽 끝을 선택했을 때를 비교한다.  두가지의 값중
최대인 것을 취하면 최선을 다하는 형태가 된다. Alice 가 항상
먼저시작하기 때문에 첫번째 `dfs()` 의 리턴값이 Alice 가 최선을 다했을
때 점수의 차이가 된다.

```
sum - S[i] - dfs(C, S, i+1, j, sum - S[i])
sum - S[j] - dfs(C, S, i, j-1, sum - S[j])
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(N^2) o(N^2)
```
