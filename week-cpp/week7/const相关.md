#C++中的const
<b>const 限定符，</b><br>
它把一个对象转换成一个常量const int me=541;这时任何任何试图修改me的操作都会引发错误。
const int me=str.size();<
# <b>1</b>、const与引用和指针
<b>引用和const</b><br>
const引用不能被用来修改它绑定绑定 的值；<br>
引用就是对象的别名，用起来很简单，但是引用声明必须初始化。常量引用类型初始化的时候要注意：引用的类型必须与其所引用的对象类型一致；有两个例外：第一个就是允许一个常量对象绑定到非常量对象、字面值、甚至一般表达式；另一个例外就是一个基类引用(或指针)可以绑定到派生类上。<br>
const int me=541；<br>
const int& you=&me；//这引用和对象都是常量<br>
you=521；//错误：you是对常量的引用<br>
int& them=me；//错误，试图让非常量引用常量<br>
<b>指针和const</b><br>
指向常量的指针，不能用来改变其所指对象的值。换言之就是，不能通过指针来修改对象的值，而没有规定那个指针对象的值不能通过其他途径修改。<br>
常量指针：必须初始化，把*放在const之前，用以说明指针是一个常量<br>
例如：int num=0; int *const cur=&num; 那么将一直指向num，此例中，我们从左往右阅读，离cur最近的符号是const，意味着cur本身是一个常量对象，对象的类型由声明的其余部分确定，声明符中的下一个符号是*，意味着cur是一个常量指针。<br>
这里就要区分顶层const和底层const的区别了；详细内容可以参考primer里面相关介绍，
顶层const表示指针本身是一个常量，底层const表示指针所指对象是一个常量。
int me;<br>
const int* you = &me;//you可变，*you不可变，此时不能用*you来修改，但是you可以转向<br>
int* const you = &me;//you不可变，*you可变，此时允许*you来修改其值，但是you不能转向。<br>
const int* const you = &me;//you不可变，*you也不可变，此时既不能用*you来修改其值，也不能转向<br>
<b>1</b>.用const修饰函数的参数--const只能修饰输入参数<br>
如果参数作输出用，不论它是什么数据类型，也不论它采用“指针传递”还是“引用传递”，都不能加const修饰，否则该参数将失去输出功能。因为修饰的参数是不能被改变的！
如果输入参数采用“指针传递”，那么加const修饰可以防止意外地改动该指针，起到保护作用。
例1、void StringCopy(char* strDest, const char *strSrc);<br>
其中strSource是输入参数，strDest是输出参数。给strSrc加上const修饰后，如果函数体内的语句试图改动strSrc的内容，编译器将指出错误。
如果输入参数采用“值传递”，由于函数将自动产生临时变量用于复制该参数，该输入参数本来就无需保护，所以不要加const修饰。
例2、void function(vector<int> vec)<br>
void function(vector<int>& vec)<br>
void function(const vector<int>& vec)<br>
对于基本数据内部数据类型的参数不存在构造、析构的过程，而复制也非常快，“值传递”和“引用传递”的效率几乎相当，对于非内部数据类型的输入参数，应该将“值传递”的方式改为“const引用传递。
#<b>2</b>、用const修饰函数的返回值<br>
以“指针传递”方式的函数返回值加const修饰，那么函数返回值（即指针）的内容不能被修改，该返回值只能被赋给加const修饰的同类型指针: const char * getStr(void);char*str =getStr();//编译错误
const char *str=getStr();//正确
如果函数返回值采用“值传递”，函数会把返回值拷贝到外部临时的存储单元中，加const修饰没有任何价值。同样对于基本数据类型的返回“引用传递”和“值传递”基本是等价的。
返回值不是基本数据类型是，将函数vector<int> function(vector<int> vec) 改写为vector<int>& function(vector<int> vec)的确能提高效率。此时要注意，函数是想返回一个对象的“拷贝”还是仅返回“别名”，否则程序会出错。这种以“引用传递”的方式常见于对象复制，比如：=重载的赋值运算符。<br>
class me
{
me & operator = (const me &you); // 赋值函数
};<br>
将赋值函数的返回值加const修饰，那么该返回值的内容不允许被改动.
#<b>3</b>.const 成员函数
任何不会修改数据成员的函数都应该声明为const类型。如果在编写const成员函数时，不慎修改了数据成员，或者调用了其它非const成员函数，编译失败，这将会提高程序的健壮性。<br>
class myStack<br>
{<br>
public:<br>
void push(int);<br>
int pop(void);<br>
int getCount(void) const; // const 成员函数<br>
private:<br>
int num;<br>
int data[100];<br>
};<br>
int myStack::getCount(void) const<br>
{<br>
++ num; // 编译错误，企图修改数据成员num,因为表达式必须是可修改的左值。<br>
pop();// 编译错误，企图调用非const函数，也就是pop含有不getCount不兼容的限定符const<br>
return num;<br>
}<br>
<b>Const函数的几点规则：</b>
1.const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数.<br>
2.const对象的成员是不可修改的,然而const对象通过指针维护的对象却是可以修改的.<br>
3.const成员函数不可以修改对象的数据,不管对象是否具有const性质.它在编译时,以是否修改成员数据为依据,进行检查.<br>
4.然而加上mutable修饰符的数据成员,对于任何情况下通过任何手段都可修改,自然此时的const成员函数是可以修改它的<br>
再具体的讲，就是类的成员函数有尾后const修饰的时候实际上是修饰this指向的对象，不能修改类中的数据其实就是一个表像。同时需要注意:如果一个const成员函数如果以引用的形式返回*this，那么它返回的类型就是一个常量引用。<br>