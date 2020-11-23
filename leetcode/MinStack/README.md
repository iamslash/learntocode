# Problem

[Min Stack](https://leetcode.com/problems/min-stack/)

# Idea

최소값을 추출할 수 있는 스택을 구현하는 문제이다.

다음과 같이 자료구조를 설계한다.

```
struct MinStack {
  min int
  stck []int
}
```

`min` 은 `Math.MaxInt32` 항상 최소값이 저장된다. `stck` 는 보통의 스택과 같다.  그러나
이전 최소값을 추가로 저장한다. 예를 들어 `-2, 0, -3` 을 push 하는 과정은
다음과 같다.

```
stck: -2 -2    -2 -2 0    -2 -2 0 -2 -3
 min: -2       -2                 -3
```

다음은 거꾸로 pop 하는 과정이다.

```
stck: -2 -2 0 -2 -3    -2 -2 0    -2 -2   
 min:         -3            -2       -2
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
  push: O(N)
   pop: O(N)
getMin: O(1)
```
