# Problem

[Coin Path](https://leetcode.com/problems/coin-path/)

# Idea

수열 `V[]`  와 숫자 `K` 가 주어진다. `V[0]` 에서 출발하여
`V[n-1]` 까지 `V[i]` 를 지불하면서 점프한다. 이때 `V[i]` 에서
`V[i+1..i+B]` 로 점프할 수 있다. 하지만 `-1` 값으로 점프할 수는 없다.
지불 비용이 최소가 되는 패스를 구하는 문제이다.

dynamic programming 으로 해결하기 위해 아래와 같이 캐시 `C[]` 와
패스 저장을 위해 `F[]` 를 선언한다. 반드시 `C[n-1] = A[n-1]` 해야 한다.

```
vector<int> C(n, INT_MAX)
vector<int> F(n, -1)
C[i]: cumulative costs from i to n-1
F[i]: next pos of i
C[n-1] = A[n-1]
```

예를 들어 `V[] = 1, 2, 4, -1, 2, K = 2` 를 살펴보자. 인덱스 `i, j` 를 이용하여 다음과 같이 순회하며 `C[], F[]` 를 갱신한다.

```
             i  j           i  j              i     j
V:  1  2  4 -1  2     1  2  4 -1  2     1  2  4 -1  2      
C: MX MX MX MX  2    MX MX MX MX  2    MX MX  6 MX  2    
F: -1 -1 -1 -1 -1    -1 -1 -1 -1 -1    -1 -1  4 -1 -1

       i  j              i     j        i  j
V:  1  2  4 -1  2     1  2  4 -1  2     1  2  4 -1  2      
C: MX  8  6 MX  2    MX  8  6 MX  2     9  8  6 MX  2    
F: -1  2  4 -1 -1    -1  2  4 -1 -1     1  4  4 -1 -1

    i     j          
V:  1  2  4 -1  2    
C:  7  8  6 MX  2    
F:  2  4  4 -1 -1
```

인덱스 `i = 0` 를 활용하여 `F[]` 를 순회하면 패스를 완성할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NK) O(N)
```
