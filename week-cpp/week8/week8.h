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

//day2 字符串压缩
//利用字符串出现的次数，编写一个方法实现基本的字符串压缩功能。比如字符串aabcccccaaa会变为a2b1c5a3.
//若压缩后的字符串没有变短，子返回原先的字符串。
