# Problem

[Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

# Idea

무게들의 모음 `W[]` 와 날짜 `D` 가 주어진다. `W[]` 의 무게들을 `D`
만큼 연속으로 짝지었을 때 합의 최소값을 구하는 문제이다.

최소의 무게를 `mincap` 이라고 하자. `mincap` 의 후보는
문제의 조건에 의해 `max(M[..]) <= mincap <= 500 * 50000` 이다.

`mincap` 이 하나 정해지면 `W[..]` 를 순회하면서 `mincap` 을 최대로
해서 짝을 지은 다음 그 그룹의 개수를 `G` 라고 해보자. 

* `G <= D` 이면 `G` 를 늘려야 한다. 따라서 `mincap` 을 줄여야 한다.
* `G > D` 이면 `G` 를 줄여야 한다. 따라서 `mincap` 을 늘려야 한다.
 
충분히 binary search 라 할만 하다.

다음과 같은 binary search template 을 머릿속에 생각하고 구현해본다.

```c
while (l < h) {
  int m = (l+h)/2;
  if (getGroup() <= D)
    h = m;
  else
    l = m+1;
}
return l;
```
 
# Implmentation

* [c++11](a.cpp)

# Complexity

```
O(N^2lgN) O(1)
```
