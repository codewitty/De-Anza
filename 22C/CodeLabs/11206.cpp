class SavingsAccount : public BankAccount {
	private:
		double interestRate;
		int interestType;
	public:		
			
		SavingsAccount(double rate, string type); 
		
		double	getInterestRate();
		int getInterestType();

};

SavingsAccount::SavingsAccount(double rate, string type) {
    interestRate = rate;
}

double	SavingsAccount::getInterestRate() {
    return interestRate;
}

int getInterestType() {
    char t[] = type;
    if (strcmp (t, "Simple") == 0)
        return 1;
    else
        return 2;
}

