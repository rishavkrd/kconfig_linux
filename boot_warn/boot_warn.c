#include<linux/module.h>
#include<linux/kernel.h>

#define BOOT_WARNING CONFIG_BOOT_WARNING

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rishav Dokania");
MODULE_DESCRIPTION("To print at kernel warning");
MODULE_VERSION("0.1");

static int __init boot_warn_init(void)
{
	string s = $(BOOT_WARNING);
	if(s!=""){
	        printk(KERN_WARNING "%s \n",s);
	}
        return 0;
}

static void __exit boot_warn_exit(void)
{
        printk(KERN_WARNING "Exiting the boot_warn module from kernel !!!\n");
}

module_init(boot_warn_init);
module_exit(boot_warn_exit);