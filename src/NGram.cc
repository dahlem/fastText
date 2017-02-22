/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "NGram.h"

#include <vector>

namespace fasttext {

NGram::NGram(std::shared_ptr<Args> args)
    : Dictionary(args) {
}

void NGram::computeSubwords(const std::string& word,
                            std::vector<int32_t>& ngrams) const {
    for (size_t i = 0; i < word.size(); i++) {
        std::string ngram;
        if ((word[i] & 0xC0) == 0x80) continue;
        for (size_t j = i, n = 1; j < word.size() && n <= args_->maxn; n++) {
            ngram.push_back(word[j++]);
            while (j < word.size() && (word[j] & 0xC0) == 0x80) {
                ngram.push_back(word[j++]);
            }
            if (n >= args_->minn && !(n == 1 && (i == 0 || j == word.size()))) {
                int32_t h = hash(ngram) % args_->bucket;
                ngrams.push_back(nwords_ + h);
            }
        }
    }
}

}
