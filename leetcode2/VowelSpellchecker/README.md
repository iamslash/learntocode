# Problem

[Vowel Spellchecker](https://leetcode.com/problems/vowel-spellchecker/)

# Idea

문자열의 모음 `W[], Q[]` 가 주어진다. `Q[i]` 에 대해서 대소문자를
무시하고 일치하는 단어가 `W[]` 에 있다면 `W[j]` 를 구한다. 그렇지 않고
모음을 무시하고 일치하는 단어가 `W[]` 에 있다면 `W[k]` 를 구하는
문제이다.

먼저 정확히 일치하는 단어가 있는지 검사하기 위해 `set<string> wordset`
을 선언하고 `W[]` 를 삽입한다. 그리고 대소문자를 무시하고 일치하는
단어를 검사하기 위해 `unordered_map<string, string> lower2word` 를
선언하고 `{tolower(W[i]): W[i]}` 를 삽입한다. 마지막으로 모음을
무시하고 일치하는 단어를 검사하기 위해 `unordered_map<string, string>
norm2word` 를 선언하고 `{tonorm(W[i]): W[i]}` 를 삽입한다.

이때 `tolower` 는 하나의 문자열을 받아 모두 소문자로 바꾼 문자열을
리턴하고 `tonorm` 은 하나의 문자열을 받아 모음을 모두 `#` 으로 바꾼
문자열을 리턴하도록 한다.

`lower2word, norm2word` 에 없는 문자열은 공백을 리턴해야 한다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(max(W,Q)) O(W)
```
