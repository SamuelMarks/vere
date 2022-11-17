# This build file is derived from the makefiles in `build/` in the `softfloat`
# repo at https://github.com/ucb-bar/berkeley-softfloat-3.
#
# The following link, which is referenced in `README.md` in the `softfloat`
# repo, was useful in deriving this build file:
#   http://www.jhauser.us/arithmetic/SoftFloat-3/doc/SoftFloat-source.html

cc_library(
    name = "softfloat",
    visibility = ["//visibility:public"],
    deps = select({
        # TODO: Test that :softfloat_arm64 is the fastest correct choice for
        # macos_arm64 builds.
        "@platforms//cpu:arm64": [":softfloat_arm64"],
        "@platforms//cpu:x86_64": [":softfloat_x86_64"],
        "//conditions:default": [],
    }),
)

cc_library(
    name = "softfloat_arm64",
    srcs = [
        # See `OBJS_PRIMITIVES` in `build/Linux-ARM-VFPv2-GCC/Makefile` in the
        # `softfloat` repo.
        "source/s_compare96M.c",
        "source/s_compare128M.c",
        "source/s_shortShiftLeft64To96M.c",
        "source/s_shortShiftLeftM.c",
        "source/s_shiftLeftM.c",
        "source/s_shortShiftRightM.c",
        "source/s_shortShiftRightJam64.c",
        "source/s_shortShiftRightJamM.c",
        "source/s_shiftRightJam32.c",
        "source/s_shiftRightJam64.c",
        "source/s_shiftRightJamM.c",
        "source/s_shiftRightM.c",
        "source/s_countLeadingZeros8.c",
        "source/s_countLeadingZeros16.c",
        "source/s_countLeadingZeros32.c",
        "source/s_countLeadingZeros64.c",
        "source/s_addM.c",
        "source/s_addCarryM.c",
        "source/s_addComplCarryM.c",
        "source/s_negXM.c",
        "source/s_sub1XM.c",
        "source/s_subM.c",
        "source/s_mul64To128M.c",
        "source/s_mul128MTo256M.c",
        "source/s_approxRecip_1Ks.c",
        "source/s_approxRecip32_1.c",
        "source/s_approxRecipSqrt_1Ks.c",
        "source/s_approxRecipSqrt32_1.c",
        "source/s_remStepMBy32.c",
        # See `OBJS_SPECIALIZE` in `build/Linux-ARM-VFPv2-GCC/Makefile` in the
        # `softfloat` repo.
        "source/ARM-VFPv2/softfloat_raiseFlags.c",
        "source/ARM-VFPv2/s_f16UIToCommonNaN.c",
        "source/ARM-VFPv2/s_commonNaNToF16UI.c",
        "source/ARM-VFPv2/s_propagateNaNF16UI.c",
        "source/ARM-VFPv2/s_f32UIToCommonNaN.c",
        "source/ARM-VFPv2/s_commonNaNToF32UI.c",
        "source/ARM-VFPv2/s_propagateNaNF32UI.c",
        "source/ARM-VFPv2/s_f64UIToCommonNaN.c",
        "source/ARM-VFPv2/s_commonNaNToF64UI.c",
        "source/ARM-VFPv2/s_propagateNaNF64UI.c",
        "source/ARM-VFPv2/extF80M_isSignalingNaN.c",
        "source/ARM-VFPv2/s_extF80MToCommonNaN.c",
        "source/ARM-VFPv2/s_commonNaNToExtF80M.c",
        "source/ARM-VFPv2/s_propagateNaNExtF80M.c",
        "source/ARM-VFPv2/f128M_isSignalingNaN.c",
        "source/ARM-VFPv2/s_f128MToCommonNaN.c",
        "source/ARM-VFPv2/s_commonNaNToF128M.c",
        "source/ARM-VFPv2/s_propagateNaNF128M.c",
        # See `OBJS_OTHERS` in `build/Linux-ARM-VFPv2-GCC/Makefile` in the
        # `softfloat` repo.
        "source/s_roundToUI32.c",
        "source/s_roundMToUI64.c",
        "source/s_roundToI32.c",
        "source/s_roundMToI64.c",
        "source/s_normSubnormalF16Sig.c",
        "source/s_roundPackToF16.c",
        "source/s_normRoundPackToF16.c",
        "source/s_addMagsF16.c",
        "source/s_subMagsF16.c",
        "source/s_mulAddF16.c",
        "source/s_normSubnormalF32Sig.c",
        "source/s_roundPackToF32.c",
        "source/s_normRoundPackToF32.c",
        "source/s_addMagsF32.c",
        "source/s_subMagsF32.c",
        "source/s_mulAddF32.c",
        "source/s_normSubnormalF64Sig.c",
        "source/s_roundPackToF64.c",
        "source/s_normRoundPackToF64.c",
        "source/s_addMagsF64.c",
        "source/s_subMagsF64.c",
        "source/s_mulAddF64.c",
        "source/s_tryPropagateNaNExtF80M.c",
        "source/s_invalidExtF80M.c",
        "source/s_normExtF80SigM.c",
        "source/s_roundPackMToExtF80M.c",
        "source/s_normRoundPackMToExtF80M.c",
        "source/s_addExtF80M.c",
        "source/s_compareNonnormExtF80M.c",
        "source/s_isNaNF128M.c",
        "source/s_tryPropagateNaNF128M.c",
        "source/s_invalidF128M.c",
        "source/s_shiftNormSigF128M.c",
        "source/s_roundPackMToF128M.c",
        "source/s_normRoundPackMToF128M.c",
        "source/s_addF128M.c",
        "source/s_mulAddF128M.c",
        "source/softfloat_state.c",
        "source/ui32_to_f16.c",
        "source/ui32_to_f32.c",
        "source/ui32_to_f64.c",
        "source/ui32_to_extF80M.c",
        "source/ui32_to_f128M.c",
        "source/ui64_to_f16.c",
        "source/ui64_to_f32.c",
        "source/ui64_to_f64.c",
        "source/ui64_to_extF80M.c",
        "source/ui64_to_f128M.c",
        "source/i32_to_f16.c",
        "source/i32_to_f32.c",
        "source/i32_to_f64.c",
        "source/i32_to_extF80M.c",
        "source/i32_to_f128M.c",
        "source/i64_to_f16.c",
        "source/i64_to_f32.c",
        "source/i64_to_f64.c",
        "source/i64_to_extF80M.c",
        "source/i64_to_f128M.c",
        "source/f16_to_ui32.c",
        "source/f16_to_ui64.c",
        "source/f16_to_i32.c",
        "source/f16_to_i64.c",
        "source/f16_to_ui32_r_minMag.c",
        "source/f16_to_ui64_r_minMag.c",
        "source/f16_to_i32_r_minMag.c",
        "source/f16_to_i64_r_minMag.c",
        "source/f16_to_f32.c",
        "source/f16_to_f64.c",
        "source/f16_to_extF80M.c",
        "source/f16_to_f128M.c",
        "source/f16_roundToInt.c",
        "source/f16_add.c",
        "source/f16_sub.c",
        "source/f16_mul.c",
        "source/f16_mulAdd.c",
        "source/f16_div.c",
        "source/f16_rem.c",
        "source/f16_sqrt.c",
        "source/f16_eq.c",
        "source/f16_le.c",
        "source/f16_lt.c",
        "source/f16_eq_signaling.c",
        "source/f16_le_quiet.c",
        "source/f16_lt_quiet.c",
        "source/f16_isSignalingNaN.c",
        "source/f32_to_ui32.c",
        "source/f32_to_ui64.c",
        "source/f32_to_i32.c",
        "source/f32_to_i64.c",
        "source/f32_to_ui32_r_minMag.c",
        "source/f32_to_ui64_r_minMag.c",
        "source/f32_to_i32_r_minMag.c",
        "source/f32_to_i64_r_minMag.c",
        "source/f32_to_f16.c",
        "source/f32_to_f64.c",
        "source/f32_to_extF80M.c",
        "source/f32_to_f128M.c",
        "source/f32_roundToInt.c",
        "source/f32_add.c",
        "source/f32_sub.c",
        "source/f32_mul.c",
        "source/f32_mulAdd.c",
        "source/f32_div.c",
        "source/f32_rem.c",
        "source/f32_sqrt.c",
        "source/f32_eq.c",
        "source/f32_le.c",
        "source/f32_lt.c",
        "source/f32_eq_signaling.c",
        "source/f32_le_quiet.c",
        "source/f32_lt_quiet.c",
        "source/f32_isSignalingNaN.c",
        "source/f64_to_ui32.c",
        "source/f64_to_ui64.c",
        "source/f64_to_i32.c",
        "source/f64_to_i64.c",
        "source/f64_to_ui32_r_minMag.c",
        "source/f64_to_ui64_r_minMag.c",
        "source/f64_to_i32_r_minMag.c",
        "source/f64_to_i64_r_minMag.c",
        "source/f64_to_f16.c",
        "source/f64_to_f32.c",
        "source/f64_to_extF80M.c",
        "source/f64_to_f128M.c",
        "source/f64_roundToInt.c",
        "source/f64_add.c",
        "source/f64_sub.c",
        "source/f64_mul.c",
        "source/f64_mulAdd.c",
        "source/f64_div.c",
        "source/f64_rem.c",
        "source/f64_sqrt.c",
        "source/f64_eq.c",
        "source/f64_le.c",
        "source/f64_lt.c",
        "source/f64_eq_signaling.c",
        "source/f64_le_quiet.c",
        "source/f64_lt_quiet.c",
        "source/f64_isSignalingNaN.c",
        "source/extF80M_to_ui32.c",
        "source/extF80M_to_ui64.c",
        "source/extF80M_to_i32.c",
        "source/extF80M_to_i64.c",
        "source/extF80M_to_ui32_r_minMag.c",
        "source/extF80M_to_ui64_r_minMag.c",
        "source/extF80M_to_i32_r_minMag.c",
        "source/extF80M_to_i64_r_minMag.c",
        "source/extF80M_to_f16.c",
        "source/extF80M_to_f32.c",
        "source/extF80M_to_f64.c",
        "source/extF80M_to_f128M.c",
        "source/extF80M_roundToInt.c",
        "source/extF80M_add.c",
        "source/extF80M_sub.c",
        "source/extF80M_mul.c",
        "source/extF80M_div.c",
        "source/extF80M_rem.c",
        "source/extF80M_sqrt.c",
        "source/extF80M_eq.c",
        "source/extF80M_le.c",
        "source/extF80M_lt.c",
        "source/extF80M_eq_signaling.c",
        "source/extF80M_le_quiet.c",
        "source/extF80M_lt_quiet.c",
        "source/f128M_to_ui32.c",
        "source/f128M_to_ui64.c",
        "source/f128M_to_i32.c",
        "source/f128M_to_i64.c",
        "source/f128M_to_ui32_r_minMag.c",
        "source/f128M_to_ui64_r_minMag.c",
        "source/f128M_to_i32_r_minMag.c",
        "source/f128M_to_i64_r_minMag.c",
        "source/f128M_to_f16.c",
        "source/f128M_to_f32.c",
        "source/f128M_to_f64.c",
        "source/f128M_to_extF80M.c",
        "source/f128M_roundToInt.c",
        "source/f128M_add.c",
        "source/f128M_sub.c",
        "source/f128M_mul.c",
        "source/f128M_mulAdd.c",
        "source/f128M_div.c",
        "source/f128M_rem.c",
        "source/f128M_sqrt.c",
        "source/f128M_eq.c",
        "source/f128M_le.c",
        "source/f128M_lt.c",
        "source/f128M_eq_signaling.c",
        "source/f128M_le_quiet.c",
        "source/f128M_lt_quiet.c",
        # See `$(OBJS_ALL)` target in `build/Linux-ARM-VFPv2-GCC/Makefile` in the
        # `softfloat` repo.
        "build/Linux-ARM-VFPv2-GCC/platform.h",
        "source/include/primitiveTypes.h",
        "source/include/primitives.h",
        # See `$(OBJS_SPECIALIZE) $(OBJS_OTHERS)` target in
        # `build/Linux-ARM-VFPv2-GCC/Makefile` in the `softfloat` repo.
        "source/include/softfloat_types.h",
        "source/include/internals.h",
        "source/ARM-VFPv2/specialize.h",
        # `platform.h` includes `opts-GCC.h`.
        "source/include/opts-GCC.h",
    ],
    hdrs = ["source/include/softfloat.h"],
    copts = [
        "-Iexternal/softfloat/build/Linux-ARM-VFPv2-GCC",
        "-Iexternal/softfloat/source/ARM-VFPv2",
        "-Werror-implicit-function-declaration",
        "-O2",
    ],
    includes = ["source/include"],
    local_defines = [
        "SOFTFLOAT_ROUND_ODD",
        "INLINE_LEVEL=5",
    ],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "softfloat_x86_64",
    srcs = [
        # See `OBJS_PRIMITIVES` in `build/Linux-x86_64-GCC/Makefile` in the
        # `softfloat` repo.
        "source/s_eq128.c",
        "source/s_le128.c",
        "source/s_lt128.c",
        "source/s_shortShiftLeft128.c",
        "source/s_shortShiftRight128.c",
        "source/s_shortShiftRightJam64.c",
        "source/s_shortShiftRightJam64Extra.c",
        "source/s_shortShiftRightJam128.c",
        "source/s_shortShiftRightJam128Extra.c",
        "source/s_shiftRightJam32.c",
        "source/s_shiftRightJam64.c",
        "source/s_shiftRightJam64Extra.c",
        "source/s_shiftRightJam128.c",
        "source/s_shiftRightJam128Extra.c",
        "source/s_shiftRightJam256M.c",
        "source/s_countLeadingZeros8.c",
        "source/s_countLeadingZeros16.c",
        "source/s_countLeadingZeros32.c",
        "source/s_countLeadingZeros64.c",
        "source/s_add128.c",
        "source/s_add256M.c",
        "source/s_sub128.c",
        "source/s_sub256M.c",
        "source/s_mul64ByShifted32To128.c",
        "source/s_mul64To128.c",
        "source/s_mul128By32.c",
        "source/s_mul128To256M.c",
        "source/s_approxRecip_1Ks.c",
        "source/s_approxRecip32_1.c",
        "source/s_approxRecipSqrt_1Ks.c",
        "source/s_approxRecipSqrt32_1.c",
        # See `OBJS_SPECIALIZE` in `build/Linux-x86_64-GCC/Makefile` in the
        # `softfloat` repo.
        "source/8086-SSE/softfloat_raiseFlags.c",
        "source/8086-SSE/s_f16UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF16UI.c",
        "source/8086-SSE/s_propagateNaNF16UI.c",
        "source/8086-SSE/s_f32UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF32UI.c",
        "source/8086-SSE/s_propagateNaNF32UI.c",
        "source/8086-SSE/s_f64UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF64UI.c",
        "source/8086-SSE/s_propagateNaNF64UI.c",
        "source/8086-SSE/extF80M_isSignalingNaN.c",
        "source/8086-SSE/s_extF80UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToExtF80UI.c",
        "source/8086-SSE/s_propagateNaNExtF80UI.c",
        "source/8086-SSE/f128M_isSignalingNaN.c",
        "source/8086-SSE/s_f128UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF128UI.c",
        "source/8086-SSE/s_propagateNaNF128UI.c",
        # See `OBJS_OTHERS` in `build/Linux-x86_64-GCC/Makefile` in the
        # `softfloat` repo.
        "source/s_roundToUI32.c",
        "source/s_roundToUI64.c",
        "source/s_roundToI32.c",
        "source/s_roundToI64.c",
        "source/s_normSubnormalF16Sig.c",
        "source/s_roundPackToF16.c",
        "source/s_normRoundPackToF16.c",
        "source/s_addMagsF16.c",
        "source/s_subMagsF16.c",
        "source/s_mulAddF16.c",
        "source/s_normSubnormalF32Sig.c",
        "source/s_roundPackToF32.c",
        "source/s_normRoundPackToF32.c",
        "source/s_addMagsF32.c",
        "source/s_subMagsF32.c",
        "source/s_mulAddF32.c",
        "source/s_normSubnormalF64Sig.c",
        "source/s_roundPackToF64.c",
        "source/s_normRoundPackToF64.c",
        "source/s_addMagsF64.c",
        "source/s_subMagsF64.c",
        "source/s_mulAddF64.c",
        "source/s_normSubnormalExtF80Sig.c",
        "source/s_roundPackToExtF80.c",
        "source/s_normRoundPackToExtF80.c",
        "source/s_addMagsExtF80.c",
        "source/s_subMagsExtF80.c",
        "source/s_normSubnormalF128Sig.c",
        "source/s_roundPackToF128.c",
        "source/s_normRoundPackToF128.c",
        "source/s_addMagsF128.c",
        "source/s_subMagsF128.c",
        "source/s_mulAddF128.c",
        "source/softfloat_state.c",
        "source/ui32_to_f16.c",
        "source/ui32_to_f32.c",
        "source/ui32_to_f64.c",
        "source/ui32_to_extF80.c",
        "source/ui32_to_extF80M.c",
        "source/ui32_to_f128.c",
        "source/ui32_to_f128M.c",
        "source/ui64_to_f16.c",
        "source/ui64_to_f32.c",
        "source/ui64_to_f64.c",
        "source/ui64_to_extF80.c",
        "source/ui64_to_extF80M.c",
        "source/ui64_to_f128.c",
        "source/ui64_to_f128M.c",
        "source/i32_to_f16.c",
        "source/i32_to_f32.c",
        "source/i32_to_f64.c",
        "source/i32_to_extF80.c",
        "source/i32_to_extF80M.c",
        "source/i32_to_f128.c",
        "source/i32_to_f128M.c",
        "source/i64_to_f16.c",
        "source/i64_to_f32.c",
        "source/i64_to_f64.c",
        "source/i64_to_extF80.c",
        "source/i64_to_extF80M.c",
        "source/i64_to_f128.c",
        "source/i64_to_f128M.c",
        "source/f16_to_ui32.c",
        "source/f16_to_ui64.c",
        "source/f16_to_i32.c",
        "source/f16_to_i64.c",
        "source/f16_to_ui32_r_minMag.c",
        "source/f16_to_ui64_r_minMag.c",
        "source/f16_to_i32_r_minMag.c",
        "source/f16_to_i64_r_minMag.c",
        "source/f16_to_f32.c",
        "source/f16_to_f64.c",
        "source/f16_to_extF80.c",
        "source/f16_to_extF80M.c",
        "source/f16_to_f128.c",
        "source/f16_to_f128M.c",
        "source/f16_roundToInt.c",
        "source/f16_add.c",
        "source/f16_sub.c",
        "source/f16_mul.c",
        "source/f16_mulAdd.c",
        "source/f16_div.c",
        "source/f16_rem.c",
        "source/f16_sqrt.c",
        "source/f16_eq.c",
        "source/f16_le.c",
        "source/f16_lt.c",
        "source/f16_eq_signaling.c",
        "source/f16_le_quiet.c",
        "source/f16_lt_quiet.c",
        "source/f16_isSignalingNaN.c",
        "source/f32_to_ui32.c",
        "source/f32_to_ui64.c",
        "source/f32_to_i32.c",
        "source/f32_to_i64.c",
        "source/f32_to_ui32_r_minMag.c",
        "source/f32_to_ui64_r_minMag.c",
        "source/f32_to_i32_r_minMag.c",
        "source/f32_to_i64_r_minMag.c",
        "source/f32_to_f16.c",
        "source/f32_to_f64.c",
        "source/f32_to_extF80.c",
        "source/f32_to_extF80M.c",
        "source/f32_to_f128.c",
        "source/f32_to_f128M.c",
        "source/f32_roundToInt.c",
        "source/f32_add.c",
        "source/f32_sub.c",
        "source/f32_mul.c",
        "source/f32_mulAdd.c",
        "source/f32_div.c",
        "source/f32_rem.c",
        "source/f32_sqrt.c",
        "source/f32_eq.c",
        "source/f32_le.c",
        "source/f32_lt.c",
        "source/f32_eq_signaling.c",
        "source/f32_le_quiet.c",
        "source/f32_lt_quiet.c",
        "source/f32_isSignalingNaN.c",
        "source/f64_to_ui32.c",
        "source/f64_to_ui64.c",
        "source/f64_to_i32.c",
        "source/f64_to_i64.c",
        "source/f64_to_ui32_r_minMag.c",
        "source/f64_to_ui64_r_minMag.c",
        "source/f64_to_i32_r_minMag.c",
        "source/f64_to_i64_r_minMag.c",
        "source/f64_to_f16.c",
        "source/f64_to_f32.c",
        "source/f64_to_extF80.c",
        "source/f64_to_extF80M.c",
        "source/f64_to_f128.c",
        "source/f64_to_f128M.c",
        "source/f64_roundToInt.c",
        "source/f64_add.c",
        "source/f64_sub.c",
        "source/f64_mul.c",
        "source/f64_mulAdd.c",
        "source/f64_div.c",
        "source/f64_rem.c",
        "source/f64_sqrt.c",
        "source/f64_eq.c",
        "source/f64_le.c",
        "source/f64_lt.c",
        "source/f64_eq_signaling.c",
        "source/f64_le_quiet.c",
        "source/f64_lt_quiet.c",
        "source/f64_isSignalingNaN.c",
        "source/extF80_to_ui32.c",
        "source/extF80_to_ui64.c",
        "source/extF80_to_i32.c",
        "source/extF80_to_i64.c",
        "source/extF80_to_ui32_r_minMag.c",
        "source/extF80_to_ui64_r_minMag.c",
        "source/extF80_to_i32_r_minMag.c",
        "source/extF80_to_i64_r_minMag.c",
        "source/extF80_to_f16.c",
        "source/extF80_to_f32.c",
        "source/extF80_to_f64.c",
        "source/extF80_to_f128.c",
        "source/extF80_roundToInt.c",
        "source/extF80_add.c",
        "source/extF80_sub.c",
        "source/extF80_mul.c",
        "source/extF80_div.c",
        "source/extF80_rem.c",
        "source/extF80_sqrt.c",
        "source/extF80_eq.c",
        "source/extF80_le.c",
        "source/extF80_lt.c",
        "source/extF80_eq_signaling.c",
        "source/extF80_le_quiet.c",
        "source/extF80_lt_quiet.c",
        "source/extF80_isSignalingNaN.c",
        "source/extF80M_to_ui32.c",
        "source/extF80M_to_ui64.c",
        "source/extF80M_to_i32.c",
        "source/extF80M_to_i64.c",
        "source/extF80M_to_ui32_r_minMag.c",
        "source/extF80M_to_ui64_r_minMag.c",
        "source/extF80M_to_i32_r_minMag.c",
        "source/extF80M_to_i64_r_minMag.c",
        "source/extF80M_to_f16.c",
        "source/extF80M_to_f32.c",
        "source/extF80M_to_f64.c",
        "source/extF80M_to_f128M.c",
        "source/extF80M_roundToInt.c",
        "source/extF80M_add.c",
        "source/extF80M_sub.c",
        "source/extF80M_mul.c",
        "source/extF80M_div.c",
        "source/extF80M_rem.c",
        "source/extF80M_sqrt.c",
        "source/extF80M_eq.c",
        "source/extF80M_le.c",
        "source/extF80M_lt.c",
        "source/extF80M_eq_signaling.c",
        "source/extF80M_le_quiet.c",
        "source/extF80M_lt_quiet.c",
        "source/f128_to_ui32.c",
        "source/f128_to_ui64.c",
        "source/f128_to_i32.c",
        "source/f128_to_i64.c",
        "source/f128_to_ui32_r_minMag.c",
        "source/f128_to_ui64_r_minMag.c",
        "source/f128_to_i32_r_minMag.c",
        "source/f128_to_i64_r_minMag.c",
        "source/f128_to_f16.c",
        "source/f128_to_f32.c",
        "source/f128_to_extF80.c",
        "source/f128_to_f64.c",
        "source/f128_roundToInt.c",
        "source/f128_add.c",
        "source/f128_sub.c",
        "source/f128_mul.c",
        "source/f128_mulAdd.c",
        "source/f128_div.c",
        "source/f128_rem.c",
        "source/f128_sqrt.c",
        "source/f128_eq.c",
        "source/f128_le.c",
        "source/f128_lt.c",
        "source/f128_eq_signaling.c",
        "source/f128_le_quiet.c",
        "source/f128_lt_quiet.c",
        "source/f128_isSignalingNaN.c",
        "source/f128M_to_ui32.c",
        "source/f128M_to_ui64.c",
        "source/f128M_to_i32.c",
        "source/f128M_to_i64.c",
        "source/f128M_to_ui32_r_minMag.c",
        "source/f128M_to_ui64_r_minMag.c",
        "source/f128M_to_i32_r_minMag.c",
        "source/f128M_to_i64_r_minMag.c",
        "source/f128M_to_f16.c",
        "source/f128M_to_f32.c",
        "source/f128M_to_extF80M.c",
        "source/f128M_to_f64.c",
        "source/f128M_roundToInt.c",
        "source/f128M_add.c",
        "source/f128M_sub.c",
        "source/f128M_mul.c",
        "source/f128M_mulAdd.c",
        "source/f128M_div.c",
        "source/f128M_rem.c",
        "source/f128M_sqrt.c",
        "source/f128M_eq.c",
        "source/f128M_le.c",
        "source/f128M_lt.c",
        "source/f128M_eq_signaling.c",
        "source/f128M_le_quiet.c",
        "source/f128M_lt_quiet.c",
        # See `$(OTHER_HEADERS)` in `build/Linux-x86_64-GCC/Makefile` in the
        # `softfloat` repo.
        "source/include/opts-GCC.h",
        # See `$(OBJS_ALL)` target in `build/Linux-x86_64-GCC/Makefile` in the
        # `softfloat` repo.
        "build/Linux-x86_64-GCC/platform.h",
        "source/include/primitiveTypes.h",
        "source/include/primitives.h",
        # See `$(OBJS_SPECIALIZE) $(OBJS_OTHERS)` target in
        # `build/Linux-x86_64-GCC/Makefile` in the `softfloat` repo.
        "source/include/softfloat_types.h",
        "source/include/internals.h",
        "source/8086-SSE/specialize.h",
    ],
    hdrs = [
        "source/include/softfloat.h",
    ],
    copts = [
        "-Iexternal/softfloat/build/Linux-x86_64-GCC",
        "-Iexternal/softfloat/source/8086-SSE",
        "-Werror-implicit-function-declaration",
        "-O2",
    ],
    # `SOFTFLOAT_FAST_INT64` is used in `softfloat.h` and therefore needs to be
    # passed to dependencies.
    defines = ["SOFTFLOAT_FAST_INT64"],
    includes = ["source/include"],
    local_defines = [
        "SOFTFLOAT_ROUND_ODD",
        "INLINE_LEVEL=5",
        "SOFTFLOAT_FAST_DIV32TO16",
        "SOFTFLOAT_FAST_DIV64TO32",
    ],
    visibility = ["//visibility:private"],
)

cc_library(
    name = "softfloat_macos_arm64",
    srcs = [
        # See `OBJS_PRIMITIVES` in `build/template-FAST_INT64/Makefile` in the
        # `softfloat` repo.
        "source/s_eq128.c",
        "source/s_le128.c",
        "source/s_lt128.c",
        "source/s_shortShiftLeft128.c",
        "source/s_shortShiftRight128.c",
        "source/s_shortShiftRightJam64.c",
        "source/s_shortShiftRightJam64Extra.c",
        "source/s_shortShiftRightJam128.c",
        "source/s_shortShiftRightJam128Extra.c",
        "source/s_shiftRightJam32.c",
        "source/s_shiftRightJam64.c",
        "source/s_shiftRightJam64Extra.c",
        "source/s_shiftRightJam128.c",
        "source/s_shiftRightJam128Extra.c",
        "source/s_shiftRightJam256M.c",
        "source/s_countLeadingZeros8.c",
        "source/s_countLeadingZeros16.c",
        "source/s_countLeadingZeros32.c",
        "source/s_countLeadingZeros64.c",
        "source/s_add128.c",
        "source/s_add256M.c",
        "source/s_sub128.c",
        "source/s_sub256M.c",
        "source/s_mul64ByShifted32To128.c",
        "source/s_mul64To128.c",
        "source/s_mul128By32.c",
        "source/s_mul128To256M.c",
        "source/s_approxRecip_1Ks.c",
        "source/s_approxRecip32_1.c",
        "source/s_approxRecipSqrt_1Ks.c",
        "source/s_approxRecipSqrt32_1.c",
        # See `OBJS_SPECIALIZE` in `build/template-FAST_INT64/Makefile` in the
        # `softfloat` repo.
        "source/8086-SSE/softfloat_raiseFlags.c",
        "source/8086-SSE/s_f16UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF16UI.c",
        "source/8086-SSE/s_propagateNaNF16UI.c",
        "source/8086-SSE/s_f32UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF32UI.c",
        "source/8086-SSE/s_propagateNaNF32UI.c",
        "source/8086-SSE/s_f64UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF64UI.c",
        "source/8086-SSE/s_propagateNaNF64UI.c",
        "source/8086-SSE/extF80M_isSignalingNaN.c",
        "source/8086-SSE/s_extF80UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToExtF80UI.c",
        "source/8086-SSE/s_propagateNaNExtF80UI.c",
        "source/8086-SSE/f128M_isSignalingNaN.c",
        "source/8086-SSE/s_f128UIToCommonNaN.c",
        "source/8086-SSE/s_commonNaNToF128UI.c",
        "source/8086-SSE/s_propagateNaNF128UI.c",
        # See `OBJS_OTHERS` in `build/template-FAST_INT64/Makefile` in the
        # `softfloat` repo.
        "source/s_roundToUI32.c",
        "source/s_roundToUI64.c",
        "source/s_roundToI32.c",
        "source/s_roundToI64.c",
        "source/s_normSubnormalF16Sig.c",
        "source/s_roundPackToF16.c",
        "source/s_normRoundPackToF16.c",
        "source/s_addMagsF16.c",
        "source/s_subMagsF16.c",
        "source/s_mulAddF16.c",
        "source/s_normSubnormalF32Sig.c",
        "source/s_roundPackToF32.c",
        "source/s_normRoundPackToF32.c",
        "source/s_addMagsF32.c",
        "source/s_subMagsF32.c",
        "source/s_mulAddF32.c",
        "source/s_normSubnormalF64Sig.c",
        "source/s_roundPackToF64.c",
        "source/s_normRoundPackToF64.c",
        "source/s_addMagsF64.c",
        "source/s_subMagsF64.c",
        "source/s_mulAddF64.c",
        "source/s_normSubnormalExtF80Sig.c",
        "source/s_roundPackToExtF80.c",
        "source/s_normRoundPackToExtF80.c",
        "source/s_addMagsExtF80.c",
        "source/s_subMagsExtF80.c",
        "source/s_normSubnormalF128Sig.c",
        "source/s_roundPackToF128.c",
        "source/s_normRoundPackToF128.c",
        "source/s_addMagsF128.c",
        "source/s_subMagsF128.c",
        "source/s_mulAddF128.c",
        "source/softfloat_state.c",
        "source/ui32_to_f16.c",
        "source/ui32_to_f32.c",
        "source/ui32_to_f64.c",
        "source/ui32_to_extF80.c",
        "source/ui32_to_extF80M.c",
        "source/ui32_to_f128.c",
        "source/ui32_to_f128M.c",
        "source/ui64_to_f16.c",
        "source/ui64_to_f32.c",
        "source/ui64_to_f64.c",
        "source/ui64_to_extF80.c",
        "source/ui64_to_extF80M.c",
        "source/ui64_to_f128.c",
        "source/ui64_to_f128M.c",
        "source/i32_to_f16.c",
        "source/i32_to_f32.c",
        "source/i32_to_f64.c",
        "source/i32_to_extF80.c",
        "source/i32_to_extF80M.c",
        "source/i32_to_f128.c",
        "source/i32_to_f128M.c",
        "source/i64_to_f16.c",
        "source/i64_to_f32.c",
        "source/i64_to_f64.c",
        "source/i64_to_extF80.c",
        "source/i64_to_extF80M.c",
        "source/i64_to_f128.c",
        "source/i64_to_f128M.c",
        "source/f16_to_ui32.c",
        "source/f16_to_ui64.c",
        "source/f16_to_i32.c",
        "source/f16_to_i64.c",
        "source/f16_to_ui32_r_minMag.c",
        "source/f16_to_ui64_r_minMag.c",
        "source/f16_to_i32_r_minMag.c",
        "source/f16_to_i64_r_minMag.c",
        "source/f16_to_f32.c",
        "source/f16_to_f64.c",
        "source/f16_to_extF80.c",
        "source/f16_to_extF80M.c",
        "source/f16_to_f128.c",
        "source/f16_to_f128M.c",
        "source/f16_roundToInt.c",
        "source/f16_add.c",
        "source/f16_sub.c",
        "source/f16_mul.c",
        "source/f16_mulAdd.c",
        "source/f16_div.c",
        "source/f16_rem.c",
        "source/f16_sqrt.c",
        "source/f16_eq.c",
        "source/f16_le.c",
        "source/f16_lt.c",
        "source/f16_eq_signaling.c",
        "source/f16_le_quiet.c",
        "source/f16_lt_quiet.c",
        "source/f16_isSignalingNaN.c",
        "source/f32_to_ui32.c",
        "source/f32_to_ui64.c",
        "source/f32_to_i32.c",
        "source/f32_to_i64.c",
        "source/f32_to_ui32_r_minMag.c",
        "source/f32_to_ui64_r_minMag.c",
        "source/f32_to_i32_r_minMag.c",
        "source/f32_to_i64_r_minMag.c",
        "source/f32_to_f16.c",
        "source/f32_to_f64.c",
        "source/f32_to_extF80.c",
        "source/f32_to_extF80M.c",
        "source/f32_to_f128.c",
        "source/f32_to_f128M.c",
        "source/f32_roundToInt.c",
        "source/f32_add.c",
        "source/f32_sub.c",
        "source/f32_mul.c",
        "source/f32_mulAdd.c",
        "source/f32_div.c",
        "source/f32_rem.c",
        "source/f32_sqrt.c",
        "source/f32_eq.c",
        "source/f32_le.c",
        "source/f32_lt.c",
        "source/f32_eq_signaling.c",
        "source/f32_le_quiet.c",
        "source/f32_lt_quiet.c",
        "source/f32_isSignalingNaN.c",
        "source/f64_to_ui32.c",
        "source/f64_to_ui64.c",
        "source/f64_to_i32.c",
        "source/f64_to_i64.c",
        "source/f64_to_ui32_r_minMag.c",
        "source/f64_to_ui64_r_minMag.c",
        "source/f64_to_i32_r_minMag.c",
        "source/f64_to_i64_r_minMag.c",
        "source/f64_to_f16.c",
        "source/f64_to_f32.c",
        "source/f64_to_extF80.c",
        "source/f64_to_extF80M.c",
        "source/f64_to_f128.c",
        "source/f64_to_f128M.c",
        "source/f64_roundToInt.c",
        "source/f64_add.c",
        "source/f64_sub.c",
        "source/f64_mul.c",
        "source/f64_mulAdd.c",
        "source/f64_div.c",
        "source/f64_rem.c",
        "source/f64_sqrt.c",
        "source/f64_eq.c",
        "source/f64_le.c",
        "source/f64_lt.c",
        "source/f64_eq_signaling.c",
        "source/f64_le_quiet.c",
        "source/f64_lt_quiet.c",
        "source/f64_isSignalingNaN.c",
        "source/extF80_to_ui32.c",
        "source/extF80_to_ui64.c",
        "source/extF80_to_i32.c",
        "source/extF80_to_i64.c",
        "source/extF80_to_ui32_r_minMag.c",
        "source/extF80_to_ui64_r_minMag.c",
        "source/extF80_to_i32_r_minMag.c",
        "source/extF80_to_i64_r_minMag.c",
        "source/extF80_to_f16.c",
        "source/extF80_to_f32.c",
        "source/extF80_to_f64.c",
        "source/extF80_to_f128.c",
        "source/extF80_roundToInt.c",
        "source/extF80_add.c",
        "source/extF80_sub.c",
        "source/extF80_mul.c",
        "source/extF80_div.c",
        "source/extF80_rem.c",
        "source/extF80_sqrt.c",
        "source/extF80_eq.c",
        "source/extF80_le.c",
        "source/extF80_lt.c",
        "source/extF80_eq_signaling.c",
        "source/extF80_le_quiet.c",
        "source/extF80_lt_quiet.c",
        "source/extF80_isSignalingNaN.c",
        "source/extF80M_to_ui32.c",
        "source/extF80M_to_ui64.c",
        "source/extF80M_to_i32.c",
        "source/extF80M_to_i64.c",
        "source/extF80M_to_ui32_r_minMag.c",
        "source/extF80M_to_ui64_r_minMag.c",
        "source/extF80M_to_i32_r_minMag.c",
        "source/extF80M_to_i64_r_minMag.c",
        "source/extF80M_to_f16.c",
        "source/extF80M_to_f32.c",
        "source/extF80M_to_f64.c",
        "source/extF80M_to_f128M.c",
        "source/extF80M_roundToInt.c",
        "source/extF80M_add.c",
        "source/extF80M_sub.c",
        "source/extF80M_mul.c",
        "source/extF80M_div.c",
        "source/extF80M_rem.c",
        "source/extF80M_sqrt.c",
        "source/extF80M_eq.c",
        "source/extF80M_le.c",
        "source/extF80M_lt.c",
        "source/extF80M_eq_signaling.c",
        "source/extF80M_le_quiet.c",
        "source/extF80M_lt_quiet.c",
        "source/f128_to_ui32.c",
        "source/f128_to_ui64.c",
        "source/f128_to_i32.c",
        "source/f128_to_i64.c",
        "source/f128_to_ui32_r_minMag.c",
        "source/f128_to_ui64_r_minMag.c",
        "source/f128_to_i32_r_minMag.c",
        "source/f128_to_i64_r_minMag.c",
        "source/f128_to_f16.c",
        "source/f128_to_f32.c",
        "source/f128_to_extF80.c",
        "source/f128_to_f64.c",
        "source/f128_roundToInt.c",
        "source/f128_add.c",
        "source/f128_sub.c",
        "source/f128_mul.c",
        "source/f128_mulAdd.c",
        "source/f128_div.c",
        "source/f128_rem.c",
        "source/f128_sqrt.c",
        "source/f128_eq.c",
        "source/f128_le.c",
        "source/f128_lt.c",
        "source/f128_eq_signaling.c",
        "source/f128_le_quiet.c",
        "source/f128_lt_quiet.c",
        "source/f128_isSignalingNaN.c",
        "source/f128M_to_ui32.c",
        "source/f128M_to_ui64.c",
        "source/f128M_to_i32.c",
        "source/f128M_to_i64.c",
        "source/f128M_to_ui32_r_minMag.c",
        "source/f128M_to_ui64_r_minMag.c",
        "source/f128M_to_i32_r_minMag.c",
        "source/f128M_to_i64_r_minMag.c",
        "source/f128M_to_f16.c",
        "source/f128M_to_f32.c",
        "source/f128M_to_extF80M.c",
        "source/f128M_to_f64.c",
        "source/f128M_roundToInt.c",
        "source/f128M_add.c",
        "source/f128M_sub.c",
        "source/f128M_mul.c",
        "source/f128M_mulAdd.c",
        "source/f128M_div.c",
        "source/f128M_rem.c",
        "source/f128M_sqrt.c",
        "source/f128M_eq.c",
        "source/f128M_le.c",
        "source/f128M_lt.c",
        "source/f128M_eq_signaling.c",
        "source/f128M_le_quiet.c",
        "source/f128M_lt_quiet.c",
        # See `$(OTHER_HEADERS)` in `build/template-FAST_INT64/Makefile` in the
        # `softfloat` repo.
        "source/include/opts-GCC.h",
        # See `$(OBJS_ALL)` target in `build/template-FAST_INT64/Makefile` in the
        # `softfloat` repo.
        "build/template-FAST_INT64/platform.h",
        "source/include/primitiveTypes.h",
        "source/include/primitives.h",
        # See `$(OBJS_SPECIALIZE) $(OBJS_OTHERS)` target in
        # `build/template-FAST_INT64/Makefile` in the `softfloat` repo.
        "source/include/softfloat_types.h",
        "source/include/internals.h",
        "source/8086-SSE/specialize.h",
    ],
    hdrs = [
        "source/include/softfloat.h",
    ],
    copts = [
        "-Iexternal/softfloat/build/template-FAST_INT64",
        "-Iexternal/softfloat/source/8086-SSE",
        "-Werror-implicit-function-declaration",
        "-O2",
    ],
    # `SOFTFLOAT_FAST_INT64` is used in `softfloat.h` and therefore needs to be
    # passed to dependencies.
    defines = ["SOFTFLOAT_FAST_INT64"],
    includes = ["source/include"],
    local_defines = [
        "URBIT_RUNTIME_OS_DARWIN",
        "SOFTFLOAT_ROUND_ODD",
        "INLINE_LEVEL=5",
        "SOFTFLOAT_FAST_DIV32TO16",
        "SOFTFLOAT_FAST_DIV64TO32",
    ],
    visibility = ["//visibility:private"],
)