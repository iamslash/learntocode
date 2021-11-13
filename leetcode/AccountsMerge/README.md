# Problem

[Accounts Merge](https://leetcode.com/problems/accounts-merge/)

이름과 이메일의 모음 `accounts[][]` 가 주어진다.  `accounts[i][0]` 은
이름이다. `accounts[i][1..n-1]` 은 이메일이다. 같은 이메일을 갖는
이름은 같은 사람이다. 이름이 같더라도 같은 이메일을 가지고 있지 않다면
동명이인이다.  이것을 같은 사람끼리 merge 하고 유일한 이름과 이메일의
목록의 모음을 구하라.

# Idea

예를 들어 `accounts =
[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]`
의 경우를 살펴보자.

```
accounts : John,johnsmith@mail.com,john_newyork@mail.com
           John,johnsmith@mail.com,john00@mail.com
           Mary,mary@mail.com
           John,johnnybravo@mail.com
           
      ans: John,john00@mail.com,johnsmith@mail.com,john_newyork@mail.com
           Mary,mary@mail.com
           John,johnnybravo@gmail.com
```

부모 email 이 있고 그 밑에 자식 email 들이 있다고 생각해 보자.  그
부모 email 의 name 을 알 수 있다면 name 을 기준으로 merg 된 email 들의
목록을 얻어올 수 있다. [Disjoint Set](/fundamentals/disjointset/unionfind/README.md) 으로 해결할 만 하다.

* `Map<String, String> ownerMap` 을 선언하여 `{email: name}` 을 저장한다.
* `Map<String, String> parentMap` 을 선언하여 `{email: email}` 을 저장한다.
* `Map<String, TreeSet<String>> mergedMap` 을 선언하여 `{email: {email,...}}` 을 저장한다.

`mergedMap` 은 부모 email 과 자식 email 들의 모음이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
