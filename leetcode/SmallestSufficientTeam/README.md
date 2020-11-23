# Problem

[Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/)

# Idea

전체 스킬이름의 모음 `R[]`, 사람별 스킬이름의 모음 `P[][]` 가
주어진다.  전체 스킬을 만족하는 최소의 사람을 모아보자. 그때의
사람들의 모음을 구하는 문제이다.

예를 들어 `R = ["java","nodejs","reactjs"], P =
[["java"],["nodejs"],["nodejs","reactjs"]]` 의 경우를 살펴보자.
`P[0], P[2]` 의 스킬은 `["java", "nodejs", "reactjs"]` 이다.
따라서 답은 `[0, 2]` 이다.

문제의 조건에 의해 `1 <= R.size() <= 16` 이다. 스킬을 비트필드로
표현할 수 있다. `unodered_map<string, int> skill2bm` 을 선언하여
`{skill name : bit field}` 를 저장하자. `unordered_map<int,
vector<int>> bm2people` 를 선언하여 `{bit field : people}` 을
저장하자. rehash 되는 것을 방지하기 위해 `bm2poeple.reserve(1<<n)` 를
수행한다. 또한 `bm2poeple[0] = {}` 을 선언하여 seed 값을 저장한다.

이제 인덱스 `i` 를 이용하여 `P` 를 순회하며 다음을 반복한다.

* `int curbm = 0` 을 선언하여 `P[i]` 가 소유한 스킬을 bit field 로
  저장하자.
* `bm2people` 를 `auto& pr` 을 이용하여 순회하며 다음을 반복한다.
  * `int combm = curbm | pr.first` 를 선언하여 이미 저장된 skill bit
    field 과 `P[i]` 의 skill bit field 를 합쳐서 저장한다.
  * `bm2people.count(combm) == 0` 이거나 `bm2people[combm].size() >
    bm2people[pr.first] + 1` 이면 기존의 사람들 보다 적은 수의
    사람들을 찾는 것이다. `bm2people[combm] = pr.second` 를 수행하고 `i` 를
    추가한다.

모든 반복이 끝나면 `bm2people[(1<<n)-1]` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
