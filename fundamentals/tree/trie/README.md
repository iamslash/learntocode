- [Abstract](#abstract)
- [Keywords](#keywords)
- [Data Structure Trie](#data-structure-trie)
- [Algorithm Insert](#algorithm-insert)
  - [Idea](#idea)
  - [Complexity](#complexity)
- [Algroithm Find](#algroithm-find)
  - [Idea](#idea-1)
  - [Complexity](#complexity-1)
- [Implementation](#implementation)

----

# Abstract

Trie 에 대해 정리한다.

# Keywords

```
TrieNode, m_next, m_term, 
insert, find
```

# Data Structure Trie

![](/_img/trie.png)

Trie 는 문자열 검색을 쉽게 하기 위한 트리 형태의 자료구조이다. 트리의
각 노드는 TrieNode 라고 정의하고 다음과 같은 두가지 멤버 변수를 갖는다.

```
TrieNode* m_next[26];
bool m_term;
```

영문자의 종류는 `26` 가지 이므로 `m_next[]` 크기가 26 개이다. `m_term` 은 `TrieNode` 가 단어의 마지막 글자인지 여부이다.  

64-bit system 에서 포인터는 8 byte 이다. 하나의 TrieNode 는 26 개의
`TrieNode*` 를 자식으로 갖는 형태이기 때문에 `8 * 26 = 208` 바이트가
필요하다. 

하나의 TrieNode 를 표현하는데 약 200 바이트가 필요하다고 가정해보자.
Trie 에 저장할 문자열들의 합이 1 백만 일때 약 200 MB (`1,000,000 * 200 =
200,000,000 bytes`)가 필요하다.  메모리가 너무 많이 필요하다. 문자열의
개수가 얼마 되지 않을때 만 사용 가능한 자료 구조이다.

`void insert(const char* s)` 를 정의하여 문자열을 삽입할 때 호출한다. `void find(const char* s)` 를 정의하여 문자열을 검색할 때 호출한다.

# Algorithm Insert

## Idea

단어를 입력 받아 TrieNode 를 생성한다. 부분 문제를 다음과 같이 정의하고 재귀적으로 구현한다.

```cpp
void insert(const char* s)
```

* `*s == NULL` 이면 문자열의 종료를 의미한다. `m_term = true` 를 수행하고 리턴한다.
* `int i = *s - 'a'` 를 선언하여 `*s` 의 `TrieNode*` 인덱스를 저장한다. `!m_next[i]` 이면 `TrieNode` 를 할당하여 저장한다.
* `m_next[i]->insert(s+1)` 를 수행한다.

## Complexity

```
O(S) O(S)

S: size of s
```

# Algroithm Find

## Idea

단어를 입력 받아 `TrieNode*` 를 리턴한다. 부분 문제를 다음과 같이 정의하고 재귀적으로 구현해 보자. 리턴된 값의 `m_term` 을 확인하면 문자열이 있는지 검증할 수 있다.

```cpp
TrieNode* find(const char* s)
```

* `*s == NULL` 이면 문자열의 종료를 의미한다. `this` 를 리턴한다. 
* `int i = *s - 'a'` 를 선언하여 `*s` 의 `TrieNode*` 인덱스를 저장한다. `!m_next[i]` 이면 해당 문자열은 없다는 의미이다. `NULL` 을 리턴하자.
* `m_next[i]->find(s+1)` 를 리턴한다.

## Complexity

```
O(S) O(S)

S: size of s
```

# Implementation

* [c++11](a.cpp)
  