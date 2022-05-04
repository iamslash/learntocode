- [Abstract](#abstract)
- [move one by one shortly](#move-one-by-one-shortly)
- [up and down](#up-and-down)
- [reverse order](#reverse-order)
- [multi control flow in loop](#multi-control-flow-in-loop)
- [number out loop](#number-out-loop)
- [forward and backward](#forward-and-backward)
- [probe and forward](#probe-and-forward)
- [count of subarray sum less equal to k](#count-of-subarray-sum-less-equal-to-k)
- [subarray](#subarray)

---

# Abstract

선형탐색 전략의 패턴을 정리한다.

# move one by one shortly

숫자 `y` 에서 숫자 `z` 까지 최단 거리로 한칸씩 이동해 보자. 음수, 양수를 고려해야 한다. 이 것을 간단히 구하는 전략을 move one by one shortly 이라고 하자.

```java
        while (y != z) {
            y += (z - y) / Math.abs(z - y);
            cost += rowCosts[y];
        }
```

* [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/)

# up and down

linear traversal 하면서 어떤 값을 증가하고 혹은 감소하면서 풀이하는 전략을 up and down 이라고 하자.

* [L](/leetcode/BullsandCows/README.md) | [Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)

# reverse order

linear traversal 할 때 거꾸로 접근하는 전략을 reverse order 라고 하자. 거꾸로 접근하면 더욱 쉽게 풀 수 있는 경우가 많다.

* [L](/leetcode2/BackspaceStringCompare/README.md) | [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)

# multi control flow in loop

loop statement 안에 여러개의 control flow statement 를 두어 해결하는 전략이다. loop statement 는 하나씩 전진하고 context 의 상태에 따라 logic 을 분리한다.

* [L](/leetcode2/DistinctNumbersinEachSubarray/) | [Distinct Numbers in Each Subarray](https://leetcode.com/problems/distinct-numbers-in-each-subarray/)

# number out loop

loop statement 밖에 또다른 숫자 num 을 두어 해결하는 전략이다.

* [L](/leetcode/MissingRanges/README.md) | [Missing Ranges](https://leetcode.com/problems/missing-ranges/)

# forward and backward

앞으로 한번 탐색하고 거꾸로 한번 탐색하는 전략이다.

* [L](/leetcode/ProductofArrayExceptSelf/README.md) | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)

# probe and forward

linear traversal 할 때 전진할 수 있는지 검사해보고 전진하는 전략이다.

* [L](/leetcode/TextJustification/README.md) | [Text Justification](https://leetcode.com/problems/text-justification/)

# count of subarray sum less equal to k

수열 `A[]` 에 대해 `tgtSum` 이 주어지면 그것보다 작거나 같은 subarray sum 의 개수를 [sliding window](/fundamentals/slidingwindow/nestedloop/README.md) 를 이용하여 구하는 전략이다. [KthSmallestSubarraySum @ learntocode](/leetcode2/KthSmallestSubarraySum/README.md) 의 `int countLessEqual(int A[], int tgtSum)` 를 참고한다.

* [L](/leetcode2/KthSmallestSubarraySum/README.md) | [Kth Smallest Subarray Sum](https://leetcode.com/problems/kth-smallest-subarray-sum/)

# subarray

subarray 를 `i, j` 인덱스를 이용하여 순회하는 방법은 다음과 같이 2 가지 방법이 있다.

첫번째 방법

```
// nums: 2 3 3 2 2
//       2
//       2 3
//       2 3 3
//       2 3 3 2
//       2 3 3 2 2
//         3 
//         3 3
//         3 3 2
//         3 3 2 2
//           3
//           3 2
//           3 2 2
//             2 
//             2 2
//               2
```

두번째 방법

```
// nums: 2 3 3 2 2
//       2
//         3
//           3
//             2
//               2
//       2 3
//         3 3
//           3 2
//             2 2
//       2 3 3
//         3 3 2
//           3 2 2
//       2 3 3 2
//         3 3 2 2
//       2 3 3 2 2
```

어느 쪽 방법이든 탐색한 subarray 의 개수는 `1 + 2 + 3 + 4 + 5 = 15` 이다.

* [L](/leetcode3/KDivisibleElementsSubarrays/) | [K Divisible Elements Subarrays](https://leetcode.com/problems/k-divisible-elements-subarrays/)
