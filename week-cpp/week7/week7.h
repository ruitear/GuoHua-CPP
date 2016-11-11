#include"mytitle.h"

//day1
//包含min函数的栈
template<typename T>
class myStack{
private:
	stack<T> stack1;
	stack<T> stack2;
public:
	myStack();
	const T& min() const;
	void pop();
	void push(const T&);
	~myStack();
};
template<typename T>
myStack<T>::myStack()
{

}
template<typename T>
myStack<T>::~myStack()
{

}
template<typename T> 
void myStack<T>::push(const T& value)
{
	stack1.push(value);
	if (stack2.size() == 0 || value < stack2.top())
	{
		stack2.push(value);
	}
	else
	{
		stack2.push(stack2.top());
	}
}
template<typename T>
void myStack<T>::pop()
{
	assert(stack1.size() > 0 && stack2.size() > 0);//如果条件成立，继续执行，否则中止执行
	stack1.pop();
	stack2.pop();
}
template<typename T>
const T& myStack<T>::min() const
{
	assert(stack1.size() > 0 && stack2.size() > 0);
	return stack2.top();
}
//day2
//利用构造函数
class temp{
public:
	temp(){ ++N; Sum += N; }
	static void reset(){ N = 0; Sum = 0; }
	static unsigned int GetSum(){ return Sum; }

private:
	static unsigned int N;
	static unsigned int Sum;
};
unsigned int temp::N = 0;
unsigned int temp::Sum = 0;

unsigned int sumOneToN(unsigned int n)
{
	temp::reset();
	temp *a = new temp[n];
	delete[] a;
	a = NULL;
	return temp::GetSum();
}
//利用函数指针
//定义两个函数一个充当递归的角色一个，充当借宿递归的角色
typedef unsigned int(*fun)(unsigned int);
unsigned int solution(unsigned int n)
{
	return 0;
}
unsigned int sumOneToN1(unsigned int n)
{
	static fun f[2] = { solution, sumOneToN1 };
	cout << !n<<"--"<< (!!n) << endl;
	return n+f[!!n](n - 1);
}
//day3
//树中给定两个接待女的最低公共祖先

//day4
//树的子结构
struct binaryTreeNode{
	int data;
	binaryTreeNode* left;
	binaryTreeNode* right;
};
bool hasSubTree(binaryTreeNode* rootA, binaryTreeNode* rootB)
{
	bool result = false;
	if (rootA != NULL&&rootB != NULL)
	{
		if (rootA->data == rootB->data) result = isSubTree(rootA, rootB);
		if (!result) result = hasSubTree(rootA->left, rootB);
		if (!result) result = hasSubTree(rootA->right, rootB);
	}
	return result;
}
bool isSubTree(binaryTreeNode* root1, binaryTreeNode* root2)
{
	if (root2 == NULL)return true;
	if (root1 == NULL) return false;
	if (root1->data != root2->data)return false;
	return isSubTree(root1->left, root2->left) && isSubTree(root1->right, root2->right);
}
//day5 二叉搜索树转换为双向链表
binaryTreeNode* convert(binaryTreeNode* pRoot)
{
	binaryTreeNode* pLastNodeOfList = NULL;//pLastNodeOfList指向已经拍好的链表的最后一个节点
	convertNode(pRoot, pLastNodeOfList);
	binaryTreeNode* pHeadOfList = pLastNodeOfList;
	while (pHeadOfList!=NULL&&pHeadOfList->left!=NULL)
		pHeadOfList = pHeadOfList->left;//遍历到最小的一个节点作为开始，也就是起始节点
	return pHeadOfList;
}
void convertNode(binaryTreeNode* node, binaryTreeNode* pLastNodeofList)
{
	if (node == NULL)return;
	binaryTreeNode* current = node;
	if (current->left != NULL)convertNode(current->left, pLastNodeofList);
	current->left = pLastNodeofList;
	if (pLastNodeofList != NULL)pLastNodeofList->right = current;
	pLastNodeofList = current;
	if (current->right != NULL)convertNode(current->right, pLastNodeofList);
}