# Problem

[Detect Squares](https://leetcode.com/problems/detect-squares/)

square 는 정사각형이다. 만들 수 있는 square 의 개수를 구하는
class 를 구현하라. 

# Idea

다음과 같은 변수들을 선언한다.

* `List<int[]> coords` 를 선언하여 입력된 좌표들을 저장한다.
* `int[][] freqs` 를 선언하여 `(x,y)` 의 출현 횟수를 저장한다.

`add(int[] point)` 는 다음과 같이 구현한다.

* `coords` 에 저장한다.
* `freqs` 도 업데이트 한다.

`count(int[] point)` 는 다음과 같이 구현한다.

* `point[]` 를 `(x3, y3)` 라고 하자. 
* `coords` 를 `(x1, y1)` 으로 순회하며 다음을 반복한다.
  * `(x1,y1)` 과 `(x3,y3)` 가 square 의 마주보는 두 개의 꼭지점이 되지
    못하면 건너뛴다.
  * `(x2,y2) = (x3,y1)` 이고 `(x4,y4) = (x1,y3)` 이다.
    * `cnt(x2, y2) * cnt(x4,y4)` 를 답에 더한다.

모든 반복을 마치면 `sum` 이 답이다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
  add: O(1) O(N)
count: O(1) O(N)
```
