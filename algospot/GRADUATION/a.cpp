// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GRADUATION

#include <cstdio>
#include <vector>

#define MAXINT 987654321

int N, K, M, L;
std::vector<int> req;
std::vector<int> sem;

int CACHE[12][12];

void PrintCourse(int taken) {
  for (int i = 11; i >= 0; --i) {
    printf("%d ", (taken & (1 << i)) ? 1 : 0);
  }
  printf("\n");
}

bool IsPrerequisited(int idx, int taken) {
  // if does not need prerequisites return true;
  if (req[idx] == 0)
    return true;
  // check req[idx] are taken
  for (int i = 0; i < 12; ++i) {
    // i should be not lecture
    if (i == idx)
      continue;
    int bm = (req[idx] & (1 << i));
    if (bm == 0)
      continue;
    // printf("-----%d\n", lecture);
    // PrintCourse(req[lecture]);
    // PrintCourse(taken);
    // if i is not taken return false;
    if ((taken & bm) == 0)
      return false;
  }
  return true;
}

int GetLecCnt(int taken) {
  int r = 0;
  for (int i = 0; i < 12; ++i) {
    if (taken & (1 << i))
      r++;
  }
  return r;
}

// order = this semester order
// taken = taken courses bitmask
int Solve(int order, int taken) {
  // printf("  %d | ", order);
  // PrintCourse(taken);

  // memoization
  int& r = CACHE[order][taken];
  if (r > -1)
    return r;
  r = 0;

  // base condition
  if (GetLecCnt(taken) >= K && order <= L)
    return r = 0;
  else if (order > L || sem[order] == 0)
    return MAXINT;

  int willbetaken = 0;
  // recursion
  for (int i = 0; i < 12; ++i) {
    int lecture = sem[order] & (1 << i);
    // printf("  o:%d i:%d l:%d, ", order, i, lecture);
    // PrintCourse(taken);
    if (lecture == 0 || lecture & taken)
      continue;
    // prerequisited and not taken yet
    if (IsPrerequisited(i, taken))
      willbetaken |= (1 << i);
  }

  // printf("  %d | ", order);
  // PrintCourse(taken);
  // printf("      ");
  // PrintCourse(willbetaken);

  int delta = willbetaken > 0 ? 1 : 0;
  r = Solve(order + 1, taken | willbetaken) + delta;

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // init cache
    memset(CACHE, -1, sizeof(CACHE));

    scanf("%d %d %d %d", &N, &K, &M, &L);
    // req[i] = requirement lecture bitmask for lecture i
    req.resize(N, 0);
    sem.resize(M, 0);
    // input for prerequisites
    for (int i = 0; i < N; ++i) {
      int cnt;
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
        int lecture;
        scanf("%d", &lecture);
        req[i] |= (1 << lecture);
      }
    }
    // input for class
    for (int i = 0; i < M; ++i) {
      int cnt;
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
        int lecture;
        scanf("%d", &lecture);
        sem[i] |= (1 << lecture);
      }
    }
    int r = Solve(0, 0);
    if (r >= MAXINT) {
      printf("IMPOSSIBLE");
    } else {
      printf("%d", r);
    }
    printf("\n");
  }
  return 0;
}
