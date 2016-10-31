#include"mytitle.h"

//day1
//����عˣ��Ʋ��������У�
//�ݹ�ʵ��
long long Fibonacci(unsigned int n)
{
	if (n <= 0)return 0;
	if (n == 1)return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//ѭ��ʵ�֣��ݹ�Ҫ�ظ�����ܶ࣬����ѭ������ǰ�ۼ��Ѿ������ֵ����������ٺܶ�
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
//�������к�Ϊĳһֵ��·��
struct binaryTreeNode{
	int data;
	binaryTreeNode* left;
	binaryTreeNode* right;
};
//����ǰ��������Ӹ��ڵ�һ�����±�����ֱ���ҵ�·����Ϊ����ֵ��·��λ�ã��������Ľڵ�ΪҶ�ӽڵ㣻
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
	path.pop_back();//���ؽڵ�֮ǰɾ����ǰ�ڵ�-��push_back(),��β�����룬��pop_back()��β��ɾ����
}
void findPath(binaryTreeNode* root, int sum)
{
	if (root == NULL)return;
	vector<int>path;
	int currentSum = 0;
	findPathSum(root,sum,path,currentSum);
}
//day2
//ջ��ѹ�뵯������

//�����򣬶�����(Heapsort)��ָ���öѻ������ѣ��������ݽṹ����Ƶ�һ�������㷨������ѡ�������һ�֡�
//��������������ص���ٶ�λָ��������Ԫ�ء��ѷ�Ϊ����Ѻ�С���ѣ�����ȫ������������ѵ�Ҫ����ÿ����
//���ֵ���������丸�ڵ��ֵ��������ķǽ��������У���Ҫʹ�õľ��Ǵ���ѣ���Ϊ���ݴ���ѵ�Ҫ���֪��
//����ֵһ���ڶѶ���
void siftDown(int data[], int start, int len){
	//����ÿ��ֻ������Ԫ�ر��浽�Ѷ�
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
//���������ڵ��е���͹�������