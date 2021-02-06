#include<iostream>
#include<vector>
using namespace std;

class Product1
{
public:
	vector<string> parts_;
	void ListParts()const 
	{
		cout << "Products parts : ";
		for (int i = 0; i < parts_.size(); i++)
		{
			if (parts_[i] == parts_.back())
				cout << parts_[i];
			else
				cout << parts_[i] << ",";
		}
		cout << endl << endl;
	}
};

class Builder 
{
public:
	virtual ~Builder(){}
	virtual void ProducePartA() const = 0;
	virtual void ProducePartB() const = 0;
	virtual void ProducePartC() const = 0;
};

class ConcreteBuilder1 :public Builder
{
private: 
	Product1* product;
public:
	void Reset()
	{
		this->product = new Product1();
	}
	ConcreteBuilder1()
	{
		this->Reset();
	}
	~ConcreteBuilder1()
	{
		delete product;
	}
	void ProducePartA() const override
	{
		this->product->parts_.push_back("PartA1");
	}
	void ProducePartB() const override
	{
		this->product->parts_.push_back("PartB1");
	}
	void ProducePartC() const override
	{
		this->product->parts_.push_back("PartC1");
	}
	Product1* getProduct()
	{
		Product1* result = this->product;
		this->Reset();
		return result;
	}
};
class Director
{
private:
	Builder* builder;
public:
	void setBuilder(Builder* builder)
	{
		this->builder = builder;
	}
	void BuildMinimalViableProduct()
	{
		this->builder->ProducePartA();
	}
	void BuildFullFeaturedProduct()
	{
		this->builder->ProducePartA();
		this->builder->ProducePartB();
		this->builder->ProducePartC();
	}
};

void ClientCode(Director& director)
{
	ConcreteBuilder1* builder = new ConcreteBuilder1();
	director.setBuilder(builder);
	cout << "Standard basic product" << endl;
	director.BuildMinimalViableProduct();

	Product1* p = builder->getProduct();
	p->ListParts();
	delete p;

	cout << "Standard full featured product:" << endl;
	director.BuildFullFeaturedProduct();
	p = builder->getProduct();
	p->ListParts();
	delete p;

	cout << "Custom product: " << endl;
	builder->ProducePartA();
	builder->ProducePartC();
	p = builder->getProduct();
	p->ListParts();
	delete p;

	delete builder;
}

int main()
{
	Director* director = new Director();
	ClientCode(*director);
	delete director;
	system("pause");
	return 0;
}