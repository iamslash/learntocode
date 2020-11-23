# Problem

* [Interleaving String](https://leetcode.com/problems/interleaving-string/)

# References

* [String Interleaving Dynamic Programming @ youtube](https://www.youtube.com/watch?v=ih2OZ9-M3OM)

# Idea

예를 들어 "s1 = aab", "s2 = axy", "s3 = aaxaby"
가 주어졌을 때 다음과 같이 이차원 표를 그려서 해결해보자.

```
  0 a a b
0 T T T F 
a T T F F
x F T T T
y F F F T
```

예를 들어 "s1 = dbbca", "s2 = aabcc", "s3 = aadbbcbcac"
가 주어졌을 때 다음과 같이 이차원 표를 그려서 해결해보자.

```
  0 d b b c a
0 T F F F F F
a T F F F F F
a T T T T T F
b F T T F T F
c F F T T T T
c F F F T F T
```

위의 표에 해당하는 캐쉬 `C[][]` 를 정의하고 다음과 같은 방법으로
채워나간다.

```cpp
if ((s3[y+x-1] == s1[x-1] && C[y][x-1]) ||
    (s3[y+x-1] == s2[y-1] && C[y-1][x]))
    C[y][x] = T
else
    C[y][x] = F
```

마지막에 `C[5][5]` 가 답이다.

캐쉬를 `C[]` 와 같이 1 차원으로 정의하면 공간복잡도를 줄일 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(W)
```
