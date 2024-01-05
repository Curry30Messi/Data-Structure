#include<bits/stdc++.h>
using namespace std;
#define M 8
#define N 8 
typedef struct {
    int i;
    int j;
    int di;
}Box;
typedef struct{
    Box data[10000];
    int top;
}StType;
int mg[M+2][N+2]={
        {1,1,1,1,1,1,1,1,1,1},
    	{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,0,1,1,0,0,1},
		{1,0,1,1,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,1,0,0,0,1,0,0,1},
		{1,0,1,1,1,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};
void InitStack(StType *&st){
	st=(StType *)malloc(sizeof(StType));
	st->top=-1;
}
void GetTop(StType *&st,Box &e){
	e=st->data[st->top];
}
void Push(StType *&st,Box &e){
	st->top++;
	st->data[st->top]=e;

}
void Pop(StType *& st,Box &e){
	e=st->data[st->top];
	st->top--;
}
void DestoryStack(StType *&st){
	free(st);
}
bool StackEmpty(StType *&st){
	if(st->top==-1)
		return true;
	return false;
}
bool mgpath(int xi,int yi,int xe,int ye){
	Box path[10000],e;
	StType *st;
	int i,j,di; //i，j，di用于记录栈顶元素
	int in,jn; //记录下一方位的方块的行列坐标
	int k;
	int find;
	InitStack(st);
	e.i=xi;
	e.j=yi;
	e.di=-1;
	Push(st,e);
	mg[xi][yi]=-1;
	while (!StackEmpty(st))
	{
		GetTop(st,e);
		i=e.i,j=e.j,di=e.di;
		if(i==xe&&j==ye){
			printf("一条迷宫路径如下:\n");
			k=0;
			while (!StackEmpty(st))
			{
				Pop(st,e);
				path[k++]=e;
			}
			while (k>=1)
			{
				k--;
				printf("\t(%d,%d)",path[k].i,path[k].j);
				if((k+2)%5==0)
				printf("\n");
			}
				printf("\n");
				DestoryStack(st);
				return true;
		}
		find=0;
		while(di<4 && find ==0){
			di++;
			switch (di)
			{
			case 0:
				in=i-1,in=j;break;
			case 1:
				in =i;jn=j+1;break;	
			case 2:
				in =i+1;jn=j;break;
			case 3:
				in =i;jn=j-1;break;
			}
			if(mg[in][jn==0])
				find=1;
		}
		if(find){
			st->data[st->top].di=di;
			e.i=in,
			e.j=jn;
			e.di=-1;
			Push(st,e);
			mg[in][jn]=-1;
		}
		else{
			Pop(st,e);
			mg[e.i][e.j]=0;
		}

	}
	DestoryStack(st);
	return false;
}

int main(){
	if(!mgpath(1,1,M,N))
	printf("该迷宫问题没有解");
	return 0;
}










