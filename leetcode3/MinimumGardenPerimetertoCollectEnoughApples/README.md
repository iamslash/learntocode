# Problem

[Minimum Garden Perimeter to Collect Enough Apples](https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/)

숫자 `neededApples` 가 주어진다. `(0,0)` 을 중심으로 정사각형을
정해보자. 각 좌표에 사과나무를 심는다. 나무에 열리는 사과의 개수는
다음과 같이 정해진다.

```
apples = |x| + |y|
```

`neededApples` 를 얻을려면 필요한 최소 크기의 정사각형을
생각해보자. 그때 정사각형의 지름을 구하라.

# Idea

정사각형의 반지름을 `len` 이라고 하자. `len` 은 `(0, 0)` 부터
모서리까지의 거리이다.

다음은 다양한 `len` 에 대해 각 좌표별 사과의 개수이다. 

```
len: 1

0

len: 2

2 1 2  
1 0 1
2 1 2

len: 3

4 3 2 3 4      
3 2 1 2 3
2 1 0 1 2
3 2 1 2 3
4 3 2 3 4 

len: 4

6 5 4 3 4 5 6
5 4 3 2 3 4 5     
4 3 2 1 2 3 4
3 2 1 0 1 2 3
4 3 2 1 2 3 4
5 4 3 2 3 4 5
6 5 4 3 4 5 6
```

`(0,0)` 을 중심으로 4 개의 영역으로 나누자. 4 개의 영역에 분포한
숫자는 모두 같은 패턴이다. 그리고 1 개의 영역은 다음과 같다.

```
len: 4



      0 
      1 2 3 4
      2 3 4 5
      3 4 5 6
```

숫자들은 연속되어 있다. 다음과 같은 규칙을 발견할 수 있다.

```
sum(1..len)        = sum(1..len) + 0
sum(2..(len+1))    = sum(1..len) + len
sum(3..(len+2))    = sum(1..len) + len + len
```

```
sum(1..len)        = sum(1..len) + len * 0
sum(2..(len+1))    = sum(1..len) + len * 1
sum(3..(len+2))    = sum(1..len) + len * 2
```

이 것은 다음의 공식과 같다. 공식을 간단하게 하기 위해 `len` 을 `n`
이라고 표현하자.

```
n(n+1)/2 + n*0
n(n+1)/2 + n*1
n(n+1)/2 + n*2
``` 

위의 공식을 모두 합하여 보자. 

```
```

영역은 4 개 이므로 마지막 점화식은 다음과 같다. 

```
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N)
```
