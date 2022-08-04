// Copyright (C) 2022 by iamslash

import java.util.*;

// bidirectional indexing
// changeRating: O(NlgN) O(N)
// highestRated: O(1) O(N)
class FoodRatings {
    static class Rating {
        public String food;
        public int rate;
        public Rating(String food, int rate) {
            this.food = food;
            this.rate = rate;
        }
    }
    Map<String, TreeSet<Rating>> cuisine2ratingsMap = new HashMap<>();
    Map<String, String> food2cuisineMap = new HashMap<>();
    
    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        int n = foods.length;
        for (int i = 0; i < n; ++i) {
            cuisine2ratingsMap.putIfAbsent(cuisines[i], new TreeSet<Rating>((a, b) -> a.rate == b.rate ? a.food.compareTo(b.food) : b.rate - a.rate));
            cuisine2ratingsMap.get(cuisines[i]).add(new Rating(foods[i], ratings[i]));
            food2cuisineMap.put(foods[i], cuisines[i]);
        }
    }
    
    public void changeRating(String food, int newRating) {
        String cuisine = food2cuisineMap.get(food);
        TreeSet ratingSet = cuisine2ratingsMap.get(cuisine);
        ratingSet.removeIf(rating -> rating.food == food);
        ratingSet.add(new Rating(food, newRating));
    }
    
    public String highestRated(String cuisine) {
        return cuisine2ratingsMap.get(cuisine).first().food;
    }
}


public class MainApp {
  public static void main(String[] args) {
  }
}
