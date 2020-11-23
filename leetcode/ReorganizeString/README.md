# Problem

* [Reorganize String](https://leetcode.com/problems/reorganize-string/)

# Idea

문자열 `s` 가 주어지면 이웃한 문자열이 갖지 않게 재배치한 문자열을
구하는 문제이다. 만약 그러한 문자열이 없다면 빈 문자열이 답이다.

greedy algorithm 을 이용하여 해결한다. 우선수위큐 `pq` 를 정의한다.
길이 `n` 인 문자열 `s` 가 있다.  소문자 26 개에 대한 빈도수를
저장한다. 그리고 `<빈도수,소문자>` 형태로 `pq` 에 삽입한다.
그리고 `pq` 가 채워있는 동안 다음을 반복한다.

0. `pr1 = pq.top(); pq.pop();`
1. `pr1.second` 가 `r.back()` 과 같으면 빈문자열을 리턴한다.
2. `r.push_back(pr1.second)`
3. `pr2 = pq.top(); pq.pop();`
4. `pr2.second` 가 `r.back()` 과 같으면 빈문자열을 리턴한다.
5. `r.push_back(pr2.second)`
6. `--pr2.first; pq.push(pr2)`
7. `--pr1.first; pq.push(pr1)`

# Implementation

[c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
