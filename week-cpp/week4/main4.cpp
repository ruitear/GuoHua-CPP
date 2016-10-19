#include"week4.h"


int main()
{
	//day1 ��������
	int arr0[] = { 1, 2, -3, 10, -4, 7, 12, -5 };
	quickSort(arr0, 0,7);
	cout << "quickSort: ";
	for (auto &temp : arr0)
		cout << temp << " ";
	cout << endl;

	//day1 �������鳤��һ�����
	int arr00[] = { 1, 2, 4, 5, 2, 2, 2, 2, 9, 2 };
	cout<<"moreHalfNum-���֣�"<<moreHalfNum(arr00,10)<<endl;
	cout << "moreHalfNum-���ɣ�" << moreHalfNum1(arr00, 10) << endl;

	//day2 ��С��k����
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

	//day2 ����������K���ֵĴ���
	int a[] = { 1, 3, 4, 5, 5, 5, 5, 6, 8 };
	cout << "getNumberOfK:"<<getNumberOfK(a, 9, 6) << endl;
	cout <<"findNum:"<< findNum(a, 9, 5) << endl;

	//�鲢����
	int arr1[] = { 1, 2, -3, 10, -4, 7, 12, -5 };
	mergeSort(arr1, 0, 7);
	cout << "mergeSort: ";
	for (auto &temp : arr0)
		cout << temp << " ";
	cout << endl;

	//�ҵ�ֻ����һ�ε���
	int num;
	int aa[] = { 2, 4, 3, 3, 5, 2, 5 };
	findOneNum(aa,7,&num);
	cout << "findOneNum: " << num << endl;
	//����һ�ε�����������ʱ��
	int aa2[] = { 2, 4, 3, 3, 5,7, 2, 5 };
	pair<int, int> res = findTwoNum(aa2, 8);
	cout << "findTwoNum: " << res.first << " " << res.second << endl;
	return 0;
}