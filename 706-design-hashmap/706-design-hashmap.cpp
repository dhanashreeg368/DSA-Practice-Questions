class MyHashMap {
    vector<vector<pair<int, int>>> map; //create map using vector
    const int size=10000; //size of vector
public:  
    MyHashMap() {
        map.resize(size); //resizing vector
    }
    
    void put(int key, int value) {
        int index=key%size; //index 
        vector<pair<int, int>> &row=map[index]; //setting rows
        for(auto iter=row.begin(); iter!=row.end(); iter++)
        {
            if(iter->first==key)
            {
                iter->second=value;
                return;
            }
        }
        row.push_back(make_pair(key,value));
    }
    
    int get(int key) {
        int index=key%size;
        vector<pair<int, int>> &row=map[index]; //setting rows
        for (auto iter=row.begin(); iter!=row.end(); iter++)
        {
            if(iter->first==key) //if key found return value
            {
                return iter->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index=key%size;
        vector<pair<int, int>> &row=map[index]; //setting rows
        for (auto iter=row.begin(); iter!=row.end(); iter++)
       {
            if(iter->first==key) //if key found return value
            {
                row.erase(iter); //erase
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */