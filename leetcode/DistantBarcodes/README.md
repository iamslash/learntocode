# Problem

[Distant Barcodes](https://leetcode.com/problems/distant-barcodes/)

# Idea

수열 `B[]` 가 주어진다. 인접한 원소끼리 같은 값이 되지 않도록 다시
배열하는 문제이다.

`set<pair<int, int>> sst` 를 선언하여 `{count, number}` 를
저장한다. 오름차순으로 정렬되어 저장된다. 개수가 가장 많은 숫자 부터
`B[]` 의 처음 부터 2 칸씩 건너 뛰어 저장한다. 그리고 1 부터 2 칸씩
건너 뛰어 저장한다.

이것을 조금 더 최적화 해보자. 가장 개수가 많은 숫자만 처음부터 2 칸씩
저장이 되어 있다면 다른 수들은 개수에 상관 없이 저장해도 된다. 즉 위와
달리 sorting 이 필요 없다.

문제의 조건에 의해 `1 <= B.size() <= 10000` 이다. `vector<int>
cnts(10001)` 를 선언하여 `cnts[number] = count of number` 를
저장한다. 이 때 가장 개수가 많은 숫자를 `B[]` 의 처음부터 2 칸씩 건너
뛰어 저장한다. 그 다음은 개수에 상관없이 2 칸씩 건너 뛰어 저장해도
된다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
