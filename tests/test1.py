
import SubsequenceFinder as sf
import numpy as np



data = np.random.rand(1200000,)
query = data[1000:1100]



a = sf.SubsequenceFinder()

locs, dists = a.search(query, data, distanceLimit=0.01, sizeOfWarpingWindow=0.05)

print('Locations:', list(locs))
print('Distances:', list(dists))


