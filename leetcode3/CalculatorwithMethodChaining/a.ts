// Copyright (C) 2023 by iamslash

// 61ms 100.00% 43.3MB 100.00%
class Calculator {
    private val: number;

    constructor(val : number) {
        this.val = val;
    }
    
    add(val : number) : Calculator {
        this.val += val;
        return this;
    }
    
    subtract(val : number) : Calculator {
        this.val -= val;
        return this;
    }
    
    multiply(val : number) : Calculator {
        this.val *= val;
        return this;
    }

    divide(val : number) : Calculator {
        if (val === 0) {
            throw new Error("Division by zero is not allowed");
        }
        this.val /= val;
        return this;
    }
    
    power(val : number) : Calculator {
        this.val **= val;
        return this;
    }

    getResult() : number {
        return this.val;
    }
}
