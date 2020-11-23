# Problem

* [Delete and Earn](https://leetcode.com/problems/delete-and-earn/)

# Idea

수열 `V` 가 주어진다. `V[i]` 를 지우면 `V[i]` 만큼의
포인트를 얻고 `V[i]-1, V[i]+1` 를 `V` 에서 삭제한다.
모두 삭제하고 최고 점수를 얻었을 때 그 점수를 구하는 문제이다.

dynamic programming 을 이용하여 해결한다.  `V[i]` 의 최대값을 `n` 에
정의한다. 그리고 일차원 배열 `B[n+1], C[n+1]` 을 정의한다.

`B[V[i]]=sum(V[i])` 한다. 이제 `V[i]` 를 선택했을 때 얻을 수 있는
점수가 저장되었다.

`C[1] = B[1]` 이다. 그리고 `C[i]` 에 `V[i]` 를 지웠을 때 혹은 지우지 않았을 때의 최대 값을 저장한다. 따라서 `C[i] = max(C[i-2]+B[i], C[i-1])` 이다. 모두 저장한후 `C[n]` 이 답이다.

다음은 `V = 2 3 4` 인 경우의 dynamic programming 과정이다.

```
//    0 1 2 3 4    0 1 2 3 4    0 1 2 3 4
// B: 0 0 2 3 4    0 0 2 3 4    0 0 2 3 4
//        i              i              i
// C: 0 0 2 0 0    0 0 2 3 0    0 0 2 3 6
```

# Implementation

* [c++11](a.cpp)

# Comlexity

```
O(N) O(N)
```
