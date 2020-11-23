# Problem

[Minimum Number of Days to Disconnect Island](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/)

그래프 `G[][]` 가 주어진다. `1` 은 섬을 의미하고 `0` 은 바다를
의미한다. 섬을 절단 하기 위해 임의의 `1` 을 `0` 으로 바꾼다.
이때 절단 하기 위해 필요한 최소 교체 횟수를 구하라.

# Idea

잘 생각해 보면 최대 `2` 개를 교체하면 어떤 섬도 절단할 수 있다.
따라서 답은 `0, 1, 2` 중 하나이다.

먼저 `1` 이 없으면 답은 `0` 이다.

`1` 이 하나라도 있으면 임의의 `1` 을 `0` 으로 수정하고 dfs all
을 수행한다. dfs all 이 두번 수행되면 섬은 절단되어 있기 때문에
답은 `1` 이다.

그렇지 않으면 답은 `2` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
