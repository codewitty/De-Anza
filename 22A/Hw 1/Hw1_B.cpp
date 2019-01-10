/**~*~*
   This program asks the user to enter a number, it performs some calculations,
   and displays the results. Run the program twice. First enter an even number,
   then enter an odd number. What do you notice? Write your answer below.
 
 Name: Joshua Nelson Gomes
 IDE:  iTerm/Vim
 Date: 10/01/2018

*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    int half_i, twice;
    double half_d;

    cout << "Hi there" << endl;
    cout << "Please input a number and then hit return" << endl;
    cin  >> number;

    twice = number * 2;
    half_i = number / 2;
    half_d = number / 2.0;
 
    cout << "Double of your number is " << twice << endl;
    cout << "Half of your number is " << half_i << endl;
    cout << "Half of your number is " << half_d << endl;
   
    return 0;
}
/**~*~*
 Hi there
 Please input a number and then hit return
 98
 Double of your number is 196
 Half of your number is 49
 Half of your number is 49
 
 Hi there
 Please input a number and then hit return
 43
 Double of your number is 86
 Half of your number is 21
 Half of your number is 21.5
 
 I noticed the program returning three lines. The first printed double my input number. The second and third printed half my input number. However, for odd numbers, the second line was an approximate half while the third line was more accurate.
*/
