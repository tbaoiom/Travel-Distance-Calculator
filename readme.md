                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Duplicates a 2-D array table of 15 cities's distances from each other.
2. Converts between strings, ints, and enum types.
3. Asks the user for the departing and arriving city, mileage, and current gas price.
4. Displays a weather alert and adds distances to table.
5. Uses 2-D array to calculate and determine the trip cost and average distance from the specified city to all others.
6. Uses 2-D array to get the closest and farthest city from that city.
7. Uses 2-D array to get the 2 closest and farthest cities from each other.
8. Displays messages from functions for user to see.



*******************************************************
*  Source files
*******************************************************

Name:  travelDistanceCalc.cpp
   Main program.  This is the driver program asks for inputs and 
   gives an output.
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server.

*******************************************************
*  Written Algorithm
*******************************************************
1. Create a 2-D array using a nested loop and copy it from the const array.
2. Make a function which gets the distance through a nested loop and uses that to calculate the trip cost.
  Also asks user for mileage and gas price.

   Trip Cost = distance * (1/mileage) * gas price

3. Make a function which uses the departing city and then loops through all distances of that city to other cities. A accumulator variable adds all of these up and is then divided to get the average distance.
4. Make a function which uses the departing city and loops through and looks at the distances to see which one has the lowest number for the closest city.
5. Make a function which uses the departing city and loops through and looks at the distances to see which one has the highest number for the farthest city.
6. Make a function which uses the 2-D array and uses a nested loop through all distances in the table. The smallest number is the distance between the two closest cities.
7. Make a function which uses the 2-D array and uses a nested loop through all distances in the table. The largest number is the distance between the two farthest cities.
8. Asks user for destination and departing city and displays all function results.

*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [HW3]

   Now you should see a directory named homework with the files:
        main.cpp
        makefile
        readme.md
        outputFile.txt
        inputFile.txt

3. Build the program.

    Change to the directory that contains the file by:
    % cd [HW3] 

    Compile the program by:
    % make

4. Run the program by:
   % ./[travelDistanceCalc]

5. Delete the obj files, executables, and core dump by
   %./make clean
