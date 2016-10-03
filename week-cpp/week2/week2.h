#include"mytitle.h"

//day1 字符串反转
void resStr(char* strBegin, char* strEnd)
{
	if (strEnd == NULL || strEnd == NULL)return;
	while (strBegin < strEnd)
	{
		char temp = *strBegin;
		*strBegin = *strEnd;
		*strEnd = temp;
		strBegin++; strEnd--;
	}
}
void resString(char str[])
{
	if (str == NULL)return;
	int strLength = strlen(str);
	resStr(str, str + strLength-1);
	int index = 0, begin=0,end=0;
	while (index <= strLength)
	{
		if (str[index] != ' '&&str[index]!='\0')
		{
			index++;
			end = index;
		}
		else if (str[index] == ' ' || index == strLength)
		{
			resStr(str + begin, str + end-1);
			index++;
			begin = index;
		}
	}
}

//day2 字符串排列  例子：abc

void permStr(char* pStr, char* pBegin)
{
	if (*pBegin == '\0') cout << pStr << endl;
	else{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			permStr(pStr, pBegin + 1);
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}
void perm(char* str)
{
	if (str == NULL)
		return;
	permStr(str, str);
}

//链表的头结点
struct Node{
	int data;
	Node* next;
};
//day3 找到链表的第K个节点
Node* findKNode(Node* head,unsigned int k)
{
	if (head == NULL || k == 0)return NULL;
	Node* ahead = head;
	Node* behind = NULL;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		if (head->next != NULL)ahead = ahead->next;
		else return NULL;
	}
	behind = head;
	while (ahead->next != NULL)
	{
		ahead = ahead->next;
		behind = behind->next;
	}
	return behind;
}


//day3   翻转链表。
Node* reverseList(Node* pHead)
{
	Node* reveNode=NULL;
	Node* pNode = pHead;
	Node* NodeTemp = NULL;

	while (pNode != NULL)
	{
		Node* temp = pNode ->next;
		if (temp == NULL) reveNode = pNode;
		pNode->next = NodeTemp;

		NodeTemp = pNode;
		pNode = temp;
	}
	return reveNode;

}

//day4  左旋转字符串
char* leftRotateStr(char* pStr, int n)
{
	if (pStr == NULL||n<=0) return pStr;
	int strLength = strlen(pStr);
	if (strLength > 0 && n > 0 && n < strLength)
	{
		char* pStart1 = pStr;
		char* pEnd1 = pStr + n - 1;
		char* pStart2 = pStr+n;
		char* pEnd2 = pStr + strLength - 1;

		reverse(pStart1, pEnd1);
		reverse(pStart2, pEnd2);
		reverse(pStart1, pEnd2);

	}
	return pStr;
}
 //day5 
void delDuplicationNode(Node* head)
{
	if (head == NULL || head == NULL) return;
	Node* preNode = NULL;
	Node* nNode = head;
	while (nNode!=NULL)
	{
		Node* nNext = nNode->next;
		bool delFlag = false;
		if (nNext != NULL&&nNext->data == nNode->data)
		{
			delFlag = true;
		}
		if (!delFlag)
		{
			preNode = nNode;
			nNode = nNode->next;
		}
		else
		{
			int value = nNode->data;
			Node* beDel = nNode;
			while (beDel != NULL&&beDel->data == value)
			{
				nNext = beDel->next;
				delete beDel;
				beDel = NULL;
				beDel = nNext;
			}
			if (preNode == NULL)
				head = nNext;
			else
				preNode->next = nNext;
			nNode = nNext;
		}
	}
}