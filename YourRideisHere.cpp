/*
 ID: ldehaan1
 TASK: ride
 LANG: C++
 */

// NAME             :   Lauren DeHaan
// GROUP            :   Argon
// LAST MODIFIED    :   30 October 2018
// PROBLEM ID       :   USACO Ride
// DESCRIPTION      :   This program takes a comet name and a group name.
//                      equates numbers 1-26 to the letters, multiplies the
//                      numbers together, and finds the mod of each name. It
//                      prints either GO or STAY according to the answer found
//                      by the previous step.
// SOURCES/HELP     :   Mr. H., USACO, Sydney Hyde and Keshavi Dave helped me.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Open files for input and output
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    // Declare variables
    string cometName, groupName;
    int cometNum = 1, groupNum = 1;
    const int ASCII_OFFSET = 64, modNum = 47;
    
    // Save input into variables
    fin >> cometName >> groupName;
    
    // Does calculations for comet
    for (int j=0; j <cometName.length(); j++)
    {
        cometNum *= (cometName[j]-ASCII_OFFSET);
        cometNum %= modNum;
    }

    // Does calculations for group
    for (int j=0; j<groupName.length(); j++)
    {
        groupNum *= (groupName[j]-ASCII_OFFSET);
        groupNum %= modNum;
    }
    
    // Prints either "GO" or "STAY," based on the mod of the comet and group names
    if (cometNum == groupNum)
    {
        fout << "GO\n";
    }
    
    else
    {
        fout << "STAY\n";
    }
    
    // Exit program
    return 0;
}
