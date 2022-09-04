/* Copyright (C) 2022 by iamslash */

// 1308ms 100.00% 120MB 100.00%
// greedy, sort
// O(HW*lgHW) O(HW)
import kotlin.math.*
class Solution {
    fun minScore(grid: Array<IntArray>): Array<IntArray> {
        val h = grid.size
        val w = grid[0].size
        val ans: Array<IntArray> = Array<IntArray>(h, { IntArray(w, { 0 }) })
        val maxRows = IntArray(h, { 0 })
        val maxCols = IntArray(w, { 0 })
        val coordList: MutableList<IntArray> = mutableListOf()
        for (y in 0 until h) {
            for (x in 0 until w) {
                coordList.add(intArrayOf(y, x))
            }
        }
        coordList.sortWith(Comparator<IntArray>{ a: IntArray, b: IntArray -> 
            val c = grid[a[0]][a[1]]
            val d = grid[b[0]][b[1]]
            c - d
        })
        // coordList.forEach({ println("grid[${it[0]}][${it[1]}]: ${grid[it[0]][it[1]]}") })
        for (i in 0 until h * w) {
            val coord = coordList.get(i)
            val y = coord[0]
            val x = coord[1]
            val maxVal = max(maxRows[y], maxCols[x]) + 1
            maxRows[y] = maxVal
            maxCols[x] = maxVal
            ans[y][x] = maxVal
        }
        return ans
    }
}
