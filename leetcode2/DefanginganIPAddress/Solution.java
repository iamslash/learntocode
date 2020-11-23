// Copyright (C) 2020 by iamslash

// 2ms 28.05% 37.7MB 100.00%
// split join
// O(N) O(1)
class Solution {
	public String defangIPaddr(String addr) {
		return addr.replaceAll("\\.", "[.]");
	}
}
