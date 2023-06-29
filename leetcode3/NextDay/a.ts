// Copyright (C) 2023 by iamslash

// 72ms 100.00% 43.8MB 100.00%
declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function(){
    const now = new Date(this.getTime());
    now.setDate(now.getDate() + 1);

    const year = now.getFullYear();
    const month = String(now.getMonth() + 1).padStart(2, '0');
    const day = String(now.getDate()).padStart(2, '0');
    return `${year}-${month}-${day}`;
}
