# top level project rules for the qemu-arm-boot project
# add bootloader commands to the shell
#
LOCAL_DIR := $(GET_LOCAL_DIR)

TARGET := qemu-arm
MODULES += \
	app/tests \
	app/shell
 
