#include"mytitle.h"

//day1 快速排序
//快速排序是对冒泡排序的一种改进。通过一趟排序将要排序的数据分割成独立的两部分，
//其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分
//数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
int partationCount = 0;
int partation(int* data, int low,int high)
{
	//随机划分

	cout << ++partationCount << endl;
	if (data == NULL || low>high)
		return -1;
	srand(unsigned(time(0)));
	int index = low + rand() % (high - low + 1);//随机初始化划分项位置
	int indexData = data[index];//划分标准项
	swap(data[index], data[high]);//把划分标志项放到最后一个数上存着，
	//同时与最后一项进行交换
	int small = low - 1;//划分位置标识，初始值为low的前一个，
	for (int i = low; i < high; ++i){//在给定的low和high区间内进行划分操作
		if (data[i]<indexData){//当区间内的值小于确定的划分值时，
			small++;//递增small，small的作用是确定循环后与high交换的那个值的位置
			if (small != i){//循环时遇到到small和i相同就不交换，说明i的值比index值小
				swap(data[i], data[small]);
			}
		}
	}
	small++;
	swap(data[small], data[high]);//交换smll位置的值和存在high的值
	return small;//返回index值所在的位置
}
void quickSort(int data[], int low, int high)
{
	if (low >= high || data == NULL)
	{
		return;
	}
	int index = partation(data, low, high);//得到第一遍大致有序排序
	if (index > low)
		quickSort(data, low, index - 1);//递归对左半边序列换分排序
	if (index <high)
		quickSort(data, index + 1, high);//递归对右半边序列换分排序
}
//数组中次数超过一半的数；
//这个方法利用基于划分的思想，试想，如果这个数组是一个有序的，那么要是一个数在数组中出现的次数超过数组长度的一半
//那么这个数组的中间位置，肯定是这个出现次数超过数组长度一般的数，基于此，我们利用快速排序划分的思想，只要我们找
//到以中间middle为划分标准的那数我们就找到了，在数组中出现次数超过数组长度一般的这个数。当然，找到这个数了我们还
//要检查一下这个数是不是我们真的有数组长度的一半，如不是就返回0.
int moreHalfNum(int* number,int length)
{ //返回0，表示没有出现超过一半的数或输入错误。
	if (number == NULL || length <= 0) return 0;
	int middle = length >> 1;

	int begin = 0;
	int end = length - 1;
	int index = partation(number, begin, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = partation(number, begin, end);
		}
		else
		{
			begin = index + 1;
			index = partation(number, begin, end);
		}
	}
	int result = number[middle];

	/**********
	如下一段代码时为了检测得到这个数是不是出现超过一半的检查
	****************/
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (number[i] == result)
		{
			count++;
		}
	}
	if (count * 2 <= length) return 0;
	return result;
}
//根据数组本身的特性得到方法
//遍历数组的时候保存两个数，一个是数组中的数，一个词次数
//如果出现的次数和之前出现的次数相同，则次数+1，否则-1，如果次数为0，则保存下一个数，并把次数设为1。
int moreHalfNum1(int* number, int length)
{
	if (number == NULL || length <= 0) return 0;
	int result = number[0];
	int count = 1;
	for (int i = 0; i < length; ++i)
	{
		if (count == 0)
		{
			result = number[i];
			count = 1;
		}
		else if (number[i] == result) count++;
		else count--;
	}
	/**********
	如下一段代码时为了检测得到这个数是不是出现超过一半的检查
	****************/
	int countNum = 0;
	for (int i = 0; i < length; ++i)
	{
		if (number[i] == result)
		{
			countNum++;
		}
	}
	if (countNum * 2 <= length) return 0;
	return result;
}
//day2 
//最小的K个数。类比day1中的出现次数超过一半的数，可以得到一定的启发，同样利用基于划分的思想
//如果基于数组的第K个数来调整，使得这个数小的数都位于数组的前边，比它大的位于它后面，调整之后位于数组左边的k个数就是要找的K个最小的数。
//int *p=new int[k];
vector<int> lastK_Num(int input[], int length, int k)
{
	vector<int> result;
	if (input == NULL || k <= 0 || k>length || length <= 0)return result;
	int begin = 0;
	int end = length - 1;
	int index = partation(input, begin, end);

	while (index != k - 1)//注意扯个地方，为什么不用k和k-1都可以，
	{
		if (index > k-1)
		{
			end = index - 1;
			index = partation(input, begin, end);
		}
		else
		{
			begin = index + 1;
			index = partation(input, begin, end);
		}
	}
	for (int i = 0; i < k; ++i)
		result.push_back(input[i]);
	return result;
}
//当然处理这个利用划分的思想来解决，还以利用堆来帮助我们解决
//针对这个问题我们建立一个可以容纳k个数的最大堆，遍历整个数组，用当前数和堆中的最大的数比较，如果堆中最大数小，则用这个数替换掉
//堆中的最大数，否则继续遍历，由于替换掉最大堆的最大的数之后，最大堆内部会进行调整重建最大堆，所以我们不用担心调整的问题，基于
//这样的思路就有了如下的实现。
//关于最大堆的实现，这里不多说，只利用STL里面的set/multiset来帮助建堆，他们在set这个头文件中。
//greater<typename>在头文件<functional>
multiset<int, greater<int>>lastK_Num1(const vector<int>& input,int k)
{
	multiset<int, greater<int>> result;
	result.clear();
	if (k <1 || (input.size()) <k) return result;
	vector<int>::const_iterator iter = input.begin();
	while (iter != input.end())
	{
		if ((result.size()) < k) result.insert(*iter);
		else
		{
			multiset<int, greater<int>>::iterator iterTemp = result.begin();
			if (*iter < *(result.begin()))
			{
				result.erase(iterTemp);
				result.insert(*iter);
			}
		}
		++iter;
	}
	return result;
}
//统计排序数组中数字出现的次数
//这个问题最直观的就是直接遍历
int findNum(int a[],int length, int k)
{
	int count = 0;
	if (a == NULL) return count;
	for (int i=0; i < length; ++i)
	{
		if (a[i] == k)count++;
	}
	return count;
}
//思考这样一个问题，如何在一个排序数组中快速的找到一个数。
//二分查找
int binarySearch(int a[], int length,int k)
{
	if (a == NULL) return -1;
	int low = 0;
	int high = length - 1;
	
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (a[middle] == k) return middle;
		else if (a[middle] > k) high = middle - 1;
		else if (a[middle < k]) low = middle + 1;
	}
	return -1;
}
//利用这种二分查找的思想去找给定数在排列数组中的出现的次数
//分别找到第一个K和最后一个K，就找到K在数组中出现了次数了；
int getFirstK(int a[], int length, int k)
{
	if (a == NULL) return -1;
	int low = 0;
	int high = length - 1;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (a[middle] == k)
		{
			if ((middle > 0 && a[middle - 1] != k) || middle == 0)
			{
				return middle;
			}
			else
				high = middle - 1;
		}
		else if (a[middle] > k) high = middle - 1;
		else if (a[middle < k]) low = middle + 1;
	}
	return -1;
}
int getLastK(int a[], int length, int k)
{
	if (a == NULL) return -1;
	int low = 0;
	int high = length - 1;
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (a[middle] == k)
		{
			if ((middle > 0 && a[middle + 1] != k) || middle == 0)
			{
				return middle;
			}
			else
				low = middle - 1;
		}
		else if (a[middle] > k) high = middle - 1;
		else if (a[middle < k]) low = middle + 1;
	}
	return -1;
}
int getNumberOfK(int a[], int length, int k)
{
	int count = 0;
	if (a != NULL&&length>0)
	{
		int first = getFirstK(a, length,k);
		int last = getLastK(a, length, k);
		if (first > -1 && last > -1)
			count = last - first + 1;
	}
	return count;
}