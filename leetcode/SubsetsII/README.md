# Problem

[SubsetsII @ leetcode](https://leetcode.com/problems/subsets-ii/description/)

입력데이터의 개수를 `N` 이라고 할 때 부분집합의 개수는 `2^N` 이다.
[멱집합 @
wikipedia](https://ko.wikipedia.org/wiki/%EB%A9%B1%EC%A7%91%ED%95%A9)

# Recursive Solution

## Idea

예를 들어서 입력이 `1 2 2` 인 경우를 생각해 보자. 입력 데이터를 `m_v`
벡터에 담고 부분집합을 `m_c` 벡터에 저장한다. 그리고 모든 부분집합은
`m_r` 에 저장한다.  만약 입력 데이터가 정렬되어 있지 않다면 가지치기를
위해 정렬부터 해야 한다. 부분집합 원소의 개수가 0 개 일때 부터 n 개일
때 까지 완전탐색을 위해 재귀호출 함수를 다음과 같이 정의한다.

```
void solve(int start) {
  if (start <= m_v.size()) {
    m_c.push_back(m_v[start]);
    m_r.push_back(m_c);
  }
  for (int i = start; i < m_v.size(); ++i) {
    m_c.push_back(m_v[i]);
    solve(i+1);
    m_c.pop_back();
  }
  ...
}
```

완전 탐색의 과정을 다음과 같이 펼쳐 보자. `_` 는 재귀호출되었을 때
콜스택의 깊이와 같다.

```
//
// 1
// _ 1 2
// _ _ 1 2 2
// _ 1 2     *
// 2
// _ 2 2
// 2         *
```

이때 `*` 가 표시된 행은 중복이기 때문에 답에서 제거해야 한다.

`for-loop` 에서 중복된 것은 다음과 같은 코드를 이용하여 가지치기 해야 한다.

```
    if (i > start && m_v[i] == m_v[i-1])
      continue;
```

## Implementation

[c++11](a.cpp)

## Time Complexity

```
O(2^N)
```

## Space Comlexity

```
O(N)
```

# Iterative Solution

## Idea

## Implementation

[c++11](a.cpp)

## Time Complexity

```
```

## Space Complexity

```
```
