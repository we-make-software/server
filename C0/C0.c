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
    struct A13*a13=NULL;
    mutex_lock(&C13);
    list_del(&c15->c11);
    kfree(c15);
    mutex_unlock(&C13);
}
static void C14(struct A13*a13){
    struct C8*c15=NULL,*c16=NULL;
    list_for_each_entry_safe(c15,c16,&C13,c12){
        if(memcmp(c15->c10,a13->a35,6)==0)
        break;
    }
    if(!c15){
        mutex_lock(&C13);
        list_for_each_entry_safe(c15,c16,&C13,c12){
            if(memcmp(c15->c10,a13->a35,6)==0){
                mutex_unlock(&C13);
                break;
            }
        }
        if(!c15){
            c15=kmalloc(sizeof(struct C8),GFP_KERNEL);
            if(!c15)return;
            memcpy(c15->c10,a13->a35,6);
            c15->c9=a13->a15;
            INIT_DELAYED_WORK(&c15->c17,C18);
            INIT_LIST_HEAD(&c15->c11);
            list_add(&c15->c11,&C12);
            mutex_unlock(&C13);
        }
    }
    schedule_delayed_work(&c15->c17, msecs_to_jiffies(600000));
}
C1(P_C0,{
  
},B20,C7,C14){
  
}