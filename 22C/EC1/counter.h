class Counter
{
    private:
        int counter;
        int limit;
        static int nCounters;
    public:
        Counter(int ba, int ab);
        void increment();
        void decrement();
        int getValue();
        static int getNCounters();
};
