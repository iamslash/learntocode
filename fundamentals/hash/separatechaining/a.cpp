// Copyright (C) 2016 by iamslash

// https://www.youtube.com/watch?v=BwcKHxUYRB4&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY&index=123

#include <cstdio>
#include <string>
#include <list>
#include <algorithm>

template <class TYPE, class HASH> class ChainMap {
 public:
  struct MapPos {
    TYPE key;
    long index;
    long pos;
  };
 public:
  ChainMap(const HASH& hash, int n_size = 100) {
    m_p_arr = new std::list<TYPE>[n_size];    
    m_hash = hash;
    m_n_arr_size = n_size;
    m_n_cnt = 0;
  }
  ~ChainMap() {
    delete[] m_p_arr;
  }
  long GetCount() const { return m_n_cnt; }
  bool IsEmpty() const { return m_n_cnt == 0; }
  void RemoveAll() {
    for (int i = 0; i < m_n_arr_size; ++i) {
      m_p_arr[i].clear();
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
    int idx = m_hash.hash(value) % m_n_arr_size;
    m_p_arr[idx].push_front(value);
  }
  bool Remove(const TYPE& key);
  bool RemoveAt(const MapPos& pos) {
    pos.index = m_hash.hash(pos.key) % m_n_arr_size;
    auto it = m_p_arr[pos.index].begin();
    for (int i = 0; i < pos.pos; ++i) {
      ++it;
    }
    m_p_arr[pos.index].erase(it);
    return true;
  }
 protected:
  std::list<TYPE>* m_p_arr;
  long m_n_arr_size;
  long m_n_cnt;
  HASH m_hash;
  bool _Find(MapPos& pos) const {
    pos.index = m_hash.hash(pos.key) % m_n_arr_size;
    auto it = m_p_arr[pos.index].begin();
    for (int i = 0; i < pos.pos; ++i) {
      ++it;
    }
    if (it == m_p_arr[pos.index].end())
      return false;
    return true;
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
  ChainMap<Person, PersonHash> map(PersonHash(), 13);
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
