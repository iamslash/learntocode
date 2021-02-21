# Problem

[Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)

수열 `A` 가 주어진다. `A[]` 를 합이 같은 두개의 subsequence
로 나눌 수 있는 검증하라.

# Idea 

[0/1 knapsack](/fundamentals/dynamicprog/knapsack01/README.md) 과
비슷하다. 하나의 동전을 여러번 사용할 수는 없다. 하나의 동전을 한번만
사용할 수 있다는 점을 주의하자.

`int half` 를 선언하여 `A[]` 의 합을 구하고 그것의 절반을 저장한다.
만약 `A[]` 의 합이 홀수 이면 2 개의 subsequence 로 나눌 수 있는 방법은
없다.  false 를 리턴하자.

`vector<bool> C(half)` 를 선언하고 `C[amount]` 에 subsequence 의 합이
`amount` 인 것을 만들 수 있는지 여부를 저장한다. `C[]` 를 모두 채우면
`C[half]` 가 답이다. seed 를 위해 `C[0] = true` 를 수행한다.

`int num` 으로 `A[]` 을 순회하며 다음을 반복한다.

* 인덱스 `amount` 를 선언하여 `[half..0)` 를 순회하며 다음을 반복한다.
  * `amount >= num` 이면 `C[amount] = C[amount] || C[amount - A[i]]`
    를 수행한다.
  
모든 반복을 마치면 `C[half]` 가 곧 답이다.

다음은 `A [5, 2, 1]` 의 풀이과정이다.

```
   i             i           i
A: 5 2 1       5 2 1       5 2 1
C: t f f f f   t f f f f   t f t f f
           a           a       a
           
       i           i    
A: 5 2 1       5 2 1     
C: t f t t f   t t t t f
         a       a      
```

따라서 답은 false 이다.
 
# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(SN)
S: half of A's sum
N: length of A
```
