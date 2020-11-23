// Copyright (C) 2020 by iamslash

import java.util.concurrent.CountDownLatch;

// 9ms 87.33% 38.9MB 100.00%
class Foo {
	private CountDownLatch lock2 = new CountDownLatch(1);
	private CountDownLatch lock3 = new CountDownLatch(1);

	public Foo() {
        
	}

	public void first(Runnable printFirst) throws InterruptedException {
        
		printFirst.run();
		lock2.countDown();
	}

	public void second(Runnable printSecond) throws InterruptedException {
		lock2.await();
		printSecond.run();
		lock3.countDown();
	}

	public void third(Runnable printThird) throws InterruptedException {
		lock3.await();
		printThird.run();
	}
}
