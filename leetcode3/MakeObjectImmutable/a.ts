// Copyright (C) 2023 by iamslash

// Proxy
type Obj = Array<any> | Record<any, any>;
const banMethods = ['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse'];
function makeImmutable(obj: Obj): Obj {
    return new Proxy(obj, {
        set(target, prop, value, receiver) {
            if (Array.isArray(target)) {
                throw Error(`Error Modifying Index: ${String(prop)}`);                
            }
            throw Error(`Error Modifying: ${String(prop)}`);
        },
        get(target, prop) {
            if (Array.isArray(target) && prop in banMethods) {
                throw Error(`Error Calling Method: ${String(prop)}`);
            }
            if (typeof(obj[prop]) === "object" && obj[prop] !== null) {
                return makeImmutable(obj[prop]);
            }
            return target[prop];
        }
    });
};
