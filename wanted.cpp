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
void PrintCriminal(ofstream &fout, string line)
{
	int barLocation = line.find("|");
	int comma;
	int space;
	string name = line.substr(0, barLocation);
	string photoName = name;

	space = photoName.find(" ");
	photoName.erase(space, 1);
	photoName += ".jpg";
	fout << "<img src = \"" << photoName << "\" width = \"120\" height = \"150\">" << endl;

	fout << "<p>Name: <b>" << name << "</b>\n";

	//erase name
	line.erase(0, barLocation + 1);

	//get gender
	string gender = line.substr(0, 1);

	if (gender == "M")
	{
		fout << "<br>Gender: <b>Male</b>\n";
	}
	else
	{
		fout << "<br>Gender: <b>Female</b>\n";
	}

	barLocation = line.find("|");

	//erase gender
	line.erase(0, barLocation + 1);

	barLocation = line.find("|");
	string height = line.substr(0, barLocation);
	fout << "<br>Height: <b>" << height << "</b>\n";

	//erase height
	line.erase(0, barLocation + 1);

	barLocation = line.find("|");
	string award = line.substr(0, barLocation);
	fout << "<br>Award: <b>$" << award << "</b>\n";

	//erase award
	line.erase(0, barLocation + 1);

	fout << "<br>Crimes:\n<ol>\n";

	do
	{
		comma = line.find(","); 	//Look for the first comma

		string crime = line.substr(0, comma); 	//Pull out the string before the comma

		//Output the crime
		fout << "  <li>" << crime << "</li>\n";

		//erase this crime
		line.erase(0, comma + 1);

	} while (comma != string::npos);

	fout << "</ol>\n";

	//delete crime from line, repeat until EOS
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
		//Call PrintCriminal with the line
		PrintCriminal(fout, line);
		fout << "</p>";
		getline(fin, line);
	}

	// Close both files
	fout.close();
	fin.close();
}