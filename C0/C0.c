#include "C0.h"

C1(P_C0,{
    printk(KERN_INFO"Goodbye from C0\n");
},B20,C7,{
    printk(KERN_INFO "Hello from incoming packet in C0\n");
}){
    printk(KERN_INFO"Hello from C0\n");
}