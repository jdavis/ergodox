FIRMWARE_DIR=firmware
BUILD_DIR=$(FIRMWARE_DIR)/keyboards/ergodox
CURRENT_DIR=$(shell pwd)
KEYMAP=jdavis
KEYMAP_FILE=keymap.c
BUILD=make -C $(BUILD_DIR) $(KEYMAP)

#
# TMK Settings
#

BOOTMAGIC_ENABLE=no
SLEEP_LED_ENABLE=no

default: build

setup:
	mkdir -p $(BUILD_DIR)/keymaps/$(KEYMAP)
	ln -sfn $(CURRENT_DIR)/$(KEYMAP_FILE) $(BUILD_DIR)/keymaps/$(KEYMAP)/$(KEYMAP_FILE)

build: setup
	$(BUILD)

program: setup
	$(BUILD) teensy

install:
	git clone git@github.com:jackhumbert/qmk_firmware.git $(FIRMWARE_DIR)


clean:
	make -C $(BUILD_DIR) clean

.PHONY: setup build program install clean
