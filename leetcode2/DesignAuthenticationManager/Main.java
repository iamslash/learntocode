// Copyright (C) 2021 by iamslash

import java.util.*;

// hash map
//             generate: O(1) O(N)
//                renew: O(N) O(N)
// countUnexpiredTokens: O(N) O(N)
class AuthenticationManager {
	private int ttl;
	private Map<String, Integer> tokenMap = new HashMap<>();

	private void expire(int ts) {
		List<String> tokenList = new ArrayList<>();
		tokenMap.forEach((key, val) -> {
				if (val <= ts) {
					tokenList.add(key);
				}		
			});
		for (String token : tokenList) {
			tokenMap.remove(token);
		}
	}

	public AuthenticationManager(int timeToLive) {
		ttl = timeToLive;
	}
    
	public void generate(String tokenId, int currentTime) {
		tokenMap.put(tokenId, currentTime);
	}
    
	public void renew(String tokenId, int currentTime) {
		expire(currentTime);
		tokenMap.put(tokenId, currentTime);
	}
    
	public int countUnexpiredTokens(int currentTime) {
		expire(currentTime);
		return tokenMap.size();
	}
}

class Main {
	public static void main(String[] args) {
	}
}
