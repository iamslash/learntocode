- [Problem](#problem)
- [Idea](#idea)
  - [Right Most](#right-most)
  - [Right Most Equal](#right-most-equal)
  - [Left Most Equal](#left-most-equal)
  - [Left Most](#left-most)
  - [Examples](#examples)
- [Implementation](#implementation)
- [Complexity](#complexity)

----

# Problem

* [binary Search with array @ geeksforgeeks](https://practice.geeksforgeeks.org/problems/binary-search/1)

수열 `A[]` 와 숫자 `K` 가 주어진다. `K` 를 `A[]` 에서 검색하는 문제이다. 

right most, right most equal, **left most equal**, left most pattern 을
기억하자. 

# Idea

## Right Most

`V[]` 를 정렬하고 `K` 가 있는지 binary search 로 검색한다. 

`K` 보다 작은 값중 가장 큰 값 (right most value) 을 검색하려면 다음
pattern 을 이용한다. [DivideChocolate @ learntocode](/leetcode2/DivideChocolate/README.md)

```cpp
// right most pattern
while (l < r) {
  int m = (l+r+1)/2;
  if (A[m] < k) { // K is in right ?
    l = m;
  } else {
    r = m-1;
  }
}
```

```cpp
middle equation: int m = (l+r+1)/2
  comparison op: A[m] < k
   low equation: l = m  
    hi equation: r = m-1
```

## Right Most Equal

`K` 보다 작거나 같은 값중 가장 큰 값 (right most equal value) 을 검색하려면 다음
pattern 을 이용한다. 

```cpp
// right most equal pattern
while (l < r) {
  int m = (l+r+1)/2;
  if (A[m] <= k) { // K is in right ?
    l = m;
  } else {
    r = m-1;
  }
}  
```

```cpp
middle equation: int m = (l+r+1)/2
  comparison op: A[m] <= k
   low equation: l = m  
    hi equation: r = m-1
```

## Left Most Equal

`K` 보다 크거나 같은 값 중 가장 작은 값 (left most equal value) 검색하려면
다음 pattern 을 이용한다. [The Earliest Moment When Everyone Become Friends @ learntocode](/leetcode/TheEarliestMomentWhenEveryoneBecomeFriends/a.cpp)

```cpp
// left most equal pattern  
while (l < r) {
  int m = (l+r)/2;
  if (A[m] < k) { // K is in right?
    l = m+1;
  } else {
    r = m;
  }
}  
```

```cpp
middle equation: int m = (l+r)/2
  comparison op: A[m] < k
   low equation: l = m+1  
    hi equation: r = m
```

## Left Most

`K` 보다 큰 값 중 가장 작은 값 (left most value) 검색하려면
다음 pattern 을 이용한다. 

```cpp
// left most pattern
while (l < r) {
  int m = (l+r)/2;
  if (A[m] <= k) { // K is in right?
    l = m+1;
  } else {
    r = m;
  }
}
```

```cpp
middle equation: int m = (l+r)/2
  comparison op: A[m] <= k
   low equation: l = m+1  
    hi equation: r = m
```

## Examples

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `right most pattern` 의 풀이과정은
다음과 같다. 답은 `3 (A[2])` 이다.

```
A: 1 2 3 5 6 7
l: 0 0 1 2
r: 5 2 2 2
m: 3 1 2
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `right most pattern` 의 풀이과정은
다음과 같다. 답은 `3 (A[2])` 이다.

```
A: 1 2 3 5 6 7
l: 0 0 1 2
r: 5 2 2 2
m: 3 1 2
```

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `right most equal pattern` 의 풀이과정은
다음과 같다. 답은 `3 (A[2])` 이다.

```
A: 1 2 3 5 6 7
l: 0 0 1 2
r: 5 2 2 2
m: 3 1 2
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `right most equal pattern` 의 풀이과정은
다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3
r: 5 5 3 
m: 3 4
```

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `left most equal pattern` 의 풀이과정은
다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 3 
r: 5 5 4 3
m: 2 4 3
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `left most equal pattern` 의 풀이과정은
다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 3
r: 5 5 4 3
m: 2 4 3
```

예를 들어 `A = [1 2 3 5 6 7], K = 4` 인 경우 `left most pattern` 의 풀이과정은
다음과 같다. 답은 `5 (A[3])` 이다.

```
A: 1 2 3 5 6 7
l: 0 3 3 3
r: 5 5 4 3
m: 2 4 3
```

예를 들어 `A = [1 2 3 5 6 7], K = 5` 인 경우 `left most pattern` 의 풀이과정은
다음과 같다. 답은 `6 (A[4])` 이다.

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
