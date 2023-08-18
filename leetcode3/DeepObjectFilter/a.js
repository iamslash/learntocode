// Copyright (C) 2023 by iamslash

/**
 * @param {Object} obj
 * @param {Function} fn
 * @return {Object|undefined}
 */
// 145ms 100.00% 62.6MB 100.00%
var deepFilter = function(obj, fn) {
  if (Array.isArray(obj)) {
    const filtered = obj
                      .map(item => deepFilter(item, fn))
                      .filter(item => item !== undefined);
    return filtered.length > 0 ? filtered : undefined;
  }
  if (typeof(obj) === 'object' && obj !== null) {
    const filteredObj = {};
    let isEmpty = true;
    for (const key in obj) {
      if (obj.hasOwnProperty(key)) {
        const filteredVal = deepFilter(obj[key], fn);
        if (filteredVal !== undefined) {
          filteredObj[key] = filteredVal;
          isEmpty = false;
        }
      }
    }
    return isEmpty ? undefined : filteredObj;
  }
  return fn(obj) ? obj : undefined;
}
