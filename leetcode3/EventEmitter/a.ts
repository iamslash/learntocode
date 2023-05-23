// Copyright (C) 2023 by iamslash

// 63ms 68.33% 44.3MB 96.67%
type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}
class EventEmitter {
    fnMap = new Map<string, Callback[]>(); 
    
    subscribe(eventName: string, callback: Callback): Subscription {
        if (!this.fnMap.has(eventName)) {
            this.fnMap.set(eventName, []);
        }
        const fns = this.fnMap.get(eventName);
        fns.push(callback);
        
        return {
            unsubscribe: () => {
                fns.splice(fns.indexOf(callback), 1);
            }
        };
    }

    emit(eventName: string, args: any[] = []): any {
        return this.fnMap.get(eventName)?.map(f => f(...args)) ?? [];
    }
}
