#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[9] = {4,7,6,9,1,8,2,3,5};
	int b[9] = {4,7,6,9,1,8,2,3,5};
	int c[9] = {4,7,6,9,1,8,2,3,5};
	nth_element(a,a+2,a+9);
	//将下标为2，也就是第3个数放在正确的位置
	//也就是求的是第3小
	cout <<"第3小是："<< a[2] << endl;
	for(int i = 0; i < 9; i++)
    cout << a[i] << " "; puts("");
}