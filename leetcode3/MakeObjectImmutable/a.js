// Copyright (C) 2023 by iamslash

const banMethods = ['pop', 'push', 'shift', 'unshift', 'splice', 'sort', 'reverse'];
var makeImmutable = function(obj) {
    return new Proxy(obj, {
        set(target, prop, value, receiver){
            if (Array.isArray(target)){
                throw `Error Modifying Index: ${prop}`;
            }            
            throw `Error Modifying: ${prop}`;
        },
        get(target, prop){
            if (Array.isArray(target) && banMethods.includes(prop)){
                return () => { throw `Error Calling Method: ${prop}`; };
            }
            if (typeof obj[prop] === 'object' && obj[prop] !== null){
                // call recursively
                return makeImmutable(obj[prop]);
            }
            return Reflect.get(target, prop); // execute default behavior
        }
    });
};
