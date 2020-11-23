/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

class SegTree {
 public:
  int m_vlen;
  std::vector<int> m_arr;
  SegTree(const std::vector<int>& V) {
    m_vlen = V.size();
    m_arr.resize(m_vlen * 4);
    init(V, 0, m_vlen - 1, 1);
  }
  
  // vleft: left index of V
  // vright: right index of V
  // idx: index of m_arr
  int init(const std::vector<int>& V, int vleft, int vright,
           int idx) {
    // base
    if (vleft == vright)
      return m_arr[idx] = V[vleft];

    // recursion
    int vmid = (vleft + vright) / 2;
    int lmin = init(V, vleft, vmid, 2*idx);
    int rmin = init(V, vmid + 1, vright, 2*idx+1);
    return m_arr[idx] = std::min(lmin, rmin);                  
  }

  int query(int vleft, int vright) {
    return query(vleft, vright, 1, 0, m_vlen - 1);
  }

  // qvleft: query left index of vector
  // qvright: query right index of vector
  // idx: index of m_arr
  int query(int qvleft, int qvright, int idx,
            int vleft, int vright) {
    // base
    if (qvright < vleft || vright < qvleft)
      return INT_MAX;
    if (qvleft <= vleft && vright <= qvright)
      return m_arr[idx];    

    // recursion
    int vmid = (vleft + vright) / 2;
    return std::min(
        query(qvleft, qvright, 2*idx, vleft, vmid),
        query(qvleft, qvright, 2*idx+1, vmid+1, vright));
  }

  int update(int vidx, int val) {
    return update(vidx, val, 1, 0, m_vlen - 1);
  }

  int update(int vidx, int val, int idx, int vleft, int vright) {
    // base
    // vidx is out of range between vleft and vright
    if (vidx < vleft || vidx > vright)
      return m_arr[idx];
    if (vleft == vright)
      return m_arr[idx] = val;

    // recursion
    int vmid = (vleft + vright) / 2;
    return m_arr[idx] = std::min(
        update(vidx, val, 2*idx, vleft, vmid),
        update(vidx, val, 2*idx+1, vmid+1, vright));
  }
};

void printv(const std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

int main() {
  std::vector<int> v;
  for (int i = 0; i <= 14; ++i)
    v.push_back(i);
  SegTree st(v);
  printf("%d\n", st.query(6, 12));
  st.update(6, 99);
  printf("%d\n", st.query(6, 12));
  // printv(rmq.m_arr);
  return 0;
}

