#include <linux/kernel.h>
#include <linux/module.h>

void stop_function(void)
{
        printk(KERN_INFO "Hello from other side\n");
}
