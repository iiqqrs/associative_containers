using namespace std;
#ifndef map_darray
#define map_darray

class map_darray {
}
    private:
        string key;
        int value;
        void doubleArray();
        int count;
        int size;
        
    public:
        map_darray();
        void remove(string key);
        void set(string key, int value)
        void get(string key);
        int &operator[](string key);
};

#endif