# Problem

숫자들의 배열 `nums` 가 주어지고 크기를 `n` 이라고 하자.  `nums` 의 숫자들중
출현 횟수가 `n/2` 보다 큰 숫자를 찾아라.  그러한 숫자를 `Majority Element` 라고
부르고 반드시 존재한다고 가정하자.

# Idea

`nums` 를 처음부터 끝까지 순회하면서 다음을 반복하자.

`Majority Element` 의 후보가 되는 숫자를 `majNum` 에 저장하고 `cnt` 를 하나
증가한다. `cnt` 는 `majNum` 의 출현 횟수를 의미한다.  만약 `majNum` 과 다른
숫자가 출현하면 `cnt` 를 하나 감소하고 `cnt` 가 `0` 이 되면 `majNum` 을 새로운
숫자로 교체한다.

후보자 `majNum` 의 출현 횟수는 반드시 `n/2` 보다 크기 때문에 마지막 까지
순회했을 때 `cnt` 는 0 보다 크거나 같다.

...

다음은 `n` 이 `3` 인 예이다.

```
{1, 1, 2}

i:0 r:1 c:1
i:1 r:1 c:2
i:2 r:1 c:1
```

다음은 `n` 이 `5` 인 예이다.

```
{1, 1, 2, 2, 1}

i:0 r:1 c:1
i:1 r:1 c:2
i:2 r:1 c:1
i:3 r:1 c:0
i:4 r:1 c:1
```

# Implementation

- [c++11](a.cpp)
- [java17](MainApp.java)

# Complexity

```
O(N) O(1)
```

# References

* [Majority Voting Algorithm](https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html)
* [The Boyer-Moore Majority Vote Algorithm](http://www.cs.rug.nl/~wim/pub/whh348.pdf)
* [Boyer–Moore majority vote algorithm @ wikipedia](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
* [MJRTY - A FAST MAJORITY VOTE ALGORITHM](http://www.dtic.mil/dtic/tr/fulltext/u2/a131702.pdf)
