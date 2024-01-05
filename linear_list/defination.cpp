// // typedef声明结构体时，声明实例不需要添加struct关键字；struct声明结构体，声明实例需要增加关键字struct；
// // 可以结合使用，一般不这么用，我比较喜欢用typedef，没必要给代码增加冗余。
// #include<stdio.h>
// #include<stdlib.h>
// struct  data
// {
//     char name[8];
//     int age;
//     char sex[2];
//     float score;
// };
// typedef struct data Elemtype;
// typedef struct  data
// {
//     char name[8];
//     int age;
//     char sex[2];
//     float score;
    
// }Elemtype;
// typedef struct 
// {
//     char name[8];
//     int age;
//     char sex[2];
//     float score;
// }Elemtype;

// // typedef struct{
// //     Elemtype data[30];
// //     int length;
// //     int listsize;
// // }SqList;
// typedef struct 
// {
//     Elemtype *elem;
//     int length;
//     int listsize;
// }SqList;
// SqList L;
// L.elem=(Elemtype*)malloc(30*sizeof(Elemtype));

// #define LIST_INIT_SIZE 80
// #define LISTINCREMENT 10
// // 这里的Status是一个结构或变量类型。STATUS是返回的状态,程序中的error,ok就是和它对应的!
// Status InitList_Sq(SqList &L){
//     L.elem=(Elemtype*)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
//     if(!L.elem)
//     exit(OVERFLOW);
//     L.length=0;
//     L.listsize=LIST_INIT_SIZE;
//     return OK;
// }
// Status DestoryList(SqList &L){
//     free(L.elem)
//     return ok;
// }
// Status PriorElem(SqList L,int cur_e,Elemtype &pre_e){
//     if(cur_e<=0||L.length==0||cur_e>L.length)
//         return error;
//     else
//         pre_e=L.elem[cur_e-1]
// }
// // Status ListInsert_Sq(SqList &L,int i,Elemtype e){
// //     for (j=L.length-1;j>=i-1;--j)
// //         L.elem[j+1]=L.elem[j];
// //     L.elem[i-1]=e;
// //     ++L.length;
// //     return OK;
// // }
// Status ListInsert_Sq(SqList &L,int i,Elemtype e){
//     if(i<1||i>L.length+1)return ERROR;
//     if(L.length>=L.listsize){
//         newbase=(Elemtype*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(Elemtype));
//     }
//     if(!newbase) exit(OVERFLOW);
//     L.elem=newbase;
//     L.listsize+=LISTINCREMENT;
//     q=&(L.elem[i-1]);
//     for (p  = &(L.elem[L.length-1]); p >=q; --p)
//     {
//         *(p+1)=*p;
//         *q=e;
//         ++L.length;
//     }
//     return OK;
// }
// Status ListDelete_Sq(SqList &L,int i,Elemtype &e){
//     if(i<1||i>L.length) return ERROR;
//     p=&(L.elem[i-1]);
//     e=*p;
//     q=L.elem+L.length-1;
//     for(++p;p<=q;++p) *(p-1)=*p;
//     --L.length;
//     return OK;
// }