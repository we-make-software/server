#include "C0.h"
struct C8{
    struct net_device*c9;
    u8 c10[6];
    struct list_head c11;
};
static LIST_HEAD(C12);
static DEFINE_MUTEX(C13);

static void C15(struct A13*a13){
    u16 a17=GetIncomingU16();
    SetPointerIncoming(2);
    u32 a18=GetIncomingU32();
    struct C8*c15,*a16;
    list_for_each_entry_safe(c15,a16,&C13,c12){
        if(c15->c11==a17&&c15->c10==a18)break;
    }
    printk(KERN_INFO "C0: %s\n",__func__);
}
C1(P_C0,{
  
},B20,C7,C15){
  
}