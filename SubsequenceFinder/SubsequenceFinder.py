

import SubsequenceFinder_core as sfc
import numpy as np

class SubsequenceFinder():

    def __init__(self):
        print('Initializing Python Class!')

        self.finder = sfc.PySubsequenceFinder()
        self.locations = None
        self.distances = None


    def search(self, query, data, distanceLimit, sizeOfWarpingWindow=0.05):
        query = query.astype(np.float32)
        data = data.astype(np.float32)

        self.locations, self.distances = self.finder.search(query, data, distanceLimit, sizeOfWarpingWindow)

        return self.locations, self.distances
