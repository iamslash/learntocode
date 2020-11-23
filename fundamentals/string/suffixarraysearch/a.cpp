// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/HABIT

#include <string>
#include <vector>
#include <deque>
#include <algorithm>

void printv(const std::vector<int>& a) {
  for (int i=0; i < a.size(); ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void printd(const std::deque<int>& a) {
  for (int i=0; i < a.size(); ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void printsa(const std::string& s, const std::vector<int> v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%s\n", s.substr(v[i]).c_str());
  }
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

    // printv(group, perm, s);

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

    // printv(group, perm, s);
  }
  return perm;
}

int match_string(const std::string& H,
                 const std::string& N) {
  int r = 0;
  while (r < H.size() && r < N.size() && H[r] == N[r]) {
    ++r;
  }
  // printf("%2d %s %s\n", r, H.c_str(), N.c_str());

  if (r == N.size())
    return 0;
  if (H[r] < N[r])
    return 1;
  return -1;
}

// 0. 정확히 찾을때까지 이진 탐색한다.
// 1. 찾았다면 위아래로 검색한다. 접미사 배열은 문자순으로 정렬되어 있다.
std::deque<int> suffixarray_search(const std::string& H,
                                    const std::string& N) {
  int h = H.size();
  int n = N.size();
  std::deque<int> rtrn;
  //
  std::vector<int> a = get_suffix_array(H);
  // binary search in sa
  // printv(a);
  // printsa(H, a);

  // search locates the starting position of the interval
  int l = 0, r = h, matched = -1;
  while (l < r) {
    int m = (l+r) / 2;
    int c = match_string(H.substr(a[m]), N);
    // printf("%d\n", c);

    if (c == 0) {  // matched
      matched = m;
      rtrn.push_front(a[matched]);
      break;
    } else if (c > 0) {
      l = m + 1;
    } else {  // matched
      r = m;
    }
  }

  if (matched >= 0) {
    // find matched prefix on suffix
    int up_matched = matched;
    while (up_matched > 0) {
      up_matched--;
      int c = match_string(H.substr(a[up_matched]), N);
      if (c == 0) {  // matched
        rtrn.push_back(a[up_matched]);
      } else {
        up_matched = -1;
      }
    }

    // find matched prefix on suffix
    int dn_matched = matched;
    while (dn_matched > 0 && dn_matched < h - 1) {
      dn_matched++;
      int c = match_string(H.substr(a[dn_matched]), N);
      if (c == 0) {  // matched
        rtrn.push_back(a[dn_matched]);
      } else {
        dn_matched = -1;
      }
    }
  }

  return rtrn;
}

int main() {
  std::string h = "hellomynameisslashmynameisnotfoo";
  std::string n = "myname";

  std::deque<int> r = suffixarray_search(h, n);

  printf("%s\n", h.c_str());
  printf("%s\n", n.c_str());
  printd(r);
  // printf("%d\n", match_string("tfoo", "myname"));
  return 0;
}
