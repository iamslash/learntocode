/* Copyright (C) 2020 by iamslash */

package main


// i
// 10#

// 0ms 100.00% 2MB 100.00%
// bute force
// O(N) O(N)
func freqAlphabets(s string) string {
  i, n := 0, len(s)
  ans := []byte{}
  for i < n {
    if i + 2 < n && s[i+2] == '#' {
        num, _ := strconv.Atoi(s[i:i+2])
        ans = append(ans, 'a' + byte(num) - 1)
      i += 3
    } else {
      ans = append(ans, 'a' + s[i] - '1')
      i += 1
    }
  }
  return string(ans)
}
