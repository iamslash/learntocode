// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

#define MAX_INT 987654321

// range freqeucy query
struct RangeItem {
  int size;       // size of range
  int mostfreq;   // frequency of the most frequent number
  int leftnum;    // left most number
  int leftfreq;   // frequency of the left most number
  int rightnum;   // right most number
  int rightfreq;  // frequency of the right most number
  RangeItem() {
    Set(0, 0, 0, 0, 0, 0);
  }
  explicit RangeItem(int _size, int _mostfreq, int _leftnum,
                     int _leftfreq, int _rightnum, int _rightfreq) {
    Set(_size, _mostfreq, _leftnum,
        _leftfreq, _rightnum, _rightfreq);
  }
  void Set(int _size, int _mostfreq, int _leftnum,
                     int _leftfreq, int _rightnum, int _rightfreq) {
    size      = _size;
    mostfreq  = _mostfreq;
    leftnum   = _leftnum;
    leftfreq  = _leftfreq;
    rightnum  = _rightnum;
    rightfreq = _rightfreq;
  }
  void Dump() {
    printf("size: %d, modstfreq: %d, leftnum: %d, leftfreq: %d, rightnum: %d, rightfreq: %d\n",
           size, mostfreq, leftnum, leftfreq, rightnum, rightfreq);
  }
};

RangeItem merge(const RangeItem& a, const RangeItem& b) {
  RangeItem r;
  r.size = a.size + b.size;
  // handle left numbers
  r.leftnum = a.leftnum;
  r.leftfreq = a.leftfreq;
  // ex. [1, 1, 1, 1] [1, 2, 2, 2]
  // ex. [2] [2]
  if (a.size == a.leftfreq && a.leftnum == b.leftnum)
    r.leftfreq += b.leftfreq;
  // handle right numbers
  r.rightnum = b.rightnum;
  r.rightfreq = b.rightfreq;
  // ex. [1, 1, 1, 2] [2, 2, 2, 2]
  // ex. [2] [2]
  if (b.size == b.rightfreq && a.rightnum == b.rightnum)
    r.rightfreq += a.rightfreq;
  // handle mostfreq
  r.mostfreq = std::max(a.mostfreq, b.mostfreq);
  // ex. [1, 2, 2, 2] [2, 3, 3, 3]
  // ex. [2] [2]
  if (a.rightnum == b.leftnum)
    r.mostfreq = std::max(r.mostfreq, a.rightfreq + b.leftfreq);
  return r;
}

class RFQT {
 public:
  int n;
  std::vector<RangeItem> rangeitems;
  explicit RFQT(const std::vector<int>& v) {
    n = v.size();
    rangeitems.resize(n * 4);
    init(v, 0, n - 1, 1);
  }
  RangeItem init(const std::vector<int>& v,
                 int vleft, int vright,
                 int rmidx) {
    // base condition
    if (vleft == vright) {
      rangeitems[rmidx].Set(1, 1, v[vleft], 1, v[vleft], 1);
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
    if (litem.size != 0 && ritem.size != 0)
      return merge(litem, ritem);
    return (litem.size != 0) ? litem : ritem;
  }
};

int main() {
  std::vector<int> v = {1, 2, 2, 2, 2, 3, 3, 3};
  RFQT rfqt(v);
  RangeItem ri = rfqt.query(0, 7);
  // ri.Dump();
  printf("%d\n", ri.mostfreq);
  return 0;
}
