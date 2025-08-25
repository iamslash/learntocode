struct Solution;

// 0ms 100.00% 2.03MB 100.00%
// math
// O(1) O(1)
impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        if b == 0 {
            return a.abs();
        }
        return Solution::gcd(b, a % b);
    }    

    pub fn gcd_of_odd_even_sums(n: i32) -> i32 {
        let nn = n + n;
        let sum = nn * (nn + 1) / 2;
        let sum_odd = (sum - n) / 2;
        let sum_evn = sum_odd + n;

        return Solution::gcd(sum_evn, sum_odd);
    }
}

fn main() {
    println!("{}", Solution::gcd_of_odd_even_sums(1));
}