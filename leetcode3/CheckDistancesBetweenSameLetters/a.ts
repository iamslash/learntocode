
// 68ms 100.00% 45MB 100.00%
// brute force
// O(N) O(1)
function checkDistances(s: string, distances: number[]): boolean {
    let n = s.length
    let prevIdxs = new Array<number>().fill(-1);
    
    for (let i = 0; i < n; ++i) {
        let c = s.charAt(i);
        let idx = c.charCodeAt(0) - 97;
        if (prevIdxs[idx] >= 0) {
            let dist = i - prevIdxs[idx] - 1;
            if (dist != distances[idx]) {
                return false;
            }
        }
        prevIdxs[idx] = i;
    }
    return true;
};
