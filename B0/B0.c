#include "B0.h"
static LIST_HEAD(B4);
static LIST_HEAD(B5);
void B10(struct B1**b1,void(*b2)(void))
{
    *b1=kmalloc(sizeof(struct B1),GFP_KERNEL);
    INIT_LIST_HEAD(&(*b1)->b3);
    (*b1)->b2 = b2;
    list_add(&(*b1)->b3, &B4);
}
EXPORT_SYMBOL(B10);
void B11(struct B1*b1,void(*b2)(void)){
    INIT_LIST_HEAD(&b1->b3);
    b1->b2=b2;
    list_add(&b1->b3,&B5);
}
EXPORT_SYMBOL(B11);
void(*A20)(struct A13*);
void A32(void(*a20)(struct A13*));
void A32(void(*a20)(struct A13*)){
    A20=a20;
    struct B1*b6,*b7;
    list_for_each_entry_safe(b6,b7,&B4,b3){
        if(b6->b2)
            b6->b2();
        list_del(&b6->b3);
        kfree(b6);
    }
}
EXPORT_SYMBOL(A32);
void A33(void);
void A33(void){
    struct B1*b8,*b9;
    list_for_each_entry_safe(b8,b9,&B5,b3){
        if(b8->b2)
            b8->b2();            
        list_del(&b8->b3);
    }
}
EXPORT_SYMBOL(A33);
static void(*B19)(struct A13*)=NULL;
void B20(void(*b19)(struct A13*));
void B20(void(*b19)(struct A13*)){
    B19=b19;
}
EXPORT_SYMBOL(B20);
void A34(struct work_struct*a31);
void A34(struct work_struct*a31){
    struct A13*a13=container_of(a31,struct A13,a31);
    a13->a35=a13->a16;
    mutex_init(&a13->c22);
    if(B19)
        B19(a13);
    if(A20)
        A20(a13);
}
EXPORT_SYMBOL(A34);
bool B36(struct A13*a13,void*c20,bool a25){
    struct A16*b37=kmalloc(sizeof(struct A16),GFP_KERNEL);
    if(!b37)return false;  
    b37->a25=a25;
    b37->a18=c20;
    INIT_LIST_HEAD(&b37->a16);
    list_add_tail(&b37->a16,&a13->a16->a16);
    return true;
}
EXPORT_SYMBOL(B36);
A1(P_B0,{
    B19=NULL;
}){}