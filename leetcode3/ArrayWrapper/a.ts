// Copyright (C) 2023 by iamslash

// 66ms 46.55% 45.1MB 44.83%
class ArrayWrapper {
    data: number[];
    
    constructor(nums: number[]) {
        this.data = nums;
    }

    valueOf() {
        return this.data.reduce((acc, iter) => acc + iter, 0);
    }

    toString() {
        return `[${this.data.join(",")}]`;        
    }
};
