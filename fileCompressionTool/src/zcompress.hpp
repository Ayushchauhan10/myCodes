#ifndef ZCOMPRESS_H
#define ZCOMPRESS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "huffman.hpp"
#include <zlib.h>

const size_t chunk_size=409600;

using namespace std;

bool compressFile(const string& fileName);
bool compressFile(const string& fileName){
    ifstream file(fileName, ios::binary);

    if (!file.is_open()) {
        cerr << "Error: Failed to open input file: '" << fileName << "'" << endl;
        return false;
    }

    ofstream outputFile(fileName + ".compressed", ios::binary); 

    if (!outputFile.is_open()) {
        cerr << "Error: Failed to create output file: " << fileName + ".compressed" << "'" << endl;
        file.close(); 
        return false;
    }

}

#endif //ZCOMPRESS_H