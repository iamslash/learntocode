// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

#define MAX_INT 987654321

// range freqeucy query
struct RangeItem {
  int no1;
  int no2;
  RangeItem() {
    no1  = -1;
    no2  = -1;
  }
  explicit RangeItem(int _no1, int _no2) {
    no1      = _no1;
    no2  = _no2;
  }
};

RangeItem merge(const RangeItem& a, const RangeItem& b) {
  RangeItem r;
  if (a.no1 < b.no1) {
    r.no1 = a.no1;
    r.no2 = std::min(a.no2, b.no1);
  } else {
    r.no1 = b.no1;
    r.no2 = std::min(a.no1, b.no2);
  }
  return r;
}

class RMQT {
 public:
  int n;
  std::vector<RangeItem> rangeitems;
  explicit RMQT(const std::vector<int>& v) {
    n = v.size();
    rangeitems.resize(n * 4);
    init(v, 0, n - 1, 1);
  }
  RangeItem init(const std::vector<int>& v,
                 int vleft, int vright,
                 int rmidx) {
    // base condition
    if (vleft == vright) {
      rangeitems[rmidx].no1 = v[vleft];
      rangeitems[rmidx].no2 = MAX_INT;
      return rangeitems[rmidx];
    }

    // recursion
    int vmid = (vleft + vright) / 2;
    RangeItem litem = init(v, vleft, vmid, rmidx * 2);
    RangeItem ritem = init(v, vmid + 1, vright, rmidx * 2 + 1);

    return rangeitems[rmidx] = merge(litem, ritem);
  }

  RangeItem query(int vleft, int vright) {
    return query(vleft, vright, 1, 0, n - 1);
  }
  // qvleft: query left index of vector
  // qvright: query right index of vector
  // rmidx: range min index
  RangeItem query(int qvleft, int qvright, int rmidx,
                  int vleft, int vright) {
    // base condition
    if (qvright < vleft || vright < qvleft)
      return RangeItem();
    if (qvleft <= vleft && vright <= qvright)
      return rangeitems[rmidx];

    // recursion
    int vmid = (vleft + vright) / 2;
    RangeItem litem = query(qvleft, qvright, rmidx * 2, vleft, vmid);
    RangeItem ritem = query(qvleft, qvright, rmidx * 2 + 1, vmid + 1, vright);
    if (litem.no1 >= 0 && ritem.no1 >= 0)
      return merge(litem, ritem);
    return (litem.no1 >= 0) ? litem : ritem;
  }
};

int main() {
  std::vector<int> v = {1, 2, 4, 3, 7, 5, 6, 0};
  RMQT rmqt(v);
  RangeItem ri = rmqt.query(0, 7);
  printf("%d %d\n", ri.no1, ri.no2);
  ri = rmqt.query(1, 7);
  printf("%d %d\n", ri.no1, ri.no2);
  return 0;
}
