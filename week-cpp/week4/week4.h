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
//day3
//归并排序
//归并排序是基于分治法（Divide and Conquer）的一个非常典型的应用。将待排序的元素分裂成两个子序列，
//再将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有
//序表，称为二路归并。归并过程为：把一个数列拆分成两个子序列，利用这两个子序列对元数组进行归并，也就是通过依次比较
//两个子序列中的数，然后依次把较小的数插入到原始数组序列中，过程如merge函数中的三个while循环所示：第一个实现依次循
//环插入较小值，第二个和第三个while循环实现比较完之后的最后一个数的插入。
void merge(int data[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L1 = new int[n1];//拆分出来的L1和L2
	int* L2 = new int[n2];
	for (int i = 0; i < n1; ++i){//对L1赋值
		L1[i] = data[left + i];
	}
	for (int i = 0; i < n2; ++i){//对L1赋值
		L2[i] = data[mid + i + 1];
	}
	int i = 0, j = 0;
	int k = left;
	while (i<n1&&j<n2){//三个while实现归并过程
		if (L1[i]<L2[j]) data[k++] = L1[i++];
		else data[k++] = L2[j++];
	}
	while (i<n1) data[k++] = L1[i++];
	while (j<n2) data[k++] = L2[j++];
	delete[] L1;
	delete[] L2;
}
void mergeSort(int data[], int left, int right){
	if (data == NULL || left >= right) return;
	if (left<right){
		int mid = (left + right) / 2;
		mergeSort(data, left, mid);
		mergeSort(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}
//只出现一次的数
//如何找到这个只出现一次的数呢？最基本的遍历当然OK的，那么除了遍历结合这个题目的特性，又能想到那些其他方法呢？
//举个例子，两个相同的数异或得到的结果是0，不容的数以后得到的结果就不是0，回到题目，除了一个数之外其他的数都是
//成对出现，那么这一对数异或的结果就是0，是不是已经想到了解决问题的方法？是的，就是利用异或，怎么个异或法呢？
//遍历数组，让所有的数都依次异或，最后剩下的数肯定就是这个只出现一次的数。
//出现的一次的数有1个
void findOneNum(int a[], int length,int* num)
{
	if (a == NULL || length<0) return;
	*num = 0;
	for (int i = 0; i < length; ++i)
		*num ^= a[i];
}
//出现一次的数有两个
//有两个出现一次的数，借用刚才第一题的思路，是不是也可以得到一定的启发呢？也利用异或，但是这次有两个异或了，我们
//怎么保证异或得到结果是这两个数呢？显然整个一次异或是不行的，要是我们能够把这个数组分组使得，这两个只出现一次的
//恰好分到两个不同的group中，那么是不是就可以利用这个抑或得到我们想要的结果了。那先现在的关键就是怎么样才能把数组
//划分成我们想要的样子？
//具体划分：还是利用异或，让数组中的每个数都异或一遍，最后得到一个数，这个数就是两个不同数抑或的结果，根据异或，
//这个书某一位是1，那么就表示这两个数，这个位是不同的，利用这点我们把数组分组，这个时候你肯定会问了：怎么保证把相
//等的数不分到两个不同的组中呢？这样说的，相等的数他们每一位都是相同的，我们利用所有数异或之后的结果的某一位是1的
//这个分组标准，相等的数肯定都是被分到相同的同一个组中的。
bool isBitOne(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}
unsigned int findBitOne(int num)
{
	int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 8 * sizeof(int)))
	{
		num == num >> 1;
		++indexBit;
	}
	return indexBit;
}
pair<int, int> findTwoNum(int a[], int length)
{
	pair<int, int> twoOr;
	if (a == NULL || length<2) return twoOr;
	int numOR = 0;
	for (int i = 0; i < length; ++i)
		numOR ^= a[i];
	unsigned int indexOfOne = findBitOne(numOR);
	twoOr.first = 0; twoOr.second = 0;
	for (int i = 0; i < length; ++i)
	{
		if (isBitOne(a[i], indexOfOne))twoOr.first ^= a[i];
		else twoOr.second ^= a[i];
	}
	return twoOr;
}