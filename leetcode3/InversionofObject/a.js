// Copyright (C) 2023 by iamslash

/**
 * @param {Object} obj
 * @return {Object}
 */
// 155ms 60.8MB
var invertObject = function(obj) {
    const ans = {};
    for (let key in obj) {
        let val = obj[key];
        if (ans.hasOwnProperty(val) === false) {
            ans[val] = key;
        } else {
            if (typeof(ans[val]) === 'string') {
                ans[val] = [ans[val]];
            } 
            ans[val].push(key);
        }
    }
    return ans;                    
};