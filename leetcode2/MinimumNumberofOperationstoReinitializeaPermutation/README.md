# Problem

> [Minimum Number of Operations to Reinitialize a Permutation](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/)

숫자 `n` 이 주어진다. 크기가 `n` 인 `perm[]` 이 있고 `perm[i] = i`
이다.

특정 operation 을 수행하면 다음과 같은 일이 벌어진다.

```
* If i % 2 == 0, then perm[i] = perm[i / 2].
* If i % 2 == 1, then perm[i] = perm[n / 2 + (i - 1) / 2].
```

처음 주어진 `perm[]` 에 임의의 개수의 operation 을 수행하여 다시 처음
`perm[]` 이 되도록 해보자. operation 의 최소 개수를 구하라.

# Idea

예를 들어 `n = 4` 인 경우를 살펴보자.

```
perm: 0 1 2 3 4 5
      0 3 1 4 2 5
      0 4 3 2 1 5
      0 2 4 1 3 5
      0 1 2 3 4 5
```

이번에는 `n = 6` 인 경우를 살펴보자.

```

perm: 0 1 2 3 4 5 6 7 8 9
      0 5 1 6 2 7 3 8 4 9
      0 7 5 3 1 8 6 4 2 9
      0 8 7 6 5 4 3 2 1 9
      0 4 8 3 7 2 6 1 5 9
      0 2 4 6 8 1 3 5 7 9
      0 1 2 3 4 5 6 7 8 9
```

`perm[1]` 이 다시 `1` 이 되었을 때 operation 의 개수가 답이다.
`perm[1]` 이 어떻게 변하는지 살펴보자.

첫번째 operation 을 수행한 `perm[]` 을 구하자. `perm[1]` 은
다음과 같은 규칙으로 변하는 것을 발견할 수 있다???

```java
i = perm[1]
while (i != 1) {
  i = perm(i)
}
```

이번에는 `1` 이 `perm[]` 에서 어떻게 이동하는지 살펴보자.
다음과 같은 규칙을 발견할 수 있다???

```java
		while (ans == 0 || idx > 1) {
			if (idx < n/2) {
				idx *= 2;
			} else {
				idx = (idx - n/2) * 2 + 1;
			}
			ans++;
		}
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
