#include "B0.h"
//b19
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
static void(*B19I)(struct A13*)=NULL;
void B20C(void(*b19)(struct A13*));
void B20C(void(*b19)(struct A13*)){
    B19I=b19;
}
EXPORT_SYMBOL(B20C);
void A34(struct work_struct*a31);
void A34(struct work_struct*a31){
    struct A13*a13=container_of(a31,struct A13,a31);
    a13->a35=a13->a31;
    if(B19I)
        B19I(a13);
    if(A20)
        A20(a13);
}
EXPORT_SYMBOL(A34);
A1(P_B0,{}){}