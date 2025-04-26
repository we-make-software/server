#include "../B0/B0.h"
#include "../D0/D0.h"
#ifndef C0
#define C0

#define C1(A2,A3,B20,C2,C3)\
    static void(*C2##I)(struct A13*)=NULL;\
    void C2##C(void(*c4)(struct A13*)){\
        C2##I=c4;\
    }\
    EXPORT_SYMBOL(C2##C);\
    static void C2##M(struct A13*a13){\
        if(!C3(a13))return;
        if(C2##I)C2##I(a13);\
    }\
    static void C5(void);\
    extern void B20##C(void(*b19)(struct A13*));\
    B14(A2,A3){\
        B20##C(&C2##M);\
        C5();\
    }\
    static void C5(void)

extern bool C19(struct A13*a13,void*c20,bool a25);

#define SetPointerIncoming(x)\
        a13->a35+=x

#define GetIncoming()\
        a13->a35

#define GetIncomingU8()\
    (*(u8*)GetIncoming())

#define GetIncomingU16()\
    (*(u16*)GetIncoming())

#define GetIncomingU32()\
    (*(u32*)GetIncoming())

#define GetIncomingU64()\
    (*(u64*)GetIncoming())
        
#define GetIncomingS8()\
    (*(s8*)GetIncoming())

#define GetIncomingS16()\
    (*(s16*)GetIncoming())

#define GetIncomingS32()\
    (*(s32*)GetIncoming())

#define GetIncomingS64()\
    (*(s64*)GetIncoming())
        

#endif