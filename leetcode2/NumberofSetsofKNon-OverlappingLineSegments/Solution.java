// Copyright (C) 2020 by iamslash

// 
// 0 1 2 3
// 

import java.util.*;
import java.math.*;

// 8ms 50.00% 38.4MB 50.00%
// O(K) O(1)
class Solution {
	private final int MOD = 1000000007;
	public int numberOfSets(int n, int k) {
		BigInteger ans = BigInteger.valueOf(1);
		for (int i = 1; i < k * 2 + 1; ++i) {
			ans = ans.multiply(BigInteger.valueOf(n + k - i));
			ans = ans.divide(BigInteger.valueOf(i));
		}
		ans = ans.mod(BigInteger.valueOf(MOD));		
		return ans.intValue();
	}
}
