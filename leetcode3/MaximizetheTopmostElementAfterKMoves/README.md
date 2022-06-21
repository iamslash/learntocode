# Problem

[Maximize the Topmost Element After K Moves](https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/)

수열 `nums[]`, 숫자 `k` 가 주어진다.

`nums[]` 에 다음과 같은 동작을 `k` 번 할 수 있다.

* `nums[0]` 를 하나 제거한다.
* `nums[]` 제거 된 숫자를 에 다시 삽입한다.

`k` 번 수행후 `nums[0]` 이 최대가 되도록 해보자. 그 최대 숫자를
구하라.

# Idea

예를 들어 `nums = [5,2,2,4,0,6], k = 4` 의 경우를 살펴보자.

```
   k: 4
nums: 5 2 2 4 0 6
      2 2 4 0 6     5
      2 4 0 6       5 2
      4 0 6         5 2 2
      5 4 0 6       2 2
```

따라서 답은 `5` 이다.

한가지 주의 사항은 제거된 숫자를 `nums[]` 에 삽입할 때도 `k` 가 하나
줄어든다는 것이다.

`k, n` 의 다양항 edge cases 들을 신경써야 한다. 

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
