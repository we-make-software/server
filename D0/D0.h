#include "../B0/B0.h"
#ifndef D0
#define D0
struct D1{
    u8 d2:2,d10:1,Unused:5;
    struct mutex d3[9];
    struct list_head d4[10];
    struct D1*d5; 
    u8 d6[];
};
#define BitWidth8 0
#define BitWidth16 1
#define BitWidth32 2
#define BitWidth64 3
extern u8 D9(const u64 x);
#define GetBitWidth(x)D9(x)
extern bool D10(u64 x);
#define IsOdd(x)D10(x)
#define IsEven(x)!(D10(x))
#endif