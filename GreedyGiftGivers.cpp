/*
 ID: laurend1
 TASK: gift1
 LANG: C++
 */

// NAME             :   Lauren DeHaan
// GROUP            :   Argon
// LAST MODIFIED    :   19 December 2018
// PROBLEM ID       :   USACO Greedy Gift Givers
// DESCRIPTION      :   This program deduces how much more money each person in
//                      a group receives than they give, based on a gift exchange
//                      wherein a group of more than 1 and less than 11 friends
//                      each withdraw an amount of money from the bank and distribute
//                      it equally to all of their friends.
// SOURCES/HELP     :   Mr. H., USACO, Aidan Eichman helped me,

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Open files for input and output
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    // Declares variables
    int bankAccount[] = {0};
    int amountToGive;
    int numberOfReceivers;
    int numberPeople;
    string namesOfPeople[10];
    string currentGiver;
    string currentReceiver;
    
    // Initializes names of people and bank accounts
    fin >> numberPeople;
    for (int j=0; j<numberPeople; j++)
    {
        fin >> namesOfPeople[j];
    }
    for (int j=0; j<numberPeople; j++)
    {
        // Controls the bank accounts of each giver
        for (int k=0; k<numberPeople; k++)
        {
            fin >> bankAccount[j];
            fin >> numberOfReceivers;
            fin >> currentGiver;
            fin >> amountToGive;
            if (currentGiver == namesOfPeople[j])
            {
                bankAccount[j]= bankAccount[j]-amountToGive;
                if (numberOfReceivers != 0)
                {
                    bankAccount[j] = bankAccount[j]+amountToGive % numberOfReceivers;
                }
            }
            
        }
        
        // Controls the bank accounts of each receiver
        for (int i=0; i<numberPeople; i++)
        {
            fin >> numberOfReceivers;
            fin >> currentReceiver;
            fin >> amountToGive;
            if(currentReceiver==namesOfPeople[j])
            {
                bankAccount[j] = bankAccount[j] + amountToGive / numberOfReceivers;
            }
        }
    }
    // Displays each bank account for each person
    fout << namesOfPeople << " " << bankAccount;
    
    // Exit program
    return 0;
}
