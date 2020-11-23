# Problem

[Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

문자열 `s` 가 주어진다.  문자의 발생횟수가 unique 가 되도록 발생횟수를
줄여 보자. 최소로 줄일 수 있는 횟수를 구하라.

# Idea

`vector<int> freqs(26)` 를 선언하여 문자의 발생횟수를 저장한다.
`unordered_set<int> used` 를 선언하여 방문한 발생횟수를 저장한다.
`ans` 를 선언하여 답을 저장한다.

이제 인덱스 `i` 를 이용하여 `[0..26)` 를 순회하며 다음을 반복한다.

* `freqs[i]` 가 `used` 에 이미 있다면 발생횟수를 삭제해야 한다. unique 할 때까지
  `freqs[i]` 를 하나씩 감소한다. 감소할 때 마다 `ans` 를 증가한다.
* `freqs[i]` 를 `used` 에 삽입한다.

모든 반복을 마치면 `ans` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
