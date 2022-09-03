//       0 1 2 3 
// nums: 4 1 3 3
//

// Idea: 
//
// This is about bad
// j - i != nums[j] - nums[i]
// i - nums[i] != j - nums[j]
//
// This is about good
// i - nums[i] == j - nums[j]
//
// total: good + bad
//   bad: total - good
// total: nC2 = n * (n - 1) / 2

//         0 1 2 3 
//   nums: 4 1 3 3
//  total: 4 * 3 / 2 = 6
// numMap:-4 0 -1  
//         1 2  1
//  good:       1
//   bad: total - good = 6 - 1 = 5

// 133ms 94.44% 65.8MB 44.44%
// math
// O(N) O(1)
function countBadPairs(nums: number[]): number {
    let n = nums.length, total = n * (n - 1) / 2, good = 0;
    let numMap = new Map<number, number>();
    for (let i = 0; i < n; ++i) {
        let diff = i - nums[i];
        // process.stdout.write(`i: ${i}, diff: ${diff} has: ${numMap.has(diff)} `);
        // console.log(numMap);
        if (numMap.has(diff)) {
            good += numMap.get(diff);
        }
        numMap.set(diff, (numMap.get(diff) || 0) + 1);
    }
    return total - good;
};
