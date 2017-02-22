/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "LZ.h"

#include <vector>

namespace fasttext {

LZ::LZ(std::shared_ptr<Args> args)
    : Dictionary(args) {
}

void LZ::computeSubwords(const std::string& word,
                         std::vector<int32_t>& ngrams) const {
    std::string ngram;
    for (size_t i = 0; i < word.size()-1; i++) {
        if ((word[i] & 0xC0) == 0x80) continue;
        ngram.push_back(word[i]);
        if (ngram.size() >= args_->minn) {
            int32_t h = hash(ngram) % args_->bucket;
            ngrams.push_back(nwords_ + h);
        }
    }
}

}
