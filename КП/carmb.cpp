#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <random>
#include <cstring>
#include <cstdlib>
using namespace std;
class carMB{
    public:
    string carDB="carbrands.txt";
    bool addCarBrand(string car_brand){
        ifstream file(this->carDB);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line==car_brand){
                    return false;
                }
            }
        file.close();
        }
        ofstream carbrands(this->carDB, ios::app);
        carbrands<<car_brand<<"\n";
        carbrands.close();
        string full_path="./carmodels/"+car_brand+".txt";
        ofstream carmodel(full_path);
        carmodel.close();
        return true;
    }
    bool addCarModel(string car_brand, string car_model){
        string full_path =  "./carmodels/" + car_brand+".txt";
        ifstream file(full_path);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line==car_model){
                    return false;
                }
            }
        file.close();
        }
        ofstream carmodel(full_path, ios::app);
        carmodel<<car_model<<"\n";
        carmodel.close();
        return true;
    }
    vector<string> getAllBrands(){
        ifstream file_r(this->carDB);
        vector<string> carb;
        string line;
        while (getline(file_r, line)) {
            carb.push_back(line);
        }
        file_r.close();
        return carb;
    }
    vector<string> getAllModelsByBrand(string car_brand){
        string full_path="./carmodels/"+car_brand+".txt";
        ifstream file_r(full_path);
        vector<string> carm;
        string line;
        while (getline(file_r, line)) {
            carm.push_back(line);
        }
        file_r.close();
        return carm;
    }
};
int main(){
    carMB Carmb;
    if (Carmb.addCarBrand("Mercedes")==false){
        cout<<"Error";
    }
    vector<string> carbrands =Carmb.getAllBrands();
    for (int i=0;i<carbrands.size();i++){
        cout<<carbrands[i]<<"\n";
    }
    vector<string> carmodels =Carmb.getAllModelsByBrand("BMW");
    for (int i=0;i<carmodels.size();i++){
        cout<<carmodels[i]<<"\n";
    }
}