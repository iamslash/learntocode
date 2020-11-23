# Problem

* [My Calendar III @ leetcode](https://leetcode.com/problems/my-calendar-iii/)


# Idea

시간의 시작과 끝이 주어지면 가장 많이 겹치는 행사의 개수를
알아내는 문제이다. 시간의 시작과 끝을 각각 `s`, `e` 라고 해보자.
예를 들어 다음과 같은 시간들이 입력되었다고 해보자. 종료시간은
`:` 문자를 붙여두었다.

```
                24         :40
                               43  :50
                  27          :43
   5         :21
                      30   :40
       14           :29
```

맵을 정의하여 `smp` 라고 해보자. 각 행사를 예약할 때마다 
`smp[s]++, smp[e]--` 해보자. 위의 예와 같이 6 개의 행사 데이터가
맵에 입력되었다면 맵을 처음부터 순회하고 다음과 같이 처리한다.

```cpp
int r, ing = 0;
for (auto pr : smp) {
       r = max(r, ing += pr->second);
}
return r;
```

`pr->second` 는 맵의 키가 `s` 혹은 `e` 일때의 횟수이다. 이것은 
`s` 를 지나칠 때는 하나 증가할 것이고 `e` 를 지나칠 때는 하나 감소할 것이다.

위와 같이 맵을 처음부터 끝까지 매번 순회하지 않고 필요한 부분만 순회한다면
더욱 최적화 할 수 있을 것이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
