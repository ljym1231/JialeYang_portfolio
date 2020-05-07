## week 1, program 1
# Program to convert the 4 control points scanner coordinates
# to Mercator Projection Grid Eastings and Northings
#
# <2486040Y> <Yang, Jiale> <04/11/2019>
# Status - test success

# Import modules
import math
import csv

# Inputs - Declare R(Earth radius)
R = 6378000

# Open the file - control points(geographical coordinates)
# the file's address is same as the address where the program was stored
madagascar = open('madagascar.txt',"r")

# Read in the data
location = csv.reader(madagascar)

# Open another file and write - to store the output result(Mercator coordinates)
# CP - control point
f=open("CP_Mercator.txt","w")

# Convert the geographical coordinates to Mercator coordinates
for row in location:
    # Print the origin data
    print row
    
    # convert the Easting coordinate and print
    a = 0.0
    a = float(row[1])
    x = R * math.radians(a)
    print 'X = ', x
    
    # convert the Northing coordinate and print
    b = 0.0
    b = float(row[0])
    y = R * math.log((math.tan(math.pi/4 + math.radians(b)/2)),math.e)
    print 'Y = ', y
    
    # Write the calculation result into file
    f.write(str(x)+",")
    f.write(str(y)+"\n")
    
# Close the written file
f.close()    

# Close the read file
madagascar.close()
