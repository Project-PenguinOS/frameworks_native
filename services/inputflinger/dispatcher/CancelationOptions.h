/*
 * Copyright (C) 2019 The Android Open Source Project
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

#pragma once

#include <utils/BitSet.h>
#include <optional>

namespace android {
namespace inputdispatcher {

/* Specifies which events are to be canceled and why. */
struct CancelationOptions {
    enum class Mode {
        CANCEL_ALL_EVENTS = 0,
        CANCEL_POINTER_EVENTS = 1,
        CANCEL_NON_POINTER_EVENTS = 2,
        CANCEL_FALLBACK_EVENTS = 3,
    };

    // The criterion to use to determine which events should be canceled.
    Mode mode;

    // Descriptive reason for the cancelation.
    const char* reason;

    // The specific keycode of the key event to cancel, or nullopt to cancel any key event.
    std::optional<int32_t> keyCode = std::nullopt;

    // The specific device id of events to cancel, or nullopt to cancel events from any device.
    std::optional<int32_t> deviceId = std::nullopt;

    // The specific display id of events to cancel, or nullopt to cancel events on any display.
    std::optional<int32_t> displayId = std::nullopt;

    // The specific pointers to cancel, or nullopt to cancel all pointer events
    std::optional<BitSet32> pointerIds = std::nullopt;

    CancelationOptions(Mode mode, const char* reason) : mode(mode), reason(reason) {}
};

} // namespace inputdispatcher
} // namespace android
