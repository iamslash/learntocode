# Problem

[Find Kth Largest XOR Coordinate Value](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/)

이차원 배열 `M[][]` 와 숫자 `k` 가 주어진다. `V(y,x)` 는 `M[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed)` 의 XOR 과 같다.

`V(y, x)` 중 `k` 번째로 큰 것을 구하라. (1-indexed)

# Idea

[partial sum @ learntocode](/fundamentals/partialsum/partialsum/README.md) 과 비슷하다.

다음과 같은 dynamic programming equation 을 생각할 수 있다.

```c
M[y][x] = M[y][x] ^ M[y-1][x] ^ M[y][x-1] ^ M[y-1][x-1]
```

`Queue<Integer> pq = new PriorityQueue<>();` 를 선언하여 다음과 같은 방법으로 `k` 번째로 큰 숫자를 유지할 수 있다.

```java
pq.offer(v);
while (pq.size() > k) {
  pq.poll();
}
```

모든 반복을 마치면 `pq.peek()` 가 곧 답이다. 

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^2lgK) O(K)
```
