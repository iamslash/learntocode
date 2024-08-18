- [Problem](#problem)
- [Idea](#idea)
  - [Right Most (K보다 작은 값 중 가장 큰 값 찾기)](#right-most-k보다-작은-값-중-가장-큰-값-찾기)
  - [Right Most Equal (K 이하의 값 중 가장 큰 값 찾기)](#right-most-equal-k-이하의-값-중-가장-큰-값-찾기)
  - [Left Most Equal (K 이상의 값 중 가장 작은 값 찾기)](#left-most-equal-k-이상의-값-중-가장-작은-값-찾기)
  - [Left Most (K보다 큰 값 중 가장 작은 값 찾기)](#left-most-k보다-큰-값-중-가장-작은-값-찾기)
  - [Examples](#examples)
- [Implementation](#implementation)
- [Complexity](#complexity)

----

# Problem

* [binary Search with array @ geeksforgeeks](https://practice.geeksforgeeks.org/problems/binary-search/1)

수열 `A[]` 와 숫자 `K` 가 주어진다. `K` 를 `A[]` 에서 검색하는 문제이다. `K` 는 `A[]` 에 있을 수도 있고 없을 수도 있다.

right most, right most equal, **left most equal**, left most pattern 을 기억하자. 그 중 **left most equal** 를 주로 사용한다.

- `(l + r + 1) / 2` vs `(l + r) / 2`: Right 패턴에서는 `m` 계산 시 `1`을 더해줘서 중간점을 오른쪽으로 이동시킨다.
  - overflow 를 방지하기 위해 `l + (r - l) / 2` 를 사용하기도 한다.
- `< K` vs `<= K`: 비교 연산자를 바꿔가며, 원하는 조건에 맞게 `l`과 `r`을 업데이트한다.
  - Right Most, Left Most Equal 은 `A[m] < k` 이다.
  - Right Most Equal, Left Most 은 `A[m] <= k` 이다.  
  - Right 는 `l = m, r = m - 1`
  - Left 는 `l = m + 1, r = m`
- 기억하기 쉬운 패턴:
  - Right 는 항상 오른쪽을 더 우선시하여 최대값을 찾는다.
  - Left 는 왼쪽을 더 우선시하여 최소값을 찾는다.

# Idea

## Right Most (K보다 작은 값 중 가장 큰 값 찾기)

`K` 보다 작은 값중 가장 큰 값을 찾는다. 

```cpp
// right most pattern
while (l < r) {
  int m = (l + r + 1)/2;
  if (A[m] < k) { // K is in right ?
    l = m;
  } else {
    r = m - 1;
  }
}
```

```cpp
middle equation: m = (l + r + 1) / 2
  comparison op: A[m] < k
   low equation: l = m  
    hi equation: r = m - 1
```

- [DivideChocolate | learntocode](/leetcode2/DivideChocolate/README.md)

## Right Most Equal (K 이하의 값 중 가장 큰 값 찾기)

`K` 보다 작거나 같은 값중 가장 큰 값을 찾는다.

```cpp
// right most equal pattern
while (l < r) {
  int m = (l + r + 1)/2;
  if (A[m] <= k) { // K is in right ?
    l = m;
  } else {
    r = m - 1;
  }
}  
```

```cpp
middle equation: int m = (l + r + 1) / 2
  comparison op: A[m] <= k
   low equation: l = m  
    hi equation: r = m - 1
```

## Left Most Equal (K 이상의 값 중 가장 작은 값 찾기)

`K` 보다 크거나 같은 값 중 가장 작은 값을 찾는다.

```cpp
// left most equal pattern  
while (l < r) {
  int m = (l + r) / 2;
  if (A[m] < k) { // K is in right?
    l = m + 1;
  } else {
    r = m;
  }
}  
```

```cpp
middle equation: int m = (l + r) / 2
  comparison op: A[m] < k
   low equation: l = m + 1  
    hi equation: r = m
```

- [The Earliest Moment When Everyone Become Friends | learntocode](/leetcode/TheEarliestMomentWhenEveryoneBecomeFriends/a.cpp)
- [Find Minimum in Rotated Sorted Array](/leetcode/FindMinimuminRotatedSortedArray/MainApp.java)

## Left Most (K보다 큰 값 중 가장 작은 값 찾기)

`K` 보다 큰 값 중 가장 작은 값을 찾는다.

```cpp
// left most pattern
while (l < r) {
  int m = (l + r) / 2;
  if (A[m] <= k) { // K is in right?
    l = m + 1;
  } else {
    r = m;
  }
}
```

```cpp
middle equation: int m = (l + r) / 2
  comparison op: A[m] <= k
   low equation: l = m + 1  
    hi equation: r = m
```

## Examples

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `right most pattern` 의 풀이과정은 다음과 같다. 답은 `3 (A[2])` 이다.

```
A: 1 2 3 5 6 7
l: 0 0 1 2
r: 5 2 2 2
m: 3 1 2
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `right most pattern` 의 풀이과정은 다음과 같다. 답은 `3 (A[2])` 이다.

```
A: 1 2 3 5 6 7
l: 0 0 1 2
r: 5 2 2 2
m: 3 1 2
```

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `right most equal pattern` 의 풀이과정은 다음과 같다. 답은 `3 (A[2])` 이다.

```
A: 1 2 3 5 6 7
l: 0 0 1 2
r: 5 2 2 2
m: 3 1 2
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `right most equal pattern` 의 풀이과정은 다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3
r: 5 5 3 
m: 3 4
```

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `left most equal pattern` 의 풀이과정은 다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 3 
r: 5 5 4 3
m: 2 4 3
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `left most equal pattern` 의 풀이과정은 다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 3
r: 5 5 4 3
m: 2 4 3
```

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `left most pattern` 의 풀이과정은 다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 3
r: 5 5 4 3
m: 2 4 3
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `left most pattern` 의 풀이과정은 다음과 같다. 답은 `6 (A[4])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 4
r: 5 5 4 4
m: 2 4 3
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(logN) O(1)
```
