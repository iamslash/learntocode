# Problem

[Combination Sum II](https://leetcode.com/problems/combination-sum-ii/description/)

# Idea

수열 `v` 를 오름차순으로 정렬하고 backtracking 전략을 사용한다. `v` 가
정렬되어 있기 때문에 중복된 숫자의 경우 한번만 고려해도 된다. 예를
들어서 `1 2 2 3` 의 경우 backtracking 을 다음과 같이 펼쳐 보자.
`target` 을 만족하는 수열을 구성하는 숫자는 괄호로 감싸서
표시하자. `_` 는 콜스택의 깊이를 의미한다.

```
1 2 2 3
_(1)2 2 3
__(1)(2)2 3
___(1)(2)(2)3
____(1)(2)(2)(3)
___(1)(2)2(3)
__(1)2(2)3
___(1)2(2)3
_1(2) 2 3
__1(2)(2)3
___1(2)(2)(3)
__1(2)2(3)        ----- a
_1 2 (2) 3
__1 2 (2)(3)      ----- b
_1 2 2 (3)
```

`target` 를 만족하는 수열을 `w` 라고 하자.  `a`, `b` 는 둘다
`w` 가 같다. 따라서 두번째 `2` 는 첫번째 `2` 때문에 고려할 필요가 없다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N!)
```

# Space Complexity

```
O(N)
```
