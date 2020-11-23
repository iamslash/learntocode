- [Abstract](#abstract)
- [References](#references)
- [Data Structure TrieNode](#data-structure-trienode)
  - [Keywords](#keywords)
- [Algorithm Insert](#algorithm-insert)
  - [Idea](#idea)
  - [Complexity](#complexity)
- [Algorithm BuildFailLink](#algorithm-buildfaillink)
  - [Idea](#idea-1)
- [Algorithm Search](#algorithm-search)
  - [Idea](#idea-2)
  - [Complexity](#complexity-1)
- [Implementation](#implementation)

-------------------------------------------------------------------------------

# Abstract

ahocorasick algorithm 에 대해 적는다.

# References

* [Aho-Corasick Algorithm for Pattern Searching](https://www.geeksforgeeks.org/aho-corasick-algorithm-pattern-searching/)

# Data Structure TrieNode

문자열 `H` 에서 문자열 `N` 을 검색할 때 효율적인 알고리즘이다. 여러개의 `N` 으로 [trie](/fundamentals/tree/trie/README.md) 를 생성한다.
검색도중 실패하면 처음부터 다시 하지 말고 중간 어딘가에서 부터 다시 한다. 여러개의
바늘들을 동시에 검색하기 때문에 바늘 1 을 찾다가 실패하면 바늘 2 를 찾는
식이다. 다음과 같이 `TrieNode` 를 구성한다.

```cpp
class TrieNode {
    TrieNode* m_next[26];
    // 다음 알파벳을 표현하는 간선의 모음
    int m_term;
    // 현재 노드에서 끝나는 바늘 문자열의 인덱스
    TrieNode* fail;
    // 현재 노드에서 매칭이 실패 했을 때 찾아갈 다음 노드
    vector<int> output;
    // fail을 통해 이 노드까지 왔을 때 검색 가능한 바늘 문자열의 인덱스 모음
}
```

## Keywords

```
TrieNode* m_next;
int m_term;
TrieNode* fail;
vector<int> output;
```

# Algorithm Insert

## Idea

트라이 노드들을 삽입하면서 `m_next` 과 `m_term` 을 채운다.

다음과 같은 부문 문제를 정의하고 재귀 적으로 수행한다.

```cpp
void Insert(const char* key, int order)
key   : 바늘 문자열
order : 바늘 문자열의 인덱스 
```

다음과 같은 여러 가지 경우를 고려하여 재귀적으로 해결한다.

* `*key` 가 NULL이면 `order` 를 `terminal` 에 저장하자.
* `*key` 가 NULL이 아니면 `Insert(key + 1, order)` 하자.

## Complexity

```
O(M) O(M)

M : sum(N.size())
```

# Algorithm BuildFailLink

## Idea

트라이 노드들을 BFS 순회하면서 `fail` 과 `output` 을 채운다.

```cpp
void BuildFailLink(TrieNode* root)
```

queue 에 저장된 노드 `u` 의 자식들을 탐색 하면서 다음과 같은 반복을
수행한다.

* 탐색된 자식을 `v` 라 하고 `u` 와 `v` 의 간선에 해당하는 알파벳을
  `edge` 라 하자. `u` 가 루트 노드라면 `v->fail` 은 루트 노드이다.
* `u` 가 루트 노드가 아니라면 `u` 의 `fail` 에 해당하는 노드 `f` 를
  찾는다. `f` 는 루트 노드도 아니고 `f->children[edge]` 는 `NULL` 인 동안에
  `f` 에 `f->fail` 을 저장한다. 만약 `f->children[edge]` 가 `NULL` 이 아니면
  `f` 에 `f->children[edge]` 를 저장한다. 이후 `v->fail` 에 `f` 를 저장한다.
* `v->output` 에 `v->fail->output` 을 저장한다. `v->terminal` 이 `-1` 이
  아니면 `v->output` 에 `v->terminal` 을 추가한다.
* 다음 BFS를 위해 `v` 를 queue에 삽입한다.

![](/_img/ahocorasick2.png)

예를 들어 노드 4의 경우를 생각해 보자. `u` 는 노드 4, `v` 는 노드 5,
`edge` 는 `e` 이다.  이제 `v->fail` 을 채워보자. 초기 `f` 는 노드 1
이다. `f` 가 루트도 아니고 `t->children[edge]` 가 NULL이 아니므로 `f` 는
노드 2 이다. 그러므로 `v->fail` 에 노드 2를 저장하자.  5 노드의
`output` 에 2 노드의 output 을 저장하고 5 노드의 `terminal` 이 `-1` 이
아니므로 5 노드의 output 에 `she` 를 추가 한다.

# Algorithm Search

## Idea

예를 들어 다음 그림과 같이 바늘들 `he, she, his, hers` 의 Trie 를
구성해 보자.

![](/_img/ahocorasick1.png)

그리고 각 노드들에 대해서 다음 단어가 예상 단어가 아니라면 다른 노드를
찾아가는 failure link를 구성해보자.

![](/_img/ahocorasick2.png)

`shis` 가 짚더미중 일부라고 해보자. `sh` 다음에 `e`가 오지 않고 `i` 가
왔으므로 failure link 에 의해 `4` 노드 대신 `1` 노드로 간다. 이후 `is` 가
오기 때문에 `his` 를 검색 할 수 있다.

KMP 역시 짚더미에서 바늘을 찾을 때 바늘의 partial match table 을 만들어
검색중 실패시 처음부터 다시 하지 않고 중간 어딘가에서 부터 다시 한다.
그러나 ahocorasic algorithm 을 이용하면 여러 바늘을 동시에 검색 할 수
있기 때문에 시간 복잡도를 더욱 줄일 수 있다.

## Complexity

```
O(N + M + P) O(M)

N : H.size()
M : sum(N.size())
P : 바늘 문자열 출현의 횟수
```

# Implementation

* [c++11](a.cpp)