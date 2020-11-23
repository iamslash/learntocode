# Problem

[Regular Expression Matching @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/119/backtracking/856/)

# Idea

먼저 regular expression 을 잘 이해해야 한다.  다음과 같이 다양한 `s,
p` 에 대해 regular expression 결과를 살펴보자. 

```
p = a.b
s = acb -> true
    aab -> true
    axb -> true
    ab  -> false
    acby -> false
    cb -> false
```

```
p = a*b
s = b,ab -> true
    aab -> true
    aaab -> true
    a  -> false
    acb -> false
```

```
p = a*b.*y
s = by -> true
    bly -> true
    ablmy -> true
    ay  -> false
    ab -> false
```

다음과 같이 CACHE C 를 정의하자.

```
C[i][j]
i is index of s
j is index of p
```

`s` 의 길이를 `m` 이라 하고 `p` 의 길이를 `n` 이라 하자.  `C[0][0] =
true` 라고 초기화 하고 `i, j` 를 각각 증가하면서 `C[m][n]` 까지 댜음과
같은 상황을 고려하여 bottom up 으로 채워보자.

```
C[i][j] = C[i-1][j-1]     : p[j-1] == s[i-1] || p[j-1] == '.'
        = C[i][j-2]       : p[j-1] == '*' (* occurs 0 times)
        = C[i-1][j]       : p[j-1] == '*' &&
                              p[j-2] == s[i-1] || p[j-2] == '.' (* occurs multiple times)
        = false
```

예를 들어서 `s = xaabyc`, `p = xa*b.c` 일 때 처리과정을 표로 나타내 보자.

|   |       | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|:-:|:-----:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|   |       |   | **x** | **a** | **\*** | **b** | **.** | **c** |
| 0 |       | T | F | F | F | F | F | F |
| 1 | **x** | F | T | F | T | F | F | F |
| 2 | **a** | F | F | T | T | F | F | F |
| 3 | **a** | F | F | F | T | F | F | F |
| 4 | **b** | F | F | F | F | T | F | F |
| 5 | **y** | F | F | F | F | F | T | F |
| 6 | **c** | F | F | F | F | F | F | T |

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(MN)
```

# Space Complexity

```
O(MN)
```

# References

* [Regular Expression Dynamic Programming @ youtube](https://www.youtube.com/watch?v=l3hda49XcDE&list=PLrmLmBdmIlpuE5GEMDXWf0PWbBD9Ga1lO)