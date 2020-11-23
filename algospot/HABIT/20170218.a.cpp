// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/HABIT

#include <string>
#include <vector>
#include <algorithm>

int K;

void print_v_int(const std::vector<int>& g,
                 const std::vector<int>& a,
                 const std::string& s) {
  // printf(" <----\n");
  for (int i=0; i < a.size(); ++i) {
    printf(" (%3d)%2d %-7s\n", g[a[i]], a[i], s.substr(a[i]).c_str());
  }
  // printf(" ---->\n");
}

// 각 접미사들의 첫 t글자를 기준으로 한 그룹번호가 주어질 때,
// 주어진 두접미사를 첫 2 * t글자를 기준으로 비교한다.
// group[]은 길이가 0인 접미사도 포함한다.
struct Comparator {
  const std::vector<int>& group;
  int t;
  Comparator(const std::vector<int>& _group, int _t) : group(_group) {
    t = _t;
  }
  bool operator() (int a, int b) {
    // printf("a:(%3d)%2d, (%3d)b:%2d\n", group[a], a, group[b], b);
    // 첫 t글자가 다르면 이들을 이용해 비교한다.
    if (group[a] != group[b])
      return group[a] < group[b];
    // 아니라면 S[a+t..]와 s[b+t..]의 첫t글자를 비교한다.
    return group[a + t] < group[b + t];
  }
};

// s의 접미사 배열을 계산한다.
std::vector<int> get_suffix_array(const std::string& s) {
  int n = s.size();
  // group[i] = 접미사들을 첫 t글자를 기준으로 정렬했을 때,
  // s[i..]가 들어가는 그룹번호.
  // t = 1일때는 정렬할 것 없이 S[i..]의 첫글자로 그룹번호를
  // 정해줘도 같은 효과가 있다.
  int t = 1;
  std::vector<int> group(n+1);
  for (int i = 0; i < n; ++i) {
    group[i] = s[i];
  }
  group[n] = -1;
  // 결과적으로 접미사 배열이 될 반환 값, 이 배열을 lg(n)번 정렬한다.
  std::vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    perm[i] = i;

  //
  while (t < n) {
    // group[]은 첫 t글자를 기준으로 계산해 뒀다.
    // 첫 2t글자를 기준으로 perm을 다시 정렬한다.
    Comparator compare_using_2T(group, t);
    // printf("====1st:%2d\n", t);
    sort(perm.begin(), perm.end(), compare_using_2T);

    // print_v_int(group, perm, s);

    // 2t글자가 n을 넘는다면 이제 접미사 배열 완성.
    t *= 2;
    if (t >= n)
      break;

    // printf("t is %d\n", compare_using_2T.t);
    // printf("----2nd\n");

    // 2t글자를 기준으로 한 그룹 정보를 만든다.
    std::vector<int> new_group(n + 1);
    new_group[n] = -1;
    new_group[perm[0]] = 0;
    for (int i = 1; i < n; ++i) {
      if (compare_using_2T(perm[i-1], perm[i])) {
        new_group[perm[i]] = new_group[perm[i-1]] + 1;
      } else {
        new_group[perm[i]] = new_group[perm[i-1]];
      }
    }
    group = new_group;

    // print_v_int(group, perm, s);
  }
  return perm;
}

// S[i..]와 S[j..]의 공통 접두사의 최대 길이를 계산한다.
int common_prefix(const std::string& s, int i, int j) {
  int r = 0;
  while (i < s.size() && j < s.size() && s[i] == s[j]) {
    ++i;
    ++j;
    ++r;
  }
  return r;
}

// k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다.
int longest_frequent(int k, const std::string& s) {
  std::vector<int> a = get_suffix_array(s);
  int r = 0;
  for (int i = 0; i + k < s.size(); ++i) {
    r = std::max(r, common_prefix(s, a[i], a[i + k - 1]));
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &K);
    char buf[4000];
    scanf("%s", buf);
    std::string s = buf;

    //
    printf("%d\n", longest_frequent(K, s));
    // std::vector<int> a = get_suffix_array(s);
  }
  //
  return 0;
}
