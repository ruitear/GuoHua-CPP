#include"mytitle.h"
struct list
{
	int data;
	list* next;
};
//day1
//寻找数组中的最大值和最小值
//直接比较
pair<int, int> findMaxMin(int a[], int length)
{
	pair<int, int> result(0,0);
	if (a == NULL) return result;
	for (int i = 0; i < length; ++i)
	{
		if (a[i] < result.first) result.first = a[i];
		if (a[i] > result.second) result.second = a[i];
	}
	return result;
}
//奇数偶数比较
//将相邻的两个数分到一组（只是概念的分组，实际并没有操作哈），然后比较一组数中奇数位数字和偶数位数字，
//讲较大的数放到偶数位，较小的数放到奇数位,经过N/2次比较后，较大的数都放到偶数位置上，较小的数都放到
//奇数位了，最后再从偶数位和奇数位上分别得到最大的和最小的数。这样比较次数就相对直接比较少了0.5N次；
pair<int, int> findMaxMin(int a[], int length)
{
	pair<int, int> result(0, 0);
	if (a == NULL) return result;
	for (int i = 0; i < length; i=i+2)
	{
		if (a[i] < a[i + 1] && i + 1 <= length) 
			swap(a[i], a[i + 1]);//注意swap函数定义在algorithm头文件中，
	}
	for (int i = 0; i < length; i = i + 2)
	{
		if (a[i]>result.first) result.first = a[i];
		if (a[i + 1]<result.second&&i+1<=length) result.second = a[i+1];

	}
	return result;

}
//数组循环移位
//直接移位，每次将数组的元素右移一位
void rightShift(int a[], int length, int k)
{
	if (a == NULL)return;
	while (k--)
	{
		int temp = a[length - 1];
		for (int i = length - 1; i > 0; --i)
		{
			a[i] = a[i - 1];
		}
		a[0] = temp;
	}
}
//针对性的规律法，与week2-day4是相同问题的不同表述
void reverseArr(int a[], int begin, int end)
{
	while (begin < end)
	{
		int temp = a[begin];
		a[end] = a[begin];
		a[begin] = temp;
		begin++; end--;
	}
}
void rightShift2(int a[], int length, int k)
{
	if (a == NULL) return;
	k %= length;
	reverseArr(a,0,length-k-1);
	reverseArr(a, length - k, length - 1);
	reverseArr(a, 0, length -  1);
}
//第三种方法，就是利用大一里面字符串包含问题的思路来解决这个问题

//day2
//字符串移位包含问题
//直观的看，和day1的很像，直接移位，显然这个费时有费力，这里只提供一个简单的方法，
//例如，对ABCD进行移位操作，ABCD->BCDA->CDAB->DABC->ABCD，如果把前面移走的数据保留
//ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD，可以看出，要判断一个字符串是否为另一个字
//符串的移位包含，只需要判断这个字符串是不是ABCDABCD的子字符串，同时满足两个字符串
//长度相同
bool isShiftIncludeStr(string &str, string &substr)
{
	int len1 = str.size();
	int len2 = substr.size();
	if (len1 != len2)return false;
	string temp = str + str;
	for (int i = 0; i < len1; ++i)
	{
		//string substr的函数声明 string substr (size_t pos = 0, size_t len = npos) const;
		if (temp.substr(i, len2) == substr)return true;
	}
	return false;
}
//day3
//从一个没有给定头结点的链表中，删除一个给定节点。这个问题跟在day2里面的讲链表节点删除的时候我们介绍过对吧？
//这里简单说一下，并直附上代码，删除当前节点，就是把当前节点和中的值换成该节点下一个节点的值，并把下一个节点
//的下一个节点赋给，当前节点的next。
//也就是如下的代码示例，其中pCurrent为要删除的当前节点：
// pCurrent->next=pNext->next;
//pCurrent->data=pNext->data;
void deleteNode(list* pCurrent)
{
	if (pCurrent == NULL)return;
	list* pNext = pCurrent->next;
	if (pNext != NULL)
	{
		 pCurrent->next=pNext->next;
		pCurrent->data=pNext->data;
		delete pNext;
	}
	else
	{
		pCurrent = NULL;
	}
}
//从尾到头打印链表
//利用链表的特性，这里最直观的方法，就是利用一个栈，依次遍历把链表节点并入栈，遍历完成之后在出栈打印。
void printListRev(list* head)
{
	stack<list*>nodes;
	list* pNode = head;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}
	while (nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->data << " ";
		nodes.pop();
	}
}
//有了栈来帮助实现，那么在深入想一下，结合倒叙输出链表，应该会想到递归，由于递归本真就是一个栈结构，这样
//利用递归来实现，就有了如下的代码：
void printListRev2(list* head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			printListRev2(head->next);
		}
		cout <<head->data <<" ";
	}
}
//day4 链表合并
//由于链表是已经有序的，合并操作其实是一件很简单的事情，只需要一次比较，再把相应的节点接起来就可以了；
//那么按照这样的思路，下边提供两种解决问题的方法，一个是递归一个是循环
list* mergeList(list* head1,list* head2)
{
	if (head1 == NULL)return head2;
	else if (head2 == NULL)return head1;

	list* mergeHead = NULL;

	if (head1->data < head2->data)
	{
		mergeHead = head1;
		mergeHead->next=mergeList(head1->next, head2);
	}
	else
	{
		mergeHead = head2;
		mergeHead->next=mergeList(head1, head2->next);
	}
	return mergeHead;
}
//利用循环合并链表
list* mergeList2(list* head1, list* head2)
{
	if (head1 == NULL)return head2;
	else if (head2 == NULL)return head1;

	list* mergeHead = NULL;
	list* tempNode = NULL;
	while (head1 != NULL&&head2!=NULL)
	{
		if (head1->data < head2->data)
		{
			if (mergeHead) 
			{ 
				tempNode->next = head1;
				tempNode = tempNode->next;
				head1 = head1->next;
			}
			else
			{	
				mergeHead = head1; 
				tempNode = mergeHead;head1 = head1->next;
			}
		}
		else
		{
			if (mergeHead) 
			{ 
				tempNode->next = head2;
				tempNode = tempNode->next;
				head2 = head2->next;
			}
			else
			{
				mergeHead = head2; 
				tempNode = mergeHead;head1 = head1->next;
			}
		}
	}
	if (head1)
	{
		tempNode->next = head1;
	}
	if (head2)
	{
		tempNode->next = head2;
	}
	return mergeHead;
}
//day5
//判断点是否在三角形内部
//利用海伦公式
struct point{
	double x, y;
};
double areaTriangle(point A,point B,point C)
{
	double ab = sqrt(abs(A.x - B.x)*abs(A.x - B.x) + abs(A.y - B.y)*abs(A.y - B.y));
	double ac = sqrt(abs(A.x - C.x)*abs(A.x - C.x) + abs(A.y - C.y)*abs(A.y - C.y));
	double bc = sqrt(abs(B.x - C.x)*abs(B.x - C.x) + abs(B.y - C.y)*abs(B.y - C.y));

	double p = (ab + ac + bc) / 2;

	return sqrt((p - ab)*(p - ac)*(p - bc)*p);
}
bool isInTriangle(point A, point B, point C, point D)
{
	return (areaTriangle(A, B, D) + areaTriangle(A, C, D) + areaTriangle(B, C, D) <= areaTriangle(A,B,C));
}
//给定的一条直线的位置关系，也就是点P是在线的左边还是右边亦或是在直线上。
//简单的方法，就是确定直线的方程，然后通过带入法，判断点和直线得关系
//设点A(x1,y1) B(x2,y2) 设直线方程为y=k*x+b，得到直线方程为 y=(y2-y1)/(x2-x1)*(x-x1)+y1; 这里k=(y2-y1)/(x2-x1)就是直线的斜率；
//b=y1-(y2-y1)/(x2-x1)*x1;有了这些知识，利用相关几何知识得到点和直线的位置关系!
// 这里利用-1 0 1三个数表示点和直线的位置关系，分别为，线左，线上，线右！
int pointLine(point A,point B,point C)
{
	//A,B定义直线；
	double k = (A.y - B.y) / (A.x - B.x);
	double b = B.y - (A.y - B.y) / (A.x - B.x)*B.x;
	//直线方程 y=k*x+b  
	double temp = k*C.x + b;
	if (k > 0 )
	{
		if (C.y > temp) return -1;
		else if (C.y == temp) return 0;
		else if (C.y < temp) return 1;
	}
	else if (k < 0)
	{
		if (C.y > temp) return 1;
		else if (C.y == temp) return 0;
		else if (C.y < temp) return -1;
	}
	else if (k == 0)
	{
		if (C.y > temp) return 1;
		else if (C.y == 0) return 0;
		else if (C.y < temp) return -1;
	}
}



//day6
//判断两个链表是否相交
bool  isCross(list* list1, list* list2)
{
	if (list1 == NULL || list2 == NULL) return false;
	list* temp1 = list1;
	list* temp2=list2;
	while (temp1->next)
	{
		temp1 = temp1->next;
	}
	while (temp2->next)
	{
		temp2 = temp2->next;
	}
	if (temp1 == temp2) return true;
	else return false;
}
//判断一个链表是否有环
bool isHasCircle(list* head)
{
	if (head == NULL) return false;
	list* fast = head;
	list* low = head;

	while (fast != NULL || low != NULL)
	{
		low = low->next;
		fast = fast->next;
		if (fast != NULL) fast = fast->next;
		if (fast == low) return true;
	}
	return false;
}
//找到带环链表的入口节点
//找到环的入口节点，在找到链表环中的一个节点后，只要知道这个环有几个，利用前面在week2-day3的找到链表的第K个节点，
//就可以找到链表的入口节点了，也就是，通过得到环中的节点个数就可以利用倒数第K个节点的问题描述来解决这个问题。
list* meetNode(list* head)
{
	if (head == NULL) return NULL;
	list* fast = head;
	list* low = head;

	while (fast != NULL || low != NULL)
	{
		low = low->next;
		fast = fast->next;
		if (fast != NULL) fast = fast->next;
		if (fast == low) return fast;
	}
	return NULL;
}
list* entryNode(list* head)
{
	list* meetingNode = meetNode(head);
	if (meetingNode == NULL) return NULL;

	int loopCount = 1;
	list* pnode = meetingNode;

	while (pnode->next != meetingNode)
	{
		pnode = pnode->next;
		++loopCount;
	}
	pnode = head;
	for (int i = 0; i < loopCount; ++i)
	{
		pnode = pnode->next;
	}
	list* ppnode = head;
	while (pnode != ppnode)
	{
		pnode = pnode->next;
		ppnode = ppnode->next;
	}
	return pnode;
}
//day7 
//连续子数组的最大和

int findGreatSum1(int data[], int length)
{
	int result = numeric_limits<int>::min();
	int sum;
	for (int i = 0; i < length; ++i)
	{
		for (int j = i; j < length; ++j)
		{
			for (int k = i; k <= j; ++k)
			{
				sum += data[k];
			}
			if (sum>result)
				result = sum;
		}
	}
	return result;
}
int findGreatSum1(int data[], int length)
{
	int result = numeric_limits<int>::min();
	int sum;
	for (int i = 0; i < length; ++i)
	{
		for (int j = i; j < length; ++j)
		{
			sum += data[j];
			if (sum>result)
				result = sum;
		}
	}
	return result;
}
int findGreatSum(int data[], int length)
{
	int result = numeric_limits<int>::min();
	if (data == NULL || length <= 0) return 0;
	
	int curSum = 0;
	for (int i = 0; i < length; ++i)
	{
		if (curSum <= 0) curSum = data[i];
		else curSum += data[i];
		if (curSum>result)result = curSum;
	}
	return result;
}
//快速找到满足条件的两个数
pair<int, int> findQuick(int a[], int length, int index)
{
	pair<int, int> reslut;
	int* begin = a;
	int* end = a + length - 1;
	while (begin<end)
	{
		if ((*begin+*end)==index)
		{
			reslut.first = *begin;
			reslut.second = *end;
			break;
		}
		else if ((*begin + *end) < index) begin++;
		else end--;
	}
	return reslut;
}

//day8 丑数
//暴力破解法
bool isUgly(int num)
{
	while (num%2==0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	return (num == 1) ? true : false;
}
int getUglyNum(int index)
{
	if (index <= 0) return 0;
	int count = 0;
	int uglyNum = 0;
	while (count < index)
	{
		++count;
		if (isUgly(count))
		{
			++uglyNum;
		}
	}
	return count;
}
//技巧规律查找
int getUglyNum2(int index)
{
	if (index <= 0) return 0;
	int *uglyNums = new int[index];
	uglyNums[0] = 1;
	int nextUglyIndex = 1;
	int* pM2 = uglyNums;
	int* pM3 = uglyNums;
	int* pM5 = uglyNums;
	while (nextUglyIndex < index)
	{
		int minNext = minIndex((*pM2)*2, (*pM3)*3, (*pM5)*5);
		uglyNums[nextUglyIndex] = minNext;

		while (*pM2*2<=uglyNums[nextUglyIndex])
		{
			++pM2;
		}
		while (*pM3 * 3 <= uglyNums[nextUglyIndex])
		{
			++pM3;
		}
		while (*pM5 * 5 <= uglyNums[nextUglyIndex]) 
		{
			++pM5;
		}
		++nextUglyIndex;
	}
	int ugly = uglyNums[nextUglyIndex - 1];
	delete[] uglyNums;
	return ugly;
}
int minIndex(int num1,int num2,int num3)
{
	int min1 = (num1 < num2) ? num1 : num2;
	int min2 = (min1 < num3) ? min1 : num3;
	return min2;
}
//把数组排成最小的数
bool compare(const string &str1, const string &str2)
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;
	return s1 < s2;   //升序排列，如果改为s1 > s2则为逆序排列  
}
void ComArrayMin(int *pArray, int num)
{
	int i;
	string *pStrArray = new string[num];

	for (i = 0; i < num; i++) //将数字转换为字符串  
	{
		stringstream stream;
		stream << pArray[i];
		stream >> pStrArray[i];
	}
	sort(pStrArray, pStrArray + num, compare); //字符串数组排序  
	for (i = 0; i < num; i++)  
		cout << pStrArray[i];
	cout << endl;
	delete[] pStrArray;
}