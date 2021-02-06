#include<iostream>
using namespace std;

class Vehicle
{
public:
	virtual void printVehicle() = 0;
};
class TwoWheeler :public Vehicle
{
public:
	void printVehicle()
	{
		cout << "I am two wheeler" << endl;
	}
};
class FourWheeler : public Vehicle
{
public:
	void printVehicle()
	{
		cout << "I am four wheeler" << endl;
	}
};
class Client
{
private:
	Vehicle* pVehicle;
public:
	Client(int type)
	{
		if (type == 1)
			pVehicle = new TwoWheeler();
		else if (type == 2)
			pVehicle = new FourWheeler();
		else
			pVehicle = NULL;
	}
	~Client()
	{
		if (pVehicle)
		{
			delete[] pVehicle;
			pVehicle = NULL;
		}
	}
	Vehicle* getVehicle()
	{
		return pVehicle;
	}
};

int main()
{
	Client* pClient = new Client(2);//1 = two wheeler, 2 = four wheeler
	Vehicle* pVehicle = pClient->getVehicle();
	if (pVehicle != NULL)
		pVehicle->printVehicle();
	else
		cout << "No car" << endl;
	system("pause");
	return 0;
}