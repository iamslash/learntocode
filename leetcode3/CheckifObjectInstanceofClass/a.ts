// Copyright (C) 2023 by iamslash

// 106ms 77.29% 54MB 25.55%
function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    while (obj != null) {
        if (obj.constructor === classFunction) {
            return true;
        }
        obj = Object.getPrototypeOf(obj);
    }
    return false;
};
