# Problem

> [Maximum Subarray Min-Product](https://leetcode.com/problems/maximum-subarray-min-product/)

수열 `nums[]` 가 주어진다. min-product 를 다음과 같이 정의한다.

* 수열의 합을 구하고 `sum` 이라고 하자.
* 가장 작은 원소를 `min` 이라고 하자.
* min-product 는 `sum * min` 을 말한다.

`nums[]` 의 부분수열들 중 min-product 가 가장 큰 것을 찾아서 구하라.

# Idea

예를 들어 `nums = [1,2,3,2]` 의 경우를 살펴보자.

```
                   _____
           nums: 1 2 3 2

max min-product: (2 + 3 + 2) * 2
```

따라서 답은 `14` 이다.

[mono stack](/doc/mono_stack.md) 을 이용하여 해결할 만 하다. [mono stack](/doc/mono_stack.md) 에 min-product 의 min 에 해당하는 인덱스를 저장한다고 생각해 보자. `nums[]` 를 방문하는 인덱스를 `i` 라고 할 때 `stck` 에 하나 꺼낸 인덱스는 `j` 라고 하자. `nums[j]` 는 min-product 의 min 을 의미한다. `stck.peek()` 은 부분수열의 시작 인덱스를 의미하고 `i` 는 부분수열의 끝 인덱스를 의미한다. 부분수열의 시작과 끝 인덱스를 알았으니 합을 구할 수 있다. 그리고 그것을 `nums[j]` 와 곱하면 min-product 가 된다. 이때 부분수열의 합은 [partial sum](/fundamentals/partialsum/partialsum/README.md) 을 이용하여 수월히 구현할 수 있다.

`int MOD = 1_000_000_007` 을 선언하여 마지막 답에 modulo 연산을 수행한다. `int n = nums.length` 를 선언하여 `nums` 의 길이를 저장한다. 

`Stack<Integer> stck = new Stack<>()` 를 선언하여 `nums[]` 의 인덱스를 저장한다. 이때 인덱스에 해당하는 값들은 오름차순으로 정렬되어 있다. 

`long ps[] = new long[n+1]` 을 선언하여 `nums[]` 의 partial sum 을 저장한다. 

인덱스 `i` 를 `[0..n]` 동안 순회하면서 다음을 반복한다. 이때 `i` 는 `ps[]` 의 인덱스이기 때문에 보통 사용했던 인덱스보다 하나가 크다.

* `!stack.empty()` 이고 `i == n` 혹은 `nums[stck.peek()] > nums[i]` 이면 다음을 반복한다.
  * `int j` 를 선언하여 `stck` 에서 인덱스를 하나 꺼내 저장한다. `nums[j]` 는 부분수열의 값들 중 가장 작은 값이 된다.
  * `int k = 0` 를 선언하여 `ps[]` 의 시작 인덱스를 저장한다. `stck` 이 비어있지 않으면 `stck.peek() + 1` 을 저장한다.
  * `long sum` 을 선언하여 부분수열의 partial sum 을 저장한다. 즉, `ps[i] - ps[k]` 을 저장한다.
  * min-product 를 구했으므로 `ans` 를 업데이트한다. 즉, `ans = max(ans, sum * nums[j])` 를 수행한다.
* `stck` 에 `i` 를 삽입한다. 마지막에 `i` 를 삽입하면 `n` 을 삽입한 것과 같다. `n` 은 `nums[]` 에 없는 인덱스이다. 그러나 `stck` 에 `n` 을 삽입하고 loop 을 탈출하기 때문에 문제가 없다. 이렇게 구현하면 loop 를 simplify 할 수 있다.

모든 반복을 마치면 `(int)(ans % MOD)` 가 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
