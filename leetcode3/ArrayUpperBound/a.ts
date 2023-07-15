// Copyright (C) 2023 by iamslash

declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function(target: number) {
    let l = 0, r = this.length - 1;
    while (l < r) {
    }
    return l
};
