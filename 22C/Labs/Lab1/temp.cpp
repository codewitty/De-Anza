void	removeMoney(Wallet &myWallet)
{
	bool loop = true;
	
	while(loop)
	{
		int choice = 0;
		int wcurrency = 0;
		int p_currency = 0;
		
		cout 	<< "What currency would you like to remove today?"
			<< endl
			<< "1: Dollars" << endl;
       			<< "2: Pounds" << endl;
       			<< "3: Yen" << endl;
       			<< "4: Rupee" << endl;
			<< "5: Yuan" << endl;
       			<< "6: EXIT" << endl;
       			<< "Enter your Selection" << endl;
		cin << choice;
		switch (choice)
		{
			case 1:
				cout	<< "How many dollars would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many cents would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::DOLLAR, currency);
           			break;
			case 2:
				cout	<< "How many pounds would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many pence would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::POUND, currency);
           			break;
			case 3:
				cout	<< "How many Yen would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many sen would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::YEN, currency);
           			break;
		
			case 4:
				cout	<< "How many Rupees would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many paise would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::RUPEE, currency);
           			break;

			case 5:
				cout	<< "How many Yuan would you like to remove?"
					<< endl;
				cin 	>> wcurrency;	 
				cout	<< "How many fen would you like to remove?"
					<< " (Between 1-99)" << endl;
				cin	>> p_currency;
				while (p_currency < 0 || p_currency > 99)
				{
					cout	<< "please enter a valid value"
						<< "between 1-99" << endl;
					cin >> p_currency;
				}
				
				myWallet.removeMoney(Wallet::YUAN, currency);
           			break;
	
			case 6:
				loop = true;
				break;

			default:
				cout 	<< "Please enter a valid choice between"
					<< " 1-6" << endl;
				break;
		}
	}
}
