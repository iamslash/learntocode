// Copyright (C) 2023 by iamslash

// 61ms 37.50% 41.9M 70.00%
var QueryBatcher = function(queryMultiple, t) {
    this.queryMultiple = queryMultiple;
    this.t = t;
    this.batchedKeys = [];
    this.timerId = null;
    this.lastCallTime = 0;	
};
QueryBatcher.prototype.getValue = async function(key) {
    return new Promise((resolve) => {
        const currentTime = Date.now();
        const timeSinceLastCall = currentTime - this.lastCallTime;
        const timeRemaining = Math.max(0, this.t - timeSinceLastCall);

        this.lastCallTime = currentTime + timeRemaining;
        this.batchedKeys.push({ key, resolve });

        if (!this.timerId) {
            clearTimeout(this.timerId);
            this.timerId = setTimeout(() => this.processBatchedKeys(), timeRemaining);
        }
    });	
};
QueryBatcher.prototype.processBatchedKeys = async function() {
    const currentBatchedKeys = this.batchedKeys.slice();
    this.batchedKeys = [];
    this.timerId = null;

    const keys = currentBatchedKeys.map((obj) => obj.key);
    const resolves = currentBatchedKeys.map((obj) => obj.resolve);

    this.lastCallTime = Date.now();
    const resolvedValues = await this.queryMultiple(keys);

    for (let i = 0; i < keys.length; i++) {
        resolves[i](resolvedValues[i]);
    }
};

// 68ms 15.00% 42MB 50.00%
var QueryBatcher = function(queryMultiple, t) {
    this.fn = queryMultiple;
    this.t = t;
    this.keys = [];
    this.resolves = [];
    this.wait = false;
};
QueryBatcher.prototype.getValue = async function(key) {
    const batcher = this;
    return new Promise((resolve) => {
        this.keys.push(key);
        this.resolves.push(resolve);
        if(this.wait === false) {
            this.call_batch();
        }
    });
};
QueryBatcher.prototype.set_throttle = function(){
    this.keys = [];
    this.resolves = [];
    this.wait = true;

    setTimeout(() => {
        this.wait = false;
        if (this.keys.length !== 0) {
            this.call_batch();
        }
    }, this.t);
};
QueryBatcher.prototype.call_batch = async function(){
    const keys = this.keys.slice();
    const resolves = this.resolves.slice();

    this.set_throttle();

    const results = await this.fn(keys);
    for(let i = 0;i < results.length; i++) {
        resolves[i](results[i]);
    }
};
