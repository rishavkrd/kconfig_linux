#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h> 

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Rishav");

MODULE_DESCRIPTION("This is my rdkmem - read from kernel memory - module");

static ulong addr=0;
module_param(addr,ulong,0444);


static int rdkmem_init(void)
{
	unsigned char* pointer = (unsigned char*)addr;
	//ulong value = (ulong) *pointer;
	printk(KERN_INFO "The byte in given address is: %X \n",*pointer);
	//printk(KERN_INFO "The byte in given address is: %X \n",(int) pointer[1]);
	return 0;
}
static void __exit rdkmem_cleanup(void)

{

    printk(KERN_INFO "Cleaning up module.\n");

}
module_init(rdkmem_init);
module_exit(rdkmem_cleanup);