// Copyright (C) 2024 by iamslash

import java.util.*;

// number: 123
//          -
// dfs(0, 0, 0)
//   dfs(1,1,1)
//     dfs(2,3,2)   - '+'
//     dfs(2,-1,-2) - '-'
//       dfs(3,2,3)    - '+'
//       dfs(3,-4,-3)  - '-'
//       dfs(3,3,3)    - '*', "1 - 2 * 3"
//     dfs(2,2,2)   - '*'
//       dfs(3,5,3)
//       dfs(3,-1,3)
//       dfs(3,6,3)    - '*', "1 * 2 * 3"
//     dfs(3,...)   - '+'
//     dfs(3,...)   - '-'
//     dfs(3,...)   - '*'
//   dfs(2,12,12)
//   dfs(3,123,123)

// Idea: backtracking
//
// Define void dfs(num, target, rst, cand, pos, lastEval, lastTerm)
// -      num: given number by problem
// -   target: given target number by problem
// -      rst: result list
// -     cand: The candidate string to be inserted to rst
// -      pos: starting position of current term 
// - lastEval: evaluation of previous lastEval and lastTerm 
// - lastTerm: last term

// 108ms 57.50% 45.5MB 41.72%
// backtracking
// O(3^N) O(N)
class Solution {
    
    private void dfs(String num,
                     int target,
                     List<String> rst,
                     String cand,
                     int pos,
                     long lastEval,
                     long lastTerm) {
        int n = num.length();
        // base
        if (pos == n) {
            if (target == lastEval) {
                rst.add(cand);
            }
            return;
        }

        // recursion
        for (int i = pos; i < n; ++i) {
            if (i != pos && num.charAt(pos) == '0') {
                break;
            }

            long currTerm = Long.parseLong(num.substring(pos, i + 1));
            if (pos == 0) {
                dfs(num, target, rst, cand + currTerm, i+1, currTerm, currTerm);
            } else {
                dfs(num, target, rst, cand + "+" + currTerm, i + 1, lastEval + currTerm, currTerm);
                dfs(num, target, rst, cand + "-" + currTerm, i + 1, lastEval - currTerm, -currTerm);
                dfs(num, target, rst, cand + "*" + currTerm, i + 1,
                    lastEval - lastTerm + lastTerm * currTerm,
                    lastTerm * currTerm);
            }
        }
    }
    
    public List<String> addOperators(String num, int target) {
        List<String> ans = new ArrayList<>();
        dfs(num, target, ans, "", 0, 0, 0);
        return ans;
    }
}

// 9ms 99.04% 45.2MB 80.81%
// backtracking
// O(3^N) O(N)
class Solution {

    private void dfs(char[] numChars, int target, List<String> result, char[] buffer, int bufferPos, int pos, long lastEval, long lastTerm) {
        // base
        if (pos == numChars.length) {
            if (lastEval == target) {
                result.add(new String(buffer, 0, bufferPos));
            }
            return;
        }
        
        long cur = 0;
        int signPos = bufferPos;
        if (pos > 0) {
            bufferPos++;  // reserve space for the operator
        }

        // recursion
        for (int i = pos; i < numChars.length; ++i) {
            // Handle numbers starting with '0'
            if (i != pos && numChars[pos] == '0') {
                break;
            }

            cur = cur * 10 + (numChars[i] - '0');
            buffer[bufferPos++] = numChars[i];

            if (pos == 0) {
                // First number, no operator
                dfs(numChars, target, result, buffer, bufferPos, i + 1, cur, cur);
            } else {
                buffer[signPos] = '+';
                dfs(numChars, target, result, buffer, bufferPos, i + 1, lastEval + cur, cur);

                buffer[signPos] = '-';
                dfs(numChars, target, result, buffer, bufferPos, i + 1, lastEval - cur, -cur);

                buffer[signPos] = '*';
                dfs(numChars, target, result, buffer, bufferPos, i + 1,
                    lastEval - lastTerm + lastTerm * cur,
                    lastTerm * cur);
            }
        }
    }

    public List<String> addOperators(String num, int target) {
        char[] numChars = num.toCharArray();
        char[] buffer = new char[2 * numChars.length];
        List<String> result = new ArrayList<>();
        dfs(numChars, target, result, buffer, 0, 0, 0, 0);
        return result;
    }

}
