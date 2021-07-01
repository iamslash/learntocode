# Problem

[Get Biggest Three Rhombus Sums in a Grid](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

이차원 배열 `grid[][]` 가 주어진다. 다이아몬드 형태를 하나 만들고
모서리에 해당하는 `grid[y][x]` 의 합을 rhombus sum 이라고 한다. 서로
다르고 최대로 큰 rhombus sum 3 개를 구하라.

# Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
grid:
 3  4   5  1  3
 3  3   4  2  3
20 30 200 40 10
 1  5   5  4  1
 4  3   2  2  5 
```

* 인덱스 `y, x` 를 이용하여 `grid[][]` 를 순회하면서 임의의
  다이아몬드를 만든다.
  * 이때 `y, x` 는 다이아몬드의 왼쪽 꼭 지점을 의미한다.
* 다시 인덱스 `len` 을 이용하여 다이아몬드 한변의 길이를 순회한다.

다이아몬드 꼭지점은 다음과 같이 구할 수 있다.

```
  left: grid[y][x]
 right: grid[y][x + 2*len]
   top: grid[y - len][x + len]
bottom: grid[y + len][x + len]
```

임의의 다이아몬드를 만들면서 rhombus sum 을 Set 에 저장한다. 모든
반복을 마치면 Set 에 저장된 rhombus sum 중 3 개가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(HW) O(HW)
```
