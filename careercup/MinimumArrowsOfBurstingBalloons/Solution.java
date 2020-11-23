// https://www.careercup.com/question?id=5728764059713536

public class Solution {
	private static int solve(int[] arr) {

		if (arr.length == 0)
			return 0;
		
		int sameNo = 0;
		int seq = 1; // if array is not empty then there will be 1 sequence by default
		int prev = 0; // to keep track of number of repeated numbers.

		for (int i = 1; i < arr.length; i++) {
			// when there is break b/w numbers.
			if (arr[i - 1] - arr[i] > 1) {
				seq++;
			}
			// when number or equal its the same number, hence we can form another set with this.
			if (arr[i] == arr[i - 1])
				sameNo++;
			if (arr[i] != arr[i - 1])
				sameNo = 0;
			if (prev < sameNo)
				prev = sameNo;
		}
		// combine both break in sequence and same numbers.
		return (seq + prev);

  }
	public static void main(String[] args) {
		int[] arr1 = { 5, 4, 3, 3, 2, 2, 1, 1, 1 };
		//int[] arr2 = { 5, 4, 2, 1 };
		System.out.println(solve(arr1));
	}
}