#include"mytitle.h"

//day1
//����min������ջ
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
	assert(stack1.size() > 0 && stack2.size() > 0);//�����������������ִ�У�������ִֹ��
	stack1.pop();
	stack2.pop();
}
template<typename T>
const T& myStack<T>::min() const
{
	assert(stack1.size() > 0 && stack2.size() > 0);
	return stack2.top();
}