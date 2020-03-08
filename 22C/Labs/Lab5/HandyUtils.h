#pragma once
#include <iostream>
#include <string>
using namespace std;

// Forward Declarations
void DeleteEmptyLines(string &Path);
string trim(string s);
string ltrim(string s);
string rtrim(string s);
const string WHITESPACE = " \n\r\t\f\v";
const int ARRAY_SIZE{ 20 };

void DeleteEmptyLines(string &Path)
{
	ifstream in(Path);
	string line, text;
	while (std::getline(in, line))
		if (!(line.empty() || line.find_first_not_of(' ') == std::string::npos))
			text += line + "\n";
	in.close();
	ofstream out(Path);
	out << text;
}


string ltrim(string s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == string::npos) ? "" : s.substr(start);
}

string rtrim(string s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(string s)
{
	return rtrim(ltrim(s));
}


