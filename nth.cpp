#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[9] = {4,7,6,9,1,8,2,3,5};
	int b[9] = {4,7,6,9,1,8,2,3,5};
	int c[9] = {4,7,6,9,1,8,2,3,5};
	nth_element(a,a+2,a+9);
	//���±�Ϊ2��Ҳ���ǵ�3����������ȷ��λ��
	//Ҳ��������ǵ�3С
	cout <<"��3С�ǣ�"<< a[2] << endl;
	for(int i = 0; i < 9; i++)
    cout << a[i] << " "; puts("");
}