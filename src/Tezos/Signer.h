// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "RLP.h"
#include "Transaction.h"
#include "../Data.h"
#include "../Hash.h"
#include "../PrivateKey.h"

#include <boost/multiprecision/cpp_int.hpp>
#include <cstdint>
#include <tuple>
#include <vector>

namespace TW {
namespace Tezos {

typedef boost::multiprecision::uint256_t uint256_t;

/// Helper class that performs Ethereum transaction signing.
class Signer {
public:
    boost::multiprecision::uint256_t chainID;

    /// Initializes a signer with a chain identifier.
    Signer(boost::multiprecision::uint256_t chainID) : chainID(chainID) {}

    /// Signs the given transaction.
    void sign(const PrivateKey& privateKey, Transaction& transaction) const noexcept;

public:
    /// Signs a hash with the given private key for the given chain identifier.
    ///
    /// @returns the r, s, and v values of the transaction signature
    static std::tuple<uint256_t, uint256_t, uint256_t> sign(const uint256_t& chainID, const PrivateKey& privateKey, const Data& hash) noexcept;

    /// R, S, and V values for the given chain identifier and signature.
    ///
    /// @returns the r, s, and v values of the transaction signature
    static std::tuple<uint256_t, uint256_t, uint256_t> values(const uint256_t& chainID, const std::array<byte, 65>& signature) noexcept;

protected:
    /// Computes the transaction hash.
    Data hash(const Transaction& transaction) const noexcept;
};

}} // namespace

/// Wrapper for C interface.
struct TWTezosSigner {
    TW::Tezos::Signer impl;
};