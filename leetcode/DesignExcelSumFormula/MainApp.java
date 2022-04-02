// Copyright (C) 2022 by iamslash

import java.util.*;

// 12ms 70.30% 43.1MB 52.12%
class Excel {
    private Cell[][] sheet;
    public Excel(int h, char w) {
        sheet = new Cell[h+1][w-'A'+1];
    }
    public void set(int r, char c, int v) {
        int y = r, x = c-'A';
        if (sheet[y][x] == null) {
            sheet[y][x] = new Cell(v);
        } else {
            sheet[y][x].setVal(v);
        }
    }
    public int get(int r, char c) {
        int y = r, x = c-'A';
        if (sheet[y][x] == null) {
            return 0;
        }
        return sheet[y][x].getVal();
    }
    public int sum(int r, char c, String[] nums) {
        int y = r, x = c-'A';
        if (sheet[y][x] == null) {
            sheet[y][x] = new Cell(nums);
        } else {
            sheet[y][x].setFormula(nums);
        }
        return sheet[y][x].getVal();
    }
    private class Cell {
        private int val = 0;
        // {cell: freq of cell}
        private Map<Cell, Integer> formula = new HashMap<>();
        public Cell(int val) {
            setVal(val);
        }
        public Cell(String[] nums) {
            setFormula(nums);
        }
        public void setVal(int val) {
            formula.clear();
            this.val = val;
        }
        public void setFormula(String[] nums) {
            formula.clear();
            for (String str : nums) {
                if (str.indexOf(":") < 0) {
                    int[] pos = getPos(str);
                    addFormulaCell(pos[0], pos[1]);
                } else {
                    String[] pos = str.split(":");
                    int[] begs = getPos(pos[0]);
                    int[] ends = getPos(pos[1]);
                    for (int y = begs[0]; y <= ends[0]; ++y) {
                        for (int x = begs[1]; x <= ends[1]; ++x) {
                            addFormulaCell(y, x);
                        }
                    }
                }
            }
        }
        private int[] getPos(String str) {
            int[] pos = new int[2];
            pos[0] = Integer.parseInt(str.substring(1));
            pos[1] = str.charAt(0) - 'A';
            return pos;
        }
        private void addFormulaCell(int y, int x) {
            if (sheet[y][x] == null) {
                sheet[y][x] = new Cell(0);
            }
            Cell rangeCell = sheet[y][x];
            formula.put(rangeCell, formula.getOrDefault(rangeCell, 0) + 1);
        }
        private int getVal() {
            if (this.formula.isEmpty()) {
                return this.val;
            }
            int sum = 0;
            for (Cell cell : formula.keySet()) {
                sum += cell.getVal() * formula.get(cell);
            }
            return sum;
        }
    }
}
