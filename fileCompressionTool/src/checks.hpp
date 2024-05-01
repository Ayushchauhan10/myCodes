#include <iostream>
#include <fstream>
using namespace std;


bool allGood(const string& fileName);
bool fileExist(const string& fileName);
bool isTextFile(const string& fileName);
bool isFileLocked(const string& fileName);

bool allGood(const string& fileName){

    if(!fileExist(fileName))
    {
        cerr<<"Error:";
        return 0;
    }

    if(!isTextFile(fileName))
    {
        cout<<"Error:";
        return 0;
    }

    // if(isFileLocked(fileName))
    // {
    //     cerr<<"Error:";
    //     return 0;
    // }

    return 1;
    
}

bool fileExist(const string& fileName){
    ifstream file(fileName);
    return file.good();
}
bool isTextFile(const string& fileName){
    int size=fileName.size();
    if(size>=4)
    {
        string compare = fileName.substr(size - 4);
        return compare==".txt";
    }
    return 0;
}

// bool isFileLocked(const string& fileName){

// }


