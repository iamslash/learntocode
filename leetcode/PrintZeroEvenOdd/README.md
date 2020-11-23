# Problem

[Print Zero Even Odd](https://leetcode.com/problems/print-zero-even-odd/)

# Idea

`class ZeroEvenOdd` 의 인스턴스가 세개의 thread 에게 전달된다. `0`
부터 `n` 까지 `01020304..n` 의 형태로 출력하도록 구현하는 문제이다.

`queue<int> m_q` 를 선언하고 `01020304..n` 를 미리 삽입한다.
이제 세개의 thread 는 `m_q` 를 polling 하다가 자신이 해야할
일이면 큐에서 하나 꺼내어 실행하고 다시 polling 한다.

condition_variable 로 해결할 만 하다. condition_variable 을
사용하려면 unique_lock 이 필요하다. unique_lock 은 mutex 가
필요하다. `mutex m_mu, condition_variable m_cv` 를 선언하고
`unique_lock<mutex> ulock(m_mu)` 를 선언한다.

thread 는 `m_cv.wait(ulock, condition function)` 를 수행하여
대기한다. 만약 깨어나면 `m_q.front()` 를 출력하고 `m_q.pop()` 를
수행한다.  반드시 `m_cv.notify_all()` 를 수행하여 `m_cv.wait()` 하고
있는 thread 들을 깨워 조건을 검사하게 해야 한다.

# Implementation

* [c++11](a.cpp)
