// Copyright (C) 2020 by iamslash

// ABABAB ABAB
//   ABAB AB
//     AB ""

// gcd
// O(N) O(N)
class Solution {
	String gcd(String a, String b) {
		// base
		if (b.isEmpty())
			return a;
        String c = a.replaceAll(b, "");
        if (c == a)
            return "";
		return gcd(b, c);
	}
	public String gcdOfStrings(String a, String b) {
		if (a.length() < b.length())
			return gcd(b, a);
		return gcd(a, b);
	}
}
