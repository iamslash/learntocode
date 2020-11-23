# Problem

[3Sum With Multiplicity](https://leetcode.com/problems/3sum-with-multiplicity/)

# Idea

수열 `A[]` 와 숫자 `T` 가 주어진다. `A[i] + A[j] + A[k] == T`
인 튜플 `i, j, k` 의 개수를 구하는 문제이다. 튜플은 중복이 가능하다.

`A[j]` 를 기준으로 `A[i]` 에 대한 `A[k]` 의 개수를 구해서 더하는
방식은 Time Limit Exceeded 가 발생한다. 조금 더 효율적으로 구해보자.

문제의 조건에 의해 `0 <= A[i] <= 100` 이다. 벡터 `vector<int64_t>
M(101, 0)` 을 선언하여 숫자를 키로 개수를 값으로 저장하자.  두개의
숫자 `a, b` 를 `M[]` 에서 고른다. `M[]` 에 존재하는 `c = T - a - b` 를
골라서 세개의 숫자에 대한 개수를 조합연산하자. 조합연산한 값은 `ans`
에 누적하여 더한다.

그렇다면 세가지 숫자가 주어졌을 때 각각 같은 경우를 따져보자.
모든 경우의 수를 따져보면 다음과 같이 5 가지가 존재한다.

```
a b c
a a b
a b b
a b a
a b c
```

다음은 앞서 언급한 5 가지 경우에 따라 조합연산을 구현한 것이다.
고른 숫자가 `a a a` 이고 `M[a] == 2` 라면 `a a a` 를
고를 수 없게 된다. 그러나 `M[a] - 2 == 0` 이 되어 곱연산할 때 
`0` 이 곱해지기 때문에 아래 구현은 문제가 없다.

```c
        if (a == b && b == c) {
          ans += M[a] * (M[a] - 1) * (M[a] - 2) / 6;
        } else if (a != b && b != c) {
          ans += M[a] * M[b] * M[c];
        } else if (a == b && b != c) {
          ans += M[a] * (M[a] - 1) / 2 * M[c];
        } else if (a != b && b == c) {
          ans += M[b] * (M[b] - 1) / 2 * M[a];
        } else if (a == c && b != c) {
          ans += M[a] * (M[a] - 1) / 2 * M[b];
        }
```

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
