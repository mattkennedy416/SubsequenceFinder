
import numpy as np
cimport numpy as np

cdef extern from "SubsequenceFinder.h":
    cdef cppclass SubsequenceFinder:
        SubsequenceFinder()
        void search(np.float32_t*, int, np.float32_t*, int, float, float, char*)
        int getResultsLength();
        void getResults(np.int32_t*, np.float32_t*)

        # int x0, y0, x1, y1
        # int getLength()
        # int getHeight()
        # int getArea()
        # void move(int, int)

cdef class PySubsequenceFinder:
    cdef SubsequenceFinder *thisptr      # hold a C++ instance which we're wrapping

    def __cinit__(self):
        print('Initializing C++ class')
        self.thisptr = new SubsequenceFinder()

    def __dealloc__(self):
        del self.thisptr

    def search(self, np.ndarray[ndim=1, dtype=np.float32_t] query, np.ndarray[ndim=1, dtype=np.float32_t] data, float distanceLimit, float sizeOfWarpingWindows, distanceMethod):
        self.thisptr.search(&query[0], len(query), &data[0], len(data), distanceLimit, sizeOfWarpingWindows, distanceMethod.encode())

        resultsLength = self.thisptr.getResultsLength()

        print("Found ResultsLength =", resultsLength)

        cdef np.ndarray[ndim=1, dtype=np.int32_t] locations = np.zeros(resultsLength, dtype=np.int32)
        cdef np.ndarray[ndim=1, dtype=np.float32_t] distances = np.zeros(resultsLength, dtype=np.float32)

        self.thisptr.getResults(&locations[0], &distances[0])

        return locations, distances


    # def getLength(self):
    #     return self.thisptr.getLength()
    #
    # def getHeight(self):
    #     return self.thisptr.getHeight()
    #
    # def getArea(self):
    #     return self.thisptr.getArea()
    #
    # def move(self, dx, dy):
    #     self.thisptr.move(dx, dy)
