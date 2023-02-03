#include <linux/module.h>
#include <linux/init.h>
#include <linux/debugfs.h>
#include <linux/utsname.h>

static int __init boot_warn_init(void)
{
	char s[] = CONFIG_BOOT_WARNING;
	char ver[] = "<version>";
	if(s[0]!='\0'){
		if(strcmp(s,ver)==0) printk(KERN_WARNING "%s \n", utsname()->release);
		else printk(KERN_WARNING  "%s \n",s);
	}
	return 0;
}
late_initcall(boot_warn_init);