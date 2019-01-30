
The core algorithms of this package are based on the highly optimized UCR Suite, with the following features added:
 - algorithms will track and return all locations which are within some specified error, not just the best subsegment
 - bindings to a python class, SubsequenceFinder()

####Example of Use:

'''python
import SubsequenceFinder as sf
import numpy as np

data = np.random.rand(1200000,)
query = data[1000:1100]

a = sf.SubsequenceFinder()

locs, dists = a.search(query, data, distanceLimit=5, sizeOfWarpingWindow=0.05)
'''



== Fairness of Usage ==

Please reference this paper in your paper as 
Thanawin Rakthanmanon, Bilson Campana, Abdullah Mueen, Gustavo Batista, Brandon Westover, Qiang Zhu, Jesin Zakaria, Eamonn Keogh (2012). Searching and Mining Trillions of Time Series Subsequences under Dynamic Time Warping SIGKDD 2012.



== Disclaimer ==

This UCR Suite software is copyright protected © 2012 by Thanawin Rakthanmanon, Bilson Campana, Abdullah Mueen, Gustavo Batista, and Eamonn Keogh.
Unless stated otherwise, all software is provided free of charge. As well, all software is provided on an "as is" basis without warranty of any kind, express or implied. Under no circumstances and under no legal theory, whether in tort, contract, or otherwise, shall Thanawin Rakthanmanon, Bilson Campana, Abdullah Mueen, Gustavo Batista, or Eamonn Keogh be liable to you or to any other person for any indirect, special, incidental, or consequential damages of any character including, without limitation, damages for loss of goodwill, work stoppage, computer failure or malfunction, or for any and all other damages or losses.
If you do not agree with these terms, then you you are advised to not use the software.



