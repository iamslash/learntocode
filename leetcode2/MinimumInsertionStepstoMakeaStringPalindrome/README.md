# Problem

[Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

Given a string `s`. You can insert any character at any index of s.
Find the minimum number of steps to make `s` palindrome.

# Recursive way

## Idea

Let's take a look `s = mbadm` with two indexes `i, j`.

```
   i       j      i   j
s: m b a d m    m b a d m
                At this time we think 2 cases like these.
                
                  i   j
                m b a d b m
                    i j
                m d b a d m
```

We can make subproblem `dfs` like this.

```
int dfs(string s, int i, int j)
s: input
i: left index
j: right index
```

We can memoize with cache `vector<int> C`.

## Implementation

* [go](a.go)

## Complexity

```
O(N^2) O(N^2)
```

# Iterative way

## Idea

What if we find a [longest palindrome
subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)?

The answer is `s.len() - <longest-palindrome-subsequence>`.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N^2) O(N^2)
```
