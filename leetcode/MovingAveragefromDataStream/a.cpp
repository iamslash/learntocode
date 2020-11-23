#include <cstdio>
#include <deque>

// 44ms 28.81% 15.6MB 14.28%
// Q. sum of val is in range of integer?
// O(N) O(N)
class MovingAverage {
 private:
  int m_size;
  std::deque<double> m_deq;
 public:
  MovingAverage(int size) {
    m_size = size;      
  }
    
  double next(int val) {
    if (m_deq.size() == m_size)
      m_deq.pop_front();
    m_deq.push_back(val);        
    int n = m_deq.size();
    return std::accumulate(m_deq.begin(), m_deq.end(), 0.0, std::plus<double>()) / n ;
  }
};

// 36ms 98.72% 15.3MB 86.51%
class MovingAverage {
 private:
  int m_n;
  int m_cur_n;
  int m_i;
  double m_sum;
  std::vector<int> m_V;
 public:
  MovingAverage(int size) {
    m_n = size;
    m_V = std::vector<int>(m_n, 0);
    m_cur_n = 0;
    m_i = 0; 
  }
  double next(int val) {
    if (m_cur_n == m_n) {
      m_sum -= m_V[m_i];
      m_sum += val;
      m_V[m_i] = val;
      m_i = (m_i + 1) % m_n;
    } else {
      m_sum += val;
      m_V[m_cur_n++] = val;
    }
    return m_sum / m_cur_n;
  }
};