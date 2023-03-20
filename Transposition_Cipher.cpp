#include<bits/stdc++.h>
using namespace std;

string encrypt(string msg, int width){
    string cipher = "";

    int adding_space = width - msg.size()%width;

    for(int i = 0; i < adding_space; i++){
        msg += ' ';
    }

    for(int i = 0; i < width; i ++){
        for(int j = i; j < msg.size(); j += width){
            cipher += msg[j];
        }
    }

    return cipher;
}

string decrypt(string cipher, int width){

    string msg = "";

    int rows =ceil(cipher.size()/(double)width);

    for(int i = 0; i < rows; i ++){
        for(int j = i; j < cipher.size(); j += rows){
            msg += cipher[j];
        }
    }

    int cnt = 0;
    for(int i = msg.size()-1; i >= 0; i--){
        if(msg[i]==' ')cnt ++;
        else break;
    }
    msg = msg.substr(0, msg.size()-cnt);

    return msg;
}


int main(){

    int width;
    string msg,cipher;
    msg="DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING UNIVERSITY OF RAJSHAHI.";
    cout<<"Enter Width Please"<<endl;
    cin>>width;

    cipher = encrypt(msg, width);
    msg = decrypt(cipher, width);

    cout<<"Cipher message : "<<cipher<<endl;
    cout<<"Original message : "<<msg<<endl;
    return 0;
}
