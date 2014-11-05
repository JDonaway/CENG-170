// This program produces a web page called wanted.html that lists all the 
// criminals in the criminals.txt file.
// Names: Josh Donaway and Adam Campbell

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Parse a line that looks like this:
// "Bruce McLarty|M|6'0"|999|Losing his Bible,Missing class,Unpaid parking tickets"
// and output the appropriate HTML to fout.
void FindName(ofstream &fout, string &line)
{
	int barLocation = line.find("|");
	int space;
	string name = line.substr(0, barLocation);
	string photoName = name;

	space = photoName.find(" ");
	photoName.erase(space, 1);
	photoName += ".jpg";
	fout << "<img src = \"" << photoName << "\" width = \"120\" height = \"150\">" << endl;
	fout << "<p>Name: <b>" << name << "</b>\n";

	line.erase(0, barLocation + 1); //erase name
}

void FindGender(ofstream &fout, string &line)
{
	string gender = line.substr(0, 1);
	int barLocation = line.find("|");

	if (gender == "M")
		fout << "<br>Gender: <b>Male</b>\n";
	else
		fout << "<br>Gender: <b>Female</b>\n";

	line.erase(0, barLocation + 1); // erase gender
}

void FindHeight(ofstream &fout, string &line)
{
	int barLocation = line.find("|"); // Find height
	string height = line.substr(0, barLocation);

	fout << "<br>Height: <b>" << height << "</b>\n";

	line.erase(0, barLocation + 1); //erase height
}

void FindAward(ofstream &fout, string &line)
{
	int barLocation = line.find("|"); // Find award
	string award = line.substr(0, barLocation);

	fout << "<br>Award: <b>$" << award << "</b>\n";

	line.erase(0, barLocation + 1);	//erase award
}

void FindCrimes(ofstream &fout, string &line)
{
	int comma;
	fout << "<br>Crimes:\n<ol>\n";
	do
	{
		//Look for the first comma
		comma = line.find(","); 

		//Pull out the string before the comma
		string crime = line.substr(0, comma); 

		//Output the crime
		fout << "  <li>" << crime << "</li>\n";

		//delete crime from line, repeat until EOS
		line.erase(0, comma + 1);

	} while (comma != string::npos);

	fout << "</ol>\n";
}

void PrintCriminal(ofstream &fout, string line)
{
	FindName(fout, line); // Get name
	FindGender(fout, line); // Get gender
	FindHeight(fout, line); // Get height
	FindCrimes(fout, line); // Get all crimes
}

void main()
{
	ifstream fin;
	ofstream fout;
	string line;

	// Open criminals.txt for input and wanted.html for output 
	fin.open("criminals.txt");
	fout.open("wanted.html");

	// Output "<h1>Wanted</h1>" to wanted.html
	fout << "<h1>Wanted</h1>\n<p>\n<hr>\n";

	getline(fin, line);

	// For each line in criminals.txt
	while (!fin.eof())
	{
		// Call PrintCriminal with the line
		PrintCriminal(fout, line);
		fout << "</p>";
		getline(fin, line);
	}
	// Close both files
	fout.close();
	fin.close();
}