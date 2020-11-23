# Problem

숫자들의 배열 `V` 가 주어지고 크기를 `N` 이라고 하자.  `V` 의 숫자들중
출현 횟수가 `N/2` 보다 큰 숫자를 찾아라.  그러한 숫자를 `Majority
Element` 라고 부르고 반드시 존재한다고 가정하자.

# Idea

`V` 를 처음부터 끝까지 순회하면서 다음을 반복하자.

`Majority Element` 의 후보가 되는 숫자를 `r` 에 저장하고 `c` 를 하나
증가한다. `c` 는 `r` 의 출현 횟수를 의미한다.  만약 `r` 과 다른 숫자가
출현하면 `c` 를 하나 감소하고 `c` 가 `0` 이 되면 `r` 을 새로운 숫자로
교체한다.

후보자 `r` 의 출현 횟수는 반드시 `N/2` 보다 크기 때문에 마지막 까지
순회했을 때 `c` 는 0 보다 크거나 같다.

...

다음은 `N` 이 `3` 인 예이다.

```
{1, 1, 2}

i:0 r:1 c:1
i:1 r:1 c:2
i:2 r:1 c:1
```

다음은 `N` 이 `5` 인 예이다.

```
{1, 1, 2, 2, 1}

i:0 r:1 c:1
i:1 r:1 c:2
i:2 r:1 c:1
i:3 r:1 c:0
i:4 r:1 c:1
```

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(N)
```

# Space Complexity

```
O(1)
```

# References

* [Boyer–Moore majority vote algorithm @ wikipedia](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
* [MJRTY - A FAST MAJORITY VOTE ALGORITHM](http://www.dtic.mil/dtic/tr/fulltext/u2/a131702.pdf)
