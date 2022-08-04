// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
//
// Log format information shared by reader and writer.
// See ../doc/log_format.md for more detail.

#ifndef STORAGE_LEVELDB_DB_LOG_FORMAT_H_
#define STORAGE_LEVELDB_DB_LOG_FORMAT_H_

namespace leveldb {
namespace log {
// Record Header 格式
// ----------------------------------------------------------
// | checksum (4 bytes) ｜ length (2 bytes) ｜ type (1 byte) ｜
// ----------------------------------------------------------
enum RecordType {
  // Zero is reserved for preallocated files
  kZeroType = 0,

  // kFullType 表示 Record 存储了完整的用户记录
  kFullType = 1,

  // For fragments
  kFirstType = 2,
  kMiddleType = 3,
  kLastType = 4
};
static const int kMaxRecordType = kLastType;

// Log Block 大小为 32 KB
static const int kBlockSize = 32768; 

// Header is checksum (4 bytes), length (2 bytes), type (1 byte).
// 每个 Record Header 大小 7 字节
static const int kHeaderSize = 4 + 2 + 1; 

}  // namespace log
}  // namespace leveldb

#endif  // STORAGE_LEVELDB_DB_LOG_FORMAT_H_
