/*
 *  Copyright 2019-2022 Diligent Graphics LLC
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including negligence),
 *  contract, or otherwise, unless required by applicable law (such as deliberate
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental,
 *  or consequential damages of any character arising as a result of this License or
 *  out of the use or inability to use the software (including but not limited to damages
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and
 *  all other commercial damages or losses), even if such Contributor has been advised
 *  of the possibility of such damages.
 */

#include "RenderStateNotation/interface/RenderStateNotationParser.h"

#include <cstddef>

namespace Diligent
{

namespace
{

#ifdef __GNUC__
// Disable GCC warnings like this one:
//    warning: offsetof within non-standard-layout type ‘Diligent::{anonymous}::DeviceObjectAttribs is conditionally-supported [-Winvalid-offsetof]
#    pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif

#define CHECK_BASE_STRUCT_ALIGNMENT(StructName) \
    struct StructName##Test : StructName        \
    {                                           \
        Uint8 AlignmentTest;                    \
    };                                          \
    static_assert(offsetof(StructName##Test, AlignmentTest) == sizeof(StructName), "Using " #StructName " as a base class may result in misalignment")

CHECK_BASE_STRUCT_ALIGNMENT(PipelineStateNotation);

} // namespace

} // namespace Diligent
