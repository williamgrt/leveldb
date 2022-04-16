//
// Created by Ruitao Guo on 2022/1/3.
//

#include "leveldb/db.h"
#include "leveldb/options.h"
#include <cassert>
#include <iostream>

using namespace std;
using namespace leveldb;

int main() {
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "testdb", &db);
  assert(status.ok());

  status = db->Put(WriteOptions(), "KeyNameExample", "ValueExample");
  assert(status.ok());
  string res;
  status = db->Get(ReadOptions(), "KeyNameExample", &res);
  assert(status.ok());
  cout << res << endl;

  delete db;
  return 0;
}