// Copyright (C) 2022 by iamslash

import java.util.*;

//     recipes = ["bread","sandwich","burger"]
// ingredients = [
//                ["yeast","flour"],
//                ["bread","meat"],
//                ["sandwich","meat","bread"]
//               ]
//    supplies = ["yeast","flour","meat"]

// hash set
// O(N) O(N)
class Solution {
    private boolean valid(Set<String> supplySet, List<String> ingredientList) {
        for (String ingredient : ingredientList) {
            if (!supplySet.contains(ingredient)) {
                return false;
            }
        }
        return true;
    }
    public List<String> findAllRecipes(String[] recipes,
                                       List<List<String>> ingredients,
                                       String[] supplies) {
        Set<String> recipeSet = new HashSet<>();
        Set<String> supplySet = new HashSet<>(Arrays.asList(supplies));
        int j = 2, n = recipes.length;
        while (j-- > 0) {
            for (int i = 0; i < n; ++i) {
                if (valid(supplySet, ingredients.get(i))) {
                    recipeSet.add(recipes[i]);
                    supplySet.add(recipes[i]);
                }
            }
        }
        return new ArrayList<>(recipeSet);
    }
}
