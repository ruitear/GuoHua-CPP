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
//day2 
//�ַ����滻
//��������ֱ�۵�Ȼ��������԰ɣ���ǰ�������������һ���ո�Ͱ��������������λ���ٷ���%RT��Ҳ��һ������ҪŲ����߶��еġ�
//����˼·��������ǴӺ����ǰŲ�ǲ��ǻ�úܶ࣬���ȱ���һ���ַ����������ж��ٸ��ո�Ȼ���ڼ����滻֮����ַ����Ƕ೤��
//�����Ӻ���ǰ�����ǲ���Ч�ʸ��˺ܶ࣬�����˴�ǰ����Ų���Ĺ��̡�
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
//�ֲ����:�������´�ӡ������
//������Ҫ��������±�����������Ŀ�ǲ��ǻ����ƣ�֮ǰ�Ӵ��ı������ǻ�����ǰ�к������������Ҫ����������±����������������������һ��
//���ڵ�1���ڵ�һ�㣬���ȱ�����������һ�������������ӽڵ�2,3��Ϊ���ܹ�������2,3��Ӧ�ð����Ǵ��������浽���أ����ǽ��ŷ������ֲ��ǰ�
//�մ������ұ�����1������2������3��Ҳ����2��ǰ���ȱ�������3�ں�ߺ���������ǲ����뵽�˶��У��Ƚ��ȳ������ʣ��ǵģ��ѽڵ����������
//���δ浽һ�������У�Ҳ���ǵ����Ǳ�����һ���ڵ��ʱ��Ͱ�����ڵ�������ӽڵ���ӣ�����ӡ���������еľ�����˴��ϵ��µı�����
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
//��֮���δ�ӡ������
//��֮���δ�ӡ������������һ���еķֲ���ϵ��´�ӡ���Ǻ�������⣬��ͬ���ǣ����������Ĳ�������ż��һ���ֻ��������Һʹ�������
//�����Ե�˼·����Ȼ�ֲ㣬���ǰ�ÿ��浽һ�����������ˣ���ʲô�����أ�һ��˳���Ƚ������һ�����ź���ȳ�����ôͳһ�أ��ǲ���
//�ȽϾ��ᣬ��������ǰ��������һ��������������㿴����������������Ľ���˳���ǲ��ǾͿ���ͳһ���Ƚ��ȳ������Ƚ�����أ�Ϊ�˼�
//�������������������ջ�ֱ�������������ʱ���ż���Ĳ�ʱ��ڵ㣬�������һ��ֻ�и��ڵ㣬���ڵ�����������ڵڶ��㣬����������
//������������һ��ջ����ջ˳����������������������������Ǵ�������Ĺ��̣����������ڶ����ÿ���ڵ��ʱ�����ǵ��ӽڵ�����
//���㣬�������ұ�����Ҳ���Ǳ����ڶ���ڵ��ʱ��������������ջ˳�������Һ���������ӡ��ʱ����Ǵ������ң����������ķ�ʽ����
//������ȥ��������ջ��û��Ԫ�ص�ʱ���ֹͣ�����ģ�ΪʲôҪ������ջ����һ������ô�����Ǻ���ʵ�ֵģ���ô��һ�������أ����ǣ�
//Ҳ�ǲ��ò����ģ�
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