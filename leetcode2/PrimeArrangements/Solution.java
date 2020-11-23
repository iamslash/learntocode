// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36MB 100.00%
// theive of erathosthenes
// O(N) O(N)
class Solution {
	private final int MOD = 1000000007;
	private int numPrime(int n) {
		boolean[] bprimes = new boolean[n+1];
		for (int i = 2; i <= n; ++i)
			bprimes[i] = true;
		for (int i = 2; i*i <= n; ++i) {
			if (!bprimes[i])
				continue;
			for (int j = i*i; j <= n; j += i) {
				bprimes[j] = false;
			}
		}
		int ans = 0;
		for (int i = 2; i <= n; ++i)
			if (bprimes[i])
				ans++;
		return ans;
	}
	public int numPrimeArrangements(int n) {
		int nPrime = numPrime(n);
		long ans = 1;
		for (int i = 2; i <= nPrime; ++i)
			ans = (ans * i) % MOD;
		for (int i = 2; i <= n-nPrime; ++i)
			ans = (ans * i) % MOD;
		return (int)ans;
	}
}
