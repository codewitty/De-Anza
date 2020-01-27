
#include <iostream> 
using namespace std; 
  
class Dollar 
{ 
private: 
    int whole, part; 
public: 
    Dollar(int r = 0, int i =0) 
    {  whole = r;   part = i; } 
    friend ostream & operator << (ostream &out, const Dollar &obj); 
    friend istream & operator >> (istream &in,  Dollar &obj); 
}; 
  
ostream & operator << (ostream &out, const Dollar &c) 
{ 
    out << c.whole; 
    out << "+i" << c.part << endl; 
    return out; 
} 
  
istream & operator >> (istream &in,  Dollar &c) 
{ 
    cout << "Enter Real Part "; 
    in >> c.whole; 
    cout << "Enter Imagenory Part "; 
    in >> c.part; 
    return in; 
} 
  
int main() 
{ 
   Dollar c1; 
   cin >> c1; 
   cout << "The complex object is "; 
   cout << c1; 
   return 0; 
}
