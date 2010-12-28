#ifdef CONFIG_USB_ANDROID
#include "board-heroc-gadget.h"

static int heroc_gadget_phy_init_seq[] = {0x40, 0x31, 0x1, 0x0D, 0x1, 0x10, -1};

static void heroc_gadget_phy_reset(void)
{
	printk("heroc_gadget_phy_reset\n");
	gpio_set_value(HEROC_GPIO_USB_PHY_RST_N, 0);
	mdelay(10);
	gpio_set_value(HEROC_GPIO_USB_PHY_RST_N, 1);
	mdelay(10);
}

static struct msm_hsusb_platform_data msm_hsusb_pdata = {
	.phy_init_seq		= heroc_gadget_phy_init_seq,
	.phy_reset		= heroc_gadget_phy_reset,
	 //.usb_id_pin_gpio =  BUZZ_GPIO_USB_ID_PIN,
};

static struct usb_mass_storage_platform_data mass_storage_pdata = {
	.nluns		= 1,
	.vendor		= "HTC",
	.product	= "Android Phone",
	.release	= 0x0100,
};

static struct platform_device usb_mass_storage_device = {
	.name	= "usb_mass_storage",
	.id	= -1,
	.dev	= {
		.platform_data = &mass_storage_pdata,
	},
};

static struct android_usb_platform_data android_usb_pdata = {
	.vendor_id	= 0x0bb4,
	.product_id	= 0x0c8b,
	.version	= 0x0100,
	.product_name		= "Android Phone",
	.manufacturer_name	= "HTC",
	.num_products = ARRAY_SIZE(usb_products),
	.products = usb_products,
	.num_functions = ARRAY_SIZE(usb_functions_all),
	.functions = usb_functions_all,
};

static struct platform_device android_usb_device = {
	.name	= "android_usb",
	.id		= -1,
	.dev		= {
		.platform_data = &android_usb_pdata,
	},
};

static void heroc_add_gadget_usb_devices(void)
{
	android_usb_pdata.products[0].product_id =
		android_usb_pdata.product_id;
	android_usb_pdata.serial_number = board_serialno();
	msm_hsusb_pdata.serial_number = board_serialno();
	msm_device_hsusb.dev.platform_data = &msm_hsusb_pdata;
	platform_device_register(&msm_device_hsusb);
	platform_device_register(&usb_mass_storage_device);
	platform_device_register(&android_usb_device);
}
#endif
