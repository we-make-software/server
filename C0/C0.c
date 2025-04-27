#include "C0.h"
struct C2{
    u8 Opration:5,c16:1,c15:1,c14:1;
    u8 c3[6];
    struct net_device*c4;
    struct list_head c5;
    struct delayed_work c6;
};
static LIST_HEAD(C7);
static DEFINE_MUTEX(C8);
static void(*C17)(struct C2*)=NULL;
static void(*C18)(struct C2*)=NULL;
static void(*C19)(struct C2*c2,struct A13*a13)=NULL;
static void(*C20)(struct C2*c2,struct A13*a13)=NULL;
void C21(void(*c17)(struct C2*),void(*c19)(struct C2*,struct A13*));
void C21(void(*c17)(struct C2*),void(*c19)(struct C2*,struct A13*)){
    C17=c17;
    C19=c19;
}
EXPORT_SYMBOL(C21);
void C22(void(*c18)(struct C2*),void(*c20)(struct C2*,struct A13*));
void C22(void(*c18)(struct C2*),void(*c20)(struct C2*,struct A13*)){
    C18=c18;
    C20=c20;
}
EXPORT_SYMBOL(C22);  
void C23(struct C2*c2){
    schedule_delayed_work(&c2->c6,msecs_to_jiffies(600000));
} 
EXPORT_SYMBOL(C23);
static void C13(struct work_struct*a6){
    struct C2*c9=container_of(a6,struct C2,c6.work);
    if(c9->c14)return;
    mutex_lock(&C8);
    if(c9->c14){
        mutex_unlock(&C8);
        return;
    }
    c9->c14=1;
    list_del(&c9->c5);
    mutex_unlock(&C8);
    if(c9->c15&&C17)
        C17(c9);
    if(c9->c16&&C18)
        C18(c9);
    kfree(c9);
}
static void C12(struct C2*c2,struct A13*a13){
    if(((struct A22*)a13->a16->a18)->a27)
        C19(c2,a13);
    else
        C20(c2,a13);
}
static void C1(struct A13*a13){
    struct C2*c9=NULL,*c10=NULL;
    list_for_each_entry_safe(c9,c10,&C7,c5){
        if(memcmp(c9->some_address_field,a13->a35,6)==0){
            C23(c9);
            C12(c9,a13);
            return;
        }
    }
    mutex_lock(&C8);
    list_for_each_entry_safe(c9,c10,&C7,c5){
        if(memcmp(c9->some_address_field,a13->a35,6)==0){
            mutex_unlock(&C8);
            C23(c9);
            C12(c9,a13);
            return;
        }
    }
    c9=kmalloc(sizeof(struct C2),GFP_KERNEL);
    if(!c9){
        mutex_unlock(&C8);
        return;
    }
    c9->c14=0;
    memcpy(c9->c3,a13->a35,6);
    c9->c4=a13->a15;
    INIT_LIST_HEAD(&c9->c5);
    list_add_tail(&c9->c5,&C7);
    INIT_DELAYED_WORK(&c9->c6,C13);
    C23(c9);
    mutex_unlock(&C8);
    C12(c9,a13);
}
extern void B20(void(*b19)(struct A13*));
static void C11(void){
    struct C2*c9=NULL,*c10;
    list_for_each_entry_safe(c9,c10,&C7,c5){
        if(!c9->c14){
            mutex_lock(&C8);
            if(c9->c14){
                mutex_unlock(&C8);
                continue;
            }
            c9->c14=1;
            list_del(&c9->c5);
            mutex_unlock(&C8);
            cancel_delayed_work_sync(&c9->c6);
            if(c9->c15&&C17)
                C17(c9);
            if(c9->c16&&C18)
                C18(c9);
            kfree(c9);
        }
    }
    C17=NULL;
    C18=NULL;
    C19=NULL;
    C20=NULL;
}
B14(P_C0,{
    C11();
}){
    B20(C1);
}