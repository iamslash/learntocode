// Copyright (C) 2022 by iamslash

import java.util.*;

// 619ms 47.12% 143.7MB 80.99%
// bidirectional indexing
// changeRating: O(NlgN) O(N)
// highestRated: O(1) O(N)
class FoodRatings {
    Map<String, TreeSet<String>> cuisine2ratingsMap = new HashMap<>();
    Map<String, String> food2cuisineMap = new HashMap<>();
    Map<String, Integer> food2rateMap = new HashMap<>();
    
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; ++i) {
            cuisine2ratingsMap.putIfAbsent(
                cuisines[i], new TreeSet<String>(
                    (a, b) -> food2rateMap.get(a) == food2rateMap.get(b) ?
                    a.compareTo(b) :
                    food2rateMap.get(b) - food2rateMap.get(a)));
            cuisine2ratingsMap.get(cuisines[i]).add(foods[i]);
            food2rateMap.put(foods[i], ratings[i]);
            food2cuisineMap.put(foods[i], cuisines[i]);
        }
    }
    
    public void changeRating(String food, int newRating) {
        String cuisine = food2cuisineMap.get(food);
        TreeSet<String> ratingSet = cuisine2ratingsMap.get(cuisine);
        ratingSet.remove(food);
        food2rateMap.put(food, newRating);
        ratingSet.add(food);
    }
    
    public String highestRated(String cuisine) {
        return cuisine2ratingsMap.get(cuisine).first();
    }
}


public class MainApp {
  public static void main(String[] args) {
  }
}
