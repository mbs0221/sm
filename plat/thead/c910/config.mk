#
# SPDX-License-Identifier: BSD-2-Clause
#

# Compiler flags
platform-cppflags-y =
platform-cflags-y = -I../src
platform-asflags-y =
platform-ldflags-y =

# Blobs to build
FW_TEXT_START?=0x40000000
FW_JUMP=y
FW_JUMP_ADDR?=0x40200000
FW_PAYLOAD=y
ifeq ($(PLATFORM_RISCV_XLEN), 32)
  # This needs to be 4MB aligned for 32-bit system
  FW_PAYLOAD_OFFSET=0x400000
else
  # This needs to be 2MB aligned for 64-bit system
  FW_PAYLOAD_OFFSET=0x200000
endif
FW_PAYLOAD_FDT_ADDR=0x48000000