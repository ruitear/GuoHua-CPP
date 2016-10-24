#include"mytitle.h"

//day1 两个链表的第一个公共节点
struct listNode{
	int data;
	listNode* next;
};
//这个题最基本的就是蛮力法，挨个遍历。回想我们之前上周的讲的问题，利用链表是否有环这个问题，我们是不是可以找到一个更好的解决办法呢？
//答案是肯定的，对吧？除了这个方法，是不是还有很多其他的方法。比如，利用一个hash表（hash表，周六专门给你讲一下），先遍历一个链表把它的
//每个节点都存到这个hash表中，然后遍历第二个链表，在hash表中查询当前链表的节点是否存在于hash中。除了利用hash表，接着之前讲的问题，比如
//从尾到头打印一个链表，结合两个链表相交的特性（之前讲过的），他们从相交的节点开始，就是重合的，我们是不是可以利用两个辅助栈，分别存两个
//两个链表的每个节点，存完之后，栈顶就是每个链表的最后一个元素，然后依次比较，找到第一个不相同的节点就是相交的第一个节点之前的节点。当然，可以利
//用栈的话，肯定可以利用递归对吧，只需要递归遍历在回溯的过程中找到第一个不相同的节点就行了。    除了这些，还有其他更简单的办法吗？当然有
//相交的链表从相交的节点开始就是重合的，也就是说，如果我们把链表从尾部对齐，然后从较短的链表的头和这个头对应到较长链表的那个节点开始，往
//后依次比较遍历，是不是第一个相同的节点，就是我们要找的节点。为此就需要先遍历得到两个链表的长度,对吧？
//遍历两个链表的长度的实现
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
	//先让长链表走diffLength
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


//问题回顾，二叉树的遍历
//二叉树的遍历，最基本的就是前序、后序和中序遍历：前序-根左右，后序-左右根，中序-左根右
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
//前序遍历
void preOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{
		visitNode(T);
		preOrder(T->left);
		preOrder(T->right);
	}
}
//后序遍历
void postOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{	
		preOrder(T->left);
		preOrder(T->right);
		visitNode(T);
	}
}
//中序遍历
void inOrder(binaryTreeNode* T)
{
	if (T != NULL)
	{
		preOrder(T->left);
		visitNode(T);
		preOrder(T->right);
	}
}
//回到题目中，在二叉树的前序遍历中，第一个节点总是树的根节点，但在中序遍历中根节点的值在序列的中间，左子树的节点在根的左边，
//右子树的值在根的右边，前序遍历{1,2,4,7,3,5,6,8}和中序遍历{4,7,2,1,5,3,8,6}，看前序遍历1，就是根节点的值，再看中序遍历，就
//能确定1的位置和左右子树的位置，也就是1前边的三个数是左子树，后边的四个数是右子树，同样前序遍历中1后边的前3个数是左子树，后
//四个数是右子树，那么在左右子树里面是不是利用同样的方法，就可以递归确定每个节点的位置了呢？
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
	//在中旬遍历中找根节点的值
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