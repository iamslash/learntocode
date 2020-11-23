# Problem

* [My Calendar I](https://leetcode.com/problems/my-calendar-i/)

# Bruteforce

## Idea

기존에 저장된 일정 `(x,y)` 들을 순회한다. 하면서 새로운 일정 `(s,e)`
과 겹치는 부분이 있는지 검사하고 없다면 `(s,e)` 를 삽입하고
있다면 `false` 를 리턴한다.

겹치는지 여부는 다음과 같은 방법들을 사용한다.

```
max(x,s) < min(y, e)
x < e && s < y
```

## Cpmplexity

```
O(N^2) O(N)
```

# Bisection

## Idea

기존의 일정은 `map<int, int> smp` 에 저장했다고 하자. 

기존의 일정 `x,y` 와 새로운 일정 `s,e` 가 겹치는 경우는 모두 다음과 같다.

```
   |-----|
   s     e
|-----|
x     y

   |-----|
   s     e
      |-----|
      x     y

   |-----|
   s     e
     |-|
     x y

   |-----|
   s     e
 |---------|
 x         y
```

`it = smp.lower_bound(s)` 를 수행한다.

`it != m_smp.end() && e > it->first` 인 경우는 다음과 같다. 겹치는 경우이다.

```
   |-----|
   s     e
      |-----|
      x     y

   |-----|
   s     e
     |-|
     x y
```

`it != m_smp.begin() && s < (--it)->second` 인 경우는 다음과 같다. 겹치는 경우이다. `m_smp.empty() == true` 인 경우는 `m_smp.begin() == m_emp.end()` 이다.

```
   |-----|
   s     e
|-----|
x     y
   |-----|
   s     e
 |---------|
 x         y
```

## Cpmplexity

```
O(lgN) O(N)
```

# Implementation

* [c++11](a.cpp)
