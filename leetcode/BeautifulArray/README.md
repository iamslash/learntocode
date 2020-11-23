# Problem

[Beautiful Array](https://leetcode.com/problems/beautiful-array/)

# Idea

숫자 `N` 이 주어진다. 모든 `i < j` 에 대하여 `i < k < j` 이고 
`A[k] * 2 = A[i] + A[j]` 를 만족하는 `k` 가 존재하지 않는
수열을 구하는 문제이다.

여러가지 방법이 있겠지만 가장 수월한 접근으로 해보자.
`N = 10` 일 때를 살펴보자. `i < k < j` 이므로 `K = [1..9]` 이다.
`A[k] * 2` 는 짝수다. 따라서 `A[i]` 는 홀 수, `A[k]` 는 짝 수 이면
`A[i] + A[k] = 홀수` 이므로 `A[k] * 2` 와 같을 수 없다.

이것을 종합해서 생각해보면 `N` 이 주어질 때 `[1..N]` 의 숫자들을
왼쪽은 홀 수 오른쪽은 짝수로 배치하면 답을 구할 수 있다.

그렇다면 벡터 `vector<int> num = {1}` 를 선언하고
`num.size() <= N` 동안 다음을 반복한다.

* `vector<int> tmp` 를 선언한다.
* `num` 을 다시 순회 하면서 `num[i] * 2 - 1` 을 `tmp` 에 삽입한다. 이것은
  홀 수 수열을 왼쪽에 배치하는 일이다.
* `num` 을 다시 순회 하면서 `num[i] * 2` 을 `tmp` 에 삽입한다.
  이것은 짝 수 수열을 오른쪽에 배치하는 일이다.
* `num = tmp` 를 수행한다.
 
# Implementation

* [c++11](a.cpp)

# Comlexity

```
O(N) O(N)
```
