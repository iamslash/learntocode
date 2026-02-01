# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a competitive programming and algorithm learning repository containing solutions to problems from LeetCode, ACMICPC, Codeforces, HackerRank, and other online judges. Solutions are implemented in C++, Java, and Python.

## Compilation Commands

**C++ (primary language):**
```bash
g++ -std=c++11 -o a.out a.cpp && ./a.out
```

**Java:**
```bash
javac MainApp.java && java MainApp
```

**Python:**
```bash
python a.py
```

## Code Organization

**Problem Sources:**
- `leetcode/`, `leetcode2/`, `leetcode3/`, `leetcode4/` - LeetCode problems
- `fundamentals/` - Core algorithms organized by type (array, tree, graph, dynamicprog, etc.)
- `acmicpc.net/`, `algospot/`, `codeforces/`, `hackerrank/` - Other online judges
- `cracking/`, `careercup/`, `devinterview/` - Interview preparation

**Each problem folder contains:**
- `a.cpp` - C++ solution
- `MainApp.java` - Java solution
- `a.py` - Python solution (when available)
- `README.md` - Problem description, approach, and complexity analysis (often in Korean)

**Documentation:**
- `doc/` - Algorithm theory documentation
- Main `README.md` - Comprehensive index of algorithms and problems

## Code Conventions

**C++ solution structure:**
```cpp
#include <cstdio>
#include <vector>

// Performance: XXms YY% ZMB WW%
// O(time) O(space)
class Solution {
 public:
  ReturnType methodName(args) {
    // implementation
  }
};

int main() {
  // Test cases
  Solution sln;
  auto result = sln.methodName(args);
  return 0;
}
```

**Comments include:**
- LeetCode performance metrics (runtime/memory percentile)
- Time and space complexity as `O(X) O(Y)`
- Clarifying questions about constraints

## Testing

Solutions contain inline test cases in `main()`. Run the compiled binary to execute tests. No automated test framework is used.
