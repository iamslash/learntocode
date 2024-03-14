import java.util.*;

class Solution {

    private boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        int sqrtn = (int)Math.sqrt(n);
        for (int p = 3; p < sqrtn; p += 2) {
            if (n % p == 0) {
                return false;
            }
        }

        return true;
    }
}
