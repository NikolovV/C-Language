#include "task_2.h"
// Sides and other calculation are approximately (not floating point).

int x1, y1, x2, y2, x3, y3;
module_param(x1, int, 0);
module_param(y1, int, 0);
module_param(x2, int, 0);
module_param(y2, int, 0);
module_param(x3, int, 0);
module_param(y3, int, 0);

int perimeter = 0, surface = 0, height = 0;
int isTriangle = 0;

static int triangle_proc_show(struct seq_file *m, void *v)
{
    if (isTriangle)
    {
        seq_printf(m, "Triangle info.\n");
        seq_printf(m, "Perimeter %d \n", perimeter);
        seq_printf(m, "Surface %d \n", surface);
		seq_printf(m, "Height %d \n", height);
    }
    else
    {
        seq_printf(m, "It is not triangle.\n");
    }
    
    return 0;
}

static int triangle_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, triangle_proc_show, NULL);
}

static const struct file_operations triangle_proc_fops = {
    .owner = THIS_MODULE,
    .open = triangle_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int __init triangle_proc_init(void)
{
    proc_create("triangle", 0, NULL, &triangle_proc_fops);

    int AB, BC, AC;

    AB = abs(vector_lenght(x1, y1, x2, y2));
    BC = abs(vector_lenght(x2, y2, x3, y3));
    AC = abs(vector_lenght(x1, y1, x3, y3));

    if (AB + BC > AC)
    {
        if (AB + AC > BC)
        {
            if (BC + AC > AB)
            {
                isTriangle = 1;
            }
        }
    }
    
    if (isTriangle)
    {
        perimeter = triangle_perimeter(AB, BC, AC);
        surface = triangle_surface(perimeter, AB, BC, AC);
	height = tringle_height(surface, AB);
    }

    return 0;
}

static void __exit triangle_proc_exit(void)
{
    remove_proc_entry("triangle", NULL);
}

MODULE_AUTHOR("Ventcislav Nikolov");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Take cootdinate of three point and calculate, if is triangle, sides, perimeter, surface, height e.t.c.");
module_init(triangle_proc_init);
module_exit(triangle_proc_exit);
