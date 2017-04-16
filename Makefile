FIRMWARE_DIR=firmware
BUILD_DIR=$(FIRMWARE_DIR)/keyboard/ergodox_ez
CURRENT_DIR=$(shell pwd)
KEYMAP=jdavis
BUILD=make -C $(BUILD_DIR) KEYMAP=$(KEYMAP)

#
# TMK Settings
#

BOOTMAGIC_ENABLE=no
SLEEP_LED_ENABLE=no

default: build

setup:
	ln -sfn $(CURRENT_DIR) $(BUILD_DIR)/keymaps/$(KEYMAP)

build: setup
	$(BUILD)

program: setup
	$(BUILD) teensy

install:
	git clone git@github.com:jackhumbert/qmk_firmware.git $(FIRMWARE_DIR)


clean:
	make -C $(BUILD_DIR) clean

.PHONY: setup build program install clean
