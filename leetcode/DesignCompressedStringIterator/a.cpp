#include <cstdio>
#include <string>

// 32ms 5.66% 12.5MB 100.00%
// Q. what is the range of the number followed by the letter? 0<num
// O(1) O(N)
class StringIterator {
 private:
  std::string m_s;
  int m_i;
  int m_n;
  int nxtc(int i) {
    int j = i;
    while (j < m_s.size() && m_s[j] >= '0' && m_s[j] <= '9')
      ++j;
    return j;
  }
  int getn(int i) {
    int j = nxtc(i);
    return i < m_s.size() ? std::stoi(m_s.substr(i, j-i))-1 : -1;
  }
 public:
  StringIterator(std::string s) {
    m_s = s;
    m_i = 0;
    m_n = getn(1);
  }

  char next() {
    if (m_i >= m_s.size())
      return ' ';   
    char c = m_s[m_i];
    if (m_n-- <= 0) {
      m_i = nxtc(m_i+1);
      m_n = getn(m_i+1);
//printf("%d %d\n", m_i, m_n);
    }
    return c;       
  }
    
  bool hasNext() {
    return m_i < m_s.size();      
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  StringIterator si = StringIterator("L1e2t1C1o1d1e1");
  printf("%c\n", si.next());
  printf("%c\n", si.next());
  printf("%c\n", si.next());
  printf("%c\n", si.next());
  printf("%c\n", si.next());
  printf("%c\n", si.next());
  printf("%c\n", si.next());
  printb(si.hasNext());
  printf("%c\n", si.next());
  printb(si.hasNext());
  printf("%c\n", si.next());

  return 0;
}