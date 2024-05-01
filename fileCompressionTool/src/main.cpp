#include<iostream>
#include <string>
#include "checks.hpp"
// #include "zcompress.hpp"
#include "compress.hpp"

using namespace std;

int main(int argc, char* argv[]){
     
     if(argc <3 )
     {
        cerr<<"Error: Command not found"<<endl;
        return 1; // 1 is returned in case of unsuccessful completion like error etc.
     }
    string operation=argv[1];
    string fileName=argv[2];

    if(!allGood(fileName))
        return 1;

    if(operation=="compress")
    {
        if(!compressFile(fileName))
        {
            cerr<<"Error: Compressing "<<fileName<<" failed!!"<<endl;
            return 1;
        }
        cout<<fileName<<" compressed sucessfully" <<endl;
    }else if(operation=="decompress")
    {
        cout<<"In decomrpess"<<endl;
    }
    else{
        cerr<<"Error: Invalid operation!!"<<endl;
        return 1;
    }
       
 
    return 0;
}