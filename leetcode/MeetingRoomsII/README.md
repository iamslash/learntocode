# Problem

[Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)

이벤트의 모임 `I[][]` 가 주어진다. `I[i][0], I[i][1]` 은 각각 이벤트의
시작과 끝을 의미한다. 이벤트를 수행할 수 있는 최소 회의실의 개수를 구하라.

# Idea

예를 들어 `I = [[0, 30],[5, 10],[15, 20]]` 의 경우를 살펴보자.

```         
   +    -  +   -
+                  -
0  5  10  15  20  30
```


`vector<int> begArr, endArr` 을 선언하여
시작의 모음, 끝의 모음을 각각 저장한다. 그리고 오름차순으로 정렬한다.

`int i, j` 를 선언하여 시작과 끝의 인덱스를 저장한다.

```
     +  +   -   +   -   -         +  +   -   +   -   -      
  I: 0  5  10  15  20  30      I: 0  5  10  15  20  30  
                                  i                     
                                         j              
ans: 0                       ans: 1                     

     +  +   -   +   -   -         +  +   -   +   -   -      
  I: 0  5  10  15  20  30      I: 0  5  10  15  20  30  
        i                                    i                     
            j                            j              
ans: 2                       ans: 2                     

     +  +   -   +   -   -         +  +   -   +   -   -      
  I: 0  5  10  15  20  30      I: 0  5  10  15  20  30  
                i                                      i
                    j                            j              
ans: 2                       ans: 2
```

따라서 답은 `2` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
