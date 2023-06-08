// Copyright (C) 2023 by iamslash

// 118ms 100.00% 45.7MB 100.00%
function houseCount(street: Street | null, k: number): number {
    for (let i = 0; i < k; ++i) {
        street.closeDoor();
        street.moveLeft();
    }
    let cnt = 0;
    while(k-- > 0) {
        if (street.isDoorOpen()) {
            break;
        }
        cnt++;
        street.openDoor();
        street.moveLeft();
    }
    return cnt;
};
