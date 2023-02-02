#ifndef __CIPHER_H__
#define __CIPHER_H__

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Cipher{

private:
    map<char, int> mp;
    map<int, char>mpBack;
public:
    Cipher();
    string Encrypt(string plainText, string key);
    void RemoveSpaces(string* string);
    string Decrypt(string cipherText, string key);
    ~Cipher();
};
#endif

