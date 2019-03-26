Write a C++ program named final.cpp. When you're done, upload the final.cpp file and press the Submit Quiz button to complete this part of the exam.

Your code must be done in accordance with the following plan.

Copy and paste the following abstract base class Person into your source file.

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
The Person class must be used “as is” and not be modified.

Derive two classes, CustomerServiceAgent and CollegeStudent from the given Person class using public inheritance. CustomerServiceAgent does not add new properties. CollegeStudent adds a new property called yearInSchool which can assume one of the values from the enum type CollegeYear = {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR}. Declare the enum type within the CollegeStudent class.

Derive two classes, CSStudent and BUSStudent, from the CollegeStudent class using public inheritance.

In the derived classes, write appropriate constructors and override the virtual function hello.

In the main function, create an array of pointers and initialize them with the following pointers.

new CustomerServiceAgent("Jacqueline")
new CollegeStudent("Jackson", CollegeStudent::FRESHMAN)
new CSStudent("Jack", CollegeStudent::SOPHOMORE)
new BUSStudent("Jacky", CollegeStudent::JUNIOR)
new BUSStudent("Joyce", CollegeStudent::SENIOR)
Write a range-based for loop to iterate through the array and use each pointer to call the hello virtual function.

Write another range-based for loop to delete the pointers returned by the new operations.

The output should be exactly the same as the following:

Hello, my name is Jacqueline.
I'm a customer service representative. How may I help you?
---
Hello, my name is Jackson.
I'm a college freshman.
---
Hello, my name is Jack.
I'm a college sophomore.
I'm a computer science major.
---
Hello, my name is Jacky.
I'm a college junior.
I'm a business major.
---
Hello, my name is Joyce.
I'm a college senior.
I'm a business major.
---
The grading criteria are the same as the labs. For one thing, make sure the lines are not too wide. If a statement is too long, split it into multiple lines and use proper indentations. You should try to limit the line width to about 80 characters for the ease of reading. Among other things, the grading will look at specific aspects such as the structure (every major step is clearly seen), documentation/comments, indentations, identifier naming of variables and constants, usage of named constants.

Note. An extra credit of 1 point will be added to this part if unique_ptr pointers are used successfully instead of using the raw pointers and the rest of requirements have been satisfied.
