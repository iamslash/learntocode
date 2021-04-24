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

* [LongestSubstringwithAtMostTwoDistinctCharacters](/leetcode/LongestSubstringwithAtMostTwoDistinctCharacters/)
