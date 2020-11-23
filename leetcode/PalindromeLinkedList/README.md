# Problem

[Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

# Idea

링크드 리스트의 노드 `ListNode* h` 가 주어진다. 회문인지 검증하는 문제이다.

예를 들어 `1 2 3 2 1` 과 같이 링크드 리스트의 개수가 홀수인 경우를
살펴보자. `ListNode *s, *f` 를 선언하고 `f->next != NULL &&
f->next->next != NULL` 인 동안 `s` 는 한칸씩 `f` 는 두칸씩
전진한다. `s->next` 부터 순서를 뒤집는다.  그리고 `s->next = NULL` 을
수행하면 두개의 링크드 리스를 얻을 수 있다. 마지막으로 `h` 와
`s->next` 부터 하나씩 비교한다.

다음은 처리과정이다.

```
s              s              s            s
1 2 3 2 1    1 2 3 2 1    1 2 3 2 1    1 2 3 1 2   
f                f                f

      s              s 
1 2 3 1 2    1 2 3 1 2 
h              h       
```

다음은 `1 2 2 1` 과 같이 링크드 리스트의 개수가 짝수인 경우의
처리과정이다.

```
s            s          s            s
1 2 2 1    1 2 2 1    1 2 1 2    1 2 1 2 
f              f                 h

      s     
1 2 1 2     
  h        
```

다음은 링크드 리스트 노드 `ListNode* h: 2 1` 를 뒤집는 과정이다.
`ListNode* b = NULL` 를 선언하여 `h` 의 이전 노드를 저장하고
`ListNode* n` 를 선언하여 `h->next` 를 백업한다. 이것을 `b h n` 으로
외워두면 편리하다.

`h != NULL` 인 동안 다음을 반복한다.

* `n = h->next` 를 수행한다.
* `h->next = b` 를 수행한다.
* `b = h` 
* `h = n`

```
         b                      b
b h      h      b h    b h      h      b h
  2 1    2 1    2 1    2 1    2 1    2 1
    n      n      n        n      n      n
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
