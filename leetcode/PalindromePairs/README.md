# Problem

[Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)

# Idea

문자열의 리스트 `W[]` 가 주어진다. 서로 다른 문자열을 두개를 선택했을
때 회문이 되는 것들의 리스트를 구하는 문제이다.

예를 들어서 `W = ["abcd", "dcba", "lls", "s", "sssll"]` 의 경우를
살펴보자.

```
W = ["abcd", "dcba", "lls", "s", "sssll"]

[0,1] : abcddcba
[1,0] : dcbaabcd
[3,2] : slls
[2,4] : llssssll
```

먼저 문자열을 두개로 분리해본다.  각 경우에 대해서 다음을 반복하자.

* 두번째 문자열이 palindrome 이면 첫번째 문자열을 뒤집어서 뒤로 붙이면
  회문이 된다. 이때 뒤집은 첫번째 문자열은 `W` 에 존재해야 한다.
* 첫번째 문자열이 palindrome 이면 두번째 문자열을 뒤집어서 앞으로
  붙이면 회문이 된다. 이때 뒤집은 두번째 문자열은 `W` 에 존재해야 한다.

```
        "" abcd
        a   bcd
        ab   cd
        abc   d
        abcd "" dcba

   dcba "" abcd
        a   bcd
        ab   cd
        abc   d
        abcd ""
        
        "" lls
        l   ls
        ll   s

        "" lls
        l   ls
      s ll   s
      
        "" sssll
        s   ssll
        ss   sll
        sss   ll
        sssl   l

        "" sssll
        s   ssll
    lls ss   sll
        sss   ll
        sssl   l
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(WS^2) O(WS)
```
