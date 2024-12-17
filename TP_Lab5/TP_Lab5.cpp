// TP_Lab5.cpp: определяет точку входа для приложения.
//

#include "Proxy.h"
#include "Bridge.h"
#include "Adapter.h"

int main()
{
	//Proxy
	/*BankAccount* account = new BankAccountProxy(2000, "passWord");
	account->deposit(1000);
	account->withdraw(500);
	std::cout << account->getBalance() << std::endl;

	delete account;*/

	//Bridge
	TV* samsung = new SamsungTV();
	TV* sony = new SonyTV();

	RemoteControl* basicRemote = new BasicRemoteControl(samsung);
	RemoteControl* advancedRemote = new AdvancedRemoteControl(sony);

	basicRemote->turnOn();
	basicRemote->turnOn();
	basicRemote->turnOff();
	basicRemote->turnOff();
	basicRemote->setChannel(33);

	advancedRemote->turnOff();
	advancedRemote->turnOn();
	advancedRemote->setChannel(5);

	delete samsung;
	delete sony;
	delete basicRemote;
	delete advancedRemote;


	//adapter

	OldLogger* oldLogger = new OldLogger();
	Logger* newLogger = new NewLogger();
	Logger* adapter = new OldLoggerAdapter(oldLogger);

	newLogger->log("This is a new log message.");
	adapter->log("This is an old log message adapted to the new system.");

	delete oldLogger;
	delete newLogger;
	delete adapter;
}
