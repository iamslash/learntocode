# Problem

[Regions Cut By Slashes](https://leetcode.com/problems/regions-cut-by-slashes/)

# Idea

그래프 `F[][]` 가 주어진다. `F[y][x]` 는 `/, \, 0` 중 하나 이다.
사선으로 만들어지는 격리된 공간의 개수를 세는 문제이다.

간단히 생각해보면 빈 칸에서 DFS 하고 덩어리의 개수를 세면 될 것
같다. 그러나 빈 칸이 없는 경우도 격리된 공간이 발생할 수 있다.
다음과 같은 경우 격리된 공간은 5 이다.

```
/\
\/
```

위의 그래프를 3 배 upscaling 하면 반드시 빈공간이 만들어지게 된다.
그리고 DFS 를 수행하면 component 의 개수가 곧 답이다.

```
  /\
 /  \
/    \
\    /
 \  /
  \/
```

다음은 `F[][]` 를 `G[][]` 로 upscaling 할 때 계산식이다.

```c
        if (F[y][x] == '/')
          G[y*3][x*3+2] = G[y*3+1][x*3+1] = G[y*3+2][x*3] = 1;
        if (F[y][x] == '\\')
          G[y*3][x*3] = G[y*3+1][x*3+1] = G[y*3+2][x*3+2] = 1;        
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
