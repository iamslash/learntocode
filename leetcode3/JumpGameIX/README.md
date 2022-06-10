# Problem

[Jump Game IX](https://leetcode.com/problems/jump-game-ix/)

수열 `nums[], costs[]` 가 주어진다. `0` index 에서 `n-1` index 까지
최소의 비용으로 이동해 보자.

`i, j` index 가 있을 때 다음 조건을 만족하면 `i` 인덱스에서 `j`
인덱스로 이동할 수 있다.

* nums[i] <= nums[j] and nums[k] < nums[i] for all indexes k in the
  range i < k < j
* nums[i] > nums[j] and nums[k] >= nums[i] for all indexes k in the
  range i < k < j
  
최소의 비용을 구하라.

# Idea

예를 들어 `nums = [3,2,4,4,1], costs = [3,7,6,4,2]` 의 경우를 살펴보자.

```
costs: 3 7 6 4 2
 nums: 3 2 4 4 1
       i   j       6
           i   j   2           
```

따라서 댭은 `8` 이다.

iterative dynamic programming, mono stack 으로 해결할 만하다.

`int C[n]` 을 선언하여 `C[i]` 에 `i` 인덱스에서 `n-1` 인덱스까지의
최소비용을 저장한다.

`Stack<Integer> ltIdxStck` 를 선언한다. 현재 인덱스 `i` 에 있다고
해보자.  `nums[i] > nums[j] (i < j < n)` 인 `j` 들을 저장한다. 즉,
`ltIdxStck` 은 `nums[i]` 보다 작은 숫자를 갖는 인덱스들이 모여있다.
`ltIdxStck.peek()` 은 `nums[i] > nums[j]` 이고 `i` 와 가장 가까운 `j`
를 의미한다.

`Stack<Integer> gteIdxStck` 를 선언한다. 현재 인덱스 `i` 에 있다고
해보자.  `nums[i] <= nums[j] (i < j < n)` 인 `j` 들을 저장한다. 즉,
`gteIdxStck` 은 `nums[i]` 보다 크거나 같은 숫자를 갖는 인덱스들이
모여있다. `gteIdxStck.peek()` 은 `nums[i] <= nums[j]` 이고 `i` 와 가장
가까운 `j` 를 의미한다.

이제 다음과 같이 풀이해 보자.

먼저 `ltIdxStck, getIdxStck` 에 `n-1` 을 삽입한다. 
`i` 로 `[n-2..0]` 동안 순회하며 다음을 반복한다. 

* `ltIdxStck` 에 `num[i] > nums[j]` 인 `j` 만 존재하도록 한다.
* `gteIdxStck` 에 `num[i] <= nums[j]` 인 `j` 만 존재하도록 한다.
* `jump1` 에 `nums[i] > nums[j]` 를 만족하는 `j` 로 점프했을 때 비용을 저장한다.
* `jump2` 에 `nums[i] <= nums[j]` 를 만족하는 `j` 로 점프했을 때 비용을 저장한다.
* `C[i]` 에 `min(jump1, jump2)` 를 저장한다.
* `ltIdxStck.push(i), gteIdxStck.push(i)` 를 수행한다.

모든 반복을 마치면 `C[0]` 이 곧 답이다.

다음은 앞의 설명에 대한 풀이과정이다.
 
```
     costs: 3 7 6 4 2
  
      nums: 3 2 4 4 1
              i
 
         C: 0 0 2 6 0
 ltIdxStck: 4  
gteIdxStck: 3 
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
