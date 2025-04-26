#include "A0.h"
#include <linux/netdevice.h>
#include <linux/skbuff.h>
#include <linux/ip.h>
#include <linux/ipv6.h>
#include <linux/inetdevice.h>
static void A20(struct A13*a13){
    if(a13->a16){
        struct A16*a22=a13->a16,*a23,*a24;
        if(!list_empty(&a22->a16)){
            list_for_each_entry_safe(a23,a24,&a22->a16,a16){
                list_del(&a23->a16);
                if (a23->a25&&a23->a18)
                    kfree(a23->a18);
                kfree(a23);
            }
        }
        if(a22->a18)
            kfree(a22->a18);
        if(a22)
            kfree(a22);
    }
    if(a13->a14)
        kfree(a13->a14);
    if(a13)   
        kfree(a13);
}

extern void A34(struct work_struct*a31);
static bool A19(struct A13*a13){
    u16 a21=ntohs(*(u16*)(a13->a14+6));
    if(a21!=2048&&a21!=34525){
        A20(a13);
        return true;
    }
    a13->a16=kmalloc(sizeof(struct A16),GFP_KERNEL);
    if(!a13->a16){
        A20(a13);
        return false;
    }
    a13->a16->a25=1;
    INIT_LIST_HEAD(&a13->a16->a16);
    a13->a16->a18=kmalloc(sizeof(struct A22),GFP_KERNEL);
    if(!a13->a16->a18){
        A20(a13);
        return false;
    }
    ((struct A22*)a13->a16->a18)->a27=(a21==2048);
    struct A16*a26=kmalloc(sizeof(struct A16),GFP_KERNEL);
    if(!a26){
        A20(a13);
        return false;
    }   
    a26->a25=1;
    INIT_LIST_HEAD(&a26->a16);
    list_add(&a26->a16,&a13->a16->a16);
    if(!(a26->a18=kmalloc(((struct A22*)a13->a16->a18)->a27?4:16,GFP_KERNEL))){
        a26->a18=NULL;
        A20(a13);
        return false;
    }
    if(((struct A22*)a13->a16->a18)->a27){
        memcpy(a26->a18, a13->a14+24,4);
        u8*a29=(u8*)a26->a18;
        if(a29[0]==0||a29[0]==10||(a29[0]==172&&a29[1]>=16&&a29[1]<=31)||(a29[0]==192&&a29[1]==168)){
            A20(a13);
            return true;
        }
    }else{
        u16*a29=(u16*)a26->a18;
        for(u8 i=0;i<8;i++)
            a29[i]=ntohs(*(u16*)(a13->a14+(32+(i*2)))); 
        if((a29[0]>=65152&&a29[0]<=65215)||(a29[0]>=64512&&a29[0]<=64767)||(a29[0]==0&&a29[7]==1)||(a29[0]==0&&a29[1]==0&&a29[2]==0&&a29[3]==0&&a29[4]==0&&a29[5]==0&&a29[6]==0&&a29[7]==0)){
            A20(a13);
            return true;
        }
    }
    struct A16*a30=kmalloc(sizeof(struct A16),GFP_KERNEL);
    if(!a30){
        A20(a13);
        return false;
    }
    a30->a25=1;
    INIT_LIST_HEAD(&a30->a16);
    list_add_tail(&a30->a16,&a13->a16->a16);
    a30->a18=kmalloc(2,GFP_KERNEL);   
    if(!a30->a18){
        a30->a18=NULL;
        A20(a13);
        return false;
    }
    *(u16*)(a30->a18)=ntohs(*(u16*)(a13->a14+(((struct A22*)a13->a16->a18)->a27?30:50)));
    ((struct A22*)a13->a16->a18)->a28=(*(a13->a14+(((struct A22*)a13->a16->a18)->a27?23:20))==6);
    if(((struct A22*)a13->a16->a18)->a28&&(*(u16*)(a30->a18)==22)){
        A20(a13);
        return true;
    }
    
    INIT_WORK(&a13->a31,A34);
    queue_work(system_wq,&a13->a31);
    return false;
}

static int A9(struct sk_buff*a10,struct net_device*dev,struct packet_type*pt,struct net_device*orig_dev){
    if(a10->len<14||a10->dev->flags&IFF_LOOPBACK)return 0;
    struct A13*a13=kmalloc(sizeof(struct A13),GFP_KERNEL);
    if(!a13){
        kfree_skb(a10);
        return 1;
    }
    u8*a11=skb_mac_header(a10);
    size_t a12=skb_tail_pointer(a10)-a11-6;
    a13->a14=kmalloc(a12,GFP_KERNEL);
    if (!a13->a14) {
        kfree(a13);
        kfree_skb(a10);
        return 1;
    }
    memcpy(a13->a14,a11+6,a12);
    a13->a15=dev; 
    a13->a16=NULL;
    if(A19(a13))
        return 0;
    kfree_skb(a10);
    return 1;
}
static struct packet_type A8;
extern void A32(void(*a20)(struct A13*));
extern void A33(void);
A1(P_A0,{
    A33();
    dev_remove_pack(&A8);
    synchronize_net();
}){
    A32(&A20);
    A8.type=htons(ETH_P_ALL);
    A8.func=A9;
    dev_add_pack(&A8);
}