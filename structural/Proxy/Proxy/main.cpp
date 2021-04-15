#include<iostream>
using namespace std;

class Subject {
public:
	virtual void Request() const = 0;
};

class RealSubject : public Subject {
public:
	void Request()const override {
		cout << "RealSubject: Handling request." << endl;
	}
};

class Proxy : public Subject {
private:
	RealSubject* realSubject;
	bool checkAccess() const {
		cout << "Proxy: Checking access prior to firing a real request." << endl;
		return true;
	}
	void logAccess() const {
		cout << "Proxy: Logging the time of request." << endl;
	}
public:
	Proxy(RealSubject *realSubject_): realSubject(new RealSubject(*realSubject_)){}
	~Proxy() {
		delete realSubject;
	}
	void Request() const override {
		if (this->checkAccess()) {
			this->realSubject->Request();
			this->logAccess();
		}
	}
};
void ClientCode(const Subject& subject) {
	subject.Request();
}

void main() {
	std::cout << "Client: Executing the client code with a real subject:\n";
	RealSubject* real_subject = new RealSubject;
	ClientCode(*real_subject);
	std::cout << "\n";
	std::cout << "Client: Executing the same client code with a proxy:\n";
	Proxy* proxy = new Proxy(real_subject);
	ClientCode(*proxy);

	delete real_subject;
	delete proxy;
	system("pause");
}