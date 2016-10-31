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
}
//day2
//栈的压入弹出序列

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
//树的两个节点中的最低公共祖先