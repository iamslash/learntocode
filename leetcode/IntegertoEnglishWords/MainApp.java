// Copyright (C) 2021 by iamslash

import java.util.*;

class Solution {
	private final String[] less_20 = new String[]{
		"",
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten",
		"Eleven",
		"Twelve",
		"Thirteen",
		"Fourteen",
		"Fifteen",
		"Sixteen",
		"Seventeen",
		"Eighteen",
		"Nineteen"
	};
	private final String[] tens = new String[]{
		"",
		"Ten",
		"Twenty",
		"Thirty",
		"Forty",
		"Fifty",
		"Sixty",
		"Seventy",
		"Eighty",
		"Ninety"		
	};
	private final String[] thousands = new String[]{
  "",
  "Thousand",
  "Million",
  "Billion"		
	}	 
	public String numberToWords(int num) {
		if (num == 0) {
			return "Zero";
		}
		int i = 0;
		StringBuilder sb = new StringBuilder();
		while (num > 0) {
			int rem = num % 1000;
			if (rem != 0) {
				sb.append(convert(rem));
				sb.append(thousands[i]);
				sb.append(" ");
			}
			num /= 1000;
			++i;
		}
		return sb.toString();
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
