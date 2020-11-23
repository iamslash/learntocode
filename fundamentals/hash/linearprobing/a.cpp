// Copyright (C) 2016 by iamslash

// https://www.youtube.com/watch?v=BwcKHxUYRB4&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=123

#include <cstdio>
#include <string>

template <class TYPE, class HASH> class HashMap {
 public:
  struct MapPos {
    TYPE key;
    long index;
  };
  enum NodeStatus {
    EMPTY,
    DELETED,
    AVAIL
  };

 protected:
  struct Node {
    TYPE data;
    NodeStatus status;
    Node() {
      status = EMPTY;
    }
  };

 public:
  HashMap(const HASH& hash, int n_size = 100) {
    m_p_arr = new Node[n_size];
    m_hash = hash;
    m_n_arr_size = n_size;
    m_n_cnt = 0;
  }
  ~HashMap() {
    delete [] m_p_arr;
  }
  //
  long GetCount() {
    return m_n_cnt;
  }
  bool IsEmpty() const {
    return m_n_cnt;
  }
  void RemoveAll() {
    for (int i = 0; i < m_n_arr_size; ++i) {
      m_p_arr[i].status = EMPTY;
    }   
  }
  bool Find(const TYPE& key) const {
    MapPos pos;
    pos.key = key;
    if (!_Find(pos))
      return false;
    return true;
  }
  bool Insert(const TYPE& value) {
    int start, idx;
    idx = start = m_hash.hash(value) % m_n_arr_size;
    // linear probe
    while (m_p_arr[idx].status == AVAIL) {
      idx = (idx + _Next(value)) % m_n_arr_size;
      // m_p_arr is full
      if (idx == start)
        return false;
    }
    m_p_arr[idx].status = AVAIL;
    m_p_arr[idx].data = value;
    m_n_cnt++;
    return true;
  }
  bool Remove(const TYPE& key) {
    MapPos pos;
    pos.key = key;
    pos.index = 0;
    if (!_Find(pos))
      return false;
    RemoveAt(pos);
    return true;
  }
  bool FindFirst(const TYPE& key, TYPE& value, MapPos& pos) const;
  bool FindNext(TYPE& value, MapPos& pos) const;
  bool RemoveAt(const MapPos& pos) {
    if (m_n_cnt <= 0 || pos.index < 0 || pos.index >= m_n_arr_size)
      return false;
    if (m_p_arr[pos.index].status != AVAIL)
      return false;
    m_p_arr[pos.index].status = DELETED;
    m_n_cnt--;
    return true;
  }
  
 protected:
  Node * m_p_arr;
  long m_n_arr_size;
  long m_n_cnt;
  HASH m_hash;
  bool _Find(MapPos& pos) const {
    int start, idx;
    idx = start = m_hash.hash(pos.key) % m_n_arr_size;
    while (m_p_arr[idx].status != EMPTY) {
      if (m_p_arr[idx].status == AVAIL && m_p_arr[idx].data == pos.key) {
        pos.index = idx;
        return true;
      }
      idx = (idx + _Next(pos.key)) % m_n_arr_size;
      // searched one circle
      if (idx == start)
        break;
    }
    return false;
  }
  int _Next(const TYPE& key) const {
    return 1;
  }
};

class PersonHash;

struct Person {
  int m_id;
  std::string m_name;
  Person() : m_id(0) {}
  Person(int id, const std::string& name) : m_id(id), m_name(name) {}
  Person(const Person& p) {
    m_id = p.m_id;
    m_name = p.m_name;
  }
  Person operator=(const Person& p) {
    m_id = p.m_id;
    m_name = p.m_name;
    return *this;
  }
  bool operator==(const Person& p) const {
    return m_id == p.m_id;
  }
  bool operator>(const Person& p) const {
    return m_id > p.m_id;
  }
  friend class personHash;
};

class PersonHash {
 public:
  unsigned long hash(const Person& p) const {
    return (unsigned long)p.m_id * 11;
  }
};

int main() {
  HashMap<Person, PersonHash> map(PersonHash(), 13);
  map.Insert(Person(5, "Foo"));
  map.Insert(Person(3, "Bar"));

  Person key;
  key.m_id = 3;

  if (map.Find(key))
    printf("FOUND");
  else
    printf("NOT FOUND");
  printf("\n");
  
  return 0;
}
