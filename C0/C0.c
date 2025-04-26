#include "C0.h"
struct C8{
    struct net_device*c9;
    u8 c10[6];
    struct list_head c11;
    struct delayed_work c17;
};
static LIST_HEAD(C12);
static DEFINE_MUTEX(C13);
static void C18(struct work_struct*a17){
    struct C8*c15=container_of(a17,struct C8,c17.work);
    mutex_lock(&C13);
    list_del(&c15->c11);
    kfree(c15);
    mutex_unlock(&C13);
}

extern struct B35*D1(struct C8*,struct A13*);
extern struct B35*E1(struct C8*,struct A13*);
static bool C14(struct A13*a13){
    printk(KERN_INFO "C14\n");
    return true;
}

static void C19(void){
    struct C8*c15,*c16;
    mutex_lock(&C13);
    list_for_each_entry_safe(c15,c16,&C12,c11){
        cancel_delayed_work_sync(&c15->c17);
        list_del(&c15->c11);
        kfree(c15);
    }
    mutex_unlock(&C13);
}
C1(P_C0,{
    C19();
},B20,C7,C14){}