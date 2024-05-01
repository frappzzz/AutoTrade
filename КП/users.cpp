#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <random>
#include <cstring>
#include <cstdlib>
using namespace std;
class User{
    public:
    string id_user;
    string status_user;
    string login;
    string email;
    string num;
    string name;
    string password;
    string DB="users.txt";
    void Registration(string status_user, string login, string email, string num, string name, string password){
        ifstream file_r(this->DB);
        vector<vector<string>> users;
        string line;
        vector<string> currentUser;

        while (getline(file_r, line)) {
            currentUser.push_back(line);
            if (currentUser.size() == 7) {
                users.push_back(currentUser);
                currentUser.clear();
            }
        }
        file_r.close();
        int last_id=0;
        for (int i=0;i<users.size();i++){
            last_id=stoi(users[i][0]);
        }
        last_id+=1;

        file_r.close();
        ofstream users_bd(this->DB, ios::app);
        users_bd<<last_id<<"\n";
        users_bd<<status_user<<"\n";
        users_bd<<login<<"\n";
        users_bd<<email<<"\n";
        users_bd<<num<<"\n";
        users_bd<<name<<"\n";
        users_bd<<password<<"\n";
        users_bd.close();
        this->id_user=last_id;
        this->status_user=status_user;
        this->login=login;
        this->email=email;
        this->num=num;
        this->name=name;
        this->password=password;
    }
    void changePassword(string id_user,string new_password){
        vector<vector<string>> usersBD=getAllUsers();
        for (int i=0; i<usersBD.size();i++){
            if (usersBD[i][0]==id_user){
                usersBD[i][6]=new_password;
            }
        }
        ofstream outFile(this->DB);
        for (int i=0;i<usersBD.size();i++){
            for (int j=0;j<usersBD[i].size();j++){
                outFile << usersBD[i][j] << "\n";
            }
        }
        outFile.close();

    }
    vector<vector<string>> getAllUsers(){
        ifstream file_r(this->DB);
        vector<vector<string>> usersBD;
        string line;
        vector<string> currentUser;
        while (getline(file_r, line)) {
            currentUser.push_back(line);
            if (currentUser.size() == 7) {
                    usersBD.push_back(currentUser);
                 
                currentUser.clear();
            }
        }
        file_r.close();
        return usersBD;
    }
    bool checkLogin(string login) {
        vector<vector<string>> usersBD=getAllUsers();
        for (int i=0;i<usersBD.size();i++){
            for (int j=0; j<7;j++){
            
                    if (login==usersBD[i][2]){
                        return true;
                    }
                    return false;
                
            }
        }
        return false;
    }
    bool checkEmail(string email){
        vector<vector<string>> usersBD=getAllUsers();
        for (int i=0;i<usersBD.size();i++){
            for (int j=0; j<7;j++){
            
                    if (email==usersBD[i][3]){
                        return true;
                    }
                    return false;
                
            }
        }
        return false;
    }
    bool checkNum(string num){
        vector<vector<string>> usersBD=getAllUsers();
        for (int i=0;i<usersBD.size();i++){
            for (int j=0; j<7;j++){
            
                    if (num==usersBD[i][4]){
                        return true;
                    }
                    return false;
                
            }
        }
        return false;
    }
    bool checkPassword(string login, string password_tc){
        vector<string> user=getUserByLogin(login);
        if (user[6]==password_tc){
            return true;
        }
        return false;
    }
    bool checkStatus(string login){
        vector<string> user=getUserByLogin(login);
        if (user[1]=="1"){
            return true;
        }
        return false;
    }
    vector<string> getUserByLogin(string login){
        ifstream file_r(this->DB);
        vector<vector<string>> usersBD;
        string line;
        vector<string> currentUser;
        while (getline(file_r, line)) {
            currentUser.push_back(line);
            if (currentUser.size() == 7) {
                if (currentUser[2] == login) {
                    usersBD.push_back(currentUser);
                } 
                currentUser.clear();
            }
        }
        vector<string> result_user;
        for (int i=0;i<7;i++){
            result_user.push_back(usersBD[0][i]);
        }
        file_r.close();
        return result_user;
    }
    vector<string> getUserByID(string id_user){
        ifstream file_r(this->DB);
        vector<vector<string>> usersBD;
        string line;
        vector<string> currentUser;

        while (getline(file_r, line)) {
            currentUser.push_back(line);
            if (currentUser.size() == 7) {
                if (currentUser[0] == id_user) {
                    usersBD.push_back(currentUser);
                } 
                currentUser.clear();
            }
        }
        vector<string> result_user;
        for (int i=0;i<7;i++){
            result_user.push_back(usersBD[0][i]);
        }
        file_r.close();
        return result_user;
    }

    
};
int main(){
    User user;
    //user.Registration("0","qwerty","qwerty@qwe","+375123456789","Test","qwe123");
    //cout<<user.login;
    vector<string> asd=user.getUserByID("6");
    for (int i=0;i<7;i++){
        cout<<asd[i]<<"\n";
    }
    cout<<user.checkLogin("qwertyyiop");
    cout<<user.checkEmail("qwerty@qwe");
    cout<<user.checkPassword("qwertyiop","qwe123");
    cout<<user.checkStatus("qwerty");
    user.changePassword("7","qwe23467667");
}