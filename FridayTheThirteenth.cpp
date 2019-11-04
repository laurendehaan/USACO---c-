/*
 ID: laurend1
 TASK: friday
 LANG: JAVA
 */

//              NAME:   Lauren DeHaan
//             CLASS:   APCS
//     LAST MODIFIED:   2 October 2019
//        PROBLEM ID:   USACO Friday
//       DESCRIPTION:   This program computes the frequency that the thirteenth of each month
//                      lands on a Sunday, Monday, Tuesday, Wednesday, Thursday, Friday,
//                      and Saturday over a given period of N years.
//      SOURCES/HELP:   Mr. H., USACO

import java.io.*;
import java.util.StringTokenizer;

public class gift1
{
    public static void main (String [] args) throws IOException
    {
        // Open files for input and output
        RandomAccessFile in = new RandomAccessFile("friday.in", "r");
        PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("friday.out")));
    
        // Declares variables
        int[] daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int[] daysInWeek = new int[6];
        int day = 0;
    
        // Saves input into variables
        int years = Integer.parseInt(f.readLine()) + 1900;
    
        // Does calculations for comet
        for (int year = 1900; year < years; year++) 
        {
             for( int j=0 ; j<12 ; j++ )
            {
               daysInWeek[day]++;
               if( j==1 && ( year%400==0 || ( year%4==0 && year%100!=0 )))
               {
                daysInWeek = (day+29) % 7;
               }
               else
               {
                day = ( day + daysOfMonth[j] ) % 7;
               }
            }
        }		  
        for (int i = 0; i<6; i++) 
        {
			   outf.print(daysInWeek[i] + " ");
		  }
      outf.print(daysInWeek[6])
		outf.println();
		outf.close();
		System.exit(0);
	}    
    
    
    // Exit program
    return 0;
}
