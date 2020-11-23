// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

#define MAX_INT 987654321

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

struct RMQ {
  int m_n;
  std::vector<int> m_rangemin;
  explicit RMQ(const std::vector<int>& v) {
    m_n = v.size();
    m_rangemin.resize(m_n * 4);
    init(v, 0, m_n - 1, 1);
  }

  // vleft: left index of v
  // vright: right index of v
  // rmidx: index of m_rangemin
  int init(const std::vector<int>& v, int vleft, int vright, int rmidx) {
    // base condition
    if (vleft == vright)
      return m_rangemin[rmidx]= v[vleft];

    // recursion
    int vmid = (vleft + vright) / 2;
    int leftmin = init(v, vleft, vmid, rmidx * 2);
    int rightmin = init(v, vmid + 1, vright, rmidx * 2 + 1);

    return m_rangemin[rmidx] = std::min(leftmin, rightmin);
  }

  int query(int vleft, int vright) {
    return query(vleft, vright, 1, 0, m_n - 1);
  }

  // qvleft: query left index of vector
  // qvright: query right index of vector
  // rmidx: range min index
  int query(int qvleft, int qvright, int rmidx,
            int vleft, int vright) {
    // base condition
    if (qvright < vleft || vright < qvleft)
      return MAX_INT;
    if (qvleft <= vleft && vright <= qvright)
      return m_rangemin[rmidx];

    // recursion
    int vmid = (vleft + vright) / 2;
    return std::min(query(qvleft, qvright, rmidx * 2, vleft, vmid),
                    query(qvleft, qvright, rmidx * 2 + 1, vmid + 1, vright));
  }

  int update(int vidx, int newvalue) {
    return update(vidx, newvalue, 1, 0, m_n - 1);
  }

  int update(int vidx, int newvalue, int rmidx, int vleft, int vright) {
    // base condition
    // vidx is out of range between vleft and vright
    if (vidx < vleft || vidx > vright)
      return m_rangemin[rmidx];
    if (vleft == vright)
      return m_rangemin[rmidx] = newvalue;

    // recursion
    int vmid = (vleft + vright) / 2;
    return m_rangemin[rmidx] = std::min(
        update(vidx, newvalue, rmidx * 2, vleft, vmid),
        update(vidx, newvalue, rmidx * 2 + 1, vmid + 1, vright));
  }
};

int main() {
  std::vector<int> v;
  for (int i = 0; i <= 14; ++i)
    v.push_back(i);
  RMQ rmq(v);
  printf("%d\n", rmq.query(6, 12));
  rmq.update(6, 99);
  printf("%d\n", rmq.query(6, 12));
  // print_v_int(rmq.m_rangemin);
  return 0;
}
