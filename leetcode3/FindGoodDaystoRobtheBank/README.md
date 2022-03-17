# Problem

[Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank/)

수열 `security[]`, 숫자 `time` 이 주어진다.  `security[i]` 는 `i-th`
날짜의 경비원 수이다. 경비원의 수가 `security[i]` 를 중심으로 왼쪽으로
`time + 1` 만큼의 숫자가 non-increasing 이고 `security[i]` 를 중심으로
오른쪽으로 `time + 1` 만큼의 숫자가 non-decreasing 인 `i` 를 구하라.

이 것을 수식으로 표현하면 다음과 같다.

```
security[i - time] >= security[i - time + 1] >= 
... 
>= security[i] <= ... <= security[i + time - 1] <= security[i + time].
```

# Idea

예를 들어 `security = [5,3,3,3,5,6,2], time = 2` 의 경우를 살펴보자.

```
security: 5 3 3 3 5 6 2
          5 3 3 3 5
            3 3 3 5 6
```

따라서 답은 `[2,3]` 이다.

`int[] lefts = new int[n]` 을 선언한다. `lefts[i]` 에 왼쪽에서 오른쪽
방향으로 연속으로 non-increasing 인 것의 개수를 저장한다.

`int[] rights = new int[n]` 을 선언한다. `rights[i]` 에 오른쪽에서
왼쪽 방향으로 연속으로 non-decreasing 인 것의 개수를 저장한다.

이제 임의의 날짜 `i` 에 대해 문제의 조건을 만족하는지 다음을 판단해 본다.

```
lefts[i] >= time && rights[i] >= time
```

예를 들어 `security = [5,3,3,3,5,6,2], time = 2` 의 경우를 다시
살펴보자.

```
security: 5 3 3 3 5 6 2
   lefts: 0 1 2 3 0 0 1
  rights: 0 4 3 2 1 0 0 
              O O
```

따라서 답은 `[2, 3]` 이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
