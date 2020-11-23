# Problem

[Text Justification](https://leetcode.com/problems/text-justification/)

문자열의 모음 `W[]` 와 숫자 `maxWidth` 가 주어진다. 한 줄의 길이는
`maxWidth` 이다. `W[i]` 를 한 줄의 길이를 넘지 않도록 배치한다. 단어의
사이는 공백으로 채운다. 완성된 문자열을 구하라.

# Idea

`int i` 를 선언하여 `W[]` 를 순회한다. `int k` 를 선언하여
방문한 줄에서 단어의 인덱스를 저장한다. `int len` 를 선언하여
방문한 줄에서 공백을 제외한 문자열들의 길이를 저장한다. 

`k` 를 이용하여 이번에 방문한 줄에 몇개의 단어를 배치하는 것이
가능한지 조사한다. 이것을 probe and forward 라고 하자.

`k` 값이 확정되면 `string line = W[i]` 을 선언한다.  `int j` 를
선언하여 `[0..k-1)` 를 순회하며 `k-1` 개의 공백과 단어를 저장한다.

`maxWidth - len` 은 이번에 방문한 줄의 공백의
개수이다. `(maxWidth-len) / (k-1)` 은 `line` 에 추가할 단어들 앞에 올
공백의 개수를 구할 수 있다. 이때 `j < (maxWidth-len)%(k-1)` 이면
공백을 하나 더 채운다. 문제의 조건에 의해 공백의 개수가 정확히
나누어지지 않으면 앞에 있는 단어부터 하나 더 채워야 한다.

마지막에 공백이 필요하면 `line` 에 채운다. 그리고 `vector<string> ans`
에 `line` 을 삽입한다. 

모든 반복을 마치면 `ans` 가 곧 답이다.

예를 들어 `W = ["This", "is", "an", "example", "of", "text",
"justification."]  maxWidth = 16` 의 경우를 살펴보자.

```
   n: 7
         i
   W: This is an example of text justification.
                       k
         j                 
 len: 8
line: This
 
"This    is    an"
"example  of text"
"justification.  "


```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
