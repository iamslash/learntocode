# Problem

[Check If It Is a Good Array](https://leetcode.com/problems/check-if-it-is-a-good-array/)

수열 `A[]` 가 주어진다. 원소들을 적당히 선택한다. 그리고 각각의
숫자에 임의의 숫자를 곱하여 모두 더하면 1 이되는지를 검증하라.

# References

* [베주 항등식 @ 나무위키](https://namu.wiki/w/%EB%B2%A0%EC%A3%BC%20%ED%95%AD%EB%93%B1%EC%8B%9D)

# Idea

이 문제는 [bezout's identity](https://github.com/iamslash/learntocode/blob/6094733820ea204b8221bcf1e2135e02eaeda227/fundamentals/numbertheory/modulararithmatic/README.md) 를
이해해야 풀 수 있다.

`gcd(A[0]..A[n-1]) == 1` 인지 검증하는 것과 같다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
