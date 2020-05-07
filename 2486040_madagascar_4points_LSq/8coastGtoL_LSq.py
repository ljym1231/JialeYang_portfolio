## week 4, program 8
## all calculation of this program based on least square
# Program  convert the coastline coordinates 
# from Geographical coordinates to Lambert Conformal Conical Projection grid coordinates
#
# <2486040Y> <Yang, Jiale> <25/11/2019>
# Status - test success

# Import modules
import math
import csv

# Inputs - Declare R(Earth radius)
R = 6378000

# Inputs - convert standard parallels from degrees to radians
Q1 = math.radians(-10)
Q2 = math.radians(-25)

# cone constant calculation
n1 = math.log((math.cos(Q1)/math.cos(Q2)),math.e)
n2 = math.log(((math.tan(math.pi/4+Q2/2))/(math.tan(math.pi/4+Q1/2))),math.e)
n = float(n1/n2)

# calculate F
F = (math.cos(Q1))*(math.tan((math.pi/4)+(Q1/2))**n)/n

# check information
print Q1, Q2, n, F

# Open the file - coastline geographical coordinates
# the file's address is same as the address where the program was stored
CoastGeographic = open('CoastlineGeographicOutput_LSq.txt',"r")

# Read in the data
#CGP = coastline geographic points coordinates
CGP = csv.reader(CoastGeographic)

# Open another file and write - to store Lambert Conformal Conical Projection grid coordinates
CoastLCCfile=open("CoastlineLambertCCOutput_LSq.txt","w")

# Convert Geographical coordinates to Lambert coordinates
for row in CGP:
    # Print the origin geographical data
    print row
    
    # change the data format, convert degree to radians, and assign the value to variables
    a = 0.0
    a = math.radians(float(row[0]))
    b = 0.0
    b = math.radians(float(row[1]))

    # calculate G, RhoO, Rho
    G = n*(a-0)
    RhoO = R*F/(math.tan(math.pi/4)**n)
    Rho = R*F/(math.tan(math.pi/4+b/2)**n)

    # calculate the x,y LCC coordinates and print them
    x = Rho*math.sin(G)
    print 'X = ', x
    y = RhoO-Rho*math.cos(G)
    print 'Y = ', y

    # Write the calculation result into file
    CoastLCCfile.write(str(x)+",")
    CoastLCCfile.write(str(y)+"\n")

# Close the file
CoastLCCfile.close()    
CoastGeographic.close()
































