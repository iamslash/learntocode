// Copyright (C) 2017 by iamslash
// http://practice.geeksforgeeks.org/problems/subset-sum-problem/0

// Subset Sum Problem

// Given a set of numbers, check whether it can be partitioned into
// two subsets such that the sum of elements in both subsets is same
// or not.

// Input:The first line contains an integer ‘T’ denoting the total
// number of test cases. Each test case constitutes of two
// lines. First line contains ‘N’, representing the number of
// elements in the set and the second line contains the elements of
// the set.

// Output: Print YES if the given set can be partioned into two
// subsets such that the sum of elements in both subsets is equal,
// else print NO.

// Constraints: 
// 1 <= T<= 100
// 1 <= N<= 100
// 0 <= arr[i]<= 1000
  
// Example:
// Input:
// 2
// 4
// 1 5 11 5
// 3
// 1 3 5

// Output:
// YES
// NO

// g++ -std=c++11 -o a.exe a.cpp

#include <cstdio>
#include <vector>

int N;
std::vector<int> NUMS;
char CACHE[101][100001]; // -1, 0, 1

char exist_subset(int idx, int sum) {
  // base condition
  if (sum == 0)
    return 1;
  if (idx == N && sum != 0)
    return 0;

  // memoization
  char& r = CACHE[idx][sum];
  if (r != -1)
    return r;
    
  // recursion
  if (NUMS[idx] > sum)
    return r = exist_subset(idx+1, sum);
  
  return r = exist_subset(idx+1, sum-NUMS[idx]) ||
      exist_subset(idx+1, sum);
}

bool solve(int sum) {
  if (sum % 2 != 0)
    return false;
  return exist_subset(0, sum/2);
}

bool solve_iter(int sum) {
  if (N == 1)
    return false;
  if (sum % 2 != 0)
    return false;
  sum = sum / 2;
  
  // init result
  // result[i][j] :
  // there is a subset of NUMS[0..i] with sum equal to j ???
  bool result[N][sum+1];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= sum; ++j) {
      result[i][j] = false;
      if (j == 0 || j == NUMS[0])
        result[i][j] = true;
    }
  }
  
  for (int i = 1; i < N; ++i) {
    int num = NUMS[i];
    for (int j = 1; j <= sum; ++j) {
      if (num <= j) {
        result[i][j] = result[i-1][j] || result[i-1][j-num];
      }
    }
  }

  // for (int i = 0; i < N; ++i) {
  //   printf("NUMS[%2d] %2d : ", i, NUMS[i]);
  //   for (int j = 0; j <= sum; ++j) {
  //     printf("%2d ", result[i][j]); 
  //   }
  //   printf("\n");
  // }
  
  return result[N-1][sum];
}


bool solve_iter_window(int sum) {
  if (N == 1)
    return false;
  if (sum % 2 != 0)
    return false;
  sum = sum / 2;

  bool result[2][sum+1];
  for (int j = 0; j <= sum; ++j) {
    result[0][j] = false;
    if (j == 0 || j == NUMS[0])
      result[0][j] = true;
  }

  printf("NUMS[%2d] %2d : ", 0, NUMS[0]);
  for (int j = 0; j <= sum; ++j) {
    printf("%2d ", result[0][j] ? 1 : 0); 
  }
  printf("\n");
  
  for (int i = 1; i < N; ++i) {
    int num = NUMS[i];
    int a = i % 2;
    int b = (i+1)%2;

    result[a][0] = true;
    for (int j = 1; j <= sum; ++j) {
      if (j < num) {
        result[a][j] = result[b][j];
      } else {
        result[a][j] = result[b][j] || result[b][j-num];
      }
    }
    
    printf("NUMS[%2d] %2d : ", i, NUMS[i]);
    for (int j = 0; j <= sum; ++j) {
      printf("%2d ", result[a][j] ? 1 : 0); 
    }
    printf("\n");
  }

// 4
// 1 5 11 5
//
// NUMS[ 0]  1 :  1  1  0  0  0  0  0  0  0  0  0  0
// NUMS[ 1]  5 :  1  0  0  0  0  1  1  0  0  0  0  0
// NUMS[ 2] 11 :  1  0  0  0  0  0  0  0  0  0  0  1
// NUMS[ 3]  5 :  1  0  0  0  0  1  0  0  0  0  0  1
  
  return result[(N-1)%2][sum];
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // for (int i = 0; i < 101; ++i)
    //   for (int j = 0; j < 100001; ++j)
    //     CACHE[i][j] = -1;
    scanf("%d", &N);
    NUMS.resize(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &NUMS[i]);
      sum += NUMS[i];
    }
    printf("%s\n", solve_iter_window(sum) ? "YES" : "NO");
  }
}
