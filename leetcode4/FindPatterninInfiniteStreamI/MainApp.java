// Copyright (C) 2024 by iamslash

import java.util.*;

//          n
//  stream: 1 1 1 0 1 1 1
//          i
// pattern: 0 1


// kmp
// O(N) O(N)
// 86ms 12.77% 61.4MB 65.96%
class Solution {
    private boolean match(int[] window, int[] pattern) {
        for (int i = 0; i < pattern.length; ++i) {
            if (window[i] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
    public int findPattern(InfiniteStream infiniteStream, int[] pattern) {
        int n = pattern.length;
        int[] window = new int[n];
        for (int i = 0; i < n; ++i) {
            window[i] = infiniteStream.next();
        }

        int beg = 0;
        while (true) {
            if (match(window, pattern)) {
                return beg;
            }
            
            for (int i = 1; i < n; ++i) {
                window[i - 1] = window[i];
            }
            window[n - 1] = infiniteStream.next();
            beg++;
        }
    }
}

// 16ms 95.74% 62.4MB 65.96%
// kmp
// O(N) O(N)
class Solution {
    public int findPattern(InfiniteStream infiniteStream, int[] pattern) {
        // Determine the length of the pattern
        int patternLength = pattern.length;
        // Initialize the LPS array for the pattern
        int[] lps = new int[patternLength];
        
        // Preprocess the pattern to fill the LPS array
        preprocessPattern(pattern, lps);
        
        // Variables to track the current position in the stream and pattern
        // Start from -1 because we increment at the beginning of the loop
        int streamIndex = -1;
        // Index to track the current character in the pattern
        int patternIndex = 0; 
        // Placeholder for the current bit from the stream, initialized to a non-matching value
        int currentBit = 2;
        
        // Continue reading from the stream indefinitely
        while (true) {
            // Increment stream index and read the next bit
            streamIndex++;
            currentBit = infiniteStream.next();
            
            // Main loop to handle pattern matching
            while (true) {
                if (currentBit == pattern[patternIndex]) {
                    // If the current bit matches the pattern, move to the next character in the pattern
                    patternIndex++;
                    // If the entire pattern has been matched
                    if (patternIndex == patternLength) {
                        // Return the starting index of the pattern match in the stream
                        return streamIndex - patternLength + 1;
                    }
                    // Exit the inner loop to read the next bit from the stream
                    break;
                } else if (patternIndex > 0) {
                    // On mismatch, use the LPS array to skip unnecessary comparisons
                    patternIndex = lps[patternIndex - 1];
                } else {
                    // If no part of the pattern has been matched, exit the inner loop to read the next bit
                    break;
                }
            }
        }
    }
    
    private void preprocessPattern(int[] pattern, int[] lps) {
        // The length of the longest proper prefix which is also a suffix
        int length = 0;
        lps[0] = 0; // LPS of the first character is always 0
        
        int i = 1;
        while (i < pattern.length) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
