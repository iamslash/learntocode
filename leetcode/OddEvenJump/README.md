# Problem

> [Odd Even Jump](https://leetcode.com/problems/odd-even-jump/)

수열 `A[]` 가 주어진다. `A[i]` 에서 점프를 한다. 첫번재 점프는 odd numbered jump
즉, 홀 수 번째 점프다. 그 다음 점프는 두번째 점프이다. 즉, even numbered jump
즉, 짝 수 번째 점프다.

홀수 번째 점프할 때는 `A[i] <= A[j]` 인 가장 작은 `A[j]` 로 간다. 이것을 higher
first 라고 하자. `A[i]` 에서 짝수 번째 점프할 때는 `A[i] >= A[j]` 인 가장 큰
`A[j]` 로 간다. 이것을 lower first 라고 하자. `n = A.size()` 이다. `A[]` 의
끝까지 도착할 수 있는 출발지의 개수를 구하는 문제이다.

# Idea

먼저 벡터 `vector<int> hier(n), loer(n)` 를 선언한다.  `A[i]` 에서
higer first 점프 할 때 끝까지 도착할 수 있으면 `hier[A[i]] = 1` 을
수행한다. 또한 `A[i]` 에서 lower first 점프 할 때 끝까지 도착할 수
있으면 `loer[A[i]] = 1` 을 수행한다. `A[n-1]` 에서 출발한다면 이미
끝에 도착해 있으므로 당연히 `hier[n-1] = loer[n-1] = 1` 이다.

그리고 맵 `map<int, int> jumpMap` 를 선언하여 `A[]` 를 인덱스 `i` 를
이용하여 거꾸로 순회할 때 이미 방문한 `{A[i] : i}` 를 저장한다. 당연히
`jumpMap[A[n-1]] = n-1` 이다.

예를 들어 `A[] = (5, 1, 3, 4, 2)` 를 살펴보자.

``` 
                 i          i          i          i
      A: 5 1 3 4 2    5 1 3 4 2    5 1 3 4 2    5 1 3 4 2
   hier: f f f f t          f t        t f t      t t f t
   loer: f f f f t          t t        t t t      f t t t
jumpMap: 2            2 4          2 3 4        1 2 3 4
         4            4 3          4 2 3        1 4 2 3
    ans: 0            0            1            2

         i
      A: 5 1 3 4 2 
   hier: f t t f t 
   loer: f f t t t 
jumpMap: 1 2 3 4 5         
         1 4 2 3 0         
    ans: 3         
```

따라서 답은 3 이다.

인덱스 `i` 를 이용하여 `[n-1..0]` 을 순회하면서 다음을 반복한다. `ans`
를 매번 갱신하여 답을 저장한다.

0. `auto ithi = jumpMap.lower_bound(A[i])` 를 수행한다. 
1. `auto itlo = jumpMap.upper_bound(A[i])` 를 수행한다.
2. `ithi != jumpMap.end()` 이면 `hier[i] = loer[ithi->second]` 이다.
3. `itlo != jumpMap.end()` 이면 `loer[i] = hier[(--itlo)->second]` 이다.
4. `hier[i]` 이면 `ans++` 이다???
5. `jumpMap[A[i]] = i` 를 수행한다.

모든 반복이 끝나면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(NlgN) O(N)
```
