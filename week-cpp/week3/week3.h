#include"mytitle.h"
struct list
{
	int data;
	list* next;
};
//day1
//Ѱ�������е����ֵ����Сֵ
//ֱ�ӱȽ�
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
//����ż���Ƚ�
//�����ڵ��������ֵ�һ�飨ֻ�Ǹ���ķ��飬ʵ�ʲ�û�в���������Ȼ��Ƚ�һ����������λ���ֺ�ż��λ���֣�
//���ϴ�����ŵ�ż��λ����С�����ŵ�����λ,����N/2�αȽϺ󣬽ϴ�������ŵ�ż��λ���ϣ���С�������ŵ�
//����λ�ˣ�����ٴ�ż��λ������λ�Ϸֱ�õ����ĺ���С�����������Ƚϴ��������ֱ�ӱȽ�����0.5N�Σ�
pair<int, int> findMaxMin(int a[], int length)
{
	pair<int, int> result(0, 0);
	if (a == NULL) return result;
	for (int i = 0; i < length; i=i+2)
	{
		if (a[i] < a[i + 1] && i + 1 <= length) 
			swap(a[i], a[i + 1]);//ע��swap����������algorithmͷ�ļ��У�
	}
	for (int i = 0; i < length; i = i + 2)
	{
		if (a[i]>result.first) result.first = a[i];
		if (a[i + 1]<result.second&&i+1<=length) result.second = a[i+1];

	}
	return result;

}
//����ѭ����λ
//ֱ����λ��ÿ�ν������Ԫ������һλ
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
//����ԵĹ��ɷ�����week2-day4����ͬ����Ĳ�ͬ����
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
//�����ַ������������ô�һ�����ַ������������˼·������������

//day2
//�ַ�����λ��������
//ֱ�۵Ŀ�����day1�ĺ���ֱ����λ����Ȼ�����ʱ�з���������ֻ�ṩһ���򵥵ķ�����
//���磬��ABCD������λ������ABCD->BCDA->CDAB->DABC->ABCD�������ǰ�����ߵ����ݱ���
//ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD�����Կ�����Ҫ�ж�һ���ַ����Ƿ�Ϊ��һ����
//��������λ������ֻ��Ҫ�ж�����ַ����ǲ���ABCDABCD�����ַ�����ͬʱ���������ַ���
//������ͬ
bool isShiftIncludeStr(string &str, string &substr)
{
	int len1 = str.size();
	int len2 = substr.size();
	if (len1 != len2)return false;
	string temp = str + str;
	for (int i = 0; i < len1; ++i)
	{
		//string substr�ĺ������� string substr (size_t pos = 0, size_t len = npos) const;
		if (temp.substr(i, len2) == substr)return true;
	}
	return false;
}
//day3
//��һ��û�и���ͷ���������У�ɾ��һ�������ڵ㡣����������day2����Ľ�����ڵ�ɾ����ʱ�����ǽ��ܹ��԰ɣ�
//�����˵һ�£���ֱ���ϴ��룬ɾ����ǰ�ڵ㣬���ǰѵ�ǰ�ڵ���е�ֵ���ɸýڵ���һ���ڵ��ֵ��������һ���ڵ�
//����һ���ڵ㸳������ǰ�ڵ��next��
//Ҳ�������µĴ���ʾ��������pCurrentΪҪɾ���ĵ�ǰ�ڵ㣺
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
//��β��ͷ��ӡ����
//������������ԣ�������ֱ�۵ķ�������������һ��ջ�����α���������ڵ㲢��ջ���������֮���ڳ�ջ��ӡ��
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
//����ջ������ʵ�֣���ô��������һ�£���ϵ����������Ӧ�û��뵽�ݹ飬���ڵݹ鱾�����һ��ջ�ṹ������
//���õݹ���ʵ�֣����������µĴ��룺
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
//day4 ����ϲ�
//�����������Ѿ�����ģ��ϲ�������ʵ��һ���ܼ򵥵����飬ֻ��Ҫһ�αȽϣ��ٰ���Ӧ�Ľڵ�������Ϳ����ˣ�
//��ô����������˼·���±��ṩ���ֽ������ķ�����һ���ǵݹ�һ����ѭ��
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
//����ѭ���ϲ�����
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
//�жϵ��Ƿ����������ڲ�
//���ú��׹�ʽ
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
//������һ��ֱ�ߵ�λ�ù�ϵ��Ҳ���ǵ�P�����ߵ���߻����ұ��������ֱ���ϡ�
//�򵥵ķ���������ȷ��ֱ�ߵķ��̣�Ȼ��ͨ�����뷨���жϵ��ֱ�ߵù�ϵ
//���A(x1,y1) B(x2,y2) ��ֱ�߷���Ϊy=k*x+b���õ�ֱ�߷���Ϊ y=(y2-y1)/(x2-x1)*(x-x1)+y1; ����k=(y2-y1)/(x2-x1)����ֱ�ߵ�б�ʣ�
//b=y1-(y2-y1)/(x2-x1)*x1;������Щ֪ʶ��������ؼ���֪ʶ�õ����ֱ�ߵ�λ�ù�ϵ!
// ��������-1 0 1��������ʾ���ֱ�ߵ�λ�ù�ϵ���ֱ�Ϊ���������ϣ����ң�
int pointLine(point A,point B,point C)
{
	//A,B����ֱ�ߣ�
	double k = (A.y - B.y) / (A.x - B.x);
	double b = B.y - (A.y - B.y) / (A.x - B.x)*B.x;
	//ֱ�߷��� y=k*x+b  
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
//�ж����������Ƿ��ཻ
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
//�ж�һ�������Ƿ��л�
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
//�ҵ������������ڽڵ�
//�ҵ�������ڽڵ㣬���ҵ������е�һ���ڵ��ֻҪ֪��������м���������ǰ����week2-day3���ҵ�����ĵ�K���ڵ㣬
//�Ϳ����ҵ��������ڽڵ��ˣ�Ҳ���ǣ�ͨ���õ����еĽڵ�����Ϳ������õ�����K���ڵ���������������������⡣
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
//���������������

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
//�����ҵ�����������������
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

//day8 ����
//�����ƽⷨ
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
//���ɹ��ɲ���
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
//�������ų���С����
bool compare(const string &str1, const string &str2)
{
	string s1 = str1 + str2;
	string s2 = str2 + str1;
	return s1 < s2;   //�������У������Ϊs1 > s2��Ϊ��������  
}
void ComArrayMin(int *pArray, int num)
{
	int i;
	string *pStrArray = new string[num];

	for (i = 0; i < num; i++) //������ת��Ϊ�ַ���  
	{
		stringstream stream;
		stream << pArray[i];
		stream >> pStrArray[i];
	}
	sort(pStrArray, pStrArray + num, compare); //�ַ�����������  
	for (i = 0; i < num; i++)  
		cout << pStrArray[i];
	cout << endl;
	delete[] pStrArray;
}