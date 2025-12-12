#include "Database.h"

bool Database::insertKey(string key,string value){
    if(db.count(key)) return false;
    db[key]=value;
    return true;
}

string Database::getKey(string key){
    if(!db.count(key)) return "NOT_FOUND";
    return db[key];
}

bool Database::updateKey(string key,string value){
    if(!db.count(key)) return false;
    db[key]=value;
    return true;
}

bool Database::exists(string key){
    return db.count(key);
}

int Database::count(){
    return db.size();
}

void Database::showAll(){
    for(auto &p : db){
        cout << p.first << " -> " << p.second << "\n";
    }
}

bool Database::deleteKey(string key){
    return db.erase(key);
}

bool Database::save(string fname){
    ofstream out(fname);
    if(!out) return false;
    for(auto &p:db){
        out << p.first << " " << p.second << "\n";
    }
    out.close();
    return true;
}

bool Database::load(string fname){
    ifstream in(fname);
    if(!in) return false;
    string key,value;
    db.clear();
    while(in >> key >> value){
        db[key]=value;
    }
    in.close();
    return true;
}