#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int sht = 0;
module_param(sht, int, 0);
char * firstName="abc";
char * lastName="abc";

module_param(firstName, charp, 0);
module_param(lastName, charp, 0);

static int __init init(void)
{
	printk(KERN_ALERT "%s,%s\n", firstName, lastName);
	return 0;
}

static void __exit cleanup(void)
{
	printk(KERN_INFO "Goodbye cruel world\n");
}

module_init(init);
module_exit(cleanup);
