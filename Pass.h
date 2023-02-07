#ifndef __Pass_H__
#define __Pass_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Cipher.h"
#include <algorithm>
using namespace std;

class Pass{

private:
Cipher cipher;
vector<string> dictionary;
int vectorSize;
int keyLength;
int firstWordLength;
string cipherText;
string alphabet;
public:
Pass(string cT, int kL, int fWdL);
string toLowerCase(string str);
void RecursiveIterator( string prefix, int keyL);
void BruteForce();
~Pass();


};



#endif

