// Copyright (C) 2020 by iamslash

import java.util.*;

// 12ms 77.53% 41.6MB 17.50%
// hash table
// addScore: O(1) O(N)
//      top: O(N) O(N)
class Player {
	public int id;
	public int score;
	public Player(int id, int score) {
		this.id = id;
		this.score = score;
	}
}
class Leaderboard {
	private Map<Integer, Player> playerMap = new HashMap<>();
	private Set<Player> playerSet = new TreeSet<>((a, b) -> {
			if (a.score == b.score)
				return a.id - b.id;
			return b.score - a.score;
	});
	public void addScore(int id, int score) {
		Player u;
		if (playerMap.containsKey(id)) {
			u = playerMap.get(id);
			playerSet.remove(u);
			u.score += score;
			playerSet.add(u);
		} else {
			u = new Player(id, score);
			playerMap.put(id, u);
			playerSet.add(u);
		}
	}
	public int top(int K) {
		Iterator<Player> it = playerSet.iterator();
		int sum = 0;
		while (K-- > 0 && it.hasNext()) {
			sum += it.next().score;
		}
		return sum;
	}
    
	public void reset(int id) {
		Player u = playerMap.get(id);
		playerSet.remove(u);
		u.score = 0;
	}
}
