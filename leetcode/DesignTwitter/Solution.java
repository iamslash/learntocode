// Copyright (C) 2020 by iamslash

import java.util.*;

// {followeeid:[followerid,...]}
// [userid:[{time,tweetid},...]}

// 65ms 14.83% 51MB 5.65%
// hash table
//   postTweet: O(1)
// getNewsFeed: O(1)
//      follow: O(1)
class Tweet {
	public int ts;
	public int id;
	public Tweet(int ts, int id) {
		this.ts = ts;
		this.id = id;
	}
}
class Twitter {
	Map<Integer, Set<Integer>> follows = new HashMap<>();
	Map<Integer, LinkedList<Tweet>> tweets = new HashMap<>();
	int ts = 0;
	public void postTweet(int userId, int tweetId) {
		follows.putIfAbsent(userId, new HashSet<>());
		follows.get(userId).add(userId);
		tweets.putIfAbsent(userId, new LinkedList<>());
		tweets.get(userId).addFirst(new Tweet(ts++, tweetId));
	}
	public List<Integer> getNewsFeed(int userId) {
		if (!follows.containsKey(userId))
			return new LinkedList<>();
		Queue<Tweet> feeds = new PriorityQueue<>((a, b) -> {
				return b.ts - a.ts;
		});
		follows.get(userId)
				.stream()
				.filter(f -> tweets.containsKey(f))
				.forEach(f -> tweets.get(f).forEach(feeds::add));
		List<Integer> ans = new LinkedList<>();
		while (feeds.size() > 0 && ans.size() < 10)
			ans.add(feeds.poll().id);
		return ans;
	}
	public void follow(int followerId, int followeeId) {
		follows.putIfAbsent(followerId, new HashSet<>());
		follows.get(followerId).add(followeeId);
	}
	public void unfollow(int followerId, int followeeId) {
		if (followerId == followeeId || !follows.containsKey(followerId))
			return;
		follows.get(followerId).remove(followeeId);
	}
}
