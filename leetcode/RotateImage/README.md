# Problem

[rotate image @ leetcode](https://leetcode.com/problems/rotate-image/description/)

# Idea

```
1 2 3
4 5 6
7 8 9
```

위와 같은 매트릭스 `M` 이 있다고 해보자. 시계방향으로 `90`도 회전하면 
아래와 같다.

```
7 4 1
8 5 2 
9 6 3
```

숫자 `1` 이 `3` 자리로, `3` 이 `9` 자리로, `9` 가 `7` 자리로, `7` 이 `1` 자리로 이동했다. 그 외의 숫자들 역시 4개가 한그룹으로 움직이는 것을 발견할 수 있다. 이것을 `M` 의 크기가 `n` 일때 다음과 같이 규칙으로 만들어 본다. 

```
M[i][j] -> M[n-1-j][i] -> M[n-1-i][n-1-j] -> M[j][n-1-i] -> M[i][j]
```

인덱스 `i` 의 범위는 `[0, n/2)` 이다. 인덱스 `j` 의 범위는 `[0, (n+1)/2)` 이다. 숫자 4개가 한그룹이기 때문에 인덱스 `i`, `j` 가 처음부터 끝까지 순회할 필요는 없다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N^2)
```

# Space Complexity

```
O(1)
```