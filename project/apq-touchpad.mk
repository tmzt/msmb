# top level project rules for the apq8064 project
#
LOCAL_DIR := $(GET_LOCAL_DIR)

TARGET := apq-touchpad

MODULES += app/aboot

DEBUG := 1

#DEFINES += WITH_DEBUG_DCC=1
#DEFINES += WITH_DEBUG_UART=1
DEFINES += WITH_DEBUG_FBCON=1
DEFINES += WITH_LIB_BIO=1
