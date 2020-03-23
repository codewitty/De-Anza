/*
Write a fragment of code that opens a file named numbers.txt, reads in pairs of number until end of file and sends the smaller of the two to a file named min.txt and the larger of the two to a file named max.txt (one number per line). You can assume there are no ties. (basic file input/output)
*/

ifstream inFile;
inFile.open("numbers.txt");
ofstream outFile1;
ofstream outFile2;
outFile1.open("max.txt");
outFile2.open("min.txt");
while(!inFile.eof()) {
    int value1 = 0;
    int value2 = 0;
    inFile >> value1 >> value2;
    if (value1 > value2) {
        outFile1 << value1 << endl;
        outFile2 << value2 << endl;
    }
    else if (value1 < value2) {
        outFile2 << value1 << endl;
        outFile1 << value2 << endl;
    }
}
