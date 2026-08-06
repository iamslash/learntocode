// Copyright (C) 2026 by iamslash

// 2ms 93.36% 46.47MB 66.87%
// linear traversal
// O(N) O(N)
class Solution {

    private int getWeight(String s, int[] weights) {
        int weight = 0;
        
        for (char c : s.toCharArray()) {
            weight += weights[c - 'a'];
        }

        return weight;
    }
    
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder ans = new StringBuilder();

        for (String word : words) {

            int weight = getWeight(word, weights) % 26;
            char c = (char)('a' + 25 - weight);
            ans.append(c);
        }

        return ans.toString();
    }
}
