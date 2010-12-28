
#ifndef __ARCH_ARM_MACH_MSM_BOARD_HEROC_GADGET_H
#define __ARCH_ARM_MACH_MSM_BOARD_HEROC_GADGET_H
#ifdef CONFIG_USB_ANDROID
#include <mach/htc_usb.h>

#define HSUSB_API_INIT_PHY_PROC  2
#define HSUSB_API_PROG    0x30000064
#define HSUSB_API_VERS MSM_RPC_VERS(1, 1)

static struct msm_hsusb_platform_data msm_hsusb_pdata;
static struct usb_mass_storage_platform_data mass_storage_pdata;
static struct platform_device usb_mass_storage_device;
static struct android_usb_platform_data android_usb_pdata;
static struct platform_device android_usb_device;
static void heroc_add_gadget_usb_devices(void);

#endif
#endif
