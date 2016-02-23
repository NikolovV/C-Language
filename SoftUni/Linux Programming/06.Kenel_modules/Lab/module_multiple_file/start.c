#include <linux/kernel.h>
#include <linux/module.h>

int start_function(void)
{
	printk(KERN_INFO "Hello\n");
	return 0;
}
