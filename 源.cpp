#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//		创建内存的方式
//  1.创建一个变量							2.创建一个数组
//	 局部变量 - 放在栈区					int a[10]; 局部变量 - 也放在栈区
//   全局变量 - 放在静态区							   全局变量 - 也放在静态区

//		栈区   ：局部变量 + 函数的形式参数（形参）
//      堆区   ：动态内存分配 - malloc + free + calloc + realloc
//		静态区 ：全局变量 + 静态变量 + static int a =10;

//			1. malloc

#include<stdlib.h>
#include<string.h>
int main()
{
	// 动态内存开辟
	// 向内存申请10个整形的空间
	//int* p = (int*)malloc(10 * sizeof(int));
	// malloc应返回void*类型地址，不过这里开辟int空间，所以强制类型转化为int*  (开辟空间>已有空间，返回NULL)
	int* p = (int*)malloc(INT_MAX);
	if (p == NULL)
	{	// 开辟失败
		// 返回错误信息
		printf("%s\n", strerror(errno));
	}
	else
	{
		// 开辟成功 - 正常使用空间
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	//	当动态申请的空间不再使用的时候，应还给操作系统
	free(p); // 主动释放地址p指向的空间	、且必须是动态开辟的 、free空指针不进行任何操作
	// but: 虽然p指向的空间被释放，但是p仍然指向这块空间，有被非法使用的风险
	p = NULL;// 直接把p赋值为空指针

	return  0;
}
