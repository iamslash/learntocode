# Abstract

suffix trie 에 대해 정리한다.

# Data Structure Suffix Trie

접미사들의 배열을 트리 형태로 저장한 자료 구조이다.
접미사들의 배열을 이용하여 문자열 검색 문제를 해결 할 때 주로 사용된다.

예를 들어서 `banana` 의 접미사들은 다음과 같다.

```
banana\0
anana\0
nana\0
ana\0
na\0
a\0
\0
```

이제 이것들을 [trie](/fundamentals/tree/trie/README.md)에 저장하면 다음과 같다.

![](/_img/suffixtrie.png)

suffix trie 는 [trie](/fundamentals/tree/trie/README.md) 를 사용하기 때문에
메모리를 많이 사용한다. 예를 들어서 1000 개의 글자로 구성된 단어의
접미사들로 구성된 suffix trie 를 생각해 보자. 모든 접미사들을 합하면
약 50 만개의 글자들로 구성된다. 한개의 글자는 한개의 `TrieNode` 로 표현되고
한개의 `TrieNode` 는 약 200 바이트가 필요하다. 따라서 50 만개의 글자는
약 100MB 가 필요하다. (`500,000 * 200 = 100,000,000`)

[suffix tree](/fundamentals/tree/suffixtree/README.md)는 suffix trie 보다 메모리를 덜
사용한다. 그러나 구현이 복잡하다. 접미사들을 이용하여 문자열 검색
문제를 해결 할 때는 차라리 [suffix
array search](/fundamentals/string/suffixarraysearch/README.md) 를 사용하자.

# Algorithm Insert

[trie](/fundamentals/tree/trie/README.md) 의 Insert 와 같다.

# Algorithm Find

[trie](/fundamentals/tree/trie/README.md) 의 Find 와 같다.

# Implementation

* [c++11](a.cpp)
