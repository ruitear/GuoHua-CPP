#include"week4.h"


int main()
{
	//day1 快速排序
	int arr0[] = { 1, 2, -3, 10, -4, 7, 12, -5 };
	quickSort(arr0, 0,7);
	cout << "quickSort: ";
	for (auto &temp : arr0)
		cout << temp << " ";
	cout << endl;

	//day1 超过数组长度一半的数
	int arr00[] = { 1, 2, 4, 5, 2, 2, 2, 2, 9, 2 };
	cout<<"moreHalfNum-划分："<<moreHalfNum(arr00,10)<<endl;
	cout << "moreHalfNum-规律：" << moreHalfNum1(arr00, 10) << endl;

	//day2 最小的k个数
	int arr[] = { 7, 0, 2, 4, 9, 1, 54, 89, 32, 78 }, k = 3;
	vector<int> arr2 = { 7, 0, 2, 4, 9, 1, 54, 89, 32, 78 };
	vector<int> lastArr=lastK_Num(arr, 10, k);
	if (lastArr.size() > 0)
	{
		for (auto &temp : lastArr)
			cout << temp << " ";
	}
	else cout << "Error!";
	cout << endl;

	multiset<int, greater<int>> lastArr1=lastK_Num1(arr2, k);
	if (lastArr1.size() > 0)
	{
		for (auto &temp : lastArr1)
			cout << temp << " ";
	}
	else cout << "Error!";
	cout << endl;

	//day2 排序数组中K出现的次数
	int a[] = { 1, 3, 4, 5, 5, 5, 5, 6, 8 };
	cout << "getNumberOfK:"<<getNumberOfK(a, 9, 6) << endl;
	cout <<"findNum:"<< findNum(a, 9, 5) << endl;

	//归并排序
	int arr1[] = { 1, 2, -3, 10, -4, 7, 12, -5 };
	mergeSort(arr1, 0, 7);
	cout << "mergeSort: ";
	for (auto &temp : arr0)
		cout << temp << " ";
	cout << endl;

	//找到只出现一次的数
	int num;
	int aa[] = { 2, 4, 3, 3, 5, 2, 5 };
	findOneNum(aa,7,&num);
	cout << "findOneNum: " << num << endl;
	//出现一次的数有两个的时候
	int aa2[] = { 2, 4, 3, 3, 5,7, 2, 5 };
	pair<int, int> res = findTwoNum(aa2, 8);
	cout << "findTwoNum: " << res.first << " " << res.second << endl;
	return 0;
}