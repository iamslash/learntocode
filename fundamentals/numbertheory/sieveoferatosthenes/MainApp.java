import java.util.*;

public class MainApp {
    public boolean[] buildPrimes() {
        boolean[] primes = new boolean[1001];
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= 1000; ++i) {
            if (primes[i]) {
                for (int j = i * i; j <= 1000; j += i) {
                    primes[j] = false;
                }
            }
        }
        return primes;        
    }
}
