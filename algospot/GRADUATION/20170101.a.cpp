// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GRADUATION

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>
#include <cassert>

const int INF = 987654321;
const int MAXN = 12;
int N, K, M, L;

// prerequisite[i] = i번째 과목의 선수과목의 집합을 비트마스크로 표현
int prerequisite[MAXN];
// classes[i] = i번째 학기에 개설되는 과목의 집합을 비트마스크로 표현
int classes[10];
// CACHE[i][j] = i번째 학기에 j과목을 수강했다.
int CACHE[10][1 << MAXN];
// n의 이진수 표현에서 켜진 비트의 수를 반환한다.
int bit_count(int n) {
  int r = 0;
  for (int i=0; i < MAXN; ++i) {
    if ((n & 1) == 1)
      ++r;
    n = n >> 1;
  }
  return r;
}
// 이번학기가 semester이고, 지금까지 들은 과목의 집합이 taken일때
// K개 이상의 과목을 모두 들으려면 몇 학기가 더 있어야 하는가?
// 불가능한 경우는 INF를 반환한다.
int graduate(int semester, int taken) {
  // base condition
  if (bit_count(taken) >= K)
    return 0;
  // base condition
  if (semester >= M)
    return INF;
  // memoization
  int& r = CACHE[semester][taken];
  if (r >= 0)
    return r;
  r = INF;
  // 이번 학기에 들을 수 있는 과목중 아직 듣지 않은 과목들을 찾는다.
  int can_take = (classes[semester] & ~taken);
  // 선수 과목을 다듣지 않은 과목들을 걸러낸다.
  for (int i = 0; i < N; ++i) {
    if ((can_take & (1 << i)) &&
        (taken & prerequisite[i]) != prerequisite[i])
      can_take &= ~(1 << i);
  }
  // can_take 0111
  // 이 집합의 모든 부분집합을 순회한다.
  for (int take = can_take; take > 0;
       take = ((take - 1) & can_take)) {
    // 한 학기에 L과목까지만 들을 수 있다.
    if (bit_count(take) > L)
      continue;  // WHY???
    r = fmin(r, graduate(semester + 1, taken | take) + 1);
  }
  // 이번 학기에 아무것도 듣지 않을 경우
  r = fmin(r, graduate(semester + 1, taken));
  return r;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    // init CACHE
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j <= (1 << MAXN); ++j) {
        CACHE[i][j] = -1;
      }
    }
    // init prerequisite, classes
    memset(prerequisite, 0, sizeof(prerequisite));
    memset(classes, 0, sizeof(classes));
    //
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &M);
    scanf("%d", &L);

    // 선수과목 처리
    for (int i=0; i < N; ++i) {
      int pre_cnt;
      scanf("%d", &pre_cnt);
      for (int j=0; j < pre_cnt; ++j) {
        int lecture;
        scanf("%d", &lecture);
        prerequisite[i] |= (1 << lecture);
      }
    }
    // 개설과목 처리
    for (int i=0; i < M; ++i) {
      int lecture_cnt;
      scanf("%d", &lecture_cnt);
      for (int j=0; j < lecture_cnt; ++j) {
        int lecture;
        scanf("%d", &lecture);
        classes[i] |= (1 << lecture);
      }
    }
    // print result
    int r = graduate(0, 0);
    if (r == INF)
      printf("IMPOSSIBLE");
    else
      printf("%d", r);
    printf("\n");
  }
  return 0;
}
