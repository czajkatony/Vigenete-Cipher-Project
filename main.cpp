#include <iostream> 
#include <string>
#include "Cipher.h"
#include "Pass.h"
#include <chrono>

using namespace std;

int main(){
    Cipher a;
    int decision = 0;
    cout<<"1)Encrypt plaintext\n2)Decrypt ciphertext\n3)Brute Force\n4)Exit";
    cout<<"\nChoose option: ";
    cin>> decision;
    bool askMessage = false;
    while (decision != 4) {
        if(askMessage){
            cout<<"1)Encrypt plaintext\n2)Decrypt ciphertext\n3)Brute Force\n4)Exit";
            cout<<"\nChoose option: ";
            cin>> decision;
        }
        else{
            askMessage = true;
        }
        if(decision == 1){
            string plainText;
            string key;
            string result;
            cout<<"Please enter the plaintext: ";
            cin.ignore(); // Need this to ignore the enter from the last choice.
            getline(cin, plainText);
            cout<<"Please enter the key: ";
            getline(cin, key);
            result = a.Encrypt(plainText, key); 
            cout<< "Here is the ciphertext from you message: "<<result<<endl;
            cout<<"The key was: "<<key<<endl;

        } 
        else if(decision == 2){
            string cipherText;
            string key;
            string result;
            cout<<"Enter ciphertext: ";
            cin.ignore(); // Need this to ignore the enter from the last choice.
            getline(cin, cipherText);
            cout<<"Enter key: ";
            getline(cin, key);
            result = a.Decrypt(cipherText, key);
            cout<<"Here is the decrypted message: "<< result<<endl;
        }
        else if(decision == 3){
            string ct;
            int kl;
            int fwdl;
            cout<< "Enter cyphertext: ";
            cin.ignore();
            getline(cin, ct);
            cout<<"Enter Key Length: ";
            cin>>kl;
            cout<<"Enter First Word Length: ";
            cin>>fwdl;
            Pass crack(ct, kl, fwdl);
            auto start = chrono::high_resolution_clock::now();
            crack.BruteForce();
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(stop-start);
            cout<<"\nBrute force time taken: "<<duration.count()<<" seconds\n";
        }       
        else if(decision !=4){
            cout<<"Invalid option chosen, please try again.\n";
            cout<<"1) Encrypt plaintext\n2)Decrypt ciphertext\n3)Brute Force\n4)Exit";
        }
    }
}
