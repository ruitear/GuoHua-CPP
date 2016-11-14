#include"mytitle.h"

//day1 ����һ��N*N��ʾ�ĵ�ͨ��ͼ������ÿ�����ش�СΪ4�Լ���дһ����������ͼ����ת90�ȣ�
//�����ö�����ڴ�ռ䣿
//��򵥵��������������ת��Ҳ����һ��һ��Ľ��У����磺���ϱ��Ƶ��ұߡ��ұ��Ƶ��±ߡ��±�
//�Ƶ���ߡ�����Ƶ��ϱ�
//α���룺
//for 1:n 
//  temp=top[i];top[i]=left[i];left[i]=bottom[i];bottom[i]=right[i];right[i]=temp;
//end
void rotateImage(int** image, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int first = i;
		int last = n - 1 - i;
		int offset = i - first;
		for (int j = first; j < last;++j)
		{
			int temp = image[first][j];
			image[first][j]=image[last][last-offset];
			image[last][last - offset]=image[j][last];
			image[j][last]=temp;
		}
	}
}
//������
//��10ƿҩ�裬����9ƿװ����1g/����ҩ�裬���µ�һƿװ��1.1g/����ҩ�衣��һ����ϸ����ƽ����ô��
//����һƿ1.1g/����ҩ����ƽֻ����һ�Ρ�
//��һ����ô���컯��Щҩ���أ��ܼ򵥵�һƿȡ1�ţ��ڶ�ƿȡ2�ţ��������ƣ�ֱ��ȡ����10ƿ��10�š�

//day2 �ַ���ѹ��
//�����ַ������ֵĴ�������дһ������ʵ�ֻ������ַ���ѹ�����ܡ������ַ���aabcccccaaa���Ϊa2b1c5a3.
//��ѹ������ַ���û�б�̣��ӷ���ԭ�ȵ��ַ�����