// Copyright (C) 2023 by iamslash

// 452ms 41.67% 71.4MB 66.67%
type Obj = Array<any> | Record<any, any>;
const banMethods = new Set(['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse']);
function makeImmutable(obj: Obj): Obj {
    return new Proxy(obj, {
        set(target, prop, value): boolean {
            if (Array.isArray(target)){
                throw `Error Modifying Index: ${String(prop)}`;
            }            
            throw `Error Modifying: ${String(prop)}`;
        },
        get(target, prop, receiver) {
            if (Array.isArray(target) && banMethods.has(String(prop))){
                return () => { throw `Error Calling Method: ${String(prop)}`; };
            }
            if (typeof target[prop] === 'object' && target[prop] !== null){
                // call recursively
                return makeImmutable(target[prop]);
            }
            return Reflect.get(target, prop, receiver); // execute default behavior
        }
    });
};
