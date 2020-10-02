//Dorizabelle Northecide
//Software Development
//HW02
//September 30, 2020

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include "encrypt.h"
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
	string line,encrypted;
	int blockSize = 4;
	int k;
	char e,t;
	
	
	string permutation = "2143";

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
		fstream myfile("PlaintextFile.txt", ios::in);
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << endl;
				encrypted="";
				for(int i = 0; i < line.length(); i=i+blockSize)
				{
				//	cout << to_string(i) + " " + line[i] << endl;
					k=0;
				
					for(int j = i; j < i+blockSize; j++)
					{
						int d = char(permutation[k++])-48;
						if ((i+d-1)<line.length())
						{
							e=line[i+(d-1)];
						}
						else
						{
							e='x';
						}
						
						if (j<line.length())
						{
							t=line[j];
						}
						else
						{
							t='x';
						}
						encrypted += e;
						cout << to_string(j%blockSize) + " " + t + " " + to_string(d) + " " + e << " ,";
					}
					cout << "." << endl;
 				} 
				cout << "Encrypted ciphertext file: " + encrypted << endl;
			}
			myfile.close();
		}
		else 
			cout << "Unable to open file";
	}
	return 0;
}
