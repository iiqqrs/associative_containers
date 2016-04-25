using namespace std;
#include "darray.h"
//#ifndef set_darray
//#define set_darray
#include "llist.h"

class set_darray{
    private:
        darray setDarray;
        string temp;
    public:
        set_darray();
        bool is_in(string key);
        void insert(string key);
        void remove(string key, bool all = true);
        bool is_empty();
};

//#endif