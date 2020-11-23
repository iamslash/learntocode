// Copyright (C) 2020 by iamslash

// 18ms 40.65% 47.5MB 100.00%
// Stream
public class Solution {
	private Stream<String> crawlMulti(String startUrl, HtmlParser htmlParser,
													String hostname, Set<String> seen) {
		Stream<String> stream = htmlParser.getUrls(startUrl)
				.parallelStream()
				.filter(url -> url.substring(7, url.length()).startsWith(hostname))
				.filter(url -> seen.add(url))
				.flatMap(url -> crawlMulti(url, htmlParser, hostname, seen));
		return Stream.concat(Stream.of(startUrl), stream);
	}
	private String getHostname(String url) {
		return url.substring(7).split("/")[0];
	}
	public List<String> crawl(String startUrl, HtmlParser htmlParser) {
		String hostname = getHostname(startUrl);
		Set<String> seen = ConcurrentHashMap.newKeySet();
		seen.add(startUrl);
		return crawlMulti(startUrl, htmlParser, hostname, seen)
				.collect(Collectors.toList());
	}	
}
