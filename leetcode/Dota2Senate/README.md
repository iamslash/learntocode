# Problem

* [Dota2 Senate](https://leetcode.com/problems/dota2-senate/)

# Idea

`R` 혹은 `D` 로 구성된 문자열이 주어진다. 각 문자는 서로 다른 팀을
나타내면서 상대를 1 턴 침묵시킬 수 있는 권리를 의미한다. 

문자열 만큼 턴이 주어지면 마지막에 침묵하는 팀이 패자가 된다.

예를 들어 `RD` 를 살펴보자. 마지막에 `D` 가 침묵하게 되어 `R` 이 승자가 된다.

```
   1 turn   2 turn
   i        i
s: R D    R D
r: R      R
```

다음은 `RDD` 를 살펴보자. `2 turn` 에서 `D` 는 현재 침묵 상태이므로
아무 것도 할 수 없다. 그러나 `3 turn` 에서 `D` 는 침묵 상태가 해제되었으므로 `R` 을 침묵시킬 수 있다.

```
   1 turn   2 turn   3 turn
   i          i          i
s: R D D    R D D    R D D
r: R        R        D
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
