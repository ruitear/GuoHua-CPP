#include"mytitle.h"

//day1 ��������ĵ�һ�������ڵ�
struct listNode{
	int data;
	listNode* next;
};
//�����������ľ�����������������������������֮ǰ���ܵĽ������⣬���������Ƿ��л�������⣬�����ǲ��ǿ����ҵ�һ�����õĽ���취�أ�
//���ǿ϶��ģ��԰ɣ���������������ǲ��ǻ��кܶ������ķ��������磬����һ��hash��hash������ר�Ÿ��㽲һ�£����ȱ���һ�����������
//ÿ���ڵ㶼�浽���hash���У�Ȼ������ڶ���������hash���в�ѯ��ǰ����Ľڵ��Ƿ������hash�С���������hash������֮ǰ�������⣬����
//��β��ͷ��ӡһ������������������ཻ�����ԣ�֮ǰ�����ģ������Ǵ��ཻ�Ľڵ㿪ʼ�������غϵģ������ǲ��ǿ���������������ջ���ֱ������
//���������ÿ���ڵ㣬����֮��ջ������ÿ����������һ��Ԫ�أ�Ȼ�����αȽϣ��ҵ���һ������ͬ�Ľڵ�����ཻ�ĵ�һ���ڵ�֮ǰ�Ľڵ㡣��Ȼ��������
//��ջ�Ļ����϶��������õݹ�԰ɣ�ֻ��Ҫ�ݹ�����ڻ��ݵĹ������ҵ���һ������ͬ�Ľڵ�����ˡ�    ������Щ�������������򵥵İ취�𣿵�Ȼ��
//�ཻ��������ཻ�Ľڵ㿪ʼ�����غϵģ�Ҳ����˵��������ǰ������β�����룬Ȼ��ӽ϶̵������ͷ�����ͷ��Ӧ���ϳ�������Ǹ��ڵ㿪ʼ����
//�����αȽϱ������ǲ��ǵ�һ����ͬ�Ľڵ㣬��������Ҫ�ҵĽڵ㡣Ϊ�˾���Ҫ�ȱ����õ���������ĳ���,�԰ɣ�
//������������ĳ��ȵ�ʵ��
unsigned int getLength(listNode* head)
{
	unsigned int nLength = 0;
	listNode* pNode = head;
	while (pNode != NULL)
	{
		++nLength;
		pNode = pNode->next;
	}
	return nLength;
}
listNode* find1stCommon(listNode* head1,listNode* head2)
{
	unsigned int nLength1=getLength(head1);
	unsigned int nLength2=getLength(head2);
	int diffLength = nLength1 - nLength2;
	listNode* longNode = head1;
	listNode* shortNode = head2;
	if (diffLength < 0)
	{
		longNode = head2;
		shortNode = head1;
		diffLength = abs(diffLength);
	}
	//���ó�������diffLength
	for (int i = 0; i < diffLength; ++i)
	{
		longNode = longNode->next;
	}
	while ((longNode != NULL) && (shortNode != NULL) && (longNode != shortNode))
	{
		longNode = longNode->next;
		shortNode = shortNode->next;
	}
	listNode* commonNode = longNode;
	return commonNode;
}


//����عˣ��������ı���
//�������ı�����������ľ���ǰ�򡢺�������������ǰ��-�����ң�����-���Ҹ�������-�����
struct binaryTreeNode{
	int data;
	binaryTreeNode* left;
	binaryTreeNode* right;
};
void visitNode(binaryTreeNode* T)
{
	if (T->data)
		cout << T->data << "-";
}
//ǰ�����
void preOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{
		visitNode(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}
//�������
void postOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{	
		preOrder(T->left);
		preOrder(T->right);
		visitNode(T);
	}
}
//�������
void inOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{
		preOrder(T->left);
		visitNode(T);
		preOrder(T->right);
	}
}
//�ص���Ŀ�У��ڶ�������ǰ������У���һ���ڵ��������ĸ��ڵ㣬������������и��ڵ��ֵ�����е��м䣬�������Ľڵ��ڸ�����ߣ�
//��������ֵ�ڸ����ұߣ�ǰ�����{1,2,4,7,3,5,6,8}���������{4,7,2,1,5,3,8,6}����ǰ�����1�����Ǹ��ڵ��ֵ���ٿ������������
//��ȷ��1��λ�ú�����������λ�ã�Ҳ����1ǰ�ߵ�������������������ߵ��ĸ�������������ͬ��ǰ�������1��ߵ�ǰ3����������������
//�ĸ���������������ô���������������ǲ�������ͬ���ķ������Ϳ��Եݹ�ȷ��ÿ���ڵ��λ�����أ�
binaryTreeNode* constructTree(int* benginPreOrder, int* endPreOrder, int* benginInOrder, int* endInOrder)
{
	int rootValue = benginPreOrder[0];
	binaryTreeNode* root = new binaryTreeNode();
	root->data = rootValue;
	root->left = root->right = NULL;

	if (benginPreOrder == endPreOrder)
	{
		if (benginPreOrder == endPreOrder&&*benginInOrder == *endPreOrder)
		{
			return root;
		}
		else
			throw exception("Invalid Input.");
	}
	//����Ѯ�������Ҹ��ڵ��ֵ
	int* rootInOrder = benginInOrder;
	while (rootInOrder<=endInOrder&&*rootInOrder!=rootValue)
	{
		++rootInOrder;
	}
	if (rootInOrder == endInOrder&&*rootInOrder != *endInOrder)
	{
		throw exception("Invalid Input.");
	}
	int leftLength = rootInOrder - benginInOrder;
	int* leftPreOrderEnd = benginPreOrder + leftLength;
	if (leftLength > 0)
	{
		root->left = constructTree(benginPreOrder + 1, leftPreOrderEnd, benginInOrder, rootInOrder - 1);
	}
	if (leftLength < endPreOrder - benginPreOrder)
	{
		root->right = constructTree(leftPreOrderEnd + 1, endPreOrder, rootInOrder+1,endInOrder);
	}
	return root;
}
binaryTreeNode* constructTree(int* preOrder, int* inOrder,int length)
{
	if (preOrder == NULL || inOrder == NULL || length <= 0) return NULL;
	
	constructTree(preOrder, preOrder + length-1, inOrder, inOrder + length-1);
}