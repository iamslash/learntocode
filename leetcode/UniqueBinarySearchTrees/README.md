# Problem

[Unique Binary Search Trees @ leetcode](https://leetcode.com/problems/unique-binary-search-trees/description/)

숫자 `n` 이 주어진다. `[1..n]` 으로 표현가능한 BST 의 개수를 구하라.

# Idea

n 이 1 인 경우를 생각해 보자. 예를 들어 키가 1 인 노드 하나를 이용하여
제작가능한 BST 는 1 개임이 자명하다.

n 이 2 인 경우를 생각해 보자. 예를 들어 키가 1, 2 인 노드 두개를
이용하여 제작가능한 BST 는 다음과 같이 2 개이다.

```
  1     2
   \   /  
    2 1
```

`T[n]` 를 키가 [1..n] 인 경우 BST 의 개수라고 정의하자. n 이 2, 3 인
경우를 고려하여 다음과 같은 식을 유도할 수 있다. 계산의 편의를 위해
`T[0] = 1` 이라고 해도 좋다.

```
T[1] = 1
T[2] = T[0] * T[1] + 
       T[1] * T[0]
T[3] = T[0] * T[2] +
       T[1] * T[1] +
       T[2] * T[0]
```

위의 식을 살펴보면 루트노드의 키가 `[1..n]` 일때 마다 왼쪽 자식을
루트노드로 하는 BST 의 개수와 오른쪽 자식을 로트노드로 하는 BST 의
개수를 곱한 것들을 모두 합한 것이 `T[n]` 과 같음을 추론할 수 있다. 즉
다음과 같은 식을 유도할 수 있다.

```cpp
T[n] = T[0]   * T[n-1] + 
       T[1]   * T[n-2] +
       ...             +
       T[n-1] * T[1]   
```

# Recursive Dynamic Programming

## Idea

`T[n]` 을 부분문제 `solve(int n)` 으로 하자. memoization 을 위해 캐시
`vector<int> C` 를 정의한다. 다음과 같이 재귀적으로 해결한다.

```cpp
     for (int i = 1; i <= n; ++i) {
       r += solve(i-1) * solve(n-i);
     }
```

## Implementation

* [c++11](b.cpp)

## Complexity

```
O(N) O(N)
```

# Iterative Dynamic Programming

## Idea

캐시 `vector<int> C(n)` 를 정의하고 `C[0] = C[1] = 1` 으로 초기화
하자. 다음과 같이 반복문을 작성하여 구현한다.

```
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        C[i] += C[j-1] * C[i-j];
      }
    }
```

## Implementation

* [c++11](a.cpp)
* [js](a.js)

## Complexity

```
O(N^2) O(N)
```
