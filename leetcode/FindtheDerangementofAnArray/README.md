# Problem

[Find the Derangement of An Array](https://leetcode.com/problems/find-the-derangement-of-an-array/)

# Idea

숫자 `n` 이 주어지면 `[1..n]` 의 숫자들의 순열들 중 
어떤 숫자도 자신의 수와 그 위치의 서수가 같은 것이 없는 
permutation 의 개수를 구하는 문제이다.

다음은 다양한 `n` 에 대한 dearangement 를 구한 것이다.

```
n: 1, r: 0
x - 1

n: 2, r: 1
x - 1 2
o - 2 1

n: 3, r: 2
x - 1 2 3
x - 1 3 2
x - 2 1 3
o - 2 3 1
o - 3 1 2
x - 3 2 1

n: 4, r: 9
x - 1 2 3 4 
x - 1 2 4 3
x - 1 3 2 4
x - 1 3 4 2
x - 1 4 2 3
x - 1 4 3 2
x - 2 1 3 4
o - 2 1 4 3
x - 2 3 1 4
o - 2 3 4 1
o - 2 4 1 3
x - 2 4 3 1
x - 3 1 2 4
o - 3 1 4 2
x - 3 2 1 4
x - 3 2 4 1
o - 3 4 1 2
o - 3 4 2 1
o - 4 1 2 3
x - 4 1 3 2
x - 4 2 1 3
x - 4 2 3 1
o - 4 3 1 2
o - 4 3 2 1
```

위의 규칙들을 기반으로 다음과 같은 점화식을 만들어낸다.

```
d(0) = 1
d(1) = 0
d(i) = (i-1) * (d(i-1) + d(i-2)) (i > 1)
```

```
d(0) = 1
d(i) = i * d(i-1) + (i & 1 ? -1 : 1) (i > 0)
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
