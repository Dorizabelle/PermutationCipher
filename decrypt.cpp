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
        int index, lineCounter = 0;
        char decryptChar, decryptText;
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
                                index = 0;

                                for (int j = i; j < i + blockSize; j++)
                                {
                                        int permIndex = char(permutation[index++]) - 48;
                                        if ((i + permIndex - 1) < line.length())
                                        {
                                                decryptChar= line[i + (permIndex - 1)];
                                        }
                                        else
                                        {
                                                decryptChar = 'x';
                                        }

                                        if (j < line.length())
                                        {
                                                decryptText = line[j];
                                        }
                                        else
                                        {
                                                decryptText = 'x';
                                        }
                                        decrypted += decryptChar;
                                        // std::cout << to_string(j % blockSize) + " " + t + " " + to_string(permIndex) + " " + e << " ,";
                                }
                                // std::cout << "." << endl;
                        }
                        int trimLine = 0;
                        for (int i = decrypted.length()-1; i > 0 ; i--) {
                                //std::cout << i << endl;
                                if (decrypted[i]=='x') {
                                        trimLine++;
                                        //std::cout << "trimLine: " + to_string(trimLine) << endl;

                                } else {
                                        decrypted.erase(decrypted.length()-trimLine);
                                        break;
                                }
                        }
                        std::cout << "decrypted ciphertext file: " + decrypted << endl;

                        //char buffer[] = decrypted;
                        //ofstream myofile(outputFile, (lineCounter++>0) ? std::ios::app : std::ios::out | std::ios::binary);
                        ofstream myofile(outputFile, std::ios::out | std::ios::binary);

                        if (myofile.is_open())
                        {
                                //myofile.write(buffer, decrypted.length());
                                myofile << decrypted << endl;
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
