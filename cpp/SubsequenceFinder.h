
#include <vector>

typedef struct Index
	{   double value;
		int    index;
	} Index;

/// Data structure (circular array) for finding minimum and maximum for LB_Keogh envolop
struct deque
{   int *dq;
	int size,capacity;
	int f,r;
};

#define INF 1e20       //Pseudo Infitinte number for this code

class SubsequenceFinder {
    public:

		/// Data structure for sorting the query



        //int x0, y0, x1, y1;
    	std::vector<long long> loc; // NEW MODIFICATION
    	std::vector<double> locDist; // NEW -- KEEP TRACK OF THE DISTANCE AT EACH LOCATION

        SubsequenceFinder();
        ~SubsequenceFinder();

        //int comp(const void *a, const void* b);
        void init(deque *d, int capacity);
        void destroy(deque *d);
        void push_back(struct deque *d, int v);
        void pop_front(struct deque *d);
        void pop_back(struct deque *d);
        int front(struct deque *d);
        int back(struct deque *d);
        int empty(struct deque *d);
        void lower_upper_lemire(double *t, int len, int r, double *l, double *u);
        double lb_kim_hierarchy(float (*distanceFunc)(float, float), double *t, double *q, int j, int len, double mean, double std, double bsf);
        double lb_keogh_cumulative(float (*distanceFunc)(float, float),  int* order, double *t, double *uo, double *lo, double *cb, int j, int len, double mean, double std, double best_so_far);
        double lb_keogh_data_cumulative(float (*distanceFunc)(float, float), int* order, double *tz, double *qo, double *cb, double *l, double *u, int len, double mean, double std, double best_so_far);
        double dtw(float (*distanceFunc)(float, float), double* A, double* B, double *cb, int m, int r, double bsf);
        void printArray(double *x, int len);
        void error(int id);

        void search(float* query, int queryLength, float* data, int dataLength, float errorLimit, float sizeOfWarpingWindows, char* distanceMethod);

        int getResultsLength();
        void getResults(int* locations, float* distances);


        // DUMMY / EXAMPLE FUNCTIONS
//        int getLength();
//        int getHeight();
//        int getArea();
//        void move(int dx, int dy);
};

