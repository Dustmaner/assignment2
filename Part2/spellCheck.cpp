#include "spellCheck.h"

using namespace std;

spellCheck::spellCheck()
{

}

spellCheck::~spellCheck()
{
//    delete dictionary;
}

void spellCheck::dictFromFile(HashTable &dictionary)
{
    char word [20];
    string inWord;

    ifstream myFile;

    myFile.open("dict.txt", ifstream::in);

    if(myFile.is_open())
    {
        while(myFile.good())
        {
        getline(myFile, inWord);
            strcpy(word, inWord.c_str());
            strcat(word, "\0");
            dictionary.insert(word);
        }
    }
    myFile.close();
}
void checkWord(char* word)
{

}

void spellCheckFile(string filename)
{

}

HashTable& spellCheck::getTable()
{
    return dictionary;
}
