// Copyright (C) 2023 by iamslash

// 83ms 100.00% 45.3MB 100.00%
function removeTrailingZeros(num: string): string {
    let bnd = num.length;
    while (bnd > 0 && num.charAt(bnd - 1) === '0') {
        bnd--;
    }
    return num.substring(0, bnd);
};
