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
//day2 
//字符串替换
//看到题最直观当然很容易想对吧，从前往后遍历，遇到一个空格就把数组整体后移两位，再放入%RT，也到一个就需要挪动后边多有的。
//喊个思路，如果我们从后边往前挪是不是会好很多，首先遍历一遍字符串，看看有多少个空格，然后在计算替换之后的字符串是多长，
//这样从后往前插入是不是效率高了很多，减少了从前往后挪动的过程。
void replaceSpace(char str[])
{
	if (str == NULL) return;
	int numSpace = 0;
	int length = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++length;
		if (str[i] == ' ') ++numSpace;
		++i;
	}
	int newLength = length + 2 * numSpace;
	int indexOri = length;
	int indexNew = newLength;
	while (indexOri >= 0 && indexNew > indexOri)
	{
		if (str[indexOri] == ' ')
		{
			str[indexNew--] = 'T';
			str[indexNew--] = 'R';
			str[indexNew--] = '%';
		}
		else
		{
			str[indexNew--] = str[indexOri];
		}
		--indexOri;
	}

}
//分层遍历:从上往下打印二叉树
//这里这要求从上往下遍历，看到题目是不是会纳闷，之前接触的遍历都是基本的前中后序遍历，现在要按层从上往下遍历，对于这个，先来分析一下
//根节点1是在第一层，首先遍历，它的下一层是它的左右子节点2,3，为了能够遍历到2,3，应该把他们存起来，存到哪呢？我们接着分析，分层是按
//照从左往右遍历，1完了是2，接着3，也就是2在前边先遍历到，3在后边后遍历到，是不是想到了队列，先进先出的性质？是的，把节点的左右子树
//依次存到一个队列中，也就是当我们遍历到一个节点的时候就把这个节点的左右子节点入队，最后打印完整个队列的就完成了从上到下的遍历。
void printTopToBottom(binaryTreeNode* root)
{
	if (!root)return;
	deque<binaryTreeNode*>dequeTree;
	dequeTree.push_back(root);
	while (dequeTree.size())
	{
		binaryTreeNode* node = dequeTree.front();
		dequeTree.pop_front();
		cout << node->data << "-";
		if (node->left)dequeTree.push_back(node->left);
		if (node->right)dequeTree.push_back(node->right);
	}
}
//按之字形打印二叉树
//按之字形打印二叉树，跟上一题中的分层从上到下打印，是很像的问题，不同的是，遍历按树的层数的奇偶，一次轮换从左往右和从右往左
//按照以的思路，既然分层，我们把每层存到一个容器就行了，用什么容器呢？一个顺着先进后出，一个倒着后进先出，怎么统一呢？是不是
//比较纠结，二叉树当前层又是上一层的左右子树，你看如果调整左右子树的进入顺序是不是就可以统一到先进先出或者先进后出呢？为了简
//单起见，这里利用两个栈分别用来存奇数的时候和偶数的层时候节点，在例如第一层只有根节点，根节点的左右子树在第二层，他们是右往
//左遍历，存入第一个栈，入栈顺序是先左子树后右子树，输出就是从右往左的过程，当遍历到第二层的每个节点的时候，他们的子节点是在
//三层，从左往右遍历，也就是遍历第二层节点的时候左右子树的入栈顺序是先右后左，这样打印的时候就是从左往右，按照这样的方式依次
//进行下去，当两个栈都没有元素的时候就停止遍历的？为什么要用两个栈，用一个不行么？答案是很难实现的，那么用一个队列呢？答案是：
//也是不好操作的！
void printZhi(binaryTreeNode* root)
{
	if (!root)return;
	stack<binaryTreeNode*> nodeLevel[2];
	int currentLevel = 0;
	int nextLevel = 1;
	nodeLevel[currentLevel].push(root);
	while (!nodeLevel[0].empty() || !nodeLevel[1].empty())
	{
		binaryTreeNode* node = nodeLevel[currentLevel].top();
		nodeLevel[currentLevel].pop();
		cout << node->data << "-";
		if (currentLevel == 0)
		{
			if (node->left != NULL)
			{
				nodeLevel[nextLevel].push(node->left);
			}
			if (node->right != NULL)
			{
				nodeLevel[nextLevel].push(node->right);
			}
		}
		else
		{
			if (node->right != NULL)
			{
				nodeLevel[nextLevel].push(node->right);
			}
			if (node->left != NULL)
			{
				nodeLevel[nextLevel].push(node->left);
			}
		}
		if (nodeLevel[currentLevel].empty())
		{
			currentLevel = 1 - currentLevel;
			nextLevel =1- nextLevel;
		}
	}
}
//day3
//树的深度
//关于树的深度，对于只有一个根节点的深度就为1，若根节点只有左子树，就是左子树的深度加1，同样只有右子树的时候，就是右子树深度加1，
//那多对于既有左子树又有右子树的情况，就是去左右子树最大的深度加1，有了这样的思路递归下去，就很方便了！代码如下：
int treeDepth(binaryTreeNode* root)
{
	if (root==NULL)return 0;
	int leftDepth = treeDepth(root->left);
	int rightDepth = treeDepth(root->right);

	return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}
//判断一个数是不是平衡二叉树，
//平衡二叉树的定义：二叉树中任意节点的左右子树的深度相差不超过1，那么那就是一个平衡二叉树。
//遍历所有节点得到深度差
bool isBalanceTree(binaryTreeNode* root)
{
	if (root == NULL)return true;
	int left = treeDepth(root->left);
	int right = treeDepth(root->left);
	if (abs(left - right) > 1)return false;
	return isBalanceTree(root->left) && isBalanceTree(root->right);
}
//利用二叉树的后序遍历这样的，遍历，当遍历到根节点时他的左右节点有已经遍历过了，只要记住它的左右子树的深度就可以判断当前树是不是平衡二叉树
bool IsBalanced(binaryTreeNode* root, int* pDepth)
{
	if (root == NULL)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(root->left, &left)&& IsBalanced(root->left, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
//这里只便函的函数
bool isBalanceTree2(binaryTreeNode* root)
{
	int depth = 0;
	return IsBalanced(root, &depth);
}
//N!末尾0的个数
//N!中末尾0的个数就是找里面2和5能够凑成多少对，也就是找min(count(2),count(5)),在序列中出现的个数显然2的频率比5高，所以只需要求5有多少个就OK了
int countN0(int n)
{
	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		j = i;
		while (j % 5 == 0)
		{
			count++;
			j /= 5;
		}
	}
	return count;
}
//关于统计5的个数的问题，有一个简单的地推公式，这里证明不说，因为我也证明过，只记着了，此处【尴尬脸】
//令f（x）表示为末尾0的个数，当0<N<5,f（N!）=0，当N>=5时，f（N!）=k+f（k!）,其中k=n/5；
//转换成和的形式这样就是f(N!)=[N/5]+[N/5^2]+[N/5^3]+....总存在一个K使得5^K>N,[5^K]=0,这里[N/5]表示不大于N的数中5的倍数贡献一个5，
//[N/5^2]表示不大于N的数中5^2再贡献一个5，依次类推；
int countN00(int n)
{
	int count = 0;
	while (n)
	{
		count += n / 5;
		n /= 5;
	}
	return count;
}
