// Copyright (C) 2023 by iamslash

// 88ms 31.91% 44.7MB 48.94%
var dateRangeGenerator = function* (start, end, step) {
    let endDate = new Date(end);
    var curDate = new Date(start);
    while (curDate <= endDate) {
        yield curDate.toISOString().split('T')[0];
        curDate.setDate(curDate.getDate() + step);
    }
};

