
obj-m +=kernel_module.o
kernel_module-objs := pow_integers.o sqrt_integers.o vector_lenght.o triangle_perimeter.o triangle_surface.o tringle_height.o module.o
KERNEL_DIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean
