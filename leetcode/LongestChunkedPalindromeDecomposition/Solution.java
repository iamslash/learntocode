class Solution {
  public int longestDecomposition(String s) {
    int ans = 0, n = s.length();
    String l = "", r = "";
    for (int i = 0; i < n; ++i) {
      l = l + s.charAt(i);
      r = s.charAt(n - i - 1) + r;
      if (l.equals(r)) {
        ++ans;
        l = "";
        r = "";
      }
    }
    return ans;
  }
}
