// Copyright (C) 2023 by iamslash


// 480ms 26.32% 121.8MB 23.68%
function join(arr1: any[], arr2: any[]): any[] {
    const arr = arr1.concat(arr2);
    const mergedObjs = {};
    arr.forEach((obj) => {
        if (!mergedObjs[obj.id]) {
            mergedObjs[obj.id] = { ...obj };
        } else {
            mergedObjs[obj.id] = { ...mergedObjs[obj.id], ...obj };
        }
    });
    const joinedArr = Object.values(mergedObjs);
    return joinedArr;
};
