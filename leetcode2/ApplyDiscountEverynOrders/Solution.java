// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;


// hash map
// getBill: O(N) O(1)
class Cashier {
	private int order;
	private int mod;
	private int cnt;
	private double ratio;
	private Map<Integer, Integer> data = new HashMap<>();
	public Cashier(int n, int discount, int[] products, int[] prices) {
		this.order = 0;
		this.mod = n;
		this.ratio = (100.00 - discount) / 100.00;
		for (int i = 0; i < products.length; ++i) {
			data.put(products[i], prices[i]);
		}
	}
    
	public double getBill(int[] product, int[] amount) {
		this.order++;
		double ans = 0.0;
		for (int i = 0; i < product.length; ++i) {
			ans += data.get(product[i]) * amount[i];
		}
		if (order % mod == 0) {
			ans *= ratio;
		}
		return ans;
	}
}
