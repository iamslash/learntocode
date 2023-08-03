// Copyright (C) 2023 by iamslash

// 96ms 100.00% 57.7MB 100.00%
Array.prototype.forEach = function(callback, context) {
    for (let i = 0; i < this.length; ++i) {
        callback.call(context, this[i], i, this);
    }
}
