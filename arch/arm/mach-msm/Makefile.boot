  zreladdr-y		:= 0x10008000
params_phys-y		:= 0x10000100
initrd_phys-y		:= 0x10800000

ifeq ($(CONFIG_ARCH_MSM7227),y)
  zreladdr-y              := 0x12C08000
params_phys-y           := 0x12C00100
initrd_phys-y           := 0x13400000
endif

ifeq ($(CONFIG_ARCH_MSM7X00A),y)
  zreladdr-y            := 0x19208000
params_phys-y           := 0x19200100
initrd_phys-y           := 0x19A00000
endif

