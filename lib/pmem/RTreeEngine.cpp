/**
 * Copyright 2018 Intel Corporation.
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you (Intel OBL Internal Use License).
 * Unless the License provides otherwise, you may not use, modify, copy,
 * publish, distribute, disclose or transmit this software or the related
 * documents without Intel's prior written permission.
 *
 * This software and the related documents are provided as is, with no
 * express or implied warranties, other than those that are expressly
 * stated in the License.
 */

#include "RTreeEngine.h"
#include "RTree.h"
namespace DaqDB {
RTreeEngine *RTreeEngine::Open(const string &engine, // open storage engine
                               const string &path,   // path to persistent pool
                               size_t size, size_t allocUnitSize) {
    return new DaqDB::RTree(path, size, allocUnitSize);
}

void RTreeEngine::Close(RTreeEngine *kv) {} // close storage engine
}