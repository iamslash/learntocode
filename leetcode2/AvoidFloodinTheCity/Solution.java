// [1,2,0,0,2,1]
//              i
//   R: 1 2 0 0 2 1 
// ans: - - 2 0 - -  
// unordered_map<int, int> lakeMap: {1, 0}
// vector<int> zeroIdxSet: {3}

class Solution {
  public int[] avoidFlood(int[] R) {
    int n = R.length;
    Map<Integer, Integer> lakeMap = new HashMap<>();
    TreeSet<Integer> zeroIdxSet = new TreeSet<>();
    int[] ans = new int[n];
    Arrays.fill(ans, -1);
    for (int i = 0; i < n; ++i) {
      if (R[i] == 0) {
        zeroIdxSet.add(i);
        ans[i] = 1;
        continue;
      } 
      if (lakeMap.containsKey(R[i])) {
        Integer idx = zeroIdxSet.higher(lakeMap.get(R[i]));
        if (idx == null)
          return new int[]{};
        ans[idx] = R[i];
        zeroIdxSet.remove(idx);
        lakeMap.remove(R[i]);
      }
      lakeMap.put(R[i], i);
    }
    return ans;
  }
}
