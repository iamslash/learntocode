# Problem

* [132 Pattern @ leetcode](https://leetcode.com/problems/132-pattern/)

# Idea

`1, 2, 3` 숫자의 순열은 총 6 가지이다. 각각의 경우에 대해서 stack 을
이용하여 정렬을 해보자. 알고리즘은 다음과 같다.

* 수열의 탐색할 숫자를 x 라고 해보자. stack.top() 이 x 클 때까지
  stack.pop() 한다.
* 를 stack.push(x) 한다.

위의 알고리즘으로 정렬이 안되는 경우는 `2, 3, 1` 뿐이다. `2, 3, 1` 을
제외한 5 가지 수열을 Stack-sortable permutations 이라고 한다. `2, 3, 1` 
을 뒤집으면 `1, 3, 2` 이다.

따라서 입력으로 주어지는 데이터를 뒤부터 앞으로 탐색하면서 stack 을
이용하여 불가능한 `2, 3, 1` 패턴을 찾으면 답을 찾을 수 있다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(N)
```

# Space Complexity

```
O(N)
```

# References

* [Stack-sortable permutation](https://en.wikipedia.org/wiki/Stack-sortable_permutation)
