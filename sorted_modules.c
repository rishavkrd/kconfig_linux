#include <linux/module.h>
#include <linux/init.h>

void __init sorted_modules(void)
{
	struct module *mod;
	char buf[8];

	printk(KERN_WARN "Test: Modules not so sorted yet:");
	/* Most callers should already have preempt disabled, but make sure */
	preempt_disable();
	list_for_each_entry_rcu(mod, &modules, list) {
		if (mod->state == MODULE_STATE_UNFORMED)
			continue;
		pr_cont(" %s%s", mod->name, module_flags(mod, buf));
	}
	preempt_enable();
	if (last_unloaded_module[0])
		pr_cont(" [last unloaded: %s]", last_unloaded_module);
	pr_cont("\n");
}
device_initcall(sorted_modules);