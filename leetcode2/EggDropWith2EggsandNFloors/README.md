# Problem

[Egg Drop With 2 Eggs and N Floors](https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/)

숫자 `n` 이 주어진다. 달걀이 2 개가 주어진다. 계단이 `[1..n]`
만큼있다.  달걀 하나를 임의의 계단에 놓아두자. 특정 계단을 `f (1 <= f
<= n)` 라고 하자. 임의의 계단 `x` 에 대해 `f < x` 이면 달걀이
깨진다. `x <= f` 이면 달걀을 깨지지 않는다.  `f` 를 찾기 위해 최소로
달걀을 놓는 행위의 수를 최소시행횟수라고 하자. 최소시행횟수를 구하라.

# Idea

달걀은 2개만 사용해야 한다. 즉, 하나 떨어뜨려 보고 깨졌는지 깨지지
않았는지 확인하고 `f` 를 찾아야 한다. 그렇다면 달걀 2 개로 수 많은
실험을 해보고 그 실험들 중 `f` 를 찾을 수 있는 최소시행횟수를 찾아야
한다. 실험을 한번만 해서는 최소시행횟수를 찾을 수 없다는 점을 이해해야
한다.

달걀을 `x` 계단에 놓았는데 깨졌다면 남은 달걀은 하나이다.  남은 달걀로
`1` 번 계단부터 놓아보자. 남은 달걀마저 깨진다면 `f` 를 찾을 수 있다.

달걀을 `x` 계단에 놓았는데 깨지지 않았다면 남은 달걀은 두개이다.
깨지지 않은 달걀로 `x` 보다 큰 계단에 놓아 보자. 무언가 반복되는
느낌이다.

다음과 같은 규칙을 발견할 수 있다.

임의의 `i (1 <= i <= n)` 계단을 선택해 달걀을 떨어뜨려 보자.

* 달걀이 깨지면 `1 <= f < i` 이다. `i - 1` 만큼 남은 달걀을 떨어
  뜨리면 `f` 를 찾을 수 있다.
* 달걀이 안 깨지면 `i <= f <= n` 이다. `n - i` 만큼의 숫자로 다시
  두개의 달걀을 떨어뜨리는 실험을 한다.

recursive dynamic programming 으로 해결할 만 하다.

`int[] C = new int[1001]` 를 선언하여 `n` 에 대한 최소 시행횟수를
저장하자. 다음과 같은 dynamic equation 을 생각할 수 있다.

```c
for (int i = 1; i <= n; ++i) {
    C[n] = Math.min(C[n], 1 + max(i - 1, twoEggDrop(n - i)));
}
```

이 것을 조금 더 최적화 해보자.

위의 방법으로 다양한 `n` 에 대한 최소시행횟수 `m` 을 구해보면 다음과
같다. [Recursive, Iterative, Generic @
leetcode.discussion](https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/discuss/1248069/Recursive-Iterative-Generic)

```
 n: m
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

다음과 같은 수식을 발견할 수 있다.

```
1 + 2 + ... + m < n
m * (m + 1) / 2 < n
```

`m * (m + 1) / 2 < n` 을 만족하는 최대 정수 `m` 이 곧 답이다.

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(N) O(N)
```
