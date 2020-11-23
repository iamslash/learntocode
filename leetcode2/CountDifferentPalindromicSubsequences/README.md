# Problem

[Count Different Palindromic Subsequences](https://leetcode.com/problems/count-different-palindromic-subsequences/)

문자열 `s` 가 주어진다. palindrome subsequence 들의 개수를 구하라.

# Idea

예를 들어 `s = 'b c b'` 의 경우를 살펴보자.

DFS 를 이용하여 subsequence 들을 생성할 수 있다. 각 subsequence 들에
대해 palindrome 인지 검사한다. `set<string> sst` 를 선언하여
subsequence 들을 저장한다.

```
                                      dfs(0, "")
                        /                                 \
                dfs(1,"")                                  dfs(1, b)
          /                \                            /             \
   dfs(2,"")            dfs(2,c)                dfs(2,b)           dfs(2,bc)
  /        \            /       \               /      \         /          \
dfs(3,"")  dfs(3,b)  dfs(3,c)  dfs(3,cb)  dfs(3,b)  dfs(3,bb)  dfs(3,bc)  dfs(3,bcb)
       0          1         1          1         1         1           1           1
```

모든 반복을 마치면 `sst.size() - 1` 곧 `4` 가 답이다. `b, c, bb, bcb` 

그러나 시간복잡도가 `O(N2^N)` 이다.

iterative dynamic porgramming 을 생각해 보자. 어렵다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3) O(N^2)
```
