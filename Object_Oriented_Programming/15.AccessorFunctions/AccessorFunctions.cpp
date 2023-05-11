#include <iostream>
#include <string>

class BankAccount {
private:
  // TODO: declare member variables
  std::string accountName;
  int accountNumber;
  int accountFunds;

public:
  BankAccount(std::string accName, int accNum, int funds)
      : accountName(accName), accountNumber(accNum), accountFunds(funds) {}
  // TODO: declare setters
  void setName(std::string name);
  void setNum(int num);
  void setFunds(int funds);
  // TODO: declare getters
  std::string getName() const;
  int getNum() const;
  int getFunds() const;
};

// TODO: implement setters
void BankAccount::setName(std::string name) { accountName = name; }
void BankAccount::setNum(int num) { accountNumber = num; }
void BankAccount::setFunds(int funds) {
  std::cout << "test"
            << "\n";
  accountFunds = funds;
}
// TODO: implement getters
std::string BankAccount::getName() const { return accountName; }
int BankAccount::getNum() const { return accountNumber; }
int BankAccount::getFunds() const { return accountFunds; }
int main() {
  // TODO: instantiate and output a bank account
  BankAccount exampleAccount("Test", 10, 1000);
  std::cout << exampleAccount.getName() << " " << exampleAccount.getNum() << " "
            << exampleAccount.getFunds() << "\n";
  exampleAccount.setName("Test 2");
  exampleAccount.setFunds(25345);
  std::cout << exampleAccount.getName() << " " << exampleAccount.getNum() << " "
            << exampleAccount.getFunds() << "\n";
}