//Dorizabelle Northecide
//Software Development
//HW02
//September 30, 2020

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "encrypt.h"
#include "decrypt.h"
using namespace std;

int main(int argc, char **argv)
{
	char opt;
	string inputFile;
	string outputFile;
	int eflag, dflag, iflag, oflag;

	eflag = 0;
	dflag = 0;
	iflag = 0;
	oflag = 0;
	

	while ((opt = getopt(argc, argv, "i:o:ed")) != -1)
	{
		switch (opt)
		{
		case 'i':
			iflag = 1;
			inputFile = optarg;
			break;
		case 'o':
			oflag = 1;
			outputFile = optarg;
			break;
		case 'e':
			eflag = 1;
			break;
		case 'd':
			dflag = 1;
			break;
		default:
			cout << "Unknown option" << argv[0] << endl;
		}
	}

	if (argc != 6 || (iflag == 0) || (oflag == 0) ||
		(eflag == dflag))
	{
		cout << "Usage: ./PermCipher option -i InputFileName -o OutputFileName \nOptions: -e Encrypt \n\t -d Decrypt" << endl;
	}
	else
	{
		if (eflag == 1)
		{
			encrypt(inputFile, outputFile); 
		}
		
		if (dflag == 1)
		{
			decrypt(inputFile, outputFile); 
		}
		
	}	
	return 0;
}
