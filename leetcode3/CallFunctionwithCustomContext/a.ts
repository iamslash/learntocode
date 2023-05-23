// Copyright (C) 2023 by iamslash

// 54ms 93.18% 44.5MB 56.82%
declare global { 
    interface Function {
        callPolyfill(context: Record<any, any>, ...args: any[]): any;
    }
}
Function.prototype.callPolyfill = function(context, ...args): any {
    const fn = this.bind(context);
    return fn(...args);
}
