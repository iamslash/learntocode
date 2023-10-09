// Copyright (C) 2023 by iamslash

// 122ms 47.62% 62MB 59.52%
var jsonParse = function(s) {
    let idx = 0;
    function parseValue() {
        const c = s[idx];
        if (c === '{') {
            return parseObject();
        } else if (c == '[') {
            return parseArray();
        } else if (c == '"') {
            return parseString();
        } else if (c == 't') {
            return parseTrue();
        } else if (c == 'f') {
            return parseFalse();
        } else if (c == 'n') {
            return parseNull();
        } else {
            return parseNumber();
        }
    }
    function parseObject() {
        idx++;  // Skip '{'
        const obj = {};
        while (s[idx] !== '}') {
            const key = parseStringToken();
            idx++;  // Skip ':'
            const val = parseValue();
            obj[key] = val;
            if (s[idx] === ',') {
                idx++;  // Skip ','
            }
        }
        idx++;  // Skip '}'
        return obj;
    }
    function parseArray() {
        idx++; // Skip '['
        const arr = [];
        while (s[idx] !== ']') {
            const val = parseValue();
            arr.push(val);
            if (s[idx] === ',') {
                idx++;  // Skip ','
            }
        }
        idx++; // Skip ']'
        return arr;
    }
    function parseString() {
        idx++;
        let endIdx = s.indexOf('"', idx);
        const val = s.slice(idx, endIdx);
        idx = endIdx + 1;  // Skip '"'
        return val;
    }
    function parseStringToken() {
        return parseString();
    }
    function parseTrue() {
        idx += 4;
        return true;
    }
    function parseFalse() {
        idx += 5;
        return false;
    }
    function parseNull() {
        idx += 4;
        return null;
    }
    function parseNumber() {
        let begIdx = idx;
        let endIdx = idx;
        if (s[endIdx] === '-') {
            endIdx++;  // Skip neg sign '-'
        }
        while (s.charCodeAt(endIdx) >= 48 && s.charCodeAt(endIdx) <= 57) {
            endIdx++;
        }
        if (s[endIdx] === '.') {
            endIdx++;  // Skip decimal point '.'
        }
        while (s.charCodeAt(endIdx) >= 48 && s.charCodeAt(endIdx) <= 57) {
            endIdx++;
        }
        const val = Number(s.slice(begIdx, endIdx));
        idx = endIdx;
        return val;
    }
    return parseValue();
};
