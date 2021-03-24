# Problem

> [Maximum Number of Consecutive Values You Can Make](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/)

수열 `coins[]` 가 주어진다. `coins[i]` 을 짝지어서 `0` 부터 시작하여
하나씩 증가하는 숫자들을 구성해 보자. 그 숫자들이 연속되었을때 최대 그
숫자들의 최대 개수를 구하라.

# Idea

예를 들어 `coins = [1,3]` 의 경우를 살펴보자. 

```
coins: 1 3
    0:
    1: 1
    2: 
```

따라서 답은 2 이다.

이번에는 `coins = [1,1,1,4]` 의 경우를 살펴보자.

```        
coins: 1 1 1 4
    0: 
    1: 1
    2: 1 1
    3: 1 1 1
    4: 4
    5: 1 4
    6: 1 1 4
    7: 1 1 1 4
    8: 
```

따라서 답은 8 이다.

다음과 같은 변수를 선언한다.

> * `ans`: 숫자들을 누적하여 더한 값을 저장한다. `0` 은 무조건 만들 수
>   있으므로 처음 값은 `1` 이다.

먼저 `coins[]` 를 오름차순으로 정렬한다. 

`int coin` 으로 `coins[]` 를 순회하면서 다음을 반복한다.

> * `coin > ans` 이면 `ans` 를 리턴한다.
> * `ans += coin` 을 수행한다. 이제 `ans-1` 는 지금까지 더한 임의의
>   숫자들을 조합하여 만들 수 있다는 의미이다.

모든 반복을 마치면 `ans` 가 곧 답이다. `ans-1` 는 답이 아니다. `ans`
는 개수를 의미하고 `0` 이 기본적으로 하나 포함되기 때문이다.

다음은 `coins = [1,1,1,4]` 의 풀이과정이다.

``` 
               i
coins:   1 1 1 4
  ans: 1 2 3 4 8
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
