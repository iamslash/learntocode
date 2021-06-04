# Problem

[Egg Drop With 2 Eggs and N Floors](https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/)

숫자 `n` 이 주어진다. 숫자 `f (1 <= f <= n)` 을 찾아보자.  임의의 숫자
`x` 에 달걀을 하나 떨어뜨리자. `f < x` 이면 달걀이 깨진다. `x <= f`
이면 달걀을 깨지지 않는다.  `f` 를 찾기 위한 최소시행횟수를 구하라.

# Idea

달걀은 2개만 사용해야 하는가???

임의의 `i (1 <= i <= n)` 을 선택해 달걀을 떨어뜨려 보자.

* 달걀이 깨지면 `1 <= f < i` 이다. `i - 1` 만큼 달걀을 떨어 뜨리면 `f`
  를 찾을 수 있다.
* 달걀이 안 깨지면 `i <= f <= n` 이다. `n - i` 만큼의 숫자로 달걀을
  떨어뜨리는 실험을 다시 하자.

두 경우의 최대 값이 `n` 개의 숫자에 대해서 `f` 를 찾기 위한
시행횟수이다.

실제로 다양한 `n` 에 대한 최소시행횟수 `m` 을 구해보면 다음과
같다. [Recursive, Iterative, Generic @
leetcode.discussion](https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/discuss/1248069/Recursive-Iterative-Generic)

```
 1: 1
 2: 2
 4: 3
 7: 4
11: 5
16: 6
22: 7
29: 8
37: 9
46: 10 
```

다음과 같은 수식이 성립한다.

```
1 + 2 + ... + m < n
m * (m + 1) / 2 < n
```

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(N) O(N)
```
