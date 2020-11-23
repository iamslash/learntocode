/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <sstream>
#include <unordered_map>
#include <vector>

//        i
// " ( mult 3 ( add 2 3 ) ) "
//         i
// " ( let x 2 ( mult x 5 ) ) "

// 8ms 95.65% 11.7MB 89.47%
// O(N) O(N)
class Solution {
 private:
  std::stringstream m_ss;
  std::unordered_map<std::string, std::vector<int>> m_ctx;
  int UNUSED = -1;

  std::pair<std::string, int> eval() {
    std::string t;
    m_ss >> t;
    int r;

    if (t == "(") {
      std::string op;
      m_ss >> op;
      if (op == "add" || op == "mult") {
        auto op1 = eval();
        auto op2 = eval();
        std::string skip;
        m_ss >> skip;
        r = op == "add" ? op1.second + op2.second :
                          op1.second * op2.second;
      } else {
        std::vector<std::string> assign;
        std::pair<std::string, int> k, v;
        while (true) {
          k = eval();
          v = eval();
          r = k.second;
          if (v.first == ")")
            break;
          m_ctx[k.first].push_back(v.second);
          assign.push_back(k.first);
        }
        for (std::string a : assign)
          m_ctx[a].pop_back();
      } 
    } else if (t == ")") {
      r = UNUSED;
    } else if (std::isalpha(t.front())) {
      r = m_ctx[t].empty() ? UNUSED : m_ctx[t].back();
    } else {
      r = std::stoi(t);
    }

    return {t, r};
  }
 public:
  int evaluate(std::string s) {
    std::string exp;
    for (char c : s)
      exp.append(c == '(' ?
                    " ( " :
                 c == ')' ? " ) " : std::string(1, c));
    m_ss = std::stringstream(exp);
    return eval().second;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.evaluate("(add 1 2)"));
  // printf("%d\n", sln.evaluate("(mult 3 (add 2 3))"));
  // printf("%d\n", sln.evaluate("(let x 2 (mult x 5))"));
  // printf("%d\n", sln.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))"));
  // printf("%d\n", sln.evaluate("(let x 3 x 2 x)"));
  // printf("%d\n", sln.evaluate("(let x 1 y 2 x (add x y) (add x y))"));
  // printf("%d\n", sln.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))"));
  // printf("%d\n", sln.evaluate("(let a1 3 b2 (add a1 1) b2)"));
  // std::string s = "(let x0 -4 x1 2 x2 -4 x3 3 x4 2 x5 3 x6 2 x7 2 x8 -1 x9 -1 (mult (mult (mult x2 -8) (add -5 (let x0 1 x5 -3 (add (add x7 (add (let x0 -5 x9 -4 (add (mult 1 1) -10)) (mult -8 (mult x3 -5)))) (add (let x0 3 x8 -1 (let x0 -1 x9 1 (add x4 -6))) x9))))) (mult (add (mult (add (mult -6 (mult (add x1 x4) -4)) (let x0 -2 x7 4 (mult (mult (let x0 -3 (mult 1 1)) (add (mult 1 1) (mult 1 1))) (mult -5 (mult -9 (mult 1 1)))))) -10) x5) (mult (mult x5 -7) x8))))";
  // printf("%s\n", sln.evaluate(s));
  
  return 0;
}

