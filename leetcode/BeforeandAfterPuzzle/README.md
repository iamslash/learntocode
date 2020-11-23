# Problem

[Before and After Puzzle](https://leetcode.com/problems/before-and-after-puzzle/)

# Idea

문장의 모음 `P[]` 가 주어진다. `P[i]` 의 마지막 단어가 `P[j]` 의
첫번째 단어와 같다면 겹치는 단어는 한번만 사용해서 `P[i] + P[j]` 의
모음을 구하는 문제이다.

예를 들어 다음의 경우를 살펴보자.

```
P = [
  "mission statement",
  "a quick bite to eat",
  "a chip off the old block",
  "chocolate bar",
  "mission impossible",
  "a man on a mission",
  "block party",
  "eat my words",
  "bar of soap"
]
```

두개의 해시맵 `unordered_map<string, set<string>> ump_first, ump_last`
을 제작한다. `P[i]` 의 첫번째 단어를 `first` 마지막 단어를 `last` 라
하자. `set<string> ans` 를 선언하여 답을 저장한다. 그리고 `P[]` 를
순회하면서 다음을 반복한다.

* `ump_first[last]` 를 `s` 라 하자. `s` 가 있다면 `ump_first[last] + s` 
를 답에 추가하자.
* `ump_last[first]` 를 `s` 라 하자. `s` 가 있다면 `s + ump_last[first]` 
를 답에 추가하자.
* `P[i]` 의 `{fist : P[i]}` 를 `ump_first` 에 저장하고
`{last : P[i]}` 를 `ump_last` 에 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
