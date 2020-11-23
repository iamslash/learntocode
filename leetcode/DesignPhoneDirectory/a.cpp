/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <set>

// 60ms 65.22% 22.5MB 54.17%
class PhoneDirectory {
 private:
  std::set<int> m_st;
 public:
  PhoneDirectory(int n) {
    for (int i = 0; i < n; ++i)
      m_st.insert(i);
  }
  int get() {
    if (m_st.empty())
      return -1;
    int n = *m_st.begin();
    m_st.erase(n);
    return n;
  }
    
  bool check(int n) {
    return m_st.count(n) ? true : false;
  }
  void release(int n) {
    m_st.insert(n);
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

void printn(int n) {
  printf("%d\n", n);
}

int main() {
  PhoneDirectory pd(3);
  printn(pd.get());
  printn(pd.get());
  printb(pd.check(2));
  printn(pd.get());
  printb(pd.check(2));
  pd.release(2);
  printb(pd.check(2));  
  
  return 0;
}
