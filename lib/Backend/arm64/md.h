//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
#pragma once

#define MD_GROW_LOCALS_AREA_UP

// Don't encode large user constants, because they won't emit them as 32-bit numbers
// in the instruction stream.
#undef MD_ENCODE_LG_CONSTS
#define MD_ENCODE_LG_CONSTS false

//
// Machine dependent constants.
//
#undef MachPtr
const int MachChar = 1;
const int MachShort = 2;
const int MachInt = 4;
const int MachRegInt = 8;
enum : int { MachPtr = 8 };
const int MachDouble = 8;
const int MachRegDouble = 8;
const int MachArgsSlotOffset = MachPtr;
const int MachStackAlignment = 16; // On ARM64 SP needs to be 16 byte aligned for load/store
const unsigned __int64 MachSignBit = 0x8000000000000000;

const int PAGESIZE = 0x1000;

const IRType TyMachReg = TyInt64;
const IRType TyMachPtr = TyUint64;
const IRType TyMachDouble = TyFloat64;

const DWORD EMIT_BUFFER_ALIGNMENT = 16;
const DWORD INSTR_ALIGNMENT = 2;

#ifdef INSERT_NOPS
const int CountNops = 10;
const int MachMaxInstrSize = (2 * CountNops + 1)*4;
#else
const int MachMaxInstrSize = 4;
#endif

#define SOFTWARE_FIXFOR_HARDWARE_BUGWIN8_502326
