# Problem

[Card Flipping Game](https://leetcode.com/problems/card-flipping-game/)

# Idea

카드 앞면의 수열 `F[]` 와 뒷면의 수열 `B[]` 가 주어진다.  카드를
무한히 뒤집을 수 있다고 해보자. 임의의 카드의 뒷면의 숫자가 앞면의
어떤 숫자들과도 같이 않을 때 그 숫자들 중 가장 작은 것을 구하는
문제이다.

만약 앞면과 뒷면의 숫자가 같다면 그 숫자는 절대 답이 될 수 없다. 그렇지 않은
숫자들 중 최소의 것을 구하면 그것이 곧 답이다.

# Implmentation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
