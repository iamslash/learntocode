- [Abstract](#abstract)
- [one step j, multi step i](#one-step-j-multi-step-i)
- [finding pairs with the condition](#finding-pairs-with-the-condition)

----

# Abstract

two pointers 로 문제를 해결할 때 사용할 수 있는 loop pattern 을 정리한다.

# one step j, multi step i

j 는 한칸씩 전진하고 필요할 때 i 는 여러칸 전진한다.

```cpp
while (j < n) {
  while (i < j) {
    i++;
  }
  j++;
}
```

* [L](/leetcode/LongestSubstringwithAtMostTwoDistinctCharacters/) | [Longest Substring with At Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)

# finding pairs with the condition

수열 `A[]` 가 있다. two pointers i, j 를 이용해서 `A[i] + A[j] > 0` 을 만족하는 짝 `(i, j)` 의 개수를 구하는 전략이다. i 를 하나씩 전진하며 다음을 더한다.

* `i < j` 이면 `i` 를 기준으로 `A[i] + A[j] > 0` 을 만족하는 `j` 의 개수를 구한다.
  * `n - 1 - j` 와 같다.
* `i == j` 이면 짝의 개수는 없다.
* `i > j` 이면 `j` 를 기준으로 `A[i] + A[j] > 0` 을 만족하는 `i` 의 개수를 구한다.
  * `n - 1 - i` 와 같다.

* [L](/leetcode2/CountPairsinTwoArrays/README.md) | [Count Pairs in Two Arrays](https://leetcode.com/problems/count-pairs-in-two-arrays/)
