// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;

// 38ms 52.07% 40.04MB 43.61%
// replace all
// O(N) O(1)
class Solution {
	public String entityParser(String s) {
		if (s == null || s.length() == 0) {
			return "";
		}
		Map<String, String> dict = new HashMap<>();
		dict.put("&quot;", "\"");
		dict.put("&apos;", "'");
		dict.put("&gt;", ">");
		dict.put("&lt;", "<");
		dict.put("&frasl;", "/");
		for (String key : dict.keySet()) {
			s = s.replaceAll(key, dict.get(key));
		}
		return s.replaceAll("&amp;", "&");
	}
}
