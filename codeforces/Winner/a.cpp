// Copyright (C) 2017 by iamslash
// http://codeforces.com/problemset/problem/2/A
#include <string>
#include <map>
#include <algorithm>
#include <vector>

#define MININT -987654321

int N;

int get_max_score(const std::map<std::string, int>& m) {
  return std::max_element(m.begin(), m.end(),
                          [](const std::pair<std::string, int>& lhs,
                             const std::pair<std::string, int>& rhs)
                          { return lhs.second < rhs.second; })->second;
}

std::vector<std::string>
get_max_name(const std::map<std::string, int>& m, int score) {
  std::vector<std::string> r;
  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second == score)
      r.push_back(it->first);
  }
  return r;
}

bool isin(std::vector<std::string> names, std::string name) {
  return std::find(names.begin(), names.end(), name) != names.end();
}

int main() {
  scanf("%d", &N);
  std::map<std::string, int> namescores;
  std::vector<std::pair<std::string, int> > history;
  //
  for (int i = 0; i < N; ++i) {
    char key[64];
    int val;
    scanf("%s %d", key, &val);
    history.push_back(std::make_pair(key, val));
    if (namescores.find(key) == namescores.end()) {
      namescores[key] = 0;
    }
    namescores[key] += val;
  }
  // get people with max scores
  int maxscore = get_max_score(namescores);
  std::vector<std::string > maxnames =
      get_max_name(namescores, maxscore);
  // trace history
  std::string r;
  for (int i = 0; i < history.size(); ++i) {
    std::string name = history[i].first;
    int score = history[i].second;
    if (isin(maxnames, name)) {
      namescores[name] -= score;
      if (namescores[name] <= 0) {
        r = name;
        break;
      }
    }
  }
  printf("%s\n", r.c_str());

  return 0;
}
