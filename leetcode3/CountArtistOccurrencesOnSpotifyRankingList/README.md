# Problem

[Count Artist Occurrences On Spotify Ranking List](https://leetcode.com/problems/count-artist-occurrences-on-spotify-ranking-list/)

# Implementation

```sql

-- 435ms 100.00% 0B 100.00%
  SELECT artist, 
         COUNT(artist) AS occurrences
    FROM Spotify
GROUP BY artist
ORDER BY occurrences DESC, artist ASC;

```
