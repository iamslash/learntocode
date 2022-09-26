// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: hash map
//
// we don't need to implement deleteRow 
// in consideration to the problem statement.

// 226ms 73.63% 111MB 79.12%
// hash map
//  insertRow: O(1)
//  deleteRow: O(1)
// selectCell: O(RC)
// R: rows
// C: cols
class SQL {
    private Map<String, List<List<String>>> db = new HashMap<>();

    public SQL(List<String> names, List<Integer> columns) {}
    public void insertRow(String name, List<String> row) {
        db.computeIfAbsent(name, l -> new ArrayList<>()).add(row);
    }
    public void deleteRow(String name, int rowId) {
    }
    
    public String selectCell(String name, int rowId, int colId) {
        return db.get(name).get(rowId - 1).get(colId - 1);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
