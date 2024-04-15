# Problem

숫자들의 배열 `nums` 가 주어지고 크기를 `n` 이라고 하자.  `nums` 의 숫자들중 출현 횟수가 `n/2` 보다 큰 숫자를 찾아라.  그러한 숫자를 `Majority Element` 라고 부르고 반드시 존재한다고 가정하자.

# Idea

다음과 같이 두가지 변수를 기억하자. 

```
majNum: majority number candidate
majCnt: majority number count
```

`nums` 를 처음부터 끝까지 순회하면서 다음을 반복하자.

- 만약 `majNum` 과 다른 숫자가 출현하면 `majCnt` 를 하나 감소하고 `majCnt` 가 `0` 이 되면 `majNum` 을 새로운 숫자로 교체한다.

`majNum` 의 출현 횟수는 반드시 `n/2` 보다 크기 때문에 마지막 까지 순회했을 때 `majCnt` 는 `0` 보다 크거나 같다.

예를 들어 `nums: 1 1 2` 의 경우를 살펴보자. 길이가 3 인 예이다. `2` 의 위치를 옮겨가며 모든 경우를 따져보자.

```
                i
  nums:   2 1 1
majNum: - 2 2 1
majCnt: 0 1 0 1
                i
  nums:   1 2 1
majNum: - 1 1 1
majCnt: 0 1 0 1
                i
  nums:   1 1 2
majNum: - 1 1 1
majCnt: 0 1 2 1
                
The answer is 1
```

예를 들어 `nums: 1 1 2 3` 의 경우를 살펴보자. 길이가 4 인 예이다. 그러나 `1` 의 개수가 `2` 이다. `4 / 2 == 2` 보다 커야 한다. 따라서 조건에 해당하는 예가 아니다. 

# Implementation

- [c++11](a.cpp)
- [java17](MainApp.java)

# Complexity

```
O(N) O(1)
```

# References

- [MajorityElementII](/leetcode/MajorityElementII/)
- [Majority Voting Algorithm](https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html)
- [The Boyer-Moore Majority Vote Algorithm](http://www.cs.rug.nl/~wim/pub/whh348.pdf)
- [Boyer–Moore majority vote algorithm | wikipedia](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
- [MJRTY - A FAST MAJORITY VOTE ALGORITHM](http://www.dtic.mil/dtic/tr/fulltext/u2/a131702.pdf)
