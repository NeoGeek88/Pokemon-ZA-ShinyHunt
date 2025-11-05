#
#             LUFA Library
#     Copyright (C) Dean Camera, 2014.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

# Run "make help" for target help.

MCU          = atmega16u2
ARCH         = AVR8
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = Joystick
SCRIPTS_DIR   = $(wildcard ./Scripts/*.c)
SRC          = $(TARGET).c Descriptors.c $(LUFA_SRC_USB) $(SCRIPTS_DIR)
LUFA_PATH    = ./LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -IConfig/
LD_FLAGS     =

# Default target
all:

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk

# Load scripts based on selection
# Bench loop script
bench_loop: all
bench_loop: CC_FLAGS += -DBENCH_LOOP

# Bench loop script for area 20
bench_loop_area_20: all
bench_loop_area_20: CC_FLAGS += -DBENCH_LOOP_AREA_20

# Script for repeatly teleporting to common wild area
wild_area_common: all
wild_area_common: CC_FLAGS += -DENTER_WILD_AREA_COMMON

# Script for wild area 16 farming
wild_area_16: all
wild_area_16: CC_FLAGS += -DWILD_AREA_16

# Script for restaurant fight farming
restaurant_fight: all
restaurant_fight: CC_FLAGS += -DRESTAURANT_FIGHT