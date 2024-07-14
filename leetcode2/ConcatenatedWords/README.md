# Problem

[Concatenated Words](https://leetcode.com/problems/concatenated-words/)

문자열의 모음 `words` 가 주어진다. `words` 를 구성하는 단어들 중 다른 단어 두개 이상으로 조합된 단어들을 구하라.

# Idea

예를 들어 `W = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]` 인 경우를 살펴보자.

`unordered_set<string> wordSet` 를 선언하여 결합된 문자열을 구성할 문자열들을 저장한다.

먼저 `W` 를 길이의 오름차순으로 정렬한다.

```
["cat", "dog", "rat", "cats", "dogcatsdog", "catsdogcats", "ratcatdogcat", "hippopotamuses"]
```

`int minLen` 을 선언하여 `W[0]` 의 길이를 저장한다. 이제 결합된 문자열의 최소길이는 `minLen * 2` 보다 크거나 같아야 한다.

인덱스 `i` 를 이용하여 `W` 를 처음부터 끝까지 순회하며 다음을 반복한다.

* 인덱스 `j` 를 이용하여 `W[i]` 를 `W[i..j), W[j..]` 형태로 나눈다. `W[i..j)` 가 `wordSet` 에 존재한다면 다시 `W[j..]` 를 비슷한 방법으로 `W[j..k), W[k..)` 으로 나누고 `W[j..k)` 가 `wordSet` 에 존재하는지 확인한다. 
  * [WordBreak](/leetcode2/WordBreak/README.md) 로 해결할 만 하다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N*S^3) O(NS)
  N: count of words
  S: avg length of each word
```
