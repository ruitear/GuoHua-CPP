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
}//˼�����������Ҫ�ҳ����еĺ�Ϊĳһֵ��·���أ�
//day2
//ջ��ѹ�뵯������
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

//day3
//������������Binary Search Tree�������֣��������������������������������һ�ÿ����������Ǿ����������ʵĶ������� ���������������գ�
//�������������н���ֵ��С�����ĸ�����ֵ�� ���������������գ��������������н���ֵ���������ĸ�����ֵ�� ������������Ҳ�ֱ�
//Ϊ������������
//����һ�������ж�����������ǲ���ĳ�������������ĺ�������Ľ����������򷵻�true�����򷵻�false��������������������������������ͬ��
//Ҫ�ж�һ�������ǲ���һ�������������ĺ���������У�����֮ǰ�������ö�������ǰ�������������ؽ���������ʵ��������Ϊ��������������
//�ӽڵ�<��<���ӽڵ㣬�ں�������У����ڵ�϶�λ�����һ��λ�ã�Ȼ����������С����������������������ʣ�µģ���ֻ�ݹ��ж��ܲ�����������
//�ǲ�������������������ĺ�������ṹ�ˡ�

bool isSequenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0) return false;
	int root = sequence[length - 1];
	int i = 0;
	for (; i < length - 1; ++i)//�����ҵ���һ���������Ľڵ㣬
	{
		if (sequence[i]>root)break;
	}
	int j = i;
	for (; j < length - 1; ++j)//�ڶ��������������������������Ƿ��б�root�ڵ�ֵС������
	{
		if (sequence[j] < root)return false;
	}
	bool left = true;
	if (i>0) left = isSequenceOfBST(sequence, i);//�ݹ��ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length - 1)right = isSequenceOfBST(sequence + i, length - i - 1);//�ݹ��ж��������ǲ��Ƕ���������
	return (left&&right);
}
//����һ���������������ҵ����еĵ�K��Ľڵ㡣
//��������������ص��϶�����������������������ȸ��ڵ�С���������ȸ��ڵ����������ĵõ�������һ����һ����������С�
//Ҳ����˵��ֻҪ�������һ��������ͺ������ҵ����ĵ�K���ڵ㡣
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
//�������ǵݹ��ǰ�к������
//���õݹ飬Ҫ��ס����·������Ȼ��Ҫһ�������ռ�����¼�������̣���������һ������ջ����ɷǵݹ����
//ǰ��
//����
//����

//ԲȦ��ʣ�µ�����Լɪ������

//day5
//����������һ���ڵ�

//����min������ջ