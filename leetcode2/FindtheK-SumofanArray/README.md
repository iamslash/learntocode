# Problem

[Find the K-Sum of an Array](https://leetcode.com/problems/find-the-k-sum-of-an-array/description/)

수열 `nums[]`, 숫자 `k` 가 주어진다. 

`k` 번째로 큰 subsequence sum 를 구하라.

# Idea

`nums[]` 가 주어졌을 때 subseq 를 만들어내는 방법은 [subsequence](/doc/subsequence.md)
를 참고해서 이해하자. 

`nums = [1, 2, 3, 4], k = 2` 의 경우를 살펴보자.

```
1                1
  1 2            3
    1 2 3        6
      1 2 3 4   10 
      1 2 4      7
    1 3          4
      1 3 4      8
      1 4        5
  2              2
    2 3          5
      2 3 4      9
      2 4        6
    3            3
      3 4        7
      4          4
      
10 9 8 7 7 6 6 5 5 4 4 3 3 2 1
```

따라서 답은 `9` 이다.

`nums[]` 의 positive 값만 모두 더하면 max-subseq-sum 이 된다.  이 것을 `int ans`
에 저장한다. `nums[]` 의 모든 수는 절대 값으로 저장하고 오름 차순으로 정렬한다.
하나의 숫자를 포함하지 않을때를 `-` 로 계산하기 위해서 절대값을 저장한다.

예를 들어 `nums = [-1, 2, 3, 4]` 의 경우를 살펴보자. `max-subseq-sum = 9` 이다.
그 다음 큰 숫자는 `max-subseq-sum + (-1)` 과 같다. 그러나 이 것을
`max-subseq-sum - (1)` 로 표현하면 loop invariant 를 수월히 구현할 수 있다. `-1`
대신 절대값에 해당하는 `1` 을 저장해야 한다. 

두번 째로 큰 `subseq-sum` 은 `max-subseq-sum - nums[0]` 과 같다.

세번 째로 큰 `subseq-sum` 은 다음 둘 중 하나이다.


```
* max-subseq-sum - nums[1] + nums[0]
* max-subseq-sum - nums[1]
```

이 것을 더욱 일반화 하면 다음과 같다.

```
* subseq-sum - nums[i+1] + nums[i]
* subseq-sum - nums[i+1]
```

이렇게 생성한 숫자들을 내림차순으로 유지하는 자료구조에 저장하면 몇번 째 큰 수를
구할 수 있다.

`Queue<long[]> pq = new PriorityQueue<>()` 를 선언하고 `long[]{subseq-sum -
nums[0], 0}` 를 삽입한다. `pq` 는 `pq.peek()[0]` 의 내림차순으로 유지한다.
 `pq.peek()[1]` 는 end condition 을 위해 필요하다.

`--k > 0` 동안 순회하면서 다음을 반복한다.

* `pq` 에서 값을 하나 꺼내어 `sum, idx` 에 저장한다.
* `i < n - 1` 이면 다음을 수행한다.
  * `{subseq-sum - nums[i+1] + nums[i], i+1}` 를 `pq` 에 삽입한다.
  * `{sibseq-sum - nums[i+1], i+1}` 를 `pq` 에 삽입한다.
* `ans = sum` 을 수행한다.

`ans` 가 곧 답이다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
