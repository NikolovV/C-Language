#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int sht = 0;
module_param(sht, int, 0);
int myArr[4]={0,1,2,3};
int count = 0;

module_param_array(myArr, int, &count, 0);

static int __init init(void)
{
	printk(KERN_ALERT "The parameter = %d\n", sht);
	int i;
	for(i = 0; i < count; i++)
	{
		printk(KERN_WARNING "myAtrr[%d]=%d\n", i, myArr[i]);
	}
	return 0;
}

static void __exit cleanup(void)
{
	printk(KERN_INFO "Goodbye cruel world\n");
}

module_init(init);
module_exit(cleanup);
