// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/BOARDCOVER2

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> BOARD;
std::vector<std::string> BLOCK;
bool COVERED[10][10];

int H, W, R, C;
int BEST;  // maximum possible count
std::vector<std::vector<std::pair<int, int> > > ROTATIONS;

bool set(int y, int x, int block_idx, bool value) {
  const std::vector<std::pair<int, int> >& block = ROTATIONS[block_idx];
  for (const auto & p : block) {
    int tgt_y = p.first + y;
    int tgt_x = p.second + x;
    if (tgt_y < 0 || tgt_y >= H || tgt_x < 0 || tgt_x >= W)
      return false;
    if (COVERED[tgt_y][tgt_x] == value)
      return false;
  }
  for (const auto & p : block) {
    int tgt_y = p.first + y;
    int tgt_x = p.second + x;
    COVERED[tgt_y][tgt_x] = value;
  }
  return true;
}

std::vector<std::string> rotate(const std::vector<std::string>& block) {
  std::vector<std::string> r(block);
  for (int i = 0; i < block.size(); ++i)
    for (int j = 0; j < block[0].size(); ++j)
      r[j][block.size() - i - 1] = block[i][j];
  return r;
}

void build_block_rotations() {
  ROTATIONS.clear();
  ROTATIONS.resize(4);

  // rotate it
  for (int r = 0; r < 4; ++r) {
    int pvt_y = -1;
    int pvt_x = -1;
    for (int i = 0; i < BLOCK.size(); ++i) {
      for (int j = 0; j < BLOCK[i].size(); ++j) {
        if (BLOCK[i][j] == '#') {
          // set pivot position with first top left '#'
          if (pvt_y == -1) {
            pvt_y = i;
            pvt_x = j;
          }
          ROTATIONS[r].push_back(
              std::make_pair(i - pvt_y, j - pvt_x));
        }
      }
    }
    BLOCK = rotate(BLOCK);
  }

  // remove duplicated rotation blocks
  std::sort(ROTATIONS.begin(), ROTATIONS.end());
  const auto& it = std::unique(ROTATIONS.begin(), ROTATIONS.end());
  ROTATIONS.erase(it, ROTATIONS.end());
}

void search(int done) {
  int y = -1;
  int x = -1;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (COVERED[i][j] == false) {
        y = i;
        x = j;
        break;
      }
    }
  }
  // base condition
  if (y == -1) {
    BEST = std::max(BEST, done);
    return;
  }
  // recursion
  // 0. include this position
  for (int i = 0; i < ROTATIONS.size(); ++i) {
    if (set(y, x, i, true))
      search(done + 1);
    set(y, x, i, false);
  }
  // 1. not include this position
  COVERED[y][x] = true;
  search(done);
  COVERED[y][x] = false;
}

int solve() {
  BEST = 0;
  // init COVERED
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      COVERED[i][j] = (BOARD[i][j] == '#' ? 1 : 0);
    }
  }

  // build block rotations
  build_block_rotations();
  // exhaustive search
  search(0);
  
  return BEST;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d %d %d", &H, &W, &R, &C);
    BOARD.resize(H);
    BLOCK.resize(W);
    for (int i = 0; i < H; ++i) {
      char buf[16];
      scanf("%s", buf);
      BOARD[i] = buf;
    }
    for (int i = 0; i < R; ++i) {
      char buf[16];
      scanf("%s", buf);
      BLOCK[i] = buf;
    }
    printf("%d\n", solve());
  }
  return 0;
}
