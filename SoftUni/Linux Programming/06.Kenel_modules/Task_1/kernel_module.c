#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define IN_METRIC 6

static int __init cube_volume(void)
{
    int side = 11;
    int volume = side * side * side;
    int beforefp, remainderAfterFp;

    int cubicUnit = 1, base = 10;
    int i = IN_METRIC;
    while(i)
    {
        cubicUnit *= base;
        i--;
    }

    beforefp = volume / cubicUnit;
    remainderAfterFp = volume % cubicUnit;

    if (beforefp > 0)
    {
        printk(KERN_ALERT "cube volume = %d.%d m3", beforefp, remainderAfterFp);
    }
    else
    {
        printk(KERN_ALERT "cube volume = 0.%0*d m3", IN_METRIC, volume);
    }

    return 0;
}

static void __exit cleanup(void)
{
	printk(KERN_INFO "All done.\n");
}

module_init(cube_volume);
module_exit(cleanup);
