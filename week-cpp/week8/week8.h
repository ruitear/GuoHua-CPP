#include"mytitle.h"

//day1 给定一幅N*N表示的单通道图像，其中每个像素大小为4自己，写一个方法，将图像旋转90度，
//不利用额外的内存空间？
//最简单的做法就是逐层旋转，也就是一层一层的进行，比如：将上边移到右边、右边移到下边、下边
//移到左边、左边移到上边
//伪代码：
//for 1:n 
//  temp=top[i];top[i]=left[i];left[i]=bottom[i];bottom[i]=right[i];right[i]=temp;
//end
void rotateImage(int** image, int n)
{
	for (int i = 0; i < n/2; ++i)
	{
		int first = i;
		int last = n - 1 - i;
		for (int j = first; j < last;++j)
		{
			int offset = j - first;
			int temp = image[first][j];
			image[first][j]=image[last][last-offset];
			image[last][last - offset]=image[j][last];
			image[j][last]=temp;
		}
	}
}
//智力题
//有10瓶药丸，其中9瓶装的是1g/粒的药丸，余下的一瓶装有1.1g/粒的药丸。有一个精细的天平，怎么找
//到这一瓶1.1g/粒的药？天平只能用一次。
//称一次怎么差异化这些药丸呢？很简单第一瓶取1颗，第二瓶取2颗，依次类推，直至取到第10瓶的10颗。

//day2 二维数组中找数
//一个二维数组，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。写一个函数，
//输入一个这样的二维数组和一个整数，判断这个数组中是否含有这个数。
//用以为数组模拟二位数组
bool findNum(int* matrix, int rows, int cols, int number)
{
	bool isFound = false;
	if (matrix != NULL&&rows > 0 && cols > 0)
	{
		int row = 0;
		int col=cols - 1;
		while (row<rows&&col>=0)
		{
			if (matrix[row*cols + col] == number)
			{
				isFound = true;
				break;
			}
			else if (matrix[row*cols + col]>number)
				--col;
			else
				++row;
		}
	}
	return isFound;
}
//智力题
//有一个8*8的棋盘，其中的一个对角的两个方格被切掉了。现在有31张牌，每张牌恰好可以覆盖两个方格。用着31张牌能不能覆盖整个棋牌？

//day3
//辗转相除法，f(x,y)表示x，y的最大公约数；取k=x/y,b=x%y,x=ky+b,
//如果一个数能够同时整除x,y一定能够同时整除b,y,也就是他们的公约数相同
//则有f(x,y)=f(y,y%x)（y>0）
//f(42,30)=f(30,12)=f(12,6)=f(6,0)
int gcd(int x,int y)
{
	return (!y)?x:gcd(y,x%y);
}
//水壶装水
//有两个水壶，一个能装3升水，一个能装5升；现在要得到4升水，不考虑缺水的问题，且水壶的而形状不规则，没办法得到精确的容量
//day4
//删除数组中的重复数
class Solution {
public:
	/**
	* @param A: a list of integers
	* @return : return an integer
	*/
	int removeDuplicates(vector<int> &nums) {
		// write your code here
		int n = nums.size();
		if (n <= 0)return 0;
		int index = 0;
		for (int i = 1; i<n; ++i)
		{
			if (nums[i] != nums[index])
				index = i;
			else if (nums[i] == nums[index])
			{
				nums.erase(nums.begin() + i);
				--i;
				n = nums.size();
			}
		}
		return index + 1;
	}
};
int removeDuplicates(vector<int> &nums) {
	// write your code here
	int n = nums.size();
	if (n <= 2)return n;
	int index = 0;
	int count=0;
	for (int i = 1; i<n; ++i)
	{
		if (nums[i] != nums[index])
		{
			if (count >= 2)
			{
				nums.erase(nums.begin() + i - count + 1, nums.begin() + i - 1);
				index = i - count;
				n = nums.size();
			}
			else{
				index = i;
			}
			count = 0;
		}
		else if (nums[i] == nums[index])
		{
			count++;
		}
	}
	return n;
}
//扔鸡蛋
//分析：首先试着从10层开始扔，然后是20层，接着30层等等，如果鸡蛋1第一次扔下来（10层）就破了，那么最多扔10层；如果鸡蛋最后一次
//（100）层才破掉，那么最多扔19次，这样考虑也是可以的，对吧？这样只考虑最坏情况。那么怎么让两个扔的鸡蛋次数更均匀一些呢？也就
//是两次的负载更均衡一些，也就是不论第一次扔还是最后一次扔，次数都很稳定？这里这样设计了一种扔法：鸡蛋1每多扔一次，鸡蛋2就少扔
//一次,因此每多扔一次鸡蛋1，就减少鸡蛋2可能需要扔下的次数，例如让鸡蛋1从20层往下仍，然后是30层，此时鸡蛋2可能扔9次，若鸡蛋1再扔
//一次，就让鸡蛋2扔的次数在减一次降为8次，这时假设鸡蛋从X层开始往下仍，然后再网上增加X-1层，直到到达100层。那么久会有这样一个方
//程 X+(x-1(x-2)+=...+1=100.得到X=14。也就是我们从14层开始扔，然后是27层，接着39层，依次类推，最差情况要扔14次。这样就平衡了最
//差问题.
//day5
//删除重复数字
class Solution2 {
public:
	/**
	* @param A: a list of integers
	* @return : return an integer
	*/
	int removeDuplicates(vector<int> &nums) {
		// write your code here
		int n = nums.size();
		if (n <= 2)return n;
		int index = 0;
		int count = 0;
		for (int i = 1; i<n; ++i)
		{
			if (nums[i] != nums[index] || i == nums.size() - 1)
			{
				if (count >= 2)
				{
					if (i != nums.size() - 1)nums.erase(nums.begin() + i - count, nums.begin() + i - 1);
					else nums.erase(nums.begin() + i - count, nums.begin() + i);
					index = i - count + 1;
					n = nums.size();
					i = index;
				}
				else{
					index = i;
				}
				count = 0;
			}
			else if (nums[i] == nums[index])
			{
				count++;
				index = i;
			}
		}
		return n;
	}
};