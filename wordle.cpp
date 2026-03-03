#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

vector<string> words;
unsigned seed=chrono::system_clock::now().time_since_epoch().count();
mt19937 gen(seed);

string TARGET;
vector<pair<string, vector<char>>> lists(6, {" ", vector<char>(5, 'B')});
int freq[26]={0};
vector<char>ans(5, 'B');

void typeWrite(string message){
    for (char ch: message) {
        cout<<ch<<flush;
        this_thread::sleep_for(chrono::milliseconds(70));
    }
}

void printColored(char letter, char status){
    if(status == 'G'){
         cout<<"\033[1;32m"<<letter<<"\033[0m "<<flush;
         this_thread::sleep_for(chrono::milliseconds(200));
    }
    else if(status == 'Y'){
         cout<<"\033[1;33m"<<letter<<"\033[0m "<<flush;
         this_thread::sleep_for(chrono::milliseconds(200));
    }
    else{
         cout<<"\033[1;37m"<<letter<<"\033[0m "<<flush;
         this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void decoration(){
    cout<<endl<<"--------------------------"<<endl;
    for(auto s: lists){
        if(s.first==" "){
            break;
        }
        for(int i = 0; i < 5; i++){
            char letter = toupper(s.first[i]);
            char status = s.second[i];
            printColored(letter, status);
        }
        cout<<endl;
        cout<<"--------------------------"<<endl;
    }
}

string askInput(){
    string inp=" ";
    while(true){
        typeWrite("Enter your guess: ");
        cin>>inp;
        transform(inp.begin(), inp.end(), inp.begin(), ::tolower);
        bool allLetters=true;
        for(char c: inp){
            if(!isalpha(c)){
                allLetters=false;
                break;
            }
        }
        if(!allLetters){
            typeWrite("Please enter only letters!");
            cout<<endl;
            continue;
        }
        if(inp.size()!=5){
            typeWrite("Please enter a 5-letter word!");
            cout<<endl;
            continue;
        }
        bool alreadyTried=false;
        for(auto word : lists){
            if(word.first==inp){
                alreadyTried=true;
                break;
            }
        }
        if(alreadyTried){
            typeWrite("Already tried!");
            cout<<endl;
            continue;
        }
        if(!binary_search(words.begin(), words.end(), inp)){
            typeWrite("Not in word list!");
            cout<<endl;
            continue;
        }
        for(int i=0; i<6; i++){
            if(lists[i].first==" "){
                lists[i].first=inp;
                break;
            }
        }
    return inp;
    }
}

void yellow(string input){
    for(int i=0; i<5; i++){
        if(ans[i]!='G'){
            freq[int(TARGET[i])-97]++;
        }
    }
    for(int i=0; i<5; i++){
        if(ans[i]!='G'&&freq[int(input[i])-97]>0){
            ans[i]='Y';
            freq[int(input[i])-97]--;
        }
    }
    for(int i=0; i<6; i++){
        if(lists[i].first==input){
            lists[i].second=ans;
            break;
        }
    }
}

void green(string input){
    for(int i=0; i<5; i++){
        if(TARGET[i]==input[i]){
            ans[i]='G';
        }
    }
    for(int i=0; i<6; i++){
        if(lists[i].first==input){
            lists[i].second=ans;
            break;
        }
    }
}

bool answer(string input){
    int i=0;
    while(i<5){
        if(input[i]!=TARGET[i]){
            return false;
        }
        else{
            i++;
        }
    }
    return true;
}

void gameMechanism(){
    typeWrite("Welcome to wordle!");
    cout<<endl;
    int i=0;
    bool label=false;
    while(i<6){
        string inp=askInput();
        ans=vector<char>(5, 'B');
        for(int j=0; j<26; j++){
            freq[j]=0;
        }
        green(inp);
        yellow(inp);
        i++;
        decoration();
        if(answer(inp)){
            label=true;
            break;
        }
    }
    if(label){
        typeWrite("Congratulations! You won!");
        cout<<endl;
        typeWrite("Tries: (");
        cout<<i;
        typeWrite("/6)");
        cout<<endl;
    }
    else{
        typeWrite("Game over!");
        typeWrite("The word was ");
        typeWrite(TARGET);
    }
}

int main(){
    ifstream inputFile("list.txt");
    if(inputFile.is_open()){
        string word;
        while (getline(inputFile, word)) {
            words.push_back(word);
        }
    }
    if(words.empty()){
        cout<<"Word list failed to load!"<<endl;
        return 1;
    }
    uniform_int_distribution<> distrib(0, words.size()-1);
    int num=distrib(gen);
    TARGET=words[num];
    inputFile.close();
    gameMechanism();
    return 0;
}
