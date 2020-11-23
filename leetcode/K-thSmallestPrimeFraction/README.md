# Problem

* [K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/)

# Idea

소수들로 구성된 수열 `V` 와 숫자 `K` 가 주어진다. `V` 의 서로다른 두수 
`p, q (p < q)` 에 대해 `K` 번째 큰 `p / q` 를 구하는 문제이다.

온라인 알고리즘을 이용한다. 즉 모든 수를 구해서 `K` 번 째를 찾지 말고
가장 작은 수부터 시작해서 `K` 번 째 수를 만들어 해결한다. 모든 수를
만들 필요가 없어서 시간 및 공간 복잡도를 향상할 수 있다.

`V = 1 2 3 5` 일 때 가능한 모든 수를 펼쳐보자. 숫자 `1/5, 1/3, 1/2` 만
있으면 다른 수들은 분자의 인덱스만 하나 증가하면서 만들어 낼 수 있다.

```
1/5 2/5 3/5
1/3 2/3
1/2
```

`V = 1 2 3 5` 라고 하자. priority queue 에 `1/5, 1/3, 1/2`
를 삽입한다.

1. `p = V[i], q = [j]` 라고 하자. 
   `p/q, i, j = pq.top(); pq.pop();` 한다.
   `K` 를 하나 감소한다. `K = 0` 이면 `pq.top()` 이 답이다.
2. `p/q` 다음으로 큰 수는 `V[i+1]/V[j]` 이다.
   `pq.push(V[i+1]/V[j], i+1, j)` 한다.
3.  `1, 2` 를 반복한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
