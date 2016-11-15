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