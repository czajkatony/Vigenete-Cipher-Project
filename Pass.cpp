#include "Pass.h"
#include "Cipher.h"
#include <algorithm>

Pass::Pass(string cT, int kL, int fWdL) : 
    keyLength{kL},
    firstWordLength{fWdL},
    cipherText{cT}
{
    dictionary = {};
    ifstream file("MP1_dict.txt");
    if(file.is_open()){
        string str;
        while(file >> str){
            dictionary.push_back(toLowerCase(str));
        }
        file.close();
    }
    else {
        cout<<"Error: dictionary file needs to be named 'MP1_dict.txt and be in this directory.";
    }
    vectorSize = dictionary.size();
    cipherText = toLowerCase(cipherText);
    alphabet = "abcdefghijklmnopqrstuvwxyz"; 
}

void Pass::RecursiveIterator(string prefix, int keyL){
    if(keyL == 0){
        string tempString = cipher.Decrypt(cipherText, prefix);
        // cout<<tempString<<endl;
        for (int i = 0; i < vectorSize; i++) {
            if (dictionary[i] == tempString.substr(0, firstWordLength)) {
                std::cout << "Potential plaintext: " << tempString << '\n';
            }
        }
        return;
    }
    for(int i = 0; i<26 ; i++){
        string newPrefix;
        newPrefix = prefix + alphabet[i];
        RecursiveIterator(newPrefix, keyL - 1);
    }
}

void Pass::BruteForce(){
    RecursiveIterator("", keyLength);
}

string Pass::toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

Pass::~Pass(){
}





