#include<stdio.h>
#include<malloc.h>
typedef  struct list {
    int data;
    struct list * next;  //下一个节点地址   
}list;
//第一条链表 
struct list * L=NULL;//头
struct list * head=NULL;//首
struct list * p=NULL;
//第二条链表
struct list * L1=NULL;//头
struct list * head1=NULL;//首
struct list * p1=NULL;
//代理链表
struct list * L2=NULL;//头
struct list * q=NULL;//L2备用地址 
struct list * q1=NULL;//备用地址 
int main(){
    int i=0,length;
    printf("请输入链表的长度\n");
    scanf("%d",&length);
    head=(struct list *)malloc(sizeof(struct  list));
    L=head;
    printf("请依次输入链表的内容\n");
    for(i;i<length;i++){
        p = (struct list *)malloc(sizeof(struct  list));
        scanf("%d",&p->data);
        p->next=NULL;
        head->next=p;
        head=p;
    }
    int i1=0,length1;
    printf("请输入链表的长度\n");
    scanf("%d",&length1);

    head1=(struct list *)malloc(sizeof(struct  list));
    L1=head1;
    printf("请依次输入链表的内容\n");
    for(i1;i1<length1;i1++){
        p1= (struct list *)malloc(sizeof(struct  list));
        scanf("%d",&p1->data);
        p1->next=NULL;
        head1->next=p1;
        head1=p1;
    }
    L2=(struct list *)malloc(sizeof(struct  list));
    q=L2;//备用合并链表起始地址 
    p=L->next;
    p1=L1->next;
    while(p&&p1){
        if(p->data<p1->data){
            L2->next=p;
            L2=p;
            p=p->next;
        }else if(p->data==p1->data){
            L2->next=p;
            L2=p;
            p=p->next;
            q1=p1->next;//备用相同元素的下一个地址指向 
            free(p1);
            p1=q1;

        }else if(p->data>p1->data){
            L2->next=p1;
            L2=p1;
            p1=p1->next;
        }
    }
    L2->next=p?p:p1;
    free(L1);
    printf("合并后链表的内容\n");
    p=q->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }

}
