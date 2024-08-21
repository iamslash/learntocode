// Copyright (C) 2024 by iamslash

// a: 1
// b: 2
//
//      
// c: 0 0  
// a: 1 1
// b: 0 0

// a: 1
// b: 3
//
// c: 0 0 0
// a: 1 0 0
// b: 0 0 0

// Idea: bitwise summation
// 
// Keyword: xor, and 
// a: sum without carry of a, b
// b: shifted carry to be added next
// [bitwise arithmetic](/fundamentals/bitmask/arithmetic/README.md)

// 0ms 100.00% 40.6MB 15.21%
// iterative bitwise summation
// O(N) O(1)
class Solution {
    public int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }

        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }

        return a;
    }
}

// 0ms 100.00% 40.3MB 33.27%
// recursive bitwise summation
// O(N) O(N)
class Solution {
    public int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
    }
}
