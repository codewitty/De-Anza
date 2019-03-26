
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//class definition
// Person is an abstract base class.
class Person {
private:
	string myName;   // Name of this person
public:
	Person(string name) : myName(name) {}
	// A pure virtual function with a function body
	virtual void hello() const = 0 {
		cout << "Hello, my name is " << myName
		     << ". ";
	}
};
//Derived Class CustomerServiceAgent
class CustomerServiceAgent : public Person{
public:
    virtual void hello() const override {
    cout    << "Hello, my name is " << myName
            << "I'm a customer service representative. How may I help you?"
		     << endl;
};

//Derived Class College Student
class CollegeStudent : public Person{
public:
    enum CollegeYear {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};
    CollegeYear yearInSchool;
    virtual void hello() const override {
    cout    << "Hello, my name is " << myName
            << "I'm a college" << CollegeStudent.CollegeYear
		     << endl;

};
//Derived class CSStudent
class CSStudent : public CollegeStudent{
public:
    virtual void hello() const override {
    cout    << "Hello, my name is " << myName
            << "I'm a college" << CollegeStudent.CollegeYear
            << endl
            << I'm a computer science major."
            << endl;
}

//Derived class BUSStudent
class BUSStudent : public CollegeStudent{
public:
    virtual void hello() const override {
    cout    << "Hello, my name is " << myName
            << "I'm a college" << CollegeStudent.CollegeYear
            << endl
            << I'm a business major."
            << endl;
}

int main() {

//array of pointers
arrPtr = new *Person[];

Person[] = {new CustomerServiceAgent("Jacqueline")
new CollegeStudent("Jackson", CollegeStudent::FRESHMAN)
new CSStudent("Jack", CollegeStudent::SOPHOMORE)
new BUSStudent("Jacky", CollegeStudent::JUNIOR)
new BUSStudent("Joyce", CollegeStudent::SENIOR)};

}

};
