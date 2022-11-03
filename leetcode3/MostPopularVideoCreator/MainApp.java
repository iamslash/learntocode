// Copyright (C) 2022 by iamslash

import java.util.*;

// 149ms 76.39% 204.9MB 82.06%
// hash map
// O(N) O(N)
class Video {
    public String id;
    public int view;
    public Video(String id, int view) {
        this.id = id;
        this.view = view;
    }
}
class Solution {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        int n = creators.length, maxView = 0;
        Map<String, Integer> creator2viewMap = new HashMap<>();
        Map<String, Video> creator2videoMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            String creator = creators[i];
            String id = ids[i];
            int view = views[i];
            creator2viewMap.put(creator, creator2viewMap.getOrDefault(creator, 0) + view);
            Video video = creator2videoMap.get(creator);
            if (video == null) {
                creator2videoMap.put(creator, new Video(id, view)); 
            } else if (video.id.equals(id)) {
                video.view += view;
            } else if ((video.view == view && id.compareTo(video.id) < 0) ||
                       (video.view < view)) {                
                creator2videoMap.put(creator, new Video(id, view));                
            }
            maxView = Math.max(maxView, creator2viewMap.get(creator)); 
        }
        // System.out.println(creator2viewMap);
        // System.out.println(maxView);
        List<List<String>> ans = new ArrayList<>();
        for (String creator : creator2viewMap.keySet()) {
            int view = creator2viewMap.get(creator);
            if (view == maxView) {
                Video video = creator2videoMap.get(creator);
                ans.add(Arrays.asList(creator, video.id));
            }            
        }
        return ans;
    }
}
