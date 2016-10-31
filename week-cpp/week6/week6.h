#include"mytitle.h"

//day1
//问题回顾，菲波那切数列，
//递归实现
long long Fibonacci(unsigned int n)
{
	if (n <= 0)return 0;
	if (n == 1)return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//循环实现，递归要重复计算很多，利用循环，提前累加已经计算的值，这样会加速很多
long long Fibonacci1(unsigned int n)
{
	int result[2] = { 0, 1 };
	if (n < 2) return result[n];
	long long fibone = 0;
	long long fibtwo = 1;
	long long fib = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fib = fibone + fibtwo;
		fibone = fibtwo;
		fibtwo = fib;
	}
	return fib;
}
//二叉树中和为某一值的路径
struct binaryTreeNode{
	int data;
	binaryTreeNode* left;
	binaryTreeNode* right;
};
//利用前序遍历，从根节点一次往下遍历，直到找到路径和为期望值的路径位置，并且最后的节点为叶子节点；
void findPathSum(binaryTreeNode* root, int sum,vector<int>& path,int currentSum)
{
	currentSum += root->data;
	path.push_back(root->data);
	bool isLeaf = root->left == NULL&&root->right == NULL;
	if (currentSum == sum&&isLeaf)
	{
		cout << "A path is found! ";
		vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); iter++)
		{
			cout << *iter << "-";
		}
		cout << endl;
	}
	if (root->left != NULL)findPathSum(root->left, sum, path, currentSum);
	if (root->right != NULL)findPathSum(root->right, sum, path, currentSum);
	path.pop_back();//返回节点之前删除当前节点-用push_back(),从尾部插入，用pop_back()从尾部删除；
}
void findPath(binaryTreeNode* root, int sum)
{
	if (root == NULL)return;
	vector<int>path;
	int currentSum = 0;
	findPathSum(root,sum,path,currentSum);
}//思考，如果给出要找出所有的合为某一值的路径呢？
//day2
//栈的压入弹出序列
bool isPoPOrder(const int* push, const int* pop, int length)
{
	bool isOK = false;
	if (push != NULL&&pop != NULL)
	{
		const int* nextPush = push;
		const int* nextPop = pop;
		stack<int>stackData;
		while (nextPop - pop<length)
		{
			while (stackData.empty() || stackData.top() != *nextPush)
			{
				if (nextPush - push == length)break;
				stackData.push(*nextPush);
				nextPush++;
			}
			if (stackData.top() != *nextPop)break;
			stackData.pop();
			nextPop++;
		}
		if (stackData.empty() && nextPop - pop == length)isOK = true;
	}
	return isOK;
}
//堆排序，堆排序(Heapsort)是指利用堆积树（堆）这种数据结构所设计的一种排序算法，它是选择排序的一种。
//可以利用数组的特点快速定位指定索引的元素。堆分为大根堆和小根堆，是完全二叉树。大根堆的要求是每个节
//点的值都不大于其父节点的值。在数组的非降序排序中，需要使用的就是大根堆，因为根据大根堆的要求可知，
//最大的值一定在堆顶。
void siftDown(int data[], int start, int len){
	//最大堆每次只把最大的元素保存到堆顶
	int i = start, lChild = start * 2 + 1;
	int temp = data[i];
	while (lChild <= len){
		if (lChild<len&&data[lChild]<data[lChild + 1]) lChild++;
		if (temp >= data[lChild]) break;
		else{
			data[i] = data[lChild]; i = lChild; lChild = 2 * lChild + 1;
		}
	}
	data[i] = temp;
}
void heapSort(int data[], int len){
	if (data == NULL || len <= 0) return;
	for (int i = len / 2; i >= 0; --i)siftDown(data, i, len);
	for (int j = len - 1; j >= 1; --j){
		swap(data[0], data[j]);
		siftDown(data, 0, --len);
	}
}

//day3
//二叉搜索树（Binary Search Tree），（又：二叉搜索树，二叉查找树）它或者是一棵空树，或者是具有下列性质的二叉树： 若它的左子树不空，
//则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别
//为二叉排序树。
//输入一个数组判断这个该数组是不是某个二叉搜索树的后序遍历的结果。如果是则返回true，否则返回false，假设输入数组中任意两个数都不相同。
//要判断一个数组是不是一个二叉搜索树的后序遍历序列，跟我之前讲的利用二叉树的前序和中序遍历的重建二叉树其实很相像，因为二叉搜索树是左
//子节点<根<右子节点，在后序遍历中，根节点肯定位于最后一个位置，然后左子树都小于它，右子树都大于它。剩下的，就只递归判断能不能左右子树
//是不是满足二叉树搜索树的后序遍历结构了。

bool isSequenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0) return false;
	int root = sequence[length - 1];
	int i = 0;
	for (; i < length - 1; ++i)//搜索找到第一个右子树的节点，
	{
		if (sequence[i]>root)break;
	}
	int j = i;
	for (; j < length - 1; ++j)//在二叉搜索树的右子树中搜索看是否有比root节点值小的数。
	{
		if (sequence[j] < root)return false;
	}
	bool left = true;
	if (i>0) left = isSequenceOfBST(sequence, i);//递归判断左子树是不是二叉排序树
	bool right = true;
	if (i < length - 1)right = isSequenceOfBST(sequence + i, length - i - 1);//递归判断右子树是不是二叉排序树
	return (left&&right);
}
//给定一个二叉搜索树，找到其中的第K大的节点。
//根据中序遍历的特点结合二叉搜索树数本身的左子树比根节点小，右子树比根节点大，中序遍历的得到的序列一定是一个有序的序列。
//也就是说，只要中序遍历一遍二叉树就很容易找到它的第K个节点。
binaryTreeNode* kNodeBST(binaryTreeNode* root, unsigned int& k)
{
	binaryTreeNode* target = NULL;
	if (root->left != NULL)target = kNodeBST(root->left,k);
	if (target == NULL)
	{
		if (k == 1)target = root;
		k--;
	}
	if (target == NULL&&root->right != NULL) target = kNodeBST(root->right, k);
	return target;
}
binaryTreeNode* findkNodeBST(binaryTreeNode* root, unsigned int k)
{
	if (root == NULL || k == 0)return NULL;
	return kNodeBST(root, k);
}

//day4 
//二叉树非递归的前中后序遍历
//不用递归，要记住回溯路径，必然需要一个辅助空间来记录遍历过程，这里利用一个辅助栈来完成非递归遍历
//前序
//后序
//中序

//圆圈中剩下的数，约瑟夫环问题

//day5
//二叉树的下一个节点

//包含min函数的栈