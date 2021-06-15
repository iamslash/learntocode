import kotlin.Comparator;

// sort
// O(NlgN) O(1)
class Solution {
    fun isCovered(ranges: Array<IntArray>, left: Int, right: Int): Boolean {
        var leftMod = left
        ranges.sortedWith(Comparator<IntArray>{ a, b ->
            when {
                a[0] > b[0] -> 1
                a[0] < b[0] -> -1
                else -> 0
            }
        })
        ranges.forEach({ println(it.contentToString()) })
        for (pair in ranges) {
            if (pair[0] <= leftMod && leftMod <= pair[1]) {
                leftMod = pair[1] + 1
            }
        }
        return leftMod > right
    }
}
