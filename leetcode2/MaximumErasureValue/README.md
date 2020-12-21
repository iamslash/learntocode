# Problem

[Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/)

수열 `A[]` 가 주어진다. `A[]` 에서 하나의 substring 을 제거할 수
있다. 단, substring 의 숫자들은 모두 unique 해야 한다. substring 의
원소들의 합이 최대가 될 때 그 최대합을 구하라.

# Idea

two pointers 로 해결할 만 하다.

`unordered_set<int> freqSet` 을 선언하여 숫자의 중복여부를 판단한다.
`sum` 을 선언하여 substring 의 합을 저장한다. `ans` 를 선언하여
substring 의 최대합을 저장한다.

인덱스 `j` 를 선언하여 `[0..n)` 동안 순회하며 다음을 반복한다. 

* `frqSet.count(nums[j]) > 0` 동안 다음을 반복한다.
  * 중복된 숫자가 존재한다는 의미이다. `i` 를 한칸씩 옮기면서 중복된
    숫자를 제거해야 한다.
  * `freqSet.erase(nums[i])` 를 수행한다.
  * `sum -= nums[i++]` 를 수행한다.
* 중복된 숫자는 모두 제거되었다. `nums[j]` 를 `freqSet` 에 삽입한다.
* `sum += nums[j]` 를 수행한다.
* `ans = max(ans, sum` 를 수행한다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
