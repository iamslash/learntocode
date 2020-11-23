# Problem

[Grumpy Bookstore Owner](https://leetcode.com/problems/grumpy-bookstore-owner/)

# Idea

고객들의 만족도 `C[]`, 주인장의 심술도 `G[]`, 숫자 `X` 가
주어진다. 주인장은 `X` 만큼 연속으로 심술을 안 부릴 수 있다.  고객들의
만족도의 합이 최대가 되도록 했을 때 그 합을 구하는 문제이다.

`int like` 를 선언하여 심술도가 0 인 만족도의 합을 저장한다. `int part` 를 선언하여 길이가 `X` 인 슬라이드를 만들고 심술도가 1 인 부분 만족도의 합을 저장한다. `int maxp` 를 선언하여 `part` 의 최대값을 저장한다. `C[]` 를 처음부터 순회하여 `like, part, maxp` 를 갱신하면
`like + maxp` 가 곧 답이다.

다음은 풀이과정이다. `___` 는 길이가 `X` 인 부분 만족도를 의미한다.

```
      i                    i                    i
      _                  ___                _____
   C: 1 0 1 2 1 1 7 5    1 0 1 2 1 1 7 5    1 0 1 2 1 1 7 5
   G: 0 1 0 1 0 1 0 1    0 1 0 1 0 1 0 1    0 1 0 1 0 1 0 1
like: 1                  1                  2
part: 0                  0                  0
maxp: 0                  0                  0

            i                    i                    i
        _____                _____                _____
   C: 1 0 1 2 1 1 7 5    1 0 1 2 1 1 7 5    1 0 1 2 1 1 7 5
   G: 0 1 0 1 0 1 0 1    0 1 0 1 0 1 0 1    0 1 0 1 0 1 0 1
like: 2                  3                  3
part: 2                  2                  3
maxp: 2                  2                  3

                  i                    i                
              _____                _____                
   C: 1 0 1 2 1 1 7 5    1 0 1 2 1 1 7 5    
   G: 0 1 0 1 0 1 0 1    0 1 0 1 0 1 0 1    
like: 10                 10                  
part: 1                  6                  
maxp: 3                  6                  
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
