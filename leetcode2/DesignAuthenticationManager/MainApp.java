// Copyright (C) 2023 by iamslash

import java.util.*;

// 62ms 35.52% 45MB 59.20%
// hash map
// O(N) O(1)
class AuthenticationManager {

    private int ttl;
    private Map<String, Integer> tokenTTLMap = new HashMap<>();

    public AuthenticationManager(int timeToLive) {
        this.ttl = timeToLive;
    }
    
    public void generate(String tokenId, int currentTime) {
        tokenTTLMap.put(tokenId, currentTime + ttl);
    }
    
    public void renew(String tokenId, int currentTime) {
        if (tokenTTLMap.containsKey(tokenId) &&
            tokenTTLMap.get(tokenId) > currentTime) {
            tokenTTLMap.put(tokenId, currentTime + ttl);
        }        
    }
    
    public int countUnexpiredTokens(int currentTime) {
        tokenTTLMap.keySet().removeIf(key -> tokenTTLMap.get(key) <= currentTime);
        return tokenTTLMap.size();
    }
}

public class MainApp {
    public static void main(String[] args) {
    }
}
