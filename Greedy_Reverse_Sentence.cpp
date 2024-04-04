#include <iostream>
#include <algorithm>
using namespace std;
//! Reverse a sentence

class Sentence{
    public:
    string reverseSentence(string s){
        string ans = "";
        string temp = "";
        for (int i = s.length() - 1; i >= 0; i--){
          if(s[i]=='.'){
              reverse(temp.begin(), temp.end());
              ans = ans + temp;
              temp = "";
          }
          else{
              temp.push_back(s[i]);
          }
        }
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        return ans;
    }
};
int main(){
    string sentence;
    cout << "Enter the sentence here and please enter '.' after each word :" << endl;
    getline(cin, sentence);

    Sentence sent;
    cout << "The reverse sentence is :" << sent.reverseSentence(sentence) << endl;

    return 0;
}