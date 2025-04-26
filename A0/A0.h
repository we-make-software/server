#ifndef A0
#define A0
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/timekeeping.h>
#include <linux/delay.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>


#define A1(A2,A3)\
    static void A5(void);\
    static int __init A6(void){A5();return 0;}\
    static void __exit A7(void){A3;}\
    module_init(A6);\
    module_exit(A7);\
    MODULE_DESCRIPTION(#A2);\
    MODULE_LICENSE("GPL");\
    MODULE_AUTHOR("We-Make-Software.Com");\
    static void A5(void)

struct A22{
    u8 Opration:6,a28:1,a27:1;
};
struct A16{
    u8 Opration:7,a25:1;
    void*a18;
    struct list_head a16;
};
struct A13{
    struct net_device*a15;
    struct A16*a16,*a35;
    u8*a14;
    struct mutex c22;
    struct work_struct a31;
};  
struct A34;

#endif
