// Copyright (C) 2023 by iamslash

// 78ms 11.11% 50.8MB 18.52%
String.prototype.replicate = function(times) {
    let ans = "";
    while (times-- > 0) {
        ans += this;
    }
    return ans;   
}