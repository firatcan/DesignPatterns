#include<iostream>

using namespace std;

class SingletonPattern
{
	static SingletonPattern* instance;
	int data;
	SingletonPattern()
	{
		data = 5;
	}
public:
	static SingletonPattern* getInstance()
	{
		if (!instance)
		{
			instance = new SingletonPattern;
		}
		return instance;
	}
	int getData()
	{
		return this->data;
	}
	void setData(int data)
	{
		this->data = data;
	}
};
SingletonPattern* SingletonPattern::instance = 0;
int main()
{
	SingletonPattern* singleton = SingletonPattern::getInstance();
	cout << singleton->getData() << endl;
	singleton->setData(50);
	cout << singleton->getData() << endl;

	system("pause");
	return 0;
}