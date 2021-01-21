# Problem

[Minimum Operations to Make a Subsequence](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/)

수열 `T[], A[]` 가 주어진다. `T[]` 의 수는 모두 distinct 하다.  `A[]`
는 그렇지 않다. `A[]` 의 사이사이에 얼마든지 임의의 숫자를 삽입할 수
있다. `T[]` 가 `A[]` 의 subsequence 가 되도록 숫자를 삽입해 보자. 그
수가 최소가 되도록 하자. 이때 그 최소의 수를 구하라.

# Idea

예를 들어 `target = [5,1,3], arr = [9,4,2,3,4]` 의 경우를 살펴보자.

```
9 4 2 3 4
5 9 4 2 3 4
5 9 4 1 2 3 4
```

따라서 답은 2 이다.

`A[]` 의 subsequence 들 중 `T[]` 의 subsequence 를 가장 많이
포함하는 것을 찾으면 된다. 그 개수를 `T[]` 의 길이에서 뺀 숫자가 답이다. 이것은 [LIS @ learntocode](/leetcode/LongestIncreasingSubsequence/README.md) 로 해결할 만 하다.

`Map<Integer, Integer> idxMap = HashMap<>()`  를 선언하여 `T[]` 의 `{num : idx}` 를 채운다.

`int lisCnt = 0, int[] lisArr = new int[A.length+1]` 를 선언하여 각각 lis 원소의 개수 lis 숫자들을 저장한다.

`int num` 으로 `A[]` 을 순회하면서 다음을 반복한다.

* `idxMap` 에 `num` 이 없다면 건너뛴다.
* `listArr` 에서 `num` 의 index 를 binary search 로 검색한다. 그것을 `int i` 에 저장한다. `Arrays.binarySearch` 는 positive 혹은 negative 를 리턴할 수 있다. negative index 를 처리하기 위해 `i = Math.max(i, ~i)` 를 수행한다.
  ```
  // Bitwise complement (~): inverts ones and zeroes in a number
  //                     ~j: (-j) - 1
  ```

* `lisArr[i]` 를 업데이트 한다. 즉, `lisArr[i] = idxMap.get(num)` 을 수행한다.
* `lisCnt` 를 업데이트 한다. 즉, `lisCnt = Math.max(lisCnt, i+1)` 를 수행한다.

모든 반복을 마치면 `T.length - lisCnt` 가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(NlgN) O(N)
```
