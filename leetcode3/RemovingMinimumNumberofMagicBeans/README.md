# Problem

[Removing Minimum Number of Magic Beans](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/)

수열 `beans[]` 가 주어진다. `beans[]` 의 모든 원소가 0 혹은 임의의
숫자와 같도록 해보자. 이때 0 혹은 특정 숫자와 같도록 만들기 위해
숫자를 뺄 수 있다. 뺀 숫자들의 합이 최소가 되도록 했을 때 뺀 숫자들의
합을 구하라.

# Idea

예를 들어 `beans = [4,1,6,5]` 의 경우를 살펴보자.

```
beans: 4 1 6 5
       4 0 4 4
 diff: 0 1 2 1 
```

따라서 답은 `4 = 0 + 1 + 2 + 1` 이다.

`beans[i]` 를 `0` 으로 바꾸는 것을 생각해 보자. 답을 구하기 위해
`beans[i]` 는 작은 값일 수록 유리하다. 제일 작은 값에 해당하는
`beans[i]` 부터 `0` 으로 바꾸어 놓고 `0` 보다 큰 숫자를 선택해
보자. 따라서 `beans` 를 오름차순으로 정렬해 놓고 생각해 보자.

예를 들어 `beans = [4, 5, 6, 1]` 의 경우를 살펴보자.

```
beans: 1 4 5 6
  sum: 16
       1 1 1 1    when choose 1, sum of removals is 16 - (4 - 0) * 1 = 12
       0 4 4 4    when choose 4, sum of removals is 16 - (4 - 1) * 4 = 4
       0 0 5 5    when choose 5, sum of removals is 16 - (4 - 2) * 5 = 6
       0 0 0 6    when choose 6, sum of removals is 16 - (4 - 3) * 6 = 10
```

따라서 답은 `4` 이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(1)
```
