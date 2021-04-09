# Problem

> [Count Nice Pairs in an Array](https://leetcode.com/problems/count-nice-pairs-in-an-array/)

수열 `nums` 가 주어진다. 임의의 수 `a` 가 있다면 그것을 가꾸로 한
숫자를 `rev(a)` 라고 해보자. 임의의 수 `a, b` 에 대해 `a + rev(b) ==
b + rev(a)` 를 만족하는 `(a, b)` 쌍의 개수를 구하라.

# Idea

예를 들어 `nums = [42,11,1,97]` 의 경우를 살펴보자.

```
  nums: 42 11 1 97
  
  42 + rev(97) = 97 + rev(42)
  11 + rev(1)  =  1 + rev(11)
```

따라서 답은 `2` 이다.

문제의 조건을 읽어보고 다음과 같은 수식을 발견할 수 있다.

```
A[i] + rev(A[j]) = A[j] + rev(A[i])
A[i] - rev(A[i]) = A[j] - rev(A[j])
B[i] = A[i] - rev(A[i])
```

따라서 `B[i]` 와 같은 숫자들의 개수가 곧 `B[i]` 와 짝을 이루는 쌍의
개수와 같다.

다음과 같은 변수들을 선언한다.

> * `Map<Integer, Integer> cntMap = new HashMap<>()`: `B[i]` 와 그
>   개수를 저장한다.
> * `int ans`: 답을 저장한다.

이제 `int num` 으로 `nums` 를 순회하며 다음을 반복한다.

* `int rev` 에 `num` 을 거꾸로 한 숫자를 저장한다.
* `num - rev` 가 `cntMap` 에 몇개 존재하는지 조사한다. 그 개수가 곧
  쌍의 개수이다. 이것을 답에 더한다.
* `num - rev` 를 `cntMap` 에 삽입한다.

모든 반복을 마치면 `ans` 가 답이다.  

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
