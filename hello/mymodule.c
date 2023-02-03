#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/init.h>


MODULE_LICENSE("GPL");

MODULE_AUTHOR("Rishav Dokania");

MODULE_DESCRIPTION("This is my hello module");


static int __init mymodule_init(void)

{

    printk(KERN_INFO "Hello world!\n");

    return 0;

}


static void __exit mymodule_cleanup(void)

{

    printk(KERN_INFO "Cleaning up module.\n");

}


module_init(mymodule_init);

module_exit(mymodule_cleanup);