/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef FASTTEXT_NGRAM_H
#define FASTTEXT_NGRAM_H

#include "dictionary.h"
#include "args.h"
#include "real.h"

namespace fasttext {


class NGram : public Dictionary {
public:
    explicit NGram(std::shared_ptr<Args>);
    void computeSubwords(const std::string&, std::vector<int32_t>&) const;
};

}

#endif
