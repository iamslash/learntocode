# Problem

[Number of Sub-arrays With Odd Sum](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)

수열 `A[]` 가 주어진다. 부분 수열들 중 합이 홀 수 인 것들의
개수를 구하라.

# Idea

예를 들어 `A[1, 3, 5]` 의 경우를 살펴보자.

`int odd[]` 를 선언하여 `A[i]` 로 끝나는 부분수열들 중 합이 홀 수 인
것을 저장한다. `int even[]` 를 선언하여 `A[i]` 로 끝나는 부분수열들 중
합이 짝수 인 것을 저장한다. 그렇다면 다음과 같은 규칙을 생각해 낼 수 있다.

* `A[i]` 가 홀수 이면
  * `odd[i] = even[i-1] + 1` 
    * `A[i-1]` 로 끝나고 합이 짝수인 subarray 에 홀수인 `A[i]` 를
      하나씩 끼워 넣은 것이다.
  * `even[i] = odd[i-1]`
* `A[i]` 가 짝수 이면
  * `odd[i] = odd[i-1]`
  * `even[i] = even[i-1] + 1`
    * `A[i-1]` 로 끝나고 합이 짝수인 subarray 에 짝수인 `A[i]` 를
      하나씩 끼워 넣은 것이다.
      
`odd[i], even[i], odd[i-1], even[i-1]` 만 필요하기 때문에 `odd[],
even[]` 대신 `odd, even` 으로 충분하다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
