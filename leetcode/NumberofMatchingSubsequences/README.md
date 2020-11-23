# Problem

[Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/)

# References

* [code_report::episode_7 () @ youtube](https://www.youtube.com/watch?v=xjLXiNlStMQ&feature=youtu.be&t=6m12s)

# Idea

문자열 `s` 와 문자열의 모음 `W[]` 가 주어진다. `W[i]` 들 중 `s` 의
subsequence 의 개수를 찾는 문제이다.

첫번째로 brute force 를 이용해보자.  `W[]` 를 처음부터 끝까지
순회하면서 `W[i]` 가 `s` 의 subsequnce 인지 확인한다. 그러나 Time
Limit Exceeded 가 발생한다.  시간복잡도는 `O(Wmax(w,s))` 이다. 조금 더
최적화 해보자.

두번째로 binary search 를 이용해보자. 먼저 `s` 를 구성하는 문자는 26
가지뿐이다. 따라서 각 문자당 `s` 에 발생하는 인덱스를
`vector<vector<int>> A` 에 저장한다.
예를 들어 `s = abcdea` 의 경우 `A` 는 다음과 같다.

```cpp
A: {
     {0, 5},
     {1},
     {2},
     {3},
     {4},
     ...
   }
```

이제 `W[i]` 를 처음부터 끝까지 순회한다. `int last = -1` 를 선언하고
마지막으로 확인한 `s` 의 인덱스를 저장한다. `A[W[i][j]-'a']` 를 binary
search 하면 `W[i]` 가 `subsequence` 인지 확인할 수 있다.
time complexity 는 `O(Wwlg(s/26))` 이다.

세번째 방법은 queue 를 이용하는 방법이다. `n = W.size()` 으로 하고
`vector<int> wi_idx(n)` 와 `vector<queue<int>> w_idx_q(26)` 를 선언한다.

`wi_idx[i]` 는 문자열 `W[i]` 의 인덱스를 의미한다. `wi_idx[i] ==
W[i].size()` 이면 `W[i]` 는 `s` 의 subsequence 와 같다.

`w_idx_q[j]` 는 다음번에 처리해야할 `W` 의 인덱스들을 의미한다. `j =
s[i]-'a'` 이다.

`s` 를 인덱스 `i` 를 이용하여 처음부터 끝까지 순회하면서 다음을
반복한다.

0. `j = s[i] - 'a'` 를 인덱스로 해서 `w_idx_q[j]` 에 해당하는 큐 `q`
   를 얻어오자. `q` 에는 이번에 처리해야할 `W` 의 인덱스들이 저장되어
   있다.
1. `q` 에서 값을 하나씩 빼서 `j` 에 저장하고 다음을 반복한다.
  0. `wi_idx[j]` 를 하나 늘리고 `k` 에 저장한다.
  1. `W[j][k]` 는 다음에 처리해야할 `W[j]` 의
     인덱스이다. `w_idx_q[k].push(j)` 를 수행하자.
  
반복이 끝나면 `wi_idx[]` 를 순회한다. 그리고 `wi_idx[i] == W[i].size()`
인 것들의 개수가 답이된다.

# Implementation

* [c++11](a.pp)

# Complexity

```
O(SW) O(W)
```
