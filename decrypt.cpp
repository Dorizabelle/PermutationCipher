//Dorizabelle Northecide
//Software Development
//HW02
//September 30, 2020

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
// #include <sstream>
#include "decrypt.h"
using namespace std;

void decrypt(string inputFile, string outputFile)
{
        string line, decrypted;
        string blockSizeInput;
        int blockSize;
        int k;
        char e, t;
        string permutation;
        string input;

        std::cout << "Welcome to the Permutation Cipher \nSelected Mode: Decrypt \nInput File: " + inputFile + "\nOutput File: " + outputFile << endl;
        std::cout << "Please enter the block size (2-8) and the permutation (e.g., 4 2413): "
                  << "";
        std::cin >> blockSizeInput >> permutation;
        blockSize = std::stoi(blockSizeInput);
        // std::cout << blockSizeInput<< endl;
        // std::cout << permutation << endl;

        fstream myfile(inputFile, ios::in);
        if (myfile.is_open())
        {
                while (getline(myfile, line))
                {
                        //std::cout << line << endl;
                        decrypted = "";
                        for (int i = 0; i < line.length(); i = i + blockSize)
                        {
                                k = 0;

                                for (int j = i; j < i + blockSize; j++)
                                {
                                        int d = char(permutation[k++]) - 48;
                                        if ((i + d - 1) < line.length())
                                        {
                                                e = line[i + (d - 1)];
                                        }
                                        else
                                        {
                                                e = ' ';
                                        }

                                        if (j < line.length())
                                        {
                                                t = line[j];
                                        }
                                        else
                                        {
                                                t = ' ';
                                        }
                                        decrypted += e;
                                        // std::cout << to_string(j % blockSize) + " " + t + " " + to_string(d) + " " + e << " ,";
                                }
                                // std::cout << "." << endl;
                        }
                        std::cout << "decrypted ciphertext file: " + decrypted << endl;

                        //char buffer[] = decrypted;
                        ofstream myofile(outputFile, ios::out | ios::binary);
                        if (myofile.is_open())
                        {
                                //myofile.write(buffer, decrypted.length());
                                myofile << decrypted;
                                myofile.close();
                        }
                        else
                                std::cout << "Unable to open file" << endl;
                        //return 0;
                        
                }
                myfile.close();
        }
        else
                std::cout << "Unable to open file";
}
