#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//		�����ڴ�ķ�ʽ
//  1.����һ������							2.����һ������
//	 �ֲ����� - ����ջ��					int a[10]; �ֲ����� - Ҳ����ջ��
//   ȫ�ֱ��� - ���ھ�̬��							   ȫ�ֱ��� - Ҳ���ھ�̬��

//		ջ��   ���ֲ����� + ��������ʽ�������βΣ�
//      ����   ����̬�ڴ���� - malloc + free + calloc + realloc
//		��̬�� ��ȫ�ֱ��� + ��̬���� + static int a =10;

//			1. malloc

#include<stdlib.h>
#include<string.h>
int main()
{
	// ��̬�ڴ濪��
	// ���ڴ�����10�����εĿռ�
	//int* p = (int*)malloc(10 * sizeof(int));
	// mallocӦ����void*���͵�ַ���������￪��int�ռ䣬����ǿ������ת��Ϊint*  (���ٿռ�>���пռ䣬����NULL)
	int* p = (int*)malloc(INT_MAX);
	if (p == NULL)
	{	// ����ʧ��
		// ���ش�����Ϣ
		printf("%s\n", strerror(errno));
	}
	else
	{
		// ���ٳɹ� - ����ʹ�ÿռ�
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	//	����̬����Ŀռ䲻��ʹ�õ�ʱ��Ӧ��������ϵͳ
	free(p); // �����ͷŵ�ַpָ��Ŀռ�	���ұ����Ƕ�̬���ٵ� ��free��ָ�벻�����κβ���
	// but: ��Ȼpָ��Ŀռ䱻�ͷţ�����p��Ȼָ�����ռ䣬�б��Ƿ�ʹ�õķ���
	p = NULL;// ֱ�Ӱ�p��ֵΪ��ָ��

	return  0;
}
