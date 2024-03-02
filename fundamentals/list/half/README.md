# Problem

singly linked list 가 주어진다. `len(a) == len(b) or len(a) == len(b) + 1` 
를 만족하는 두개의 리스트로 분리하자. 두번째 리스트를 리턴하라.

```
Input:
  1 2 3 4
Output: 
  3 4

Input:
  1 2 3 4 5
Output:
  4 5
```

# Idea

다음과 같이 `p = head, q = head` 를 선언한다. 
`q.next != null && q.next.next != null` 동안 다음을 반복한다.

- `p = p.next`
- `q = q.next.next`

```   
  p    
1 2 3 4
    q

    p    
1 2 3 4 5
        q
```

모든 반복을 마치면 `p.next` 가 곧 답이다.

# Implementation

* [java17](MainApp.java)
