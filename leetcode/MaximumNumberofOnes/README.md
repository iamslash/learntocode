# Problem

[Maximum Number of Ones](https://leetcode.com/problems/maximum-number-of-ones/)

# Idea

사각형의 넓이와 높이 `w, h`, 작은 사각형의 넓이와 높이 `sidelen`, 최대
1 의 개수 `maxone` 가 주어진다. `w X h` 크기의 사각형에서 임의의
`sidelen X sidelen` 의 작은 사각형에 최대 1 의 개수가 `maxone` 이
되도록 `0, 1` 을 배치해 보자. 이때 `1` 의 개수를 구하는 문제이다.

예를 들어 `w = 3, h = 3, sidelen = 2, maxone = 1` 인 경우를 살펴보자.
다음과 같이 `0, 1` 을 구성하면 문제의 조건을 만족하고 답은 `4` 이다.

```
1 0 1
0 0 0
1 0 1
```

위의 예를 잘 살펴보면 몇가지 규칙을 발견할 수 있다. 다음과 같이 큰 사각형을
작은 사각형으로 나누고 작은 사각형에 번호를 부여해 보자.

```
0 1 0
2 3 1
0 1 0
```

`1` 의 개수가 최대가 되려면 작은 사각형의 번호중 가장 많이 등장하는 곳
부터 `1` 을 배치하면 된다. 예를 들어 위의 경우 `0` 은 4 번 등장하고
`1` 은 3 번 등장한다. 따라서 `maxone` 이 1 이면 `0` 에 `1` 을 배치하고
`maxone` 이 2 이면 `0, 1` 에 `1` 을 배치한다.

`vector<int> rec` 를 선언하여 작은 사각형의 번호별 등장 횟수를
저장한다. 이때 인덱스 `i, j` 를 이용하여 각각 `[0..sidelen), [0..sidelen)`
만큼 순회하며 다음을 반복한다.

* `int r = (h - i - 1) / sideLength + 1`
* `int c = (w - j - 1) / sideLength + 1`
* `rec.push_back(r * c)`

그리고 `rec` 를 내림차순으로 정렬한다. `int ans = 0` 을
선언하여 인덱스 `i` 를 `[0..maxone)` 만큼 순환하면서 다음을 반복한다.

* `ans += rec[i]`

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)
* [java](Solution.java)
* [python3](a.py)
* [go](a.go)

# Complexity

```
O(NlgN) O(N)
```
