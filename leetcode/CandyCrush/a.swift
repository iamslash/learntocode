// Wrong Answer
// matrix
// O(HW) O(1)
class Solution {
    func candyCrush(_ B: [[Int]]) -> [[Int]] {
        let h = B.count
        let w = B[0].count
        var B = B
        while true {
            var found = false
            // crush
            for y in 0..<h {
                for x in 0..<w {
                    let val = abs(B[y][x])
                    if x + 2 < w, val > 0, val == abs(B[y][x+1]), val == abs(B[y][x+2]) {
                        B[y][x] = -val
                        B[y][x+1] = -val
                        B[y][x+2] = -val
                        found = true
                    }
                    if y + 2 < h, val > 0, val == abs(B[y+1][x]), val == abs(B[y+2][x]) {
                        B[y][x] = -val
                        B[y+1][x] = -val
                        B[y+2][x] = -val
                        found = true
                    }
                }
            }
            if !found {
                break
            }
            // drop
            for x in 0..<w {
                var i = h - 1
                for y in (0..<h).reversed() {
                    if B[y][x] >= 0 {
                        B[i][x] = B[y][x]
                        i -= 1
                    }
                }
                for y in (0...i).reversed() {
                    B[y][x] = 0
                }
            }
        }
        return B
    }
}
