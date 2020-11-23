# Problem

[Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

# Idea

2-D 배열 `M[][]` 와 숫자 `k` 가 주어진다. 사각형들 중 `k` 보다 작거나 같은 최대 합을 구하라.  


인덱스 `i, j` 를 이용하여 사각형의 가로를 순회한다. 각 `i` 의 경우에
대하여 `wSum` 을 선언하여 가로합들을 저장한다. 그리고 각 `j` 에 대하여
`wSum` 을 업데이트한다.

```
for (int i = 0; i < M.size(); i++) {
  vector<int> wSum(h, 0);
  for (int j = i; j < M.size(); j++) {
    for (int y = 0; y < h; y++) {
      wSum[y] += M[y][j];
    }
  }
}
```

모든 `i, j` 에 대하여
[MaxSumofRectangleNoLargerThanK](/fundamentals/array/MaximumSubarrayNoLessThanK/README.md)
를 이용하여 최대 값을 `ans` 에 업데이트 한다.

모든 반복을 마치면 `ans` 가 답이다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(W^2H) O(H)
```
