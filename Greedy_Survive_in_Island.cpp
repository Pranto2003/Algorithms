#include <iostream>
using namespace std;
//!Check if it's possible to survive on island


class Island{
    public:

    int minimumDays(int daystosurvive, int unitofbuyingfood, int caneatperday){
        int sunday = daystosurvive / 7;

        int buyingdays = daystosurvive - sunday;
        int totalfood = daystosurvive * caneatperday;
        int answer = 0;

        if(totalfood%daystosurvive==0){
            answer = totalfood / daystosurvive;
        }
        else{
            answer=(totalfood/daystosurvive)+1;
        }
        if(answer<=buyingdays){
            return answer;
        }
        else{
            return -1;

        }
    }
};
int main(){
    Island isl;
    int daystosurvive,unitofbuyingfood,caneatperday;

    cout << "Enter how many days i have to survive :" << endl;
    cin >> daystosurvive;
    cout << "How many units of food i can buy per day except SUNDAY ?" << endl;
    cin >> unitofbuyingfood;
    cout << "How many units of food i can eat per day ?" << endl;
    cin >> caneatperday;

    int result = isl.minimumDays(daystosurvive, unitofbuyingfood, caneatperday);

    if(result>1){
        cout << "Yes, I can survive" << endl;
    }
    else{
        cout << "No, I can't survive . I need more units of food" << endl;
    }

    return 0;
}