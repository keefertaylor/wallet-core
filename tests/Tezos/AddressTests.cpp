// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Tezos/Address.h"
#include "Tezos/BinaryCoding.h"
#include "Tezos/PublicKey.h"
#include "Tezos/Transaction.h"

#include <gtest/gtest.h>
using namespace TW::Tezos;

TEST(TezosAddress, ForgeBoolTrue) {
  auto expected = "ff";

  auto output = forgeBool(true);

  ASSERT_EQ(output, expected);
}

TEST(TezosAddress, ForgeBoolFalse) {
  auto expected = "00";

  auto output = forgeBool(false);

  ASSERT_EQ(output, expected);
}

TEST(TezosAddress, forge_tz1) {
  auto input = Address("tz1eZwq8b5cvE2bPKokatLkVMzkxz24z3Don");
  auto expected = "0000cfa4aae60f5d9389752d41e320da224d43287fe2";

  ASSERT_EQ(input.forge(), expected);
}

TEST(TezosAddress, forge_tz2) {
  auto input = Address("tz2Rh3NYeLxrqTuvaZJmaMiVMqCajeXMWtYo");
  auto expected = "0001be99dd914e38388ec80432818b517759e3524f16";

  ASSERT_EQ(input.forge(), expected);
}

TEST(TezosAddress, forge_tz3) {
  auto input = Address("tz3RDC3Jdn4j15J7bBHZd29EUee9gVB1CxD9");
  auto expected = "0002358cbffa97149631cfb999fa47f0035fb1ea8636";

  ASSERT_EQ(input.forge(), expected);
}

TEST(TezosAddress, forge_KT1) {
  auto input = Address("KT1HiGcq47Yek7dcre7So2yfWTLU83FTBaf1");
  auto expected = "0164244bbdc7790d7896b6a52ac49802cfe4eafc4b00";

  ASSERT_EQ(input.forge(), expected);
}
