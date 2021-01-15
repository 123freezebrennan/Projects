class cashRegister{
public:
	cashRegister(); 
	cashRegister(int cashIn);
	int getCurrentBalance();
	void acceptAmount(int amountIn);
private:
	int cashOnHand;
};