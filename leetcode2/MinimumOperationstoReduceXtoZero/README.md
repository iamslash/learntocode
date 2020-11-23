# Problem

[Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

수열 `A[]` 와 숫자 `x` 가 주어진다. `A[]` 양 끝의 숫자들의 합이 `x` 가
되는 방법을 찾아보자. 그 개수가 최소일 때 그 수를 구하라.

# Idea

예를 들어 `A = [1, 1, 4, 2, 3], x = 5` 를 살펴보자. 양끝의
합이 `5` 인 경우는 다음과 같다.

```
A: 1 1 4 2 3
         . .         
```
따라서 답은 2 이다.

`A[]` 의 모든 원소들의 합을 `sum` 이라고 하자. 양끝의 합이 `x` 인
최소 길이를 찾는 것은 중간의 합이 `sum - x` 인 최대길이를 찾는
것과 같다.

```
   * * *
A: 1 1 4 2 3
         . .
```

`int n = A.size()` 를 선언한다.  `int ps[n+1]` 를 선언하여 `A[]` 의
prefix sum 을 저장한다. `int tgt` 를 선언하여 `ps.back() - x` 를
저장한다. 최대길이 중간 부분수열의 합과 같다. `int head = 0` 을
선언하여 중간 부분수열의 시작 인덱스를 저장한다.

이제 인덱스 `i` 를 선언하여 `[0..n)` 를 순회하며 다음을 반복한다.

* `head < i && ps[i] - ps[head] > tgt` 인 동안 다음을 반복한다.
  * `head++` 를 수행한다.
* `ps[i] - ps[head] == tgt` 이면 `ans = max(ans, i - head)` 를
  수행한다.
  
모든 반복을 마치고 `ans < 0` 이면 `-1` 를 리턴한다. `ans >= 0` 이면
`n - ans` 를 리턴한다.

`int ps[]` 를 선언하지 않고 구현하면 공간복잡도를 개선할 수
있다. 주어진 `A[]` 의 앞에 `0` 를 삽입하고 `A[]` 에 부분합을 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
