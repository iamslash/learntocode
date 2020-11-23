// Copyright (C) 2017 by iamslash

// Boolean Evaluation: Given a boolean expression consisting of the
// symbols 0 (false), 1 (true), & (AND), | (OR), and ^ (XOR), and a
// desired boolean result value result, implement a function to count
// the number of ways of parenthesizing the expression such that it
// evaluates to result. The expression should be fully parenthesized
// (e.g., (0)^(1)) but not extraneously (e.g., (((0))^(1)))
//
// EXAMPLE
// countEval("1^0|0|1", false) -> 2
// countEval("0&0&0&1^1|0", true) -> 10

#include <cstdio>
#include <vector>

std::vector<char> OPS;

int CACHE[100][100][2];


void print_indent(int indent) {
  for (int i = 0; i < indent; ++i)
    printf("  ");
}
// return : profit case count
int solve(int indent, int start, int end, char result) {
  // print_indent(indent);
  // printf("%d %d %c\n", start, end, result);
  // memoization
  int& r = CACHE[start][end][result-'0'];
  if (r != -1) {
    // print_indent(indent);
    // printf(";%d\n", r);
    return r;
  }
  // base condition
  if (start == end - 1 && (OPS[start] == '0' || OPS[start] == '1')) {
    r = (OPS[start] == result ? 1 : 0);
    // print_indent(indent);
    // // printf(".%c %c %d\n", OPS[start], result, r);
    // printf(".%d\n", r);
    return r;
  }

  // recursion
  r = 0;
  for (int i = start + 1; i < end; ++i) {
    if (OPS[i] == '0' || OPS[i] == '1')
      continue;
    int left_true   = solve(indent+1, start, i, '1');  // 1
    int left_false  = solve(indent+1, start, i, '0');  // 0
    int right_true  = solve(indent+1, i+1, end, '1');  // 1
    int right_false = solve(indent+1, i+1, end, '0');  // 0
    int total       = (left_true + left_false) * (right_true + right_false);
    int total_true  = 0;
    if (OPS[i] == '&') {
      total_true += left_true * right_true;
    } else if (OPS[i] == '|') {
      total_true += left_true * right_true + left_false * right_true +
          left_true * right_false;
    } else if (OPS[i] == '^') {
      total_true += left_true * right_false + left_false * right_true;
    }
    r += result == '1' ? total_true : total - total_true;
  }
  // print_indent(indent);
  // printf(".%d\n", r);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // init
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        CACHE[i][j][0] = -1;
        CACHE[i][j][1] = -1;
      }
    }
    char buf1[1024];
    char buf2[1024];
    scanf("%s %s", buf1, buf2);
    int n_buf1_len = strlen(buf1);
    OPS.clear();
    for (int i = 0; i < n_buf1_len; ++i) {
        OPS.push_back(buf1[i]);
    }
    printf("%d\n",
           solve(0, 0, OPS.size(), strcmp(buf2, "true") == 0 ? '1' : '0'));
  }
  return 0;
}
