// Copyright (C) 2023 by iamslash

import java.util.*;

// money: 20
// child:  3
//        20 - 3 = 17
//

// Idea: greedy
//
// If money < children, there is no answer.
// If money > children * 8, can distribute except one child.
// Otherwise, can distribte at least one child.
// Subtract 8 money, 1 child as much as possible.
// If remained money is 4, child is 1, drop it.

// 3ms 100.00% 42.4MB 100.00%
// greedy
// O(M) O(1)
class Solution {
    public int distMoney(int money, int children) {
        int cnt = 0;
        if (money < children) {
            return -1;
        }
        if (money > children * 8) {
            return children - 1;
        }
        while (money > 0 && money - 8 >= children - 1) {
            cnt++;
            money -= 8;
            children--;
        }
        if (money == 4 && children == 1) {
            cnt--;
        }
        return cnt;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
