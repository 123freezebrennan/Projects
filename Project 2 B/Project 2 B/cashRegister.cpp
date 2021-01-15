#include "cashRegister.h"

cashRegister::cashRegister(){cashOnHand = 500;}
void cashRegister::acceptAmount(int cash_input){cashOnHand = cashOnHand + cash_input;}
cashRegister::cashRegister(int new_cash){cashOnHand = new_cash;}
int cashRegister::getCurrentBalance(){return cashOnHand;}