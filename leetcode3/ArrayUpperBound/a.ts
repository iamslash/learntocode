// Copyright (C) 2023 by iamslash

declare global {
    interface Array<T> {
        upperBound(target: number): number;
    }
}

Array.prototype.upperBound = function(target: number) {
    
};
