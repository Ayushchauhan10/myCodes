#ifndef LZ77_H
#define LZ77_H

#include <iostream>
#include <vector>
#include <fstream>
#define windowSize 51200
#define searchBuffer 46080
#define lookAheadBuffer 5120

using namespace std;

void compressData(const vector<char>&buffer,const size_t size,ofstream& outputFile);

class Token{

    public:
        size_t offset;
        size_t length;
        char codeWord;
        Token()
        {

        }
        Token(size_t offset,size_t length,char codeWord){
            this->offset=offset;
            this->length=length;
            this->codeWord=codeWord;
        }
        size_t getOffset() const {
            return offset;
        }

        size_t getLength() const {
            return length;
        }

        char getCodeWord() const {
            return codeWord;
        }

};
int counter = 0;   
void compressData(const vector<char>& buffer, const size_t size, ofstream& outputFile) {


    int bufferLength = size;
    int final_size = bufferLength - lookAheadBuffer + 1;
    int position = 0;
    int count=0;
    while (position < bufferLength)
    {
        Token token(0,0,buffer[position]);

        int max_offset = (position - searchBuffer) < 0 ? position : searchBuffer;
      

        int max_search_length = (position + lookAheadBuffer) > bufferLength ? bufferLength - position : lookAheadBuffer;


        for (int offset = 1; offset <= max_offset; offset++)
        {
            int len = 0;
            while (len < max_search_length && buffer[position - offset + len] == buffer[position + len])
            {
                len++;
            }
          

            if (len > token.length)
            {
                token.offset = offset;
                token.length = len;
                token.codeWord = buffer[position + len];
            }
        }
        // if(token.codeWord=='\0')
        //  token.codeWord=' ';

        outputFile<<token.offset<<" "<<token.length<<" "<<token.codeWord<<" " ;
        position += token.length + 1;
        count+=5;
    }   

    cout<<"Count: "<<count<<endl;   
}



#endif //LZ77_H