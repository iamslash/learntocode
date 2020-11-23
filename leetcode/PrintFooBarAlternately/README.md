# Problem

[Print FooBar Alternately](https://leetcode.com/problems/print-foobar-alternately/)

# Idea

`class FooBar` 의 인스턴스가 두개의 thread 에 주어진다.  `printFoo()`
와 `printBar()` 가 한번씩 교대로 호출하도록 구현하는 문제이다. thread
순서를 보장해 주는 문제이다. 그리고 하나의 thread 만 run 상태임을
유의하자.

첫번째 방법은 두개의 `mutex` 를 사용하는 것이다.

먼저 `mutex m_mufoo, m_mubar` 를 선언한다.  생성자에서
`m_mubar.lock()` 를 수행한다. 

```cpp
  void foo(std::function<void()> printFoo) {
        
    for (int i = 0; i < n; i++) {
      m_mufoo.lock();      
      printFoo();
      m_mubar.unlock();
    }
  }

  void bar(std::function<void()> printBar) {
        
    for (int i = 0; i < n; i++) {
      m_mubar.lock();           
      printBar();
      m_mufoo.unlock();
    }
  }
```

* main thread 가 `class FooBar` 의 생성자에서 이미 `m_mubar.lock()` 을
  수행했으므로 `bar()` thread 는 `m_mubar.lock()` 을 수행할 때 block 될 것이다.
* `foo()` thread 는 `m_mufoo.lock(), m_mubar.unlock()` 를 수행하고
  다시 `m_mufoo.lock()` 수행하기 때문에 block 될 것이다.
* `bar()` thread 는 `foo()` thread 의 `m_mubar.unlock()` 때문에 깨어날 것이다. 
  `m_mufoo.unlock()` 을 수행하기 때문에 `foo()` thread 는 깨어날 것이다.
  `bar()` thread 는 `m_mubar.lock()` 을 두번째 수행하기 때문에 block 될 것이다. 

두번째 방법은 하나의 `atomic_bool m_b` 와 `this_thread::yield()` 를
사용하는 것이다.

* main thread 는 `class FooBar` 의 생성자에서 `m_b = false` 를
  수행한다. `bar()` thread 는 `while (!m_b)` 때문에 반복문안에 머물
  것이다.
* `foo()` thread 는 `printFoo()` 를 수행하고 `m_b = true` 를 수행한다. 
  그리고 `while (m_b)` 때문에 반복문안에 머물 것이다. `m_b = true` 이므로
  `bar()` thread 는 반복문을 탈출할 것이다.
* `bar()` thread 는 `printBar()` 를 수행하고 `m_b = false` 를
  수행한다. 그리고 `while (!m_b)` 때문에 반복문안에 머물 것이다. `m_b = false`
  이므로 `foo()` thread 는 반복문을 탈출할 것이다.
  
```cpp
  void foo(std::function<void()> printFoo) {
        
    for (int i = 0; i < n; i++) {
      while (m_b)
        std::this_thread::yield();
      printFoo();
      m_b = !m_b;
    }
  }

  void bar(std::function<void()> printBar) {
        
    for (int i = 0; i < n; i++) {
      while (!m_b)
        std::this_thread::yield();
      printBar();
      m_b = !m_b;
    }
  }
```

# Implementation

* [c++11](a.cpp)
