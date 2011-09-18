LOCAL_DIR := $(GET_LOCAL_DIR)

INCLUDES += \
			-I$(LOCAL_DIR)/include

DEFINES += $(TARGET_XRES)
DEFINES += $(TARGET_YRES)

OBJS += \
	$(LOCAL_DIR)/timer.o \
	$(LOCAL_DIR)/debug.o \
	$(LOCAL_DIR)/smem.o \
	$(LOCAL_DIR)/smem_ptable.o \
	$(LOCAL_DIR)/hsusb.o \
	$(LOCAL_DIR)/jtag_hook.o \
	$(LOCAL_DIR)/jtag.o \
	$(LOCAL_DIR)/nand.o \
	$(LOCAL_DIR)/mmc.o \
	$(LOCAL_DIR)/partition_parser.o

ifeq ($(PLATFORM),msm8x60)
	OBJS += $(LOCAL_DIR)/mipi_dsi.o \
			$(LOCAL_DIR)/i2c_qup.o \
			$(LOCAL_DIR)/uart_dm.o \
			$(LOCAL_DIR)/crypto_eng.o \
			$(LOCAL_DIR)/crypto_hash.o \
			$(LOCAL_DIR)/scm.o \
			$(LOCAL_DIR)/lcdc.o \
			$(LOCAL_DIR)/mddi.o \
			$(LOCAL_DIR)/qgic.o \
			$(LOCAL_DIR)/mdp4.o \
			$(LOCAL_DIR)/certificate.o \
			$(LOCAL_DIR)/image_verify.o
endif

ifeq ($(PLATFORM),apq8064)
	OBJS += $(LOCAL_DIR)/qgic.o \
			$(LOCAL_DIR)/uart_dm.o
endif

ifeq ($(PLATFORM),apq-touchpad)
	OBJS += $(LOCAL_DIR)/qgic.o \
			$(LOCAL_DIR)/uart_dm.o \
			$(LOCAL_DIR)/lcdc.o
endif

ifeq ($(PLATFORM),msm8960)
	OBJS += $(LOCAL_DIR)/mipi_dsi.o \
			$(LOCAL_DIR)/i2c_qup.o \
			$(LOCAL_DIR)/uart_dm.o \
			$(LOCAL_DIR)/qgic.o \
			$(LOCAL_DIR)/mdp4.o \
			$(LOCAL_DIR)/crypto4_eng.o \
			$(LOCAL_DIR)/crypto_hash.o \
			$(LOCAL_DIR)/certificate.o \
			$(LOCAL_DIR)/image_verify.o
endif

ifeq ($(PLATFORM),msm7x27a)
	OBJS += $(LOCAL_DIR)/uart.o \
			$(LOCAL_DIR)/proc_comm.o \
			$(LOCAL_DIR)/lcdc.o \
			$(LOCAL_DIR)/mdp3.o \
			$(LOCAL_DIR)/mipi_dsi.o
endif

ifeq ($(PLATFORM),msm7k)
	OBJS += $(LOCAL_DIR)/uart.o \
			$(LOCAL_DIR)/proc_comm.o \
			$(LOCAL_DIR)/lcdc.o \
			$(LOCAL_DIR)/mddi.o
endif

ifeq ($(PLATFORM),msm7x30)
	OBJS += $(LOCAL_DIR)/crypto_eng.o \
			$(LOCAL_DIR)/crypto_hash.o \
			$(LOCAL_DIR)/uart.o \
			$(LOCAL_DIR)/proc_comm.o \
			$(LOCAL_DIR)/lcdc.o \
			$(LOCAL_DIR)/mddi.o \
			$(LOCAL_DIR)/certificate.o \
			$(LOCAL_DIR)/image_verify.o
endif

ifeq ($(PLATFORM),mdm9x15)
	OBJS += $(LOCAL_DIR)/qgic.o \
			$(LOCAL_DIR)/uart_dm.o
endif
