/**
 PART B:
 
 A movie theater keeps 20 percent of the gross box office profit.  The remainder goes to the
 movie distributor. Write a program that calculates a theater’s gross and net box office profit
 for a night and one movie. The price of an adult ticket is $10.00 and a child’s ticket is
 $6.00. The program asks for the name of the movie, and how many adult and child tickets were
 sold, calculates the gross box office profit, the net box office profit, the amount paid to
 the distributor, and displays a report.
 
Name : Joshua Nelson Gomes
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int	main(void)
{
	double const	a_tx = 10.00;
	double const	c_tx = 6.00;
	int	no_a_tx;
	int	no_c_tx;
	double	bo_gr_pr;
	double	bo_net_pr;
	double	dist_pmt;
	string	movieName;

	cout << "What movie did you enjoy today?\n";
	getline (cin, movieName);
	cout << "\nHow many childrens' tickets were sold?\n";
	cin >> no_c_tx;
	cout << "\nHow many adults' tickets were sold?\n";	
	cin >> no_a_tx;
	bo_gr_pr = (a_tx * no_a_tx) + (c_tx * no_c_tx);
	bo_net_pr = bo_gr_pr * 0.2;
	dist_pmt = bo_gr_pr * 0.8;

	cout << setprecision(2) << fixed;
	cout << "\nMovie Name: "  << setw(17) << right << "\"" << movieName << "\"";
	cout << "\nAdult Tickets (" << setw(3) << no_a_tx << "):" << setw(15) << right << "$" << setw(9) << right << a_tx * no_a_tx;
	cout << "\nChild Tickets (" << setw(3) << no_c_tx << "):" << setw(15)<< right << "$"  << setw(9) << right << c_tx * no_c_tx;
	cout << "\nGross Box Office Profit: " << setw(10) << right <<"$"  << setw(9) << right << bo_gr_pr;
	cout << "\nNet Box Office Profit: " << setw(12) << right <<"$"  << setw(9) << right << bo_net_pr;
	cout << "\nAmount Paid to Distributor: "  << setw(7) << right <<"$"  << setw(9) << right << dist_pmt << endl;
	return (0);
} 
/***********************************************************************

Movie Name:                 "Star Wars: The Force Awakens"
Adult Tickets (382):              $  3820.00
Child Tickets (127):              $   762.00
Gross Box Office Profit:          $  4582.00
Net Box Office Profit:            $   916.40
Amount Paid to Distributor:       $  3665.60


*/


/***********************************************************************

Movie Name:                 "The Good Dinosaur"
Adult Tickets (100):              $  1000.00
Child Tickets (200):              $  1200.00
Gross Box Office Profit:          $  2200.00
Net Box Office Profit:            $   440.00
Amount Paid to Distributor:       $  1760.00

*/
