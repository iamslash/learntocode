# Problem

[Insert Delete GetRandom O(1) - Duplicates allowed](https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/)

# Idea

`insert(val), remove(val), getRandom()` 을 O(1) 으로 수행할 수있도록 구현하라.

`vector<int> nums` 를 선언하고 val 을 저장한다.  `unordered_map<int,
unordered_set<int>> vals` 를 선언하고 val 과 val 이 저장된 nums 의
index 를 저장한다.

## `getRandom()`

예를 들어 `1 2 3 3 4` 가 모두 입력되었다면. `nums = [1, 2, 3, 3, 4]`
형태로 저장한다. 그렇다면 `nums[rand() % nums.size()].first` 가 곧
`getRandom()` 에 해당한다.

## `insert(val)`

`1 2 3 3 4` 가 모두 입력되면 자료구조의 모양은 다음과 같다.

```
nums: [1, 2, 3, 3, 4]
vals: {{1 : {0}},
       {2 : {1]},
       {3 : {2, 3}},
       {4 : {4}}}
```

## `remove(val)`

이제 `3` 을 삭제해 보자. 

* `vals[3]` 의 첫번째 index 2 를 삭제한다. 그리고 그 index 2 를 저장한다.

```
nums: [1, 2, 3, 3, 4]
vals: {{1 : {0}},
       {2 : {1]},
       {3 : {3}},
       {4 : {4}}}
```

* `nums[2]` 에 `nums.back()` 을 저장한다. 

```
nums: [1, 2, 4, 3, 4]
vals: {{1 : {0}},
       {2 : {1]},
       {3 : {3}},
       {4 : {4}}}
```

* `3` 은 사라졌다. 이제 `nums.back()` 에 해당하는 `4` 의 index 를 업데이트 한다.
* `vals[4]` 에서 `4` 의 원래 index 4 를 삭제한다. 그리고 예전 `3` 의 인덱스 2 를 추가한다.

```
nums: [1, 2, 4, 3, 4]
vals: {{1 : {0}},
       {2 : {1]},
       {3 : {3}},
       {4 : {2}}}
```

* `4` 는 자리 이동이 되었다. `nums` 의 마지막 원소를 삭제한다.

```
nums: [1, 2, 4, 3]
vals: {{1 : {0}},
       {2 : {1]},
       {3 : {3}},
       {4 : {2}}}
```

* `3` 이 마지막 원소라면 `vals` 에서 `3` 을 삭제한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
insert:    O(1)
remove:    O(1)
getRandom: O(1)
```
