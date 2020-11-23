# Problem

* [Minimum Cost to Hire K Workers](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)

# Idea

`N` 명의 근로자가 있고 근로자 `i` 의 질과 최저임금을
`quality[i]`, `wage[i]` 라고 하자. 최소의 임금을
소비하고 다음 두가지 조건을 만족하면서 
`K` 명의 근로자를 고용하는 문제이다.

* `K` 그룹의 근로자는 퀄러티의 비율에 따라 임금을 지급한다. 따라서
  `wage[i] : wage[j] = quality[i] : quality[j]` 를 만족한다. 또한
  `wage[i] : quality[i] = wage[j] : quality[j]` 이다.
* 모든 근로자가 `wage[i]` 이상의 임금이 보장되어야 한다.

`K` 그룹의 근로자들은 모두 `wage[i]/quality[i]` 가 같다.  이들의
퀄리티를 모두 합하고 `wage[i]/quality[i]` 를 곱하면 이들의 임금을
얻어낼 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
