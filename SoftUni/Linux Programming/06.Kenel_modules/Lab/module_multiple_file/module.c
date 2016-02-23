#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int start_function(void);
void stop_function(void);

static int __init init_function(void)
{
	return start_function();
}

static void __exit cleanup_function(void)
{
	stop_function();
}

module_init(init_function);
module_exit(cleanup_function);
