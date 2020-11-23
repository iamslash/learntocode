# References

* [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

# Sliding Window Basic

보통 두개의 인덱스 `i, j` 를 이용하여 window 를 옮기는 것을 sliding
window 라고 한다.  이때 인덱스 `i, j` 에 대하여 인덱스를 늘리고 로직을
처리할지 로직을 처리하고 증가할지 유의해야 한다. nested loop 를
사용하면 더욱 간결하게 코드를 작성할 수 있다.

# Sliding Window With Limited Resources

제한된 자원 `k` 가 주어진다. `k` 가 특정한 값보다 크면 `i` 를 증가하고
`k` 가 특정한 값보다 작으면 `j` 를 증가하면서 sliding 해보자.

```go
func longestSubarray(A []int) int {
	i, j, n, k, ans := 0, 0, len(A), 1, 0
	for j = 0; j < n; j++ {
		if A[j] == 0 {
			k--
		}
		for k < 0 {
			if A[i] == 0 {
				k++
			}
			i++
		}
		ans = max(ans, j-i)
	}
	return ans
}
```

# Sliding Window With Limited Resources Not Shrinking

또한 한번 늘어난 window 를 다시 줄이지 않고 sliding 할 수도 있다.

```go
func longestSubarray(A []int) int {
	i, j, n, k := 0, 0, len(A), 1
	for j = 0; j < n; j++ {
		if A[j] == 0 {
			k--
		}
		if k < 0 {
			i++
			if A[i] == 0 {
				k++
			}
		}
	}
	return j - i
}
```
