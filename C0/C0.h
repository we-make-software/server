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
        C3 \
        if(C2##I)C2##I(a13);\
    }\
    static void C5(void);\
    extern void B20##C(void(*b19)(struct A13*));\
    B14(A2,A3){\
        B20##C(&C2##M);\
        C5();\
    }\
    static void C5(void)


#endif
