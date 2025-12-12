#include <bits/stdc++.h>
using namespace std;

class Database{
    private: 
        unordered_map<string,string> db;
    public:
        bool insertKey(string key,string value);
        string getKey(string key);
        bool deleteKey(string key);
        bool updateKey(string key,string value);
        bool exists(string key);
        void showAll();
        int count();
        bool save(string filename);
        bool load(string filename);
};
