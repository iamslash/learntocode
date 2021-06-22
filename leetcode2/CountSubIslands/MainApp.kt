
// 740ms 100.00% 74.3MB 100.00%
// DFS
// O(Hw) O(HW)
val dir: IntArray = intArrayOf(-1, 0, 1, 0, -1)
class Solution {    
    fun dfs(B: Array<IntArray>, y: Int, x: Int, c: Int): Unit {
        val h = B.size; val w = B[0].size
        B[y][x] = c
        for (i in 0 until 4) {
            val ny = y + dir[i]
            val nx = x + dir[i+1]
            if (ny < 0 || ny >= h || nx < 0 || nx >=w ||
                B[ny][nx] == 0) {
                continue
            }
            dfs(B, ny, nx, 0)
        }
    }
    fun countSubIslands(A: Array<IntArray>, B: Array<IntArray>): Int {
        val h = A.size
        val w = A[0].size
        for (y in 0 until h) {
            for (x in 0 until w) {
                if (A[y][x] == 0 && B[y][x] == 1) {
                    dfs(B, y, x, 0)
                }
            }
        }
        var cnt = 0
        for (y in 0 until h) {
            for (x in 0 until w) {
                if (B[y][x] == 1) {
                    dfs(B, y, x, 0)
                    cnt++
                }
            }    
        }
        return cnt
    }
}
