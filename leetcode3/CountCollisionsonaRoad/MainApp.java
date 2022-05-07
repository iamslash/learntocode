// Copyright (C) 2022 by iamslash

import java.util.*;

// 369ms 12.31% 42.7MB 96.10%
// stack
// O(N) O(N)
class Solution {
    public int countCollisions(String directions) {
        int hit = 0, n = directions.length();
        Stack<Character> stck = new Stack<>();
        stck.push(directions.charAt(0));
        for (int i = 1; i < n; ++i) {
            char c = directions.charAt(i);
            if (stck.peek() == 'R' && c == 'L') {
                hit += 2;
                stck.pop();
                c = 'S';
            } else if (stck.peek() == 'S' && c == 'L') {
                hit++;
                stck.pop();
                c = 'S';
            }
            while (!stck.isEmpty() &&
                   stck.peek() == 'R' && c == 'S') {
                hit++;
                stck.pop();
            }
            stck.push(c);
        }
        return hit;
    }
}

//       l
// dirs: RLRSLL
//            r
// all cases of l, l+1
// 0) R L, hit += 2
// 1) R S, hit += 1
// 2) S L, hit += 1
// 3) S R, hit += 1

// 11ms 97.75% 42.8MB 92.51%
// back and forth
// O(N) O(1)
class Solution {
    public int countCollisions(String directions) {
        int hit = 0, n = directions.length();
        int l = 0, r = n - 1;
        char[] dirs = directions.toCharArray();
        while (l < n && dirs[l] == 'L') {
            l++;
        }
        while (r >= 0 && dirs[r] == 'R') {
            r--;
        }
        while (l <= r) {
            if (dirs[l] != 'S') {
                hit++;
            }
            l++;
        }
        return hit;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
