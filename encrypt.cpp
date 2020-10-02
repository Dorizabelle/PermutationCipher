//Dorizabelle Northecide
//Software Development
//HW02
//September 30, 2020

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
// #include <sstream>
#include "encrypt.h"
using namespace std;

void encrypt(string inputFile, string outputFile)
{
        string line, encrypted;
        string blockSizeInput;
        int blockSize;
        int index, lineCounter = 0;
        char encryptChar, encryptText;
        string permutation;
        string input;

        std::cout << "Welcome to the Permutation Cipher \nSelected Mode: Encrypt \nInput File: " + inputFile + "\nOutput File: " + outputFile << endl;
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
                        encrypted = "";
                        lineCounter++;
                        for (int i = 0; i < line.length(); i = i + blockSize)
                        {
                                index = 0;

                                for (int j = i; j < i + blockSize; j++)
                                {
                                        int permIndex = char(permutation[index++]) - 48;
                                        if ((i + permIndex - 1) < line.length())
                                        {
                                                encryptChar = line[i + (permIndex - 1)];
                                        }
                                        else
                                        {
                                                encryptChar = 'x';
                                        }

                                        if (j < line.length())
                                        {
                                                encryptText = line[j];
                                        }
                                        else
                                        {
                                                encryptText = 'x';
                                        }
                                        encrypted += encryptChar;
                                        // std::cout << to_string(j % blockSize) + " " + t + " " + to_string(permIndex) + " " + e << " ,";
                                }
                                // std::cout << "." << endl;
                        }
                        std::cout << "Encrypted ciphertext file: " + encrypted << endl;

                        //char buffer[] = encrypted;
                        //std::cout << lineCounter << " ";
                        //ofstream myofile(outputFile, (lineCounter++>1) ? std::ios::app : std::ios::out | std::ios::binary); //if multiple lines
                        ofstream myofile(outputFile, std::ios::out | std::ios::binary); //if multiple lines
                        if (myofile.is_open())
                        {
                                //myofile.write(buffer, encrypted.length());
                                myofile << encrypted << endl;
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
