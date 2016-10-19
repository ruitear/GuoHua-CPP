#include"mytitle.h"

//day1 ��������
//���������Ƕ�ð�������һ�ָĽ���ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�
//����һ���ֵ��������ݶ�������һ���ֵ��������ݶ�ҪС��Ȼ���ٰ��˷�������������
//���ݷֱ���п�����������������̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�
int partationCount = 0;
int partation(int* data, int low,int high)
{
	//�������

	cout << ++partationCount << endl;
	if (data == NULL || low>high)
		return -1;
	srand(unsigned(time(0)));
	int index = low + rand() % (high - low + 1);//�����ʼ��������λ��
	int indexData = data[index];//���ֱ�׼��
	swap(data[index], data[high]);//�ѻ��ֱ�־��ŵ����һ�����ϴ��ţ�
	//ͬʱ�����һ����н���
	int small = low - 1;//����λ�ñ�ʶ����ʼֵΪlow��ǰһ����
	for (int i = low; i < high; ++i){//�ڸ�����low��high�����ڽ��л��ֲ���
		if (data[i]<indexData){//�������ڵ�ֵС��ȷ���Ļ���ֵʱ��
			small++;//����small��small��������ȷ��ѭ������high�������Ǹ�ֵ��λ��
			if (small != i){//ѭ��ʱ������small��i��ͬ�Ͳ�������˵��i��ֵ��indexֵС
				swap(data[i], data[small]);
			}
		}
	}
	small++;
	swap(data[small], data[high]);//����smllλ�õ�ֵ�ʹ���high��ֵ
	return small;//����indexֵ���ڵ�λ��
}
void quickSort(int data[], int low, int high)
{
	if (low >= high || data == NULL)
	{
		return;
	}
	int index = partation(data, low, high);//�õ���һ�������������
	if (index > low)
		quickSort(data, low, index - 1);//�ݹ���������л�������
	if (index <high)
		quickSort(data, index + 1, high);//�ݹ���Ұ�����л�������
}
//�����д�������һ�������
//����������û��ڻ��ֵ�˼�룬���룬������������һ������ģ���ôҪ��һ�����������г��ֵĴ����������鳤�ȵ�һ��
//��ô���������м�λ�ã��϶���������ִ����������鳤��һ����������ڴˣ��������ÿ������򻮷ֵ�˼�룬ֻҪ������
//�����м�middleΪ���ֱ�׼���������Ǿ��ҵ��ˣ��������г��ִ����������鳤��һ������������Ȼ���ҵ�����������ǻ�
//Ҫ���һ��������ǲ���������������鳤�ȵ�һ�룬�粻�Ǿͷ���0.
int moreHalfNum(int* number,int length)
{ //����0����ʾû�г��ֳ���һ��������������
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
	����һ�δ���ʱΪ�˼��õ�������ǲ��ǳ��ֳ���һ��ļ��
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
//�������鱾������Եõ�����
//���������ʱ�򱣴���������һ���������е�����һ���ʴ���
//������ֵĴ�����֮ǰ���ֵĴ�����ͬ�������+1������-1���������Ϊ0���򱣴���һ���������Ѵ�����Ϊ1��
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
	����һ�δ���ʱΪ�˼��õ�������ǲ��ǳ��ֳ���һ��ļ��
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
//��С��K���������day1�еĳ��ִ�������һ����������Եõ�һ����������ͬ�����û��ڻ��ֵ�˼��
//�����������ĵ�K������������ʹ�������С������λ�������ǰ�ߣ��������λ�������棬����֮��λ��������ߵ�k��������Ҫ�ҵ�K����С������
//int *p=new int[k];
vector<int> lastK_Num(int input[], int length, int k)
{
	vector<int> result;
	if (input == NULL || k <= 0 || k>length || length <= 0)return result;
	int begin = 0;
	int end = length - 1;
	int index = partation(input, begin, end);

	while (index != k - 1)//ע�⳶���ط���Ϊʲô����k��k-1�����ԣ�
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
//��Ȼ����������û��ֵ�˼����������������ö����������ǽ��
//�������������ǽ���һ����������k���������ѣ������������飬�õ�ǰ���Ͷ��е��������Ƚϣ�������������С������������滻��
//���е��������������������������滻�����ѵ�������֮�������ڲ�����е����ؽ����ѣ��������ǲ��õ��ĵ��������⣬����
//������˼·���������µ�ʵ�֡�
//�������ѵ�ʵ�֣����ﲻ��˵��ֻ����STL�����set/multiset���������ѣ�������set���ͷ�ļ��С�
//greater<typename>��ͷ�ļ�<functional>
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
//ͳ���������������ֳ��ֵĴ���
//���������ֱ�۵ľ���ֱ�ӱ���
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
//˼������һ�����⣬�����һ�����������п��ٵ��ҵ�һ������
//���ֲ���
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
//�������ֶ��ֲ��ҵ�˼��ȥ�Ҹ����������������еĳ��ֵĴ���
//�ֱ��ҵ���һ��K�����һ��K�����ҵ�K�������г����˴����ˣ�
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
//�鲢����
//�鲢�����ǻ��ڷ��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á����������Ԫ�ط��ѳ����������У�
//�ٽ�������������кϲ����õ���ȫ��������У�����ʹÿ��������������ʹ�����жμ������������������ϲ���һ����
//�����Ϊ��·�鲢���鲢����Ϊ����һ�����в�ֳ����������У����������������ж�Ԫ������й鲢��Ҳ����ͨ�����αȽ�
//�����������е�����Ȼ�����ΰѽ�С�������뵽ԭʼ���������У�������merge�����е�����whileѭ����ʾ����һ��ʵ������ѭ
//�������Сֵ���ڶ����͵�����whileѭ��ʵ�ֱȽ���֮������һ�����Ĳ��롣
void merge(int data[], int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L1 = new int[n1];//��ֳ�����L1��L2
	int* L2 = new int[n2];
	for (int i = 0; i < n1; ++i){//��L1��ֵ
		L1[i] = data[left + i];
	}
	for (int i = 0; i < n2; ++i){//��L1��ֵ
		L2[i] = data[mid + i + 1];
	}
	int i = 0, j = 0;
	int k = left;
	while (i<n1&&j<n2){//����whileʵ�ֹ鲢����
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
//ֻ����һ�ε���
//����ҵ����ֻ����һ�ε����أ�������ı�����ȻOK�ģ���ô���˱�����������Ŀ�����ԣ������뵽��Щ���������أ�
//�ٸ����ӣ�������ͬ�������õ��Ľ����0�����ݵ����Ժ�õ��Ľ���Ͳ���0���ص���Ŀ������һ����֮��������������
//�ɶԳ��֣���ô��һ�������Ľ������0���ǲ����Ѿ��뵽�˽������ķ������ǵģ��������������ô������أ�
//�������飬�����е���������������ʣ�µ����϶��������ֻ����һ�ε�����
//���ֵ�һ�ε�����1��
void findOneNum(int a[], int length,int* num)
{
	if (a == NULL || length<0) return;
	*num = 0;
	for (int i = 0; i < length; ++i)
		*num ^= a[i];
}
//����һ�ε���������
//����������һ�ε��������øղŵ�һ���˼·���ǲ���Ҳ���Եõ�һ���������أ�Ҳ������򣬵����������������ˣ�����
//��ô��֤���õ���������������أ���Ȼ����һ������ǲ��еģ�Ҫ�������ܹ�������������ʹ�ã�������ֻ����һ�ε�
//ǡ�÷ֵ�������ͬ��group�У���ô�ǲ��ǾͿ�����������ֻ�õ�������Ҫ�Ľ���ˡ��������ڵĹؼ�������ô�����ܰ�����
//���ֳ�������Ҫ�����ӣ�
//���廮�֣�������������������е�ÿ���������һ�飬���õ�һ���������������������ͬ���ֻ�Ľ�����������
//�����ĳһλ��1����ô�ͱ�ʾ�������������λ�ǲ�ͬ�ģ�����������ǰ�������飬���ʱ����϶������ˣ���ô��֤����
//�ȵ������ֵ�������ͬ�������أ�����˵�ģ���ȵ�������ÿһλ������ͬ�ģ������������������֮��Ľ����ĳһλ��1��
//��������׼����ȵ����϶����Ǳ��ֵ���ͬ��ͬһ�����еġ�
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