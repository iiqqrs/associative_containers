#define map_llist

using namespace std;

class map_llist {
    private:
        string key;
        int value;
        
    public:
        map_llist;
        void set(string key, int value);
        void remove(string key);
        void get(string key);
        void int &operator[](string key);
};