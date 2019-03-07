// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWCoinType.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_CLASS
struct TWWallet;

/// Validates an address string for a specific coin.
TW_EXPORT_STATIC_METHOD
bool TWWalletValidate(TWString *_Nonnull string, enum TWCoinType coin);

TW_EXTERN_C_END