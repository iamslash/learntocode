
// 960ms 91.67% 128.5MB 79.17%
// greedy
// O(N) O(1)
class Solution {
    fun mergeTriplets(tris: Array<IntArray>, tgt: IntArray): Boolean {
        var fndA = false; var fndB = false; var fndC = false
        for (tri in tris) {
            if (tri[0] == tgt[0] && tri[1] <= tgt[1] && tri[2] <= tgt[2]) {
                fndA = true
            }
            if (tri[0] <= tgt[0] && tri[1] == tgt[1] && tri[2] <= tgt[2]) {
                fndB = true
            }
            if (tri[0] <= tgt[0] && tri[1] <= tgt[1] && tri[2] == tgt[2]) {
                fndC = true
            }
            if (fndA && fndB && fndC) {
                return true
            }
        }
        return false
    }
}
