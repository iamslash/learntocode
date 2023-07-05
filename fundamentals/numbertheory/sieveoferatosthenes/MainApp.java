import java.util.*;

// sieve of eratosthenes
// O(Nsqrt(N)) O(N)
public class MainApp {
    public boolean[] buildPrimes() {
        int n = 1000;
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        // c = p * q (p <= q)
        // p <= sqrt(n)
        // p * p <= n
        for (int p = 2; p * p <= n; ++p) {
            if (!primes[p]) {
                continue;
            }
            // c = p * q (p <= q) 
            // q >= sqrt(n)
            for (int c = p * p; c <= n; c += p) {
                primes[c] = false;
            }
        }
        return primes;        
    }
}
