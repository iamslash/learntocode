# Problem

> [Implement Trie II (Prefix Tree)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)

# Idea

다음과 같이 `TrieNode` 를 선언한다.

```
class TrieNode {
  public TrieNode[] next = new TrieNode[26];
  public int termCnt = 0;
  public int fromCnt = 0;
}
```

* `termCnt` 는 해당 node 에서 끝나는 단어들의 개수이다.
* `fromCnt` 는 해당 node 에서 시작하는 단어들의 개수이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
                insert: O(N)
     countWordsEqualTo: O(N)
countWordsStartingWith: O(N)
                 erase: O(N)
```
