#include"mytitle.h"
///第一天_--1的个数，从1—N中1的个数//////////////////////////
//day1 1的个数  只考虑数为正数的情况  方法1
int countNum(int num)
{
	int count = 0;//注意这里假设1个个数不超出最大int范围，如果可能超出，类型换位long
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

//1的个数 方法2
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

///第二天_--排序之冒泡、选择和shell排序//////////////////////////
//冒泡排序
void bubbleSort(int* arr, int length){
	if (arr == NULL){
		return;
	}
	//冒泡排序的最后是进行倒数第二个和
	//最后一个进行比较所以循环到倒数第二个就OK
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
//插入排序
void insertSort(int* arr, int length){
	if (arr == NULL)
		return;
	for (int i = 1; i < length; ++i){
		if (arr[i]<arr[i - 1]){//比较待插入元素和它之前的一个元素
			int temp = arr[i];//待插入元素
			int j = i - 1;//之所以在这里声明j是因为如果放到for循环内部后边无法通过编译
			for (; j >= 0 && temp<arr[j]; --j){//一次比较插入区间的元素与待插入得值
				arr[j + 1] = arr[j];//循环借宿的时候j最小减到-1，此时为移动最坏的情况
			}
			arr[j + 1] = temp;
		}
	}
}
//选择排序
void selectSort(int data[], int length){//此时参数是int* data与int data[]无异
	if (data == NULL || length <= 0){
		return;
	}
	for (int i = 0; i < length - 1; ++i){
		int index = i;//在i和n-1之间找最小的元素
		for (int j = i + 1; j < length; ++j){
			if (data[j]<data[index]){
				index = j;//遇到比index小的元素就把它的位置信息存到index
			}
		}
		if (index != i){
			swap(data[i], data[index]);//交换，把每趟得到的最小元祖存放到index的位置
		}
	}
}
//shell排序
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
//基本数据结构 day3 链表、队列、栈
         
//整数排序 day4
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
//进制转换 day5  10进制转换成12进制
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


