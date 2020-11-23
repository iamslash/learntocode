# Problem

* [Shopping Offers @ leetcode](https://leetcode.com/problems/shopping-offers/)

# Idea

물건별 가격들 `P`, 할인액수와 제공물건개수 `S`, 필요한 물건개수 `N` 이
주어졌을 때 `S` 를 적절히 사용하여 `N` 만큼 물건을 확보할 수 있는
최소금액을 찾는 문제이다. 단, `S` 를 이용할 때 `N` 보다 만은 물건을
구매할 수는 없다.

`P` 와 `N` 을 적절히 곱하면 할인행사를 이용하지 않았을 때 지불해야할
금액을 구할 수 있다.


다음과 같이 부분문제를 정의한다.

```
shoppingOffer(P, S, N)
```

`S` 를 처음부터 순회하면서 할인행사를 이용했을 때 조건에 맞는지
검사하고 만약 그렇다면 `N` 에서 할인행사를 이용하여 구매한 물건개수를
제외한다. 그리고 이것을 `N'` 이라고 하자. 앞서 언급한 부분문제에 `N`
대신 `N'` 을 이용하자.

```
shoppingOffer(P, S, N')
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(S^L) O(L)
S : count of special offers
L : level of tree
```