# Problem

[Best Team With No Conflicts](https://leetcode.com/problems/best-team-with-no-conflicts/)

수열 `scores[], ages[]` 가 주어진다. 임의의 사람으로 팀을 구성해
보자. 나이가 적은 사람은 나이가 많은 사람보다 큰 점수를 획득할 수
없다. 최대의 점수를 획득할 수 있도록 했을 때 그 점수를 구하라.

# Idea

`vector<pair<int, int>> scoreAges` 를 선언하고 `{ages[i], scores[i]}`
를 저장한다. `scoreAges` 를 내림차순으로 정렬한다.

`vector<int> C(n)` 를 선언한다. `C[i]` 는 `[0..i-1]` 사람들을 대상으로
팀을 구성했을 때 최대의 점수이다. `int ans` 를 선언하여 답을 저장한다.

인덱스 `i` 를 이용하여 `[0..n)` 동안 순회하며 다음을 반복한다.

* `int socre = scoreAges[i].second` 를 선언한다.
* `C[i] = score` 를 수행한다.
* 인덱스 `j` 를 이용하여 `[0..i)` 를 순회하며 다음을 반복한다.
  * `scoreAges[j] >= score` 이면 j-번째 사람을 팀에 포함시킬 수
    있다. `C[i] = max(C[i], C[j] + score)` 를 수행한다.
* `ans = max(ans, C[i])` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
