// Copyright (C) 2025 by iamslash

// 0ms 100.00% 55.75MB 0.0%
// math
// O(1) O(1)
function abs(x) {
  return x < 0 ? -x : x;
}
function gcd(a, b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
/**
 * @param {number} n
 * @return {number}
 */
var gcdOfOddEvenSums = function(n) {
  const nn = n + n;
  const sum = nn * (nn + 1) / 2;
  const sumOdd = (sum - n) / 2;
  const sumEvn = sumOdd + n;

  return gcd(sumEvn, sumOdd);
};

console.log("Hello World")