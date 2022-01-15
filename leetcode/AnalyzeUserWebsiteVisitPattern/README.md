# Problem

[Analyze User Website Visit Pattern](https://leetcode.com/problems/analyze-user-website-visit-pattern/)

유저의 모음 `U[]`, 사이트의 모음 `W[]`, 시간의 모음 `T[]` 가 주어진다.
가장 많은 유저가 방문한 사이트들의 `1, 2, 3` 위를 구하는 문제이다.

# Idea

예를 들어 `U =
["joe","joe","joe","james","james","james","james","mary","mary","mary"],
T = [1,2,3,4,5,6,7,8,9,10], W =
["home","about","career","home","cart","maps","home","home","about","career"]`
의 경우를 살펴보자. `["home", "maps", "home"]` 의 경우 최소 하나의
유저에 의해 방문되었다.

`map<vector<string>, int> smp_cnts` 를 선언하여 모든 3-seq 의 횟수를
저장한다.

`unordered_map<string, map<int, vector<string>>> ump_history` 를
선언하여 `{user : {time: [site]}}` 를 저장한다.

`vector<string> v` 을 선언하고 `ump_history` 를 순회하면서 site 를 `v`
에 삽입한다. 이제 `v` 를 인덱스 `i, j, k` 를 이용하여 3 중으로
반복하면서 `3-seq` 를 만들어 `smp_cnts` 를 갱신한다.

`smp_cnts` 의 key 중 가장 큰 횟수를 가진 key 가 답이다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
O(N^3) O(N)
```
