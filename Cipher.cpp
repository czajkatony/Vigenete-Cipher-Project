#include "Cipher.h"
using namespace std;

Cipher::Cipher(){
    // map the letters to respective numbers
    // to get the numbers do mp["letter"]
    int startLower = 0;
    int startHigher = 0;
    string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(char c : lowerCase){
        mp[c] = startLower;
        startLower++;
    }
    for(char c : upperCase){
        mp[c] = startHigher;
        startHigher++;
    }
    for(int i=0; i<26; i++){
        mpBack[i]=lowerCase[i];
    }
}

void Cipher::RemoveSpaces(string* string){
    string->erase(remove(string->begin(), string->end(), ' '), string->end()); 
}

string Cipher::Encrypt(string plainText, string key){
    RemoveSpaces(&plainText);
    RemoveSpaces(&key);
    string encryptedString; // final string we will return
    int j = 0; // initialize j
    for(int i = 0; i<plainText.length(); i++){ // iterate thru plaintext
        int helperInt = (mp[plainText[i]] + mp[key[j]])%26; // helperChar is int
        char newChar = mpBack[helperInt]; //helperInt mapped back to letter
        encryptedString.push_back(newChar); // pushes newChar to final str
        if(j == key.length()-1){ // resets the key loop if needed
            j = -1;
        }
        j++; // iterate to the next letter of the key
    }
   return encryptedString; // change this
}

string Cipher::Decrypt(string plainText, string key){
    RemoveSpaces(&plainText);
    RemoveSpaces(&key);
    string decryptedString;
    int j =0;
    for(int i = 0; i<plainText.length(); i++){ // iterate thru plaintext
            int helperInt = ((mp[plainText[i]] - mp[key[j]]+26) %26); // helperChar is int
            char newChar = mpBack[helperInt]; //helperInt mapped back to letter
            decryptedString.push_back(newChar); // pushes newChar to final str
            if(j == key.length()-1){ // resets the key loop if needed
                j = -1;
            }
            j++; // iterate to the next letter of the key
     }
    return decryptedString; // change this
}

Cipher::~Cipher(){

}


