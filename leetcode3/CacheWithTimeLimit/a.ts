// Copyright (C) 2023 by iamslash

// Idea:
//
// Use setTimeout for evicting item from the cache.

// 67ms 30.94% 42.9MB 42.60%
interface TTLValue {
    value: number;
    timer: ReturnType<typeof setTimeout>;
}
class TimeLimitedCache {
    cache = new Map<number, TTLValue>();

    set(key: number, value: number, duration: number): boolean {
        const found = this.cache.has(key);
        if (found) {
            clearTimeout(this.cache.get(key).timer);
        }
        this.cache.set(key, {value, timer: setTimeout(() => this.cache.delete(key), duration)});
        return found;
    }

    get(key: number): number {
        if (this.cache.has(key) === false) {
            return -1;
        }
        return this.cache.get(key).value;
    }

    count(): number {
        return this.cache.size
    }
}
