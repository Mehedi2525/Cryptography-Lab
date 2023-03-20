#include<bits/stdc++.h>
using namespace std;

void print(string msg, int width){

    int len=msg.size();
    for(int i=0;i<len;i++){

        cout<<msg[i]<<" ";
        if((i+1)%width==0)cout<<endl;
    }
    cout<<endl;
}

string encrypt(string msg, int width){
    string cipher = "";

    int adding_space = width - msg.size()%width;

    for(int i = 0; i < adding_space; i++){
        msg += ' ';
    }
    print(msg,width);

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

    cipher = encrypt(encrypt(msg, width), width);
    msg = decrypt(decrypt(cipher, width), width);

    cout<<"Cipher message : "<<cipher<<endl;
    cout<<"Original message : "<<msg<<endl;
    return 0;
}
