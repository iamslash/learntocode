

// // prefix sum
// // O(H^2W^2) O(HW)
// class Solution {
//     fun largestMagicSquare(grid: Array<IntArray>): Int {
//         val h = grid.size
//         val w = grid[0].size
//         var maxLen = 0
//         val rows = Array(h+2, {i -> IntArray(w+2)})
//         val cols = Array(h+2, {IntArray(w+2)})
//         val dia1 = Array(h+2, {IntArray(w+2)})
//         val dia2 = Array(h+2, {IntArray(w+2)})
        
//         return maxLen
//     }
// }

fun main() {
    // 1d array
    val a = Array(3, {i -> 0})
    val b = Array(3, {0})
    val c = IntArray(3, {i -> 0})
    val d = IntArray(3, {0})
    val e = arrayOf(1, 2, 3)
    val f = intArrayOf(1, 2, 3)
    // late initialization
    val h = arrayOfNulls<Number>(3)
    for (i in h.indices) {
        h[i] = i * i
    }

    // 2d array
    val aa = Array(3, {Array(3, {i -> 0})})
    val bb = Array(3, {Array(3, {0})})
    val cc = Array(3, {IntArray(3, {i -> 0})})
    val dd = Array(3, {IntArray(3, {0})})
    val ee = Array(3, {arrayOf(1, 2, 3)})
    val ff = Array(3, {intArrayOf(1, 2, 3)})
    // late initialization
    val hh = Array(3, {arrayOfNulls<Number>(3)})
    for (i in hh.indices) {
        for (j in hh[0].indices) {
            hh[i][j] = i * j
        }
    }
    for (i in 0 until 3) {
        for (j in 0 until 3) {
            hh[i][j] = i * j
        }
    }
}
