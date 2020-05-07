## week 2, program 2
# Use the two-dimensional similarity transformation constants obtained last week in excel
# Program convert the digitized coastline from scanner coordinates 
# to Mercator Projection grid coordinates
#
# <2486040Y> <Yang, Jiale> <11/11/2019>
# Status - test success

# Import modules
import csv

# Open the file -  digitized coastline points
# the file's address is same as the address where the program was stored
CoastDigitised = open('CoastlineDigitizedPointsInput.txt',"r")

# Read in the data
#CDP = coastline digitised points coordinates
CDP = csv.reader(CoastDigitised)

# Open another file and write - to store the coastline Mercator coordinates
CoastMerfile=open("CoastlineMercatorOutput.txt","w")

# Convert the digitized coordinates to Mercator coordinates
for row in CDP:
    # Print the origin data
    print row
    
    # change the data format and assign the value to variables
    x0 = 0.0
    x0 = float(row[0])
    y0 = 0.0
    y0 = float(row[1])
    
    # calculate the x,y Mercator coordinates
    # the constants calculated by excel
    x = (19889.45374*x0 - 101.5492431*y0) - 5010720.653
    y = (101.5492431*x0 + 19889.45374*y0) + 3199431.827

    # print the calculation result
    print 'X = ', x
    print 'Y = ', y

    # Write the calculation result into file
    CoastMerfile.write(str(x)+",")
    CoastMerfile.write(str(y)+"\n")
    
# Close the written file
CoastMerfile.close()
# Close the read file
CoastDigitised.close()
