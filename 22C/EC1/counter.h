class Counter
{
    private:
        int counter;
        int limit;
        static int nCounters;
    public:
        Counter(int ba, int ab);	//Constructor
        void increment();		//Increment function
        void decrement();		//Decrement function
        int getValue();			//Get Value function
        static int getNCounters();	//Get nCounters function
};
