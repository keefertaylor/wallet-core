// Copyright © 2017-2019 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#ifndef JNI_TW_TEZOSADDRESS_H
#define JNI_TW_TEZOSADDRESS_H

#include <jni.h>
#include <TrustWalletCore/TWBase.h>

TW_EXTERN_C_BEGIN

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_TezosAddress_initWithString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_TezosAddress_initWithPublicKey(JNIEnv *env, jclass thisClass, jobject publicKey);

JNIEXPORT
jstring JNICALL Java_wallet_core_jni_TezosAddress_description(JNIEnv *env, jclass thisClass, jobject address);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_TezosAddress_isValid(JNIEnv *env, jclass thisClass, jbyteArray data);

JNIEXPORT
jboolean JNICALL Java_wallet_core_jni_TezosAddress_isValidString(JNIEnv *env, jclass thisClass, jstring string);

JNIEXPORT
jbyteArray JNICALL Java_wallet_core_jni_TezosAddress_data(JNIEnv *env, jclass thisClass, jobject address);


TW_EXTERN_C_END

#endif // JNI_TW_TEZOSADDRESS_H
