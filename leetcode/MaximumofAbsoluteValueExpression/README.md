# Problem

[Maximum of Absolute Value Expression](https://leetcode.com/problems/maximum-of-absolute-value-expression/)

# Idea

길이가 같은 수열 `X[], Y[]` 가 주어진다. 임의의 `0 <= i, j < A.size()`
대하여 `|X[i] - X[j]| + |Y[i] - Y[j]| + |i - j|` 가 최대가 되었을 때
그 최대 값을 구하는 문제이다.

수식에 절대값이 사용되었으므로 모든 경우의 수를 고려해보자.

```
0.   (X[i] - X[j])  +  (Y[i] - Y[j])  +  (i - j) 
1.   (X[i] - X[j])  +  (Y[i] - Y[j])  -  (i - j) 
2.   (X[i] - X[j])  -  (Y[i] - Y[j])  +  (i - j) 
3.   (X[i] - X[j])  -  (Y[i] - Y[j])  -  (i - j) 
4.  -(X[i] - X[j])  +  (Y[i] - Y[j])  +  (i - j) 
5.  -(X[i] - X[j])  +  (Y[i] - Y[j])  -  (i - j) 
6.  -(X[i] - X[j])  -  (Y[i] - Y[j])  +  (i - j) 
7.  -(X[i] - X[j])  -  (Y[i] - Y[j])  -  (i - j) 
```

위의 수식을 `i` 관련 항과 `j` 관련 항으로 정리하면 다음과 같다.

```
0.   (X[i] + Y[i] + i)  -  (X[j] + Y[j] + j)
1.   (X[i] + Y[i] - i)  -  (X[j] + Y[j] - j)
2.   (X[i] - Y[i] + i)  -  (X[j] - Y[j] + j)
3.   (X[i] - Y[i] - i)  -  (X[j] - Y[j] - j)
4.  -(X[i] - Y[i] - i)  +  (X[j] - Y[j] - j)
5.  -(X[i] - Y[i] + i)  +  (X[j] - Y[j] + j)
6.  -(X[i] + Y[i] - i)  +  (X[j] + Y[j] - j)
7.  -(X[i] + Y[i] + i)  +  (X[j] + Y[j] + j)
```
결과는 절대값이기 때문에 `0, 7`, `1, 6`, `2, 5`, `3, 4` 은 같다.
중복된 수식을 정리하면 다음과 같다.

```
0.   (X[i] + Y[i] + i)  -  (X[j] + Y[j] + j)
1.   (X[i] + Y[i] - i)  -  (X[j] + Y[j] - j)
2.   (X[i] - Y[i] + i)  -  (X[j] - Y[j] + j)
3.   (X[i] - Y[i] - i)  -  (X[j] - Y[j] - j)
```

위의 수식을 만족하기 위해서는 다음과 같이 4 가지
항이 있으면 계산할 수 있다.

```
A = (X[i] + Y[i] + i)
B = (X[i] + Y[i] - i)
C = (X[i] - Y[i] + i)
D = (X[i] - Y[i] - i)
```

이제 `X, Y` 를 순회하면서 `A[], B[], C[], D[]` 를 완성한다.
그리고 각 `A, B, C, D` 의 최대값과 최소값의 차이를 `a, b, c, d` 
라고 하자. `max(a, b, c, d)` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
