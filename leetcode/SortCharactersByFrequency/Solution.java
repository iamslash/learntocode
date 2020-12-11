
// 3ms 95.55% 39.2MB 97.37%
class Solution {
    public String frequencySort(String s) {
        int[] freqs = new int[256];
        Arrays.fill(freqs, 0);
        for (int i = 0; i < s.length(); ++i) {
            freqs[s.charAt(i)]++;
        }
        StringBuilder sb = new StringBuilder();
        int maxidx = 0, maxval = Integer.MIN_VALUE;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < 256; ++j) {
                if (maxval < freqs[j]) {
                    maxval = freqs[j];
                    maxidx = j;
                }
            }            
            if (maxval == 0) {
                return sb.toString();
            } else {
                for (int k = 0; k < maxval; ++k) {
                    sb.append((char)maxidx);
                }
                freqs[maxidx] = 0;
                maxval = Integer.MIN_VALUE;
            }
        }
        return sb.toString();
    }
}
