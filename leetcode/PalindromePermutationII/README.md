# Problem

* [Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/)

# Idea

문자열 `s` 가 주어진다. 회문이 가능한 순열을 구하는 문제이다.

맵 `unordered_map<char, int> ump` 를 선언한다.  `s` 를 순회하면서
`ump[c]++` 를 수행한다. `ump[c]` 가 홀수인 것이 두개이상 존재하면 답은
없다.

`ump{}` 를 순회하면서 `ump[c]` 를 두개 제거하고 두개 복구하는 방식으로
backtracking 한다. 맵을 사용했기 때문에 backtracking 을 하더라도
반복된 순열은 발생하지 않는다.

`s = aabbbb` 인 경우 `ump{} = {a:2, b:4}` 이다. `ump[c]` 를 2 개씩
제거하고 복구하는 방식으로 backtracking 을 하면 다음과 같다.

```
{a:0, b:4}     a    {a:2, b:2}     b                
              /                   / \
{a:0, b:2}   b      {a:0, b:2}   a   b
            /                   /     \
{a:0, b:0} b        {a:0, b:0} b       a
```

`s = aabbbb` 인 경우 recursion tree 와 답은 다음과 같다.

```
0 {b:4} {a:2} 
_1 {b:2} {a:2} 
__2 {b:0} {a:2} 
___3 {b:0} {a:0} 
__2 {b:2} {a:0} 
___3 {b:0} {a:0} 
_1 {b:4} {a:0} 
__2 {b:2} {a:0} 
___3 {b:0} {a:0} 
bbaabb
babbab
abbbba
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O((N/2)!) O(N)
```
