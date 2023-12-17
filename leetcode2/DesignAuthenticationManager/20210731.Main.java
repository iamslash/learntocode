// Copyright (C) 2021 by iamslash

import java.util.*;

// hash map
//             generate: O(1) O(N)
//                renew: O(N) O(N)
// countUnexpiredTokens: O(N) O(N)
class AuthenticationManager {
	private int ttl;
	private Map<String, Integer> tokenMap = new HashMap<>();

	public AuthenticationManager(int timeToLive) {
		ttl = timeToLive;
	}
    
	public void generate(String tokenId, int currentTime) {
		tokenMap.put(tokenId, currentTime + ttl);
	}
    
	public void renew(String tokenId, int currentTime) {
		if (tokenMap.containsKey(tokenId) && tokenMap.get(tokenId) > currentTime) {
			tokenMap.put(tokenId, currentTime + ttl);
		}
	}
    
	public int countUnexpiredTokens(int currentTime) {
		tokenMap.entrySet().removeIf(e -> e.getValue() <= currentTime);
		return tokenMap.size();
	}
}

class Main {
	public static void main(String[] args) {
	}
}
