// This program allows users to vote for their favorite soft drink.
// The program determines which soft drinks wins based on the number
// of votes each drink received.

#include <iostream>
using namespace std;

int Choice(char vote)						// Keep reading votes until Q is entered
{	
	int coke_votes = 0, pepsi_votes = 0, dr_pepper_votes = 0;
	cout << "Enter your vote for Pepsi, Coke, or Dr. Pepper (p/c/d): ";
	cin >> vote;


	while (vote != 'q' && vote != 'Q')
	{
		
		if (vote == 'P' || vote == 'p')
			pepsi_votes++;
		else if (vote == 'C' || vote == 'c')
			coke_votes++;
		else if (vote == 'D' || vote == 'd')
			dr_pepper_votes++;
		else
			cout << "Please ented p, c, or d.\n";

		cout << "Enter your vote for Pepsi, Coke, or Dr. Pepper (p/c/d): ";
		cin >> vote;
		
	}
	return pepsi_votes, coke_votes, dr_pepper_votes;
}



void main()
{
	char vote;
	int pepsi_votes=0, coke_votes=0, dr_pepper_votes=0;
	
	cout << "Enter your vote for Pepsi, Coke, or Dr. Pepper (p/c/d): ";
	cin >> vote;

	Choice(vote);

	cout << pepsi_votes << " " << coke_votes << " " << dr_pepper_votes;

	/*cout << "\nTotal votes:\nPepsi = " << pepsi_votes << "\nCoke = " <<
		coke_votes << "\nDr. Pepper = " << dr_pepper_votes << endl << endl;

	if (pepsi_votes == coke_votes && pepsi_votes == dr_pepper_votes)
		cout << "Pepsi, Coke, and Dr. Pepper tie.\n";
	else if (pepsi_votes > coke_votes && pepsi_votes > dr_pepper_votes)
		cout << "Pepsi won.\n";
	else if (coke_votes > pepsi_votes && coke_votes > dr_pepper_votes)
		cout << "Coke won.\n";
	else if (dr_pepper_votes > coke_votes && dr_pepper_votes > pepsi_votes)
		cout << "Dr. Pepper won.\n";
	else if (pepsi_votes == dr_pepper_votes)
		cout << "Pepsi and Dr. Pepper tied.\n";
	else if (pepsi_votes == coke_votes)
		cout << "Pepsi and Coke tied.\n";
	else
		cout << "Coke and Dr. Pepper tied.\n";*/

}