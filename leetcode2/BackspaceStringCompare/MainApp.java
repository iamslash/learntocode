// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 37.1MB 73.92%
// list
// O(N) O(N)
class Solution {
	private StringBuilder getSb(String s) {
		StringBuilder sb = new StringBuilder();
		int n = s.length(), cntBack = 0;
		for (int i = n-1; i >= 0; --i) {
			char c = s.charAt(i);
			if (c == '#') {
				cntBack++;
			} else {
				if (cntBack > 0) {
					cntBack--;
				} else {
					sb.append(c);
				}
			}
		}
		return sb;
	}
	public boolean backspaceCompare(String s, String t) {
		StringBuilder sbS = getSb(s);
		StringBuilder sbT = getSb(t);		
		return sbS.toString().equals(sbT.toString());
	}
}

// 1ms 61.11% 37.2MB 47.48%
// list
// O(N) O(N)
class Solution {
	private List<Character> getList(String s) {
		List<Character> sList = new ArrayList<>();		
		for (char c : s.toCharArray()) {
			if (c == '#') {
				if (sList.size() > 0) {
					sList.remove(sList.size()-1);
				}
			} else {
				sList.add(c);
			}
		}
		return sList;
	}
	public boolean backspaceCompare(String s, String t) {
		List<Character> sList = getList(s);
		List<Character> tList = getList(t);
		if (sList.size() != tList.size()) {
			return false;
		}
		for (int i = 0; i < sList.size(); ++i) {
			if (sList.get(i) != tList.get(i)) {
				return false;
			}
		}
		return true;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
