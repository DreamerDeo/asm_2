#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;


void swap(int *m, int *n) {//����swap����������Ϊint��ָ��m��n
	int tem;
	tem = *m;
	*m = *n;
	*n = tem;
}

int main() {//����������ֵ����Ϊ����
	int x = 1, y = 2;
	cout << "Before swap" <<endl<< "x=" << x << ",y=" << y << endl;//���x��y��ֵ
	swap(&x, &y);//����swap����
	cout << "After swap" << endl << "x=" << x << ",y=" << y << endl;
	if (x > y)
		cout << 'x';
	else
		cout << 'y';
	getchar();
	return 0;
}