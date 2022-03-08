# Problem

[Number of Ways to Build House of Cards](https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/)

숫자 `n` 이 주어진다. `n` 은 카드의 개수이다.
카드로 만들 수 있는 집의 개수를 구하라.

```
n: 2
/\

n: 5
  _
/\ /\

n: 7
 /_\ 
/\ /\
```

# Idea

[L](/leetcode/CoinChange/README.md) 와 비슷하다.

카드의 개수를 늘려가면서 집을 만들 수 있는지 따져보자. 최소 2 장은 있어야 집을
만들 수 있다. 이후 3 장씩 더해져서 한줄을 구성할 수 있다.

```
n: 2
/ \

n: 5
  _
/\ /\

n: 7
  /\
  _  
/\ /\

n: 8
  _  _
/\ /\ /\
```

`int[] C = new int[n+1]` 를 선언하여 `C[a]` 에 카드의 개수가 `a` 인 경우 만들 수
있는 집의 개수를 저장한다. `C[0] = 1` 을 수행한다. (magic seed) 두개의 숫자 `a,
b (b >= a)` 가 있다고 해보자. 다음과 같이 반복한다.

* `a` 는 `[2..n]` 동안 `3` 씩 더한다.
  * `b` 는 `[n..a]` 동안 `1` 씩 뺀다.
    * `C[b] += C[b-a]` 를 수행한다. 

모든 반복을 마치면 `C[n]` 이 답이다. 다음은 풀이과정이다.

```
n: 2
           
       a
C: 1 0 1
       b
n: 5
           .
             a
C: 1 0 1 0 0 1
             b
n: 6
           .        
             a
C: 1 0 1 0 0 1 0
             b
n: 7
           .        
             a
C: 1 0 1 0 1 1 0 1 
             b
n: 8
           .        
                   a
C: 1 0 1 0 0 1 0 1 1
                   b
n: 12
           .         .
                         a
C: 1 0 1 0 0 1 0 0 1 0 0 1 0
                         b
n: 16
           .         .
                               a
C: 1 0 1 0 0 1 0 1 1 0 1 1 0 2 1 1 2
                               b
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N^2) O(N)
```
