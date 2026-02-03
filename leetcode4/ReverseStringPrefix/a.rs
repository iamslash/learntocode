struct Solution;

// linear traversal
// O(N) O(1)
// 0ms 100.00% 2.32MB 3.37%
impl Solution {
    pub fn reverse_prefix(s: String, k: i32) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        let k = k as usize;
        let h = k / 2;
        
        for i in 0..h {
            chars.swap(i, k - i - 1);
        }
        
        chars.iter().collect()
    }
}

fn main() {
    let result = Solution::reverse_prefix("abcdef".to_string(), 4);
    println!("{}", result);
}
