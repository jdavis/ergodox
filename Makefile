FIRMWARE_DIR=firmware
BUILD_DIR=$(FIRMWARE_DIR)/keyboard/ergodox_ez
CURRENT_DIR=$(shell pwd)
KEYMAP=jdavis

build:
	ln -fs $(CURRENT_DIR) $(BUILD_DIR)/keymaps/$(KEYMAP)
	make -C $(BUILD_DIR) KEYMAP=$(KEYMAP)

program:
	make -C $(BUILD_DIR) teensy

install:
	git clone git@github.com:jackhumbert/qmk_firmware.git $(FIRMWARE_DIR)


clean:
	make -C $(BUILD_DIR) clean
