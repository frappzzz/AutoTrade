#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <random>
#include <cstring>
#include <cstdlib>
using namespace std;
class DBAds{
    public:
    string DB="ads.txt";
    vector<vector<string>> getAllAds(){
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление
        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line); // Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[8] == "1") {// Проверка на то, является ли объявление активным
                    ads.push_back(currentAd); // Добавляем объявление в результирующий вектор
                } 
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAdsByID(int id){
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление

        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line); // Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[9] == to_string(id) && currentAd[8]!="0") { // Сортируем объявления по id user
                    ads.push_back(currentAd); // Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAdsByIDModerate(){
        ifstream file_r(this->DB);
        vector<vector<string>> ads;
        string line;
        vector<string> currentAd;
        while (getline(file_r, line)) {
            currentAd.push_back(line);
            if (currentAd.size() == 11) { 
                if (currentAd[8] == "2") { 
                    ads.push_back(currentAd);
                }
                currentAd.clear();
            }
        }
        file_r.close();
        return ads;
    }
    void setStatusAd(int id, int choose, string cause="-"){
        //использовать для одобрения/отклонения админом а так же для удаления объявления РЕАЛИЗОВАТЬ ЕЩЕ ПРИЧИНУ ОТКЛОНЕНИЯ ЗАЯВКИ
        ifstream file_r(this->DB);
        vector<vector<string>> ads;
        string line;
        vector<string> currentAd;
        while (getline(file_r, line)) {
            currentAd.push_back(line);
            if (currentAd.size() == 11) {
                ads.push_back(currentAd);
                currentAd.clear();
            }
        }
        file_r.close();
        for (int i=0;i<ads.size();i++){
            if (ads[i][7]==to_string(id)){
                ads[i][8]=to_string(choose);
                if (cause!="-"){
                ads[i][10]=cause;
                }
            }
        }
        ofstream outFile(this->DB);
        for (int i=0;i<ads.size();i++){
            for (int j=0;j<ads[i].size();j++){
                outFile << ads[i][j] << "\n";
            }
        }
        outFile.close();
    }
    void deleteAd(string ad_id){
        ifstream file_r(this->DB);
        vector<vector<string>> ads;
        string line;
        vector<string> currentAd;
        while (getline(file_r, line)) {
            currentAd.push_back(line);
            if (currentAd.size() == 11) {
                if (currentAd[7]!=ad_id){
                    ads.push_back(currentAd);
                }
                currentAd.clear();
            }
            else{
                continue;
            }
        }
        file_r.close();
        ofstream outFile(this->DB);
        for (int i=0;i<ads.size();i++){
            for (int j=0;j<ads[i].size();j++){
                outFile << ads[i][j] << "\n";
            }
        }
        outFile.close();
    }
    void createAd(string model, string marka, string year, string place, string price, string kratkoe_opisanie, string num, string id){
        ifstream file_r(this->DB);
        vector<vector<string>> ads;
        string line;
        vector<string> currentAd;
        while (getline(file_r, line)) {
            currentAd.push_back(line);
            if (currentAd.size() == 11) {
                ads.push_back(currentAd);
                currentAd.clear();
            }
        }

        file_r.close();
        int last_id=0;
        for (int i=0;i<ads.size();i++){
            last_id=stoi(ads[i][7]);
        }
        last_id+=1;
        string statusad="2";
        string cause="-";
        ofstream file(this->DB, ios::app);
        file<<model<<"\n";
        file<<marka<<"\n";
        file<<year<<"\n";
        file<<place<<"\n";
        file<<price<<"\n";
        file<<kratkoe_opisanie<<"\n";
        file<<num<<"\n";  
        file<<last_id<<"\n";
        file<<statusad<<"\n";
        file<<id<<"\n";
        file<<cause<<"\n";
        file.close();
    }
};
int main(){
    DBAds dbAds;
    string model,marka,year,place,price,kratkoe_opisanie,num,id;
    model="mercedes";
    marka="g63";
    year="1999";
    place="minsk";
    price="10000$";
    kratkoe_opisanie="sgfgadfgsatharbar";
    num="+375123456789";
    id="4";
    //dbAds.createAd(model,marka,year,place,price,kratkoe_opisanie,num,id);
    vector<vector<string>> ads = dbAds.getAllAds();
    // Выводим прочитанные объявления
    for (const auto& ad : ads) {
        cout<<ad[1];
        for (const auto& item : ad) {
            cout << item << "\n";
        }
        cout<<"\n";
    }
    dbAds.setStatusAd(2,0, "Неверный формат объявления");
    vector<vector<string>> adsz = dbAds.getAdsByID(4);
     for (const auto& ad : adsz) {
        for (const auto& item : ad) {
            cout << item << "\n";
        }
        cout<<"\n";
    }
    dbAds.deleteAd("3");
    
}