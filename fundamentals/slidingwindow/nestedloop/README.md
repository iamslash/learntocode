- [Abstract](#abstract)
- [shrinkable sliding window](#shrinkable-sliding-window)
- [non-shrinkable sliding window](#non-shrinkable-sliding-window)
- [References](#references)

------

# Abstract

보통 두개의 인덱스 `i, j` 를 이용하여 window 를 옮기는 것을 sliding window 라고
한다.  이때 인덱스 `i, j` 에 대하여 인덱스를 늘리고 로직을 처리할지 로직을
처리하고 증가할지 유의해야 한다. 

slding window 의 크기를 줄이느냐 혹은 크기를 줄이지 않느냐에 따라 다음과 같은
전략으로 구분할 수 있다.

* shrinkable sliding window 
* non-shrinkable sliding window 

sliding window 의 크기를 줄이지 않고 반복하는 것이 시간복잡도가 더욱 좋다.
그러나 사용할 수 없는 경우도 있다.

# shrinkable sliding window 

보통 다음과 같은 code-pattern 을 갖는다. 

```java
int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // TODO: update sliding window using j
    for (; invalid(); ++i) { 
			// TODO: shrink sliding window using i
    }
		// update sliding window
    ans = max(ans, j - i + 1);
}
return ans;
```

* [L](/leetcode2/FrequencyoftheMostFrequentElement/README.md) | [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

# non-shrinkable sliding window 

보통 다음과 같은 code-pattern 을 갖는다.

```java
int i = 0, j = 0;
for (; j < N; ++j) {
    // TODO: update sliding window using j
    if (invalid()) {
      // TODO: update sliding window using i
      ++i;
    }
}
// return maximum sliding window
return j - i; 
```

* [L](/leetcode2/FrequencyoftheMostFrequentElement/README.md) | [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

# References

* [C++ Maximum Sliding Window Cheatsheet Template! @ leetcode.discussion](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)
* [L](/leetcode2/LongestSubarrayof1sAfterDeletingOneElement/a.go) | [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)
* [L](/leetcode3/MaximumBeautyofanArrayAfterApplyingOperation/) | [Maximum Beauty of an Array After Applying Operation](https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/)
