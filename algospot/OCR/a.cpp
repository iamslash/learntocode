#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <cstring>

int m, q, N;  // 원문에 출현할 수 있는 단어의 수, 처리해야할 문장의 수
double B[501];  // 원문에 대하여 i가 문장의 처음에 출현할 확률
double T[501][501];  // 원문에 대하여 i이후 j가 출현할 확률
double M[501][501];  // i가 j로 인식될 확률
std::string WORDS[501];  // 사전
double CACHE[102][502];  // 인식된 문장의 단어 idx, prev 원문 단어 idx
int CHOICE[102][502];  // best case
int R[100];

int word_to_idx(std::string s) {
  for (int i = 0; i < m; ++i) {
    if (s.compare(WORDS[i]) == 0)
      return i;
  }
  assert(0);
}

double _solve(int cur_recog_idx, int prev_match_idx) {
  // printf("  ");
  // for (int i = 0; i < cur_recog_idx; ++i)
  //   printf(" ");
  // printf("%d %d\n", cur_recog_idx, prev_match_idx);
  
  // base condition
  if (cur_recog_idx == N)
    return 0;
  double& r = CACHE[cur_recog_idx][prev_match_idx];  
  if (r != 1.0)
    return r;
  r = -1e200;
  int& choose = CHOICE[cur_recog_idx][prev_match_idx];
  // recursion
  for (int cur_match_idx = 0; cur_match_idx < m; ++cur_match_idx) {
    double cand = T[prev_match_idx][cur_match_idx] +
                  M[cur_match_idx][R[cur_recog_idx]] +
                  _solve(cur_recog_idx + 1, cur_match_idx);
    if (r < cand) {
      r = cand;
      choose = cur_match_idx;
    }
  }
  return r;
}

void solve() {
  for (int i = 0; i < 102; ++i)
    for (int j = 0; j < 502; ++j)
      CACHE[i][j] = 1.0;

  double r = -1e200;
  for (int cur_match_idx = 0; cur_match_idx = m; ++cur_match_idx) {
    double cand = B[cur_match_idx] + M[cur_match_idx][R[0]] +
        _solve(1, cur_match_idx);
    if (r < cand) {
      CACHE[0][0] = cand;
      CHOICE[0][0] = cur_match_idx;
    }
  }

}

// TODO(iamslash): prev_match_idx can be negative
std::string reconstruct(int cur_recog_idx, int prev_match_idx) {
  int choose = CHOICE[cur_recog_idx][prev_match_idx];
  // printf("  %d %d %d\n", cur_recog_idx, prev_match_idx, choose);
  std::string r = WORDS[choose];
  if (cur_recog_idx < N - 1)
    r += " " + reconstruct(cur_recog_idx + 1, choose);
  return r;
}

int main() {
  scanf("%d %d", &m, &q);
  for (int i = 0; i < m; ++i) {
    char buf[1024];
    scanf("%s", buf);
    WORDS[i] = buf;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%lf", &B[i]);
    // B[i] = B[i] == 0.0 ? 0.0 : log(B[i]);
    B[i] = log(B[i]);
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lf", &T[i][j]);
      // T[i][j] = T[i][j] == 0.0 ? 0.0 : log(T[i][j]);
      T[i][j] = log(T[i][j]);
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lf", &M[i][j]);
      // M[i][j] = M[i][j] == 0.0 ? 0.0 : log(M[i][j]);
      M[i][j] = log(M[i][j]);
    }
  }
  for (int i = 0; i < q; ++i) {
    
    scanf("%d", &N);
    for (int j = 0; j < N; ++j) {
      char buf[1024];
      scanf("%s", buf);
      R[j] = word_to_idx(buf);
    }
    solve();
    printf("%s\n", reconstruct(0, 0).c_str());
  }
}

