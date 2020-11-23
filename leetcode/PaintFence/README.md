# Problem

* [Paint Fence](https://leetcode.com/problems/paint-fence/)

# References

* [Dynamic Programming-Paint Fence @ youtube](https://www.youtube.com/watch?v=deh7UpSRaEY)

# Idea

숫자 `n, k` 가 주어지면 `2` 번을 초과하여 같은 색을 칠하지 않을
경우의 수를 구하는 문제이다.

예를 들어서 `n = 3, k = 2` 인 경우를 살펴보자.
다음과 같이 트리를 그래프를 그려보자. `0-0-0, 1-1-1` 은 조건에 맞지 않기 때문에 정답은 `6` 이라고 할 수 있다.

```
1          0            1
         /   \        /   \
2       0     1      0     1         
       / \   / \    / \   / \
3     0   1 0   1  0   1 0   1
      |                      |
      X                      X
```

`n` 번째에 대해 조건에 맞는 경우의 수를 `nw(n)` 라고 하자. `n` 번째에 `n-1` 번째와 다른색으로 칠하는 경우의 수를 `nwdiff(n)` 라고 하자. `n` 번째에 `n-1` 번째와 같은색으로 칠하는 경우의 수를 `nwsame(n)` 이라고 하면 다음과 같은 규칙이 성립한다.

```cpp
    nw(n) = nwdiff(n)     + nwsame(n)

nwdiff(n) = nw(n-1)*(k-1)
          = (nwdiff(n-1) + nwsame(n-1))*(k-1)
nwsame(n) = nwdiff(n-1)*1
```

`nwdiff(n)` 은 `nwdiff(n-1), nwsame(n-1)` 을 이용하여 계산할 수 있다. `nwsame(n)` 은 `nwdiff(n-1)` 을 이용하여 계산할 수 있다. 그리고 마지막에 `nw(n) = nwdiff(n) + nwsame(n)` 이 답이다.

따라서 두개의 변수 `cntdiff, cntsame` 을 사용하면 dynamic programming 전략으로 문제를 해결할 수 있다.

# Complexity

```
O(N) O(1)
```

# Implementation

* [c++11](a.cpp)