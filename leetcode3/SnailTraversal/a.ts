// Copyright (C) 2023 by iamslash

// 218ms 67.81% 57.3MB 45.89%
declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}
Array.prototype.snail = function(h: number, w: number): number[][] {
    if (this.length != h * w) {
        return [];
    }
    const rst = (new Array(h).fill([])).map(() => []);
    let y = 0, x = 0, dir = 1;
    this.forEach(v => {
        rst[y][x] = v;
        y += dir;
        if (y === h || y === -1) {
            x++;
            dir = -dir;
            y += dir;
        }
    });
    return rst;
}
