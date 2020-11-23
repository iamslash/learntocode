# Problem

[Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)

# Idea

수열 `A[]`, 숫자 `T` 가 주어진다. 임의의 숫자를 `num` 이라고 하자.
`A[i]` 들 중 `num` 보다 큰 숫자는 모두 `num` 으로 바꾸었을 때 `A[]` 의
합이 `T` 보다 작거나 같아야 한다. 이때 그 합이 최대가 되는 `num` 을
구하는 문제이다.

예를 들어 `A = [4, 9, 3], T = 10` 인 경우를 살펴보자. 
`num = 3` 이면 `3 + 3 + 3 = 9` 이므로 `3` 이 답이다.
`num = 4` 이면 `3 + 4 + 3 = 11` 이므로 `4` 는 답이 될 수 없다.

`A[]` 를 오름차순으로 정렬한다. 인덱스 `i` 를 이용하여 `i < n &&
A[i] * (n - i) < T` 동안 다음을 반복한다.

* T -= A[i++];

모든 반복을 마치고 `i == n` 이면 당연히 `A[n-1]` 가 답이다.
이때 `A[i]` 는 단 하나도 교체될 필요가 없다.

그렇지 않으면 `A[i..n)` 은 모두 `num` 보다 큰 수로 교체되야 한다.
따라서 `num` 은 교체 되어야할 수보다 작아야 하므로 다음과 같이 계산한다.

```cpp
int(std::round((T - 0.0001 / (n-i)))
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
