- [Abstract](#abstract)
- [up and down](#up-and-down)
- [reverse order](#reverse-order)
- [multi control flow in loop](#multi-control-flow-in-loop)
- [number out loop](#number-out-loop)
- [forward and backward](#forward-and-backward)

---

# Abstract

선형탐색 전략의 패턴을 정리한다.

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
