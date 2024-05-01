#ifndef COMPRESS_H
#define COMPRESS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "lz77.hpp"
#include "huffman.hpp"

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


    try {
        vector<char> buffer(chunk_size);
        int c=0;
        while (true) {
            file.read(buffer.data(), chunk_size);
            size_t bytes_read = file.gcount();
            c++;

            if (bytes_read > 0) {
                size_t lastLine = bytes_read;

                for (size_t i = 0; i < bytes_read; i++) 
                   if (buffer[i] == '\n') 
                        lastLine = i;

                if (lastLine < bytes_read && !file.eof()) {
                    file.seekg(lastLine - bytes_read + 1, ios::cur);
                    bytes_read = lastLine + 1;
                }

                compressData(buffer,bytes_read,outputFile);

                // outputFile.write(buffer.data(), bytes_read);
                // cout<<"Buffer No: "<<c<<endl;
                // for(auto x:buffer)
                //    cout<<x<<" ";
                //  cout<<endl;  
            } 
            else break;
        }

        cout<<c<<endl;

        return true;
    } catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        outputFile.close();
        file.close();
        remove((fileName + ".compressed").c_str()); 
        return false;
    }

        return true;
    
}



    
//     try
//     {
//     // cout<<"1"<<endl;
//         vector<char>buffer(chunk_size);
//         // for (int i = 0; i < buffer.size(); i++)
//         // {
//         //     cout<<buffer[i]<<": ";
//         // }
//             cout<<"13 "<<endl;
//         long long c=0;

//         // while (!file.eof()) {
//         //     file.read(buffer.data(), chunk_size);
//         //     // cout<<"2 ";
//         //     size_t bytes_read=file.gcount();
//         //     size_t lastLine=bytes_read;
//         //     for(int i=0;i<bytes_read;i++){
//         //         // outputFile<<buffer[i]<<" bkjdbck ";
//         //         if(buffer[i]=='\n') lastLine=i;
//         //     }

//         //     if(lastLine <bytes_read && lastLine!= string::npos)    
//         //     {
//         //         file.seekg(bytes_read-lastLine+1,ios::cur);
//         //         bytes_read = lastLine + 1;
//         //     }

//         //     // compressData(buffer,bytes_read,outputFile);
//         //     // cout<<"This is buffer "<<endl;
//         //     // for(auto x:buffer)
//         //     //  cout<<x<<" ";
//         //     //  cout<<endl;
//         //      c++;

//         // }
//         while (!file.eof()) {
//     file.read(buffer.data(), chunk_size);
//     size_t bytes_read = file.gcount();

//     // Check if any bytes were read
//     if (bytes_read > 0) {
//         size_t lastLine = bytes_read;

//         // Find the position of the last newline character
//         for (size_t i = 0; i < bytes_read; i++) {
//             if (buffer[i] == '\n') {
//                 lastLine = i;
//             }
//         }

//         // If a newline character was found within the buffer, adjust the read position
//         if (lastLine < bytes_read) {
//             file.seekg(bytes_read - lastLine + 1, ios::cur);
//             bytes_read = lastLine + 1;
//         }

//         // Process the buffer (e.g., compressData(buffer, bytes_read, outputFile))
//     }
//     c++;
// }
            
//              cout<<c<<" : ";


//         return 1;
//     }
//     catch(const exception& e)
//     {
//         cerr << e.what() << '\n';
//         outputFile.close(); 
//         file.close();
//         remove((fileName + ".compressed").c_str()); 
//         return false;
#endif // COMPRESS_H