# <Assignment_part_B>
# <Description: Extracts the cells of a raster ArranDEM that correspond with
# the areas defined by a polygon shapefile arranF.shp. And create a shapefile
# of 30m contour lines for the Isle of Arran from the clipped raster DEM.>

# <Requirements: Spatial Analyst Extension>
# <2486040Y> <Yang, Jiale> <08/04/2020>
# <Status - test success>


# Import modules
import arcpy
from arcpy.sa import *
from arcpy import env

# Set environment settings
arcpy.env.workspace = 'C:/sapyexamples/data'

# Set local variables for extracting DEM
# Specify the path location of the input raster
inRaster = 'F:\\1Glasgow\\2B_Applied_GIS\\python_assignment\\AssignmentData2020\\PartB\\ArranDEM.tif'
# Specify the path location of the mask
inMaskData = 'F:\\1Glasgow\\2B_Applied_GIS\\python_assignment\\AssignmentData2020\\PartB\\arranF.shp'

# Set local variables for creating contours
contourInterval = 30
baseContour = 0
outContours = 'F:\\1Glasgow\\2B_Applied_GIS\\python_assignment\\arran_contours.shp'


# Check out the spatial analyst extension license
if arcpy.CheckExtension('Spatial') == 'Available':
    arcpy.CheckExtension('Spatial')
    
    # Execute ExtractByMask
    outExtractByMask = ExtractByMask(inRaster, inMaskData)
    # Save the output
    outExtractByMask.save('F:\\1Glasgow\\2B_Applied_GIS\\python_assignment\\ArranDEM_extract.tif')

    # Execute Contour
    Contour(outExtractByMask, outContours, contourInterval, baseContour)

    # Check in the spatial analyst extension
    arcpy.CheckInExtension('Spatial')
    
else:
    print ('Spatial Analyst license is not available')
