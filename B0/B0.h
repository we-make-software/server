#include "../A0/A0.h"
#ifndef B0
#define B0

struct B1{
    void(*b2)(void);
    struct list_head b3;
};

extern void B10(struct B1**b1,void(*b2)(void));
extern void B11(struct B1*b1,void(*b2)(void));

#define B14(A2,A3)\
    static struct B1*B15,B16;\
    static void B18(void);\
    static void B17(void){\
        A3 \
    }\
    A1(A2,{}){\
        B10(&B15,B18);\
        B11(&B16,B17);\
    }\
    static void B18(void)



#endif