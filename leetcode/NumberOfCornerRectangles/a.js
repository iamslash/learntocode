// Copyright (C) 2020 by iamslash

// 144ms 58.82% 43.3MB 5.88%
// combination
// O(HW^2) O(1)
var countCornerRectangles = function(G) {
    let ans = 0, h = G.length, w = G[0].length;
    for (let i = 0; i < h - 1; ++i) {
        for (let j = i+1; j < h; ++j) {
            let cnt = 0;
            for (let x = 0; x < w; ++x) {
                if (G[i][x] > 0 && G[j][x] > 0) {
                    cnt++;
                }
            }
            if (cnt > 0) {
                ans += cnt * (cnt - 1) / 2;
            }
        }
    }
    return ans;
};
