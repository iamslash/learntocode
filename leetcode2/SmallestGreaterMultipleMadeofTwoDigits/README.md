# Problem

[Smallest Greater Multiple Made of Two Digits](https://leetcode.com/problems/smallest-greater-multiple-made-of-two-digits/)

숫자 `k, digit1, digit2` 가 주어진다. `digit1, digit2` 로 구성된
숫자를 만들어 보자. 그 숫자를 `num` 이라 하자. `num` 은 `k` 로 나누어
떨어지는 수중 가장 작은 숫자이다.

# Idea

`digit1, digit2` 로 작은 숫자부터 만들어 본다. 그리고 `k` 로 나누어
떨어지는 숫자 `num` 을 찾는다.

예를 들어 `k = 2, digit1 = 0, digit2 = 2` 의 경우를 살펴보자.

```
num:  0
      2
    0 0
    0 2
    2 0    20 % 4 == 0
    2 2
```

따라서 답은 20 이다.

모든 숫자를 생성하고 `k` 로 나누어 떨어지는 숫자를
찾아보자. 완전탐색이다. DFS 로 해결할 만 하다.

`digit1, digit2` 로 어떻게 숫자를 생성할지 고민해보자. 예를 들어
`digit1 = 0, digit2 = 2` 의 경우를 살펴보자. 숫자들은 오름차순이다.
이전에 발생한 수에 10 을 곱하고 새로운 숫자를 더하기만 하면 된다. 예를
들어 이전에 발생한 수가 `0` 이라면 `0 * 10 + 0, 0 * 10 + 2` 를 생성할
수 있다.

```
      0
      2
    0 0
    0 2
    2 0  
    2 2
```

다음과 같은 부분문제 `dfs` 를 정의한다.

```
int dfs(k, digit1, digit2, num)

return: answer
     k: input data
digit1: input data
digit2: input data
   num: candidate
```

다음과 같은 몇가지 주의사항이 있다.

* 문제의 조건에 의해 `num >= k` 이어야 한다.
* `num >= 0` 이다. `0 <= digit1, digit2 <= 9` 이다. 따라서 `num +
  digit1 == 0` 이면 `num == 0, digit1 == 0` 이다. 새로 생성한 수 역시
  0 이다.. `dfs` 를 계속 호출할 필요가 없다. `digit2` 도 마찬가지이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(2^L) O(L)

L: length of num
```
