# Problem

[Delete Columns to Make Sorted II](https://leetcode.com/problems/delete-columns-to-make-sorted-ii/)

# Idea

문자열의 모음 `A[]` 가 주어진다. 모든 `A[i]` 에 대하여 `A[i][j]`를
삭제 했을 때 `A[0] <= A[1] <= A[2] ... <= A[n-1]` 를 만족하도록
해보자. 이때 삭제한 인덱스의 개수가 최소가 되엇을 때 그 개수를 구하는
문제이다.

brute force 로 해결해 보자. 먼저 `unordered_set<char> D` 를
선언하여 삭제 하길 원하는 `j` 를 저장하자. 

* 인덱스 `i` 를 `[1..n)` 동안 순회하면서 다음을 반복한다. 
  * 인덱스 `j` 를 `[0..A[i].size())` 동안 순회하면서 다음을 반복한다.
    * `D.count(j) || A[i-1][j] == A[i][j]` 이면 이미 `j` 는
    삭제되었거나 사전순이 같다. 다음문자를 검증하기 위해 continue 한다.
    * `A[i-1][j] > A[i][j]` 이면 사전순이 아니기 때문에 `j` 는
    삭제해야 한다. `D.insert(j)` 를 수행한다. `j` 를 삭제했으므로 `i`
    는 1 부터 다시 검증한다. `i = 0` 을 수행하자.
    * 인덱스 `j` loop 를 종료하기 위해 break 하자.

모든 반복을 마치면 `D.size()` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(MN) O(N)
```
