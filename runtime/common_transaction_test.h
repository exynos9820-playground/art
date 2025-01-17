/*
 * Copyright (C) 2024 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_RUNTIME_COMMON_TRANSACTION_TEST_H_
#define ART_RUNTIME_COMMON_TRANSACTION_TEST_H_

#include "common_runtime_test.h"

namespace art HIDDEN {

class CommonTransactionTestImpl {
 protected:
  static void EnterTransactionMode() REQUIRES_SHARED(Locks::mutator_lock_);
  static void ExitTransactionMode();
  static void RollbackAndExitTransactionMode() REQUIRES_SHARED(Locks::mutator_lock_);
  static bool IsTransactionAborted();
};

template <typename TestType>
class CommonTransactionTestBase : public TestType, public CommonTransactionTestImpl {};

using CommonTransactionTest = CommonTransactionTestBase<CommonRuntimeTest>;

}  // namespace art

#endif  // ART_RUNTIME_COMMON_TRANSACTION_TEST_H_
