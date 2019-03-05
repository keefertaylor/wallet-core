// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Address.h"
#include "PublicKey.h"
#include <string>
#include <variant>

namespace TW {
namespace Tezos {

enum class TransactionType {
    REVEAL      = 0,
    PAYMENT     = 1
};

class Transaction {

public:
    Address source;
    int64_t fee;
    int64_t counter;
    int64_t gas_limit;
    int64_t storage_limit;
    int64_t amount;
    std::variant<Address, PublicKey> destination_or_public_key;
    TransactionType transaction_type;

    Transaction() = default;
    Transaction(Address source, int64_t fee, int64_t counter, int64_t gas_limit, int64_t storage_limit, int64_t amount, std::variant<Address, PublicKey> destination_or_public_key, TransactionType transaction_type)
    : source(source)
    , fee(fee)
    , counter(counter)
    , gas_limit(gas_limit)
    , storage_limit(storage_limit)
    , amount(amount)
    , destination_or_public_key(destination_or_public_key)
    , transaction_type(transaction_type)
    {}

public:
    /// serialize transaction
    std::string forge();
};

}} // namespace
