// Copyright (C) 2023 by iamslash

// 79ms 100.00% 43.5MB 100.00%
// O(1) O(1)
async function sleep(millis: number): Promise<void> {
    return new Promise((resolve, reject) => {
        setTimeout(() => resolve(), millis);
    });
}
