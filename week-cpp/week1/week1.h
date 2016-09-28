#include"mytitle.h"
///��һ��_--1�ĸ�������1��N��1�ĸ���//////////////////////////
//day1 1�ĸ���  ֻ������Ϊ���������  ����1
int countNum(int num)
{
	int count = 0;//ע���������1���������������int��Χ��������ܳ��������ͻ�λlong
	while (num)
	{
		count += (num % 10 == 1) ? 1 : 0;
		num = num / 10;
	}
	return count;
}
int countNumofOne(int num)
{
	if (num <= 0)return 0;
	else
	{
		int countofOne = 0;
		for (int i = 1; i <= num; ++i)
			countofOne += countNum(i);
		return countofOne;
	}
}

//1�ĸ��� ����2
int countNumofOne2(int num)
{
	int count = 0;
	int factor = 1;
	int lowerNum = 0; int curNum = 0; int  highNum = 0;

	while (num / factor != 0)
	{
		lowerNum = num - (num / factor)*factor;
		curNum = (num / factor) % 10;
		highNum = num / (factor * 10);

		switch (curNum)
		{
		case 0:
			count += highNum*factor; break;
		case 1:
			count += highNum*factor + lowerNum+1; break;
		default:
			count += (highNum + 1)*factor; break;
		}
		factor *= 10;
	}
	return count;
	
}

///�ڶ���_--����֮ð�ݡ�ѡ���shell����//////////////////////////
//ð������
void bubbleSort(int* arr, int length){
	if (arr == NULL){
		return;
	}
	//ð�����������ǽ��е����ڶ�����
	//���һ�����бȽ�����ѭ���������ڶ�����OK
	for (int i = 0; i<length - 1; ++i){
		for (int j = i + 1; j <length; ++j){
			if (arr[i]>arr[j]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
//��������
void insertSort(int* arr, int length){
	if (arr == NULL)
		return;
	for (int i = 1; i < length; ++i){
		if (arr[i]<arr[i - 1]){//�Ƚϴ�����Ԫ�غ���֮ǰ��һ��Ԫ��
			int temp = arr[i];//������Ԫ��
			int j = i - 1;//֮��������������j����Ϊ����ŵ�forѭ���ڲ�����޷�ͨ������
			for (; j >= 0 && temp<arr[j]; --j){//һ�αȽϲ��������Ԫ����������ֵ
				arr[j + 1] = arr[j];//ѭ�����޵�ʱ��j��С����-1����ʱΪ�ƶ�������
			}
			arr[j + 1] = temp;
		}
	}
}
//ѡ������
void selectSort(int data[], int length){//��ʱ������int* data��int data[]����
	if (data == NULL || length <= 0){
		return;
	}
	for (int i = 0; i < length - 1; ++i){
		int index = i;//��i��n-1֮������С��Ԫ��
		for (int j = i + 1; j < length; ++j){
			if (data[j]<data[index]){
				index = j;//������indexС��Ԫ�ؾͰ�����λ����Ϣ�浽index
			}
		}
		if (index != i){
			swap(data[i], data[index]);//��������ÿ�˵õ�����СԪ���ŵ�index��λ��
		}
	}
}
//shell����
void shellSort(int* arr, int length){
	if (arr == NULL)
		return;
	for (int incrD = length / 2; incrD>0; incrD = incrD / 2){
		for (int i = 0; i < length - incrD; ++i){
			if (arr[i + incrD]<arr[i]){
				int temp = arr[i + incrD];
				arr[i + incrD] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
//�������ݽṹ day3 �������С�ջ
         
//�������� day4
vector<int> StrToInt(string strInt)
{
	int size = strInt.size();
	vector<int> vecInt;
	if (size == 0)
	{
		return vecInt;
	}
	int num = 0;
	for (int i = 0; i <= size; ++i)
	{
		if (i == size || strInt[i] == ',')
		{
			vecInt.push_back(num);
			num = 0;
		}
		else if (strInt[i] >= '0' && strInt[i] <= '9')
		{
			num = num * 10 + strInt[i] - '0';
		}
	}
	sort(vecInt.begin(), vecInt.end());
	int count = vecInt.size();
	int start = 0;
	for (int i = 1; i <= count; ++i)
	{
		if (i == count || vecInt[i] != vecInt[i - 1] + 1)
		{
			for (int j = start + 1; j <= i - 2; ++j)
			{
				vecInt[j] = -1;
			}
			start = i;
		}
	}
	for (vector<int>::iterator Iter = vecInt.begin(); Iter != vecInt.end(); Iter++)
	{
		if (*Iter == -1)
		{
			vecInt.erase(Iter);
			Iter = vecInt.begin();
		}
	}
	return vecInt;
}
//����ת�� day5  10����ת����12����
string pushChar(int  intTemp, string result)
{
	char temp;
	switch (intTemp)
	{
	case 10:
		result.push_back('A');
		break;
	case 11:
		result.push_back('B');
		break;
	default:
		temp = intTemp + '0';
		result.push_back(temp);
	}
	return result;
}
string scaleTenTwElve(int num)
{
	string result;
	if (num <= 11&&num>=0)
	{
		result=pushChar(num, result);
		return result;
	}
	else if (num >= 12)
	{
		int intTemp = 0;
		while (num / 12)
		{
			intTemp = num % 12;
			num = num / 12;
			result = pushChar(intTemp, result);
		}
		result = pushChar(num, result);
		return result;
	}
}


