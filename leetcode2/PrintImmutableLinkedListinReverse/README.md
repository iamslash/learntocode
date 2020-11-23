# Problem

[Print Immutable Linked List in Reverse](https://leetcode.com/problems/print-immutable-linked-list-in-reverse/)

# References

* [Jave Solution including Follow Up](https://leetcode.com/problems/print-immutable-linked-list-in-reverse/discuss/436647/Jave-Solution-including-Follow-Up)

# Idea

immutable linked list node `ImmutableListNode` 와 멤버 함수
`getNext(), printValue()` 가 주어진다. 주어진 함수를 이용하여 모든
node 의 value 들을 거꾸로 출력하라.

다음과 같이 여러가지 방법을 생각해 볼 수 있다.

* Recursive way - O(N) O(N)

* Iterative way - O(N) O(N)

* Print from the last node - O(N^2) O(1)

  * `int n` 을 선언하고 node 의 개수를 구하여 저장한다. O(N)
  * 인덱스 `i` 을 선언하고 0 부터 n - 1 까지 순회하여 다음을 반복한다.
    * head 부터 `i` 까지 순회하고 출력한다. 
  
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
