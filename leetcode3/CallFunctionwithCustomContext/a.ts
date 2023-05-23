// Copyright (C) 2023 by iamslash

declare global { 
    interface Function {
        callPolyfill(context: Record<any, any>, ...args: any[]): any;
    }
}

Function.prototype.callPolyfill = function(context, ...args): any {
    const fn = this.bind(context);
    return fn(...args);
}
