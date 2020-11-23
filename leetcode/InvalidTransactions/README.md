# Problem

[Invalid Transactions](https://leetcode.com/problems/invalid-transactions/)

# Idea

`name, time, amount, city` 로 구성된 문자열의 모음 `T[]` 가 주어진다.
이것들 중 invalid transaction 들을 구하는 문제이다.

문제의 조건에 의해 다음과 같은 문자열을 invalid transaction 이라 한다.

* amount 가 $1000 을 초과 하였느냐
* 서로 다른 city 에서 60 분 내에 트랜잭션이 발생했느냐

예를 들어 `T = ["alice,20,800,mtv","alice,50,100,beijing"]` 인 경우를
살펴보자. `mtv, beijing` 에서 `30` 사이에 트랜잭션이 발생했으므로 답은 
`["alice,50,1200,mtv"]` 이다.

`unordered_set<string> ust_inval` 을 선언하여 invalid transaction 을
저장한다. `unordered_map<string, vector<vector<string>> ump_trns` 를
선언하여 `{name, {{name, time, amount, city},...}}` 를 저장한다.

이제 `T` 를 순회하면서 `name, time, amount, city` 를 얻어올 수 있다.
이것을 `t` 라 하자.  그리고 `t[2] > 1000` 인지 검증한다. 같은 이름의
트랜잭션 데이터를 `ump_trns[name]` 으로 구할 수 있다. 이것을 `v` 라
하자.  `t[3] != v[3]` 이면 서로 다른 city 를 의미한다. `abs(stoi(t[2])
-stoi(v[2])) <= 60` 를 검사하여 60 분 내에 발생한 트랜잭션인지
검증한다.

마지막으로 `vector<string>(ust_inval.begin(), ust_inval.end())` 가
답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
