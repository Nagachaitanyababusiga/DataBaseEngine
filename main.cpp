#include "Database.h"

int main(){
    Database db;
    string command;

    cout << "Simple DB > ";
    while(true){
        string cmd;
        cin>>cmd;

        if(cmd=="INSERT"||cmd=="insert"){
            string key,value;
            cin >> key >> value;
            cout << (db.insertKey(key,value)?"OK": "KEY_EXISTS") << "\n";
        }else if(cmd==" GET "||cmd=="get"){
            string key;
            cin >> key;
            cout << (db.getKey(key)) << "\n";
        }else if(cmd=="DELETE"||cmd=="delete"){
            string key;
            cin >> key;
            cout << (db.deleteKey(key)? "DELETED": "NOT_FOUND") << "\n";
        }else if(cmd=="UPDATE"||cmd=="update"){
            string key,value;
            cin >> key >> value;
            cout << (db.updateKey(key,value)? "OK": "NOT_FOUND") << "\n";
        }else if(cmd=="SHOWALL"||cmd=="showall"){
            db.showAll();
        }else if(cmd=="COUNT"||cmd=="count"){
            cout << db.count() << "\n";
        }else if(cmd=="ExISTS"||cmd=="exists"){
            string key;
            cin >> key;
            cout << (db.exists(key) ? "YES" : "NO") << "\n";
        }else if(cmd=="SAVE"||cmd=="save"){
            string fname;
            cin >> fname;
            cout << (db.save(fname) ? "SAVED" : "ERROR") << "\n";
        }else if(cmd=="LOAD"||cmd=="load"){
            string fname;
            cin >> fname;
            cout << (db.load(fname) ? "LOADED" : "ERROR") << "\n";
        }else if (cmd == "HELP" || cmd == "help") {
            cout << "\n========== SimpleDB Commands ==========\n";
            cout << "INSERT <key> <value>   : Insert a new key-value pair\n";
            cout << "GET <key>              : Retrieve value for a given key\n";
            cout << "UPDATE <key> <value>   : Update value of an existing key\n";
            cout << "DELETE <key>           : Remove a key-value pair\n";
            cout << "EXISTS <key>           : Check if key exists (YES/NO)\n";
            cout << "COUNT                  : Show number of entries\n";
            cout << "SHOWALL                : Display all key-value pairs\n";
            cout << "SAVE <filename>        : Save database to a file\n";
            cout << "LOAD <filename>        : Load database from a file\n";
            cout << "HELP                   : Show all available commands\n";
            cout << "EXIT                   : Quit the program\n";
            cout << "=======================================\n\n";
        }
        else if(cmd=="EXIT"||cmd=="exit") break;
        else{
            cout<< "use 'HELP' for use Commands" << "\n" << "SimpleDB > ";
            continue;
        }
        cout<< "SimpleDB > ";
    }
}