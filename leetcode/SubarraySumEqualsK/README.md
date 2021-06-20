# Problem

[subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

수열 `A[]` 와 숫자 `K` 가 주어진다. `A` 의 subarray 중 합이 `K` 와
같은 것들의 개수를 구하는 문제이다.

# Idea

예를 들어 `A = 1 1 1, K = 2` 인 경우 `i == 2` 일 때를 살펴보자.

```
         _
      A: 1 1 1
             i
    sum: 1 2 3
freqMap: 0 1
         1 1
    cnt: 0 1 2 
```

* 인덱스 `i` 를 이용하여 `[0..A.length]` 동안 순회한다.
* `int sum` 을 선언하고 `A[0]` 부터 `A[i]` 까지 더하여 저장한다. `sum` 에 `A[i]`
  가 합하여 질 때 마다 map 에 그 발생횟수를 저장한다. 이때 사용한 map 을
  `Map<Integer, Integer> freqMap` 이라고 하자. 참고로 `i == 2` 일 때 `sum == 3`
  이다.
* `freqMap` 은 seed 값이 필요하다. `freqMap[0] = 1` 을 수행한다.
* `sum - K` 를 freqMap 에서 검색한다. 그 수가 1 이라는 것은 `A[2]` 를 포함한
  subarray 중 합이 `K` 인 것이 하나 있다는 의미이다. 만약 그 수가 2 이라면
  subarray 중 합이 `K` 인 것이 두개가 있다는 의미이다. 이때 발생횟수를 `cnt` 에
  더한다. 반복을 마치면 cnt 는 답이된다.
* 예를 들어 `A = 1 0 1 0 1, K = 2` 인 경우 `i == 4` 일 때를 살펴보자. `sum - K =
  1` 의 발생횟수는 2 이다. 이것은 `sum - K` 의 구간이 `A[0], A[0..1]` 와 같이 2
  곳에서 발생했다는 것을 의미한다. 즉, 조건을 만족하는 subarray 의 구간은
  `A[1..4], A[2..4]` 와 같이 2 곳이 가능하다는 의미와 같다.

     ```
          = +++++++
          === +++++
       A: 1 0 1 0 1
                  i
     sum: 1 1 2 2 3
 freqMap: 0 1 2 3
          1 2 2 1  
     ```

따라서 답은 2 이다.

위의 아이디어를 바탕으로 다음과 같이 구현한다. 먼저 다음과 같은 변수를 선언한다.

* `int cnt`: 답을 저장한다.
* `int sum`: 지금까지 출현한 `A[i]` 의 합을 저장한다.
* `Map<Integer, Integer> freqMap`: `sum` 의 발생횟수를 저장한다.

인덱스 `i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `sum` 에 `A[i]` 를 더한다.
* 이전에 `sum - K` 가 발생한 횟수를 `cnt` 에 더한다.
* `sum` 의 발생횟수를 하나 증가한다. 문제의 조건에 의해 `-1000 <= A[i] <= 1000` 이므로 `sum` 은 증가 혹은 감소할 수 있음을 주의하자.

모든 반복을 마치면 `cnt` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(N) O(N)
```
