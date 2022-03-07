# Problem

수열 `V` 가 주어지면 오름차순으로 정렬하는 문제이다.

# References

* [[자료구조 알고리즘] 퀵정렬(Quicksort)에 대해 알아보고 자바로 구현하기 @ youtube](https://www.youtube.com/watch?v=7BDzle2n47c)

# Idea

Divide and Conquer 전략을 이용한다.

하나의 기준값을 정하고 이것을 피봇이라고 하자. 수열을 처음부터 순회하면서 피봇보다 작은 녀석들은 수열의 앞쪽으로 피봇보다 큰 녀석들은 수열의 뒤쪽으로 배치한다. 이렇게 하는 것을 파티셔닝이라고 한다. 파티셔닝을 하면서 정렬이 수행된다. 

또한 파티셔닝을 하는 방법에 따라 Hoare 방법과 Lomuto 방법이 있다. Hoare 방법은
수열의 중간에 놓여있는 수를 피봇으로 정한다. Lomuto 방법은 수열의 마지막에
놓여있는 수를 피봇으로 정한다.

파티셔닝후 피봇의 왼쪽으로 놓여있는 수열과 오른쪽으로 놓여있는 수열에 대해 다시
재귀적으로 정렬한다.

다음은 Lomuto partitioning 을 이용한 quicksort 의 과정이다.

```       
                                           j                j
   i         j p      i     j   p          i     p          i     p
V: 5 3 7 6 2 1 4    1 3 7 6 2 5 4    1 3 2 6 7 5 4    1 3 2 4 7 5 6

V: 1 3 2 | 7 5 6    1 2 3 | 5 6 7    1 2 3 4 5 6 7
```

다음은 Hoare paritioning 을 이용한 quicksort 의 과정이다.

```       
   l           r          i                  i                  i
   i     p     j          p   j              j p              j p
V: 5 3 7 6 2 1 4    5 3 4 6 2 1 7    5 3 4 1 2 6 7    5 3 4 1 2 6 7  

V: 5 3 4 1 2 | 6 7  
```

# Implementation

* [c++11](a.cpp)
* [kotlin](MainApp.kt)

# Complexity

```
O(NlgN) O(lgN)
```
