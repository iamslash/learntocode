// Copyright (C) 2023 by iamslash

// 56ms 100.00% 43.5MB 100.00%
type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};
function expect(val: any): ToBeOrNotToBe {
    const toBe = (x: any): boolean => {
        if (val !== x) {
            throw new Error("Not Equal");
        }
        return true;
    }
    const notToBe = (x: any): boolean => {
        if (val === x) {
            throw new Error("Equal");
        }
        return true;
    }
    return {toBe, notToBe};
};
