// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.84% 41.4MB 53.97%
// random, filter
// O(N) O(N)
class Solution {
    public void findSecretWord(String[] words, Master master) {
        Random random = new Random();
        int count = 30, n = words.length;
        while(count > 0) {
            count--;
            String rndWord = words[random.nextInt(n)]; 
            int matchCnt = master.guess(rndWord);
            if(matchCnt == 6) {
                break;
            }
            List<String> candList = new ArrayList<>();
            for(String word : words) {
                if(matchCnt == getMatches(rndWord, word)) {
                    candList.add(word);
                }
            }
            words = candList.toArray(new String[0]);
        }
    }
    private int getMatches(String word1, String word2) {
        int count = 0;
        for(int i = 0; i < 6; i++) {
            if(word1.charAt(i) == word2.charAt(i)) {
                count++;
            }
        }
        return count;
    } 
}

// 3ms 21.56% 41.3MB 71.31%
// string
// O(N) O(N)
class Solution {

    private int match(String s1, String s2) {
        int matchCnt = 0;

        for (int i = 0; i < s1.length(); ++i) {
            if (s1.charAt(i) == s2.charAt(i)) {
                matchCnt++;
            }
        }

        return matchCnt;
    }
    
    public void findSecretWord(String[] words, Master master) {

        int matchCnt = 0;

        while (matchCnt < 6) {
            List<int[]> posFreqList = new ArrayList<>();
            for (int i = 0; i < 6; ++i) {
                posFreqList.add(new int[26]);
            }

            for (String word : words) {
                for (int i = 0; i < 6; ++i) {
                    char c = word.charAt(i);
                    posFreqList.get(i)[c - 'a']++;
                }
            }

            String bestGuess = "";
            int maxScore = -1;
            for (String word : words) {
                int score = 0;
                for (int i = 0; i < 6; ++i) {
                    char c = word.charAt(i);
                    score += posFreqList.get(i)[c - 'a'];
                }
                if (score > maxScore) {
                    maxScore = score;
                    bestGuess = word;
                }
            }

            matchCnt = master.guess(bestGuess);

            List<String> filteredWordList = new ArrayList<>();
            for (String word : words) {
                if (match(bestGuess, word) == matchCnt) {
                    filteredWordList.add(word);
                }
            }

            words = filteredWordList.toArray(new String[0]);
            
        }
        
    }
}
