# Problem

[Minimum Swaps to Group All 1's Together II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)

수열 `nums[]` 가 주어진다. `nums[i]` 는 `1, 0` 으로만 구성되어 있다.
모든 `1` 이 연속되게 해보자. 임의의 `1` 과 `0` 의 위치를 바꿀 수 있다.
최소 회수를 구하라. 이때 `nums[]` 는 circular array 이다.

# Idea

예를 들어 `nums = [0,1,0,1,1,0,0]` 의 경우를 살펴보자.

```
nums: 0 1 0 1 1 0 0
          1 1 1
```

따라서 답은 `1` 이다.

이번에는 `nums = [1,1,0,0,1]` 의 경우를 살펴보자.

```
nums: 1 1 0 0 1 
                1 1 0 0 1
```

따라서 답은 `0` 이다.

`int ones = 0` 를 선언하고 `1` 의 개수를 저장한다.  `int[] circledNums
= new int[nums.length * 2]` 를 선언하고 `nums[]` 를 두번 복사한다.

`ones` 크기의 fixed sliding window 를 만들고 `circledNums[]` 를
순회한다.  `int maxOnesInWnd = nums.length` 를 선언하고 sliding
window 에 등장하는 `1` 의 최대 개수를 저장한다. 

모든 반복을 마치면 `ones - maxZeroesInWnd` 가 곧 답이다.

다음은 `nums = [1,1,0,0,1]` 의 풀이과정이다.

```
        nums: 1 1 0 0 1

        ones: 3
                                i
 circledNums: 1 1 0 0 1 1 1 0 0 1
maxOnesInWnd: 1 2 2 2 2 2 3 3 3 3
         ans: 3 - 3 = 0
```
 
# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
