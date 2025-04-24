#include "D0.h"
/*
d2 
    0 = 8 bit
    1 = 16 bit
    2 = 32 bit
    3 = 64 bit
*/

static struct mutex D7[8];
static struct list_head D8[8];
u8 D9(const u64 x){
    return x<256?BitWidth8:x<65536?BitWidth16:x<4294967296?BitWidth32:BitWidth64;
}
EXPORT_SYMBOL(D9);
bool D10(u64 x){
    return x & 1;
}
EXPORT_SYMBOL(D10);

B14(P_D0,{
    for(u8 i=0;i<8;i++){
        mutex_init(&D7[i]);
        INIT_LIST_HEAD(&D8[i]);
    }
}){
    printk(KERN_INFO"Hello from D0\n");
}