# Problem

[Find the Most Competitive Subsequence](https://leetcode.com/problems/find-the-most-competitive-subsequence/)

수열 `A[]` 와 숫자 `k` 가 주어진다. `A[]` 의 subsequence 들 중 `k`
개인 것들을 나열한다. 그것들 중 가장 competitive 한 것을 구하라.

`B[]` 가 `C[]` 보다 competitive 하다는 의미는 `B[i]` 가 `C[i]` 보다
작은 것이 존재한다는 의미이다. 예를 들어, `[1, 3, 4]` 는 `[1, 3, 5]`
보다 competitive 하다.

# Idea

monotone increasing stack 을 이용하여 해결할 만 하다.

`vector<int> stck` 를 선언하여 답을 저장한다. 그리고 첫번째 숫자가
작고 모든 숫자가 오름차순이 되도록 유지한다.

예를 들어, `A = [3, 5, 2, 6], k = 2` 인 경우를 생각해보자.

```
   k: 2            
                      i                  i      
   A: 3 5 2 6      A: 3 5 2 6       A: 3 5 2 6
stck:           stck: 3          stck: 3 5       

          i                 i      
   A: 3 5 2 6      A: 3 5 2 6    
stck: 2         stck: 2 6         
```

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `stck.size() > 0` 이고 `stck.back() > A[i]` 이고 앞으로 순회할
  숫자들의 개수와 `stck().size() - 1` 의 합이 `k` 보다 크거나 같은
  동안 `stck.pop_back()` 를 수행한다. `stck` 는 첫번째 원소는 최소이고
  각 원소들은 오름차순으로 유지된다.
* `stck.size() < k` 이면 `stck` 에 `A[i]` 를 삽입한다.

모든 반복을 마치면 `stck` 는 `k` 개가 된다. `stck` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
