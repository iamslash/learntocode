// Copyright (C) 2019 by iamslash

// 0000 0000-0000 007F | 0xxxxxxx
// 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
// 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
// 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

// 80ms 91.30% 39.9MB 65.22%
var validUtf8 = function(D) {
    let i = 0;
    let n = D.length;
    while (i < n) {
        if ((i+4 <= n) && 
           (D[i]>>3) == 0x1E &&
           (D[i+1]>>6) == 0x02 &&
           (D[i+2]>>6) == 0x02 &&
           (D[i+3]>>6) == 0x02) {
            i += 4;
        } else if ((i+3 <= n) &&
                  (D[i]>>4) == 0x0E &&
                  (D[i+1]>>6) == 0x02 &&
                  (D[i+2]>>6) == 0x02) {
            i += 3;
        } else if ((i+2 <= n) &&
                   (D[i]>>5) == 0x06 &&
                   (D[i+1]>>6 == 0x02)){
            i += 2;            
        } else if (D[i]>>7 == 0x00) {
            i += 1;
        } else {
            return false;
        }
    }
    return true;
};
