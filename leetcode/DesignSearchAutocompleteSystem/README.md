# Problem
> [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system/)

문자열들의 모음 `S[]` 와 출현횟수의 모음 `T[]` 가 주어진다.  한문자
`c` 를 입력받았을 때 마다 자동완성하는 시스템을 구현하는 문제이다.

# Idea

[Trie](/fundamentals/tree/trie/README.md) 를 이용하여 해결할 만 하다.

먼저 다음과 같은 `TrieNode` 를 구현한다.

```java
class TrieNode {
	char ch;
	Map<Character, TrieNode> nextMap = new HashMap<>();
	Map<String, Integer> cntMap = new HashMap<>();
	public TrieNode(Character c) {
		this.ch = c;
	}
}
```

`Map<String, Integer> cntMap` 은 지금까지 방문한 문자열을 접두사로 하는 문장의
출현 횟수이다.

`TrieNode` 가 구성되었다면 임의의 접두사에 대해 그것으로 시작하는 문장의 출현
개수를 얻어올 수 있다. 

`String prefix` 를 member field 로 선언하고 지금까지 입력받은 문자열들을
저장하자. 지금 입력받은 문자 `c` 가 `#` 이면 `prefix` 를 출현횟수 `1` 로 해서
`TrieNode` 에 삽입한다. 그리고 `prefix` 는 비운다.

지금 입력받은 문자 `c` 가 `[a-z]` 혹은 `' '` 이면 `prefix` 에 추가한다. `prefix`
가 Trie 에서 검색되지 않더라도 `#` 이 입력되면 `prefix` 를 Trie 에 삽입해야
하므로 `prefix` 를 유지해야 한다.

`prefix` 가 Trie 에 존재한다면 해당 문자열들을 priority_queue 에 삽입하고 상위 3
개를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
 ctor: O(K*L)
input: O(MlgM)
```
