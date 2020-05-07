## week 2, program 3
# Program  convert the coastline coordinates 
# from Mercator Projection grid coordinates to Geographical coordinates (φ,λ) 
#
# <2486040Y> <Yang, Jiale> <11/11/2019>
# Status - test success

# Import modules
import math
import csv

# Inputs - Declare R(Earth radius)
R = 6378000

# Open the file - Mercator coastline points
# the file's address is same as the address where the program was stored
CoastMercator = open('CoastlineMercatorOutput.txt',"r")

# Read in the data
#CMP = coastline mercator points coordinates
CMP = csv.reader(CoastMercator)

# Open another file and write - to store the coastline geographical coordinates
CoastGeofile=open("CoastlineGeographicOutput.txt","w")

# convert the coastline coordinates from Mercator to Geographical coordinates
for row in CMP:
    # Print the origin Mercator data
    print row
    
    # convert the X coordinate and print
    a = 0.0
    a = float(row[0])
    x = math.degrees(a/R)
    print 'X = ', x
    
    # convert the Y coordinate and print
    b = 0.0
    b = float(row[1])
    y = math.degrees(math.atan(math.sinh(b/R)))
    #inverse: y = R * math.log((math.tan(math.pi/4 + math.radians(b)/2)),math.e)
    print 'Y = ', y
    
    # Write the calculation result into file
    CoastGeofile.write(str(x)+",")
    CoastGeofile.write(str(y)+"\n")
    
# Close the written file
CoastGeofile.close()
# Close the read file
CoastMercator.close()
