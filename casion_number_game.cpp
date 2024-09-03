/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*------  CASION NUMBER GAME --------*/
/*
generate a random number. -------> \/
get the total amount from user. ------>
get the betting amount. ------- >
let the user guess the number . ------->
compare and change the betting money.
*/




#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

//declarations
void bet( int *total);
void decision(bool decs, int betting_money, int *total);


//method for random number genration
int rand_integer()
{
    srand(time(0));
    
    int randomNO  = rand() % 11;
    
    return randomNO;
}
void add_money(int *total)
{
    cout << "Enter the money you wanna add"<< endl;
    int n;
    cin>> n;
    
   *total = *total + n;
   cout << "Your total balancec is now, " << *total;
   
   bet(total);
   
   //return total;
}

bool guess(int randomNO)
{
    int guessNO;
     cout<< "guess the number"<<endl;
     cin>> guessNO;
     
    if(guessNO == randomNO)
        return true;
    else
        return false;
}

void bet(int* total)
{
    int betting;
    
    cout<< "Enter the bet"<<endl;
    cin>>betting;
    
    if(betting > *total)
    {
        cout<< "You broke homie"<<endl;
        //display how much they have
        if(total)
            cout<< "you got "<<*total<<endl;
        
        cout<< "Whatcha gonna do"<<endl;
        cout<< "1. add more moeny"<<endl;
        cout<< "2. retry"<<endl;
        cout<< "3. quit"<<endl;
        
        int choice;
        
        cin>>choice;
        
        switch(choice){
            case 1:
                add_money(total);
                break;
            case 2:
                bet(total);
                break;
            case 3:
                exit(0);
                break;
        }
        
    }
    else
    {
        *total = *total - betting;
        cout<< "your bet of "<< betting<< " is placed"<<endl;
        
        int number;
        number = rand_integer();
        bool guessed = guess(number);
        decision(guessed, betting, total);
        
    }
}

void total_money()
{
    int n;
    cout<< "Enter the total deposit money"<<endl;
    cin>> n;
    
    int *total = &n;
    
    bet(total);
    //return total;
}




void decision(bool decs, int betting_money, int *total)
{
    if(decs)
    {
        cout << "Congrats boo you won!!!"<< endl;
        *total = *total + (betting_money * 2);
    }
    else
    {
        cout<< "sorry boo wrong guess"<<endl;
        
    }
    cout<< "total amount is: "<<*total<<endl;
    
}

int main()
{
    cout << "Welcome to the game!!"<<endl;
    
    cout<< "Lests play!"<<endl;
  
    total_money();
    

    return 0;
}
