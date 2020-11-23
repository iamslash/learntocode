# Problem

[Divide Chocolate](https://leetcode.com/problems/divide-chocolate/)

수열 `S[]` 와 숫자 `K` 가 주어진다. 하나의 초콜릿을 `K` 만큼 절단하여
`K+1` 개의 그룹으로 나눈다. `S[i]` 는 i-th 초콜릿 덩어리의 당도이다.
`K+1` 개의 그룹중 당도의 합이 가장 낮은 것을 내가 갖는다. 내가 갖는
그룹의 당도가 최대가 되도록 했을 때 그 최대 값을 구하라.

# Idea

예를 들어 `S = [1,2,3,4,5,6,7,8,9], K = 5` 일 때 다음과 같이
초콜릿을 나눌 수 있다.

```
[1, 2, 3], [4, 5], [6], [7], [8], [9]
```

따라서 답은 `6` 이다.

내가 갖는 그룹의 당도합을 `mins` 라고 하자. `mins` 가 최대이려면
그룹마다 당도의 합이 `mins` 보다 크거나 같도록 나누어야 한다. 이때
나누어진 그룹의 개수가 `K` 와 일치하면 된다. `mins` 의 범위는 `min(S)
<= mins <= sum(S)` 이다. 

[binary search](/fundamentals/search/binarysearch/README.md) 로 해결할 만 하다. 특히 `mins` 가 최대이어야 하므로 [right most pattern](/fundamentals/search/binarysearch/README.md) 이 유용하다. `int split(vector<int> &S, int mins)` 를 정의하여 `mins` 를 기준으로 초콜릿을 나누었을 때 그 그룹의 개수를 리턴한다.

```cpp
int m = (l + r + 1) / 2;
if (split(S, m) >= K)
  l = m;
else
  r = m-1;
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2lgN) O(1)
```
