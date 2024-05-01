#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <random>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <locale>
#include <codecvt>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;
class DBAds {
public:
    string DB = "./DB/ads.txt";
    vector<vector<string>> getAllAds() {
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление
        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line);// Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[8] == "1" ) {// Проверка на то, является ли объявление активным
                    ads.push_back(currentAd);// Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAllAdsByBrand(string brand) {
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление
        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line);// Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[8] == "1"&&currentAd[0] == brand) {// Проверка на то, является ли объявление активным
                    ads.push_back(currentAd);// Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAllAdsByModel(string model) {
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление
        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line);// Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[8] == "1" && currentAd[1] == model) {// Проверка на то, является ли объявление активным
                    ads.push_back(currentAd);// Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAllAdsByPrice(string price, string max_price) {
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление
        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line);// Добавляем строку в текущее объявление
            if (currentAd.size() == 11) {
                string digits_current_ad;
                string digits_price;
                string digits_max_price;
                for (char c : currentAd[4]) {
                    if (isdigit(c)) {
                        digits_current_ad += c;
                    }
                }
                for (char c : price) {
                    if (isdigit(c)) {
                        digits_price += c;
                    }
                }
                for (char c : max_price) {
                    if (isdigit(c)) {
                        digits_max_price += c;
                    }
                }
                if (currentAd[8] == "1" && (stoi(digits_current_ad)>=stoi(digits_price)&& stoi(digits_current_ad) <= stoi(digits_max_price))) {// Проверка на то, является ли объявление активным
                    ads.push_back(currentAd);// Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAllAdsByPlace(string place) {
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление
        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line);// Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[8] == "1" && currentAd[3] == place) {// Проверка на то, является ли объявление активным
                    ads.push_back(currentAd);// Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAdsByID(int id) {
        ifstream file_r(this->DB);
        vector<vector<string>> ads; // Создаем вектор векторов строк для хранения объявлений
        string line;
        vector<string> currentAd; // Текущее объявление

        while (getline(file_r, line)) { // Читаем строки из файла
            currentAd.push_back(line); // Добавляем строку в текущее объявление
            if (currentAd.size() == 11) { // Если в объявлении уже 11 строк
                if (currentAd[9] == to_string(id)) { // Сортируем объявления по id user
                    ads.push_back(currentAd); // Добавляем объявление в результирующий вектор
                }
                currentAd.clear(); // Очищаем текущее объявление для чтения следующего
            }
        }
        file_r.close();
        return ads;
    }
    vector<vector<string>> getAdsByIDModerate() {
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
    void setStatusAd(int id, int choose, string cause = "-") {
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
        for (int i = 0; i < ads.size(); i++) {
            if (ads[i][7] == to_string(id)) {
                ads[i][8] = to_string(choose);
                if (cause != "-") {
                    ads[i][10] = cause;
                }
            }
        }
        ofstream outFile(this->DB);
        for (int i = 0; i < ads.size(); i++) {
            for (int j = 0; j < ads[i].size(); j++) {
                outFile << ads[i][j] << "\n";
            }
        }
        outFile.close();
    }
    void deleteAd(string ad_id) {
        ifstream file_r(this->DB);
        vector<vector<string>> ads;
        string line;
        vector<string> currentAd;
        while (getline(file_r, line)) {
            currentAd.push_back(line);
            if (currentAd.size() == 11) {
                if (currentAd[7] != ad_id) {
                    ads.push_back(currentAd);
                }
                currentAd.clear();
            }
            else {
                continue;
            }
        }
        file_r.close();
        ofstream outFile(this->DB);
        for (int i = 0; i < ads.size(); i++) {
            for (int j = 0; j < ads[i].size(); j++) {
                outFile << ads[i][j] << "\n";
            }
        }
        outFile.close();
    }
    void createAd(string model, string marka, string year, string place, string price, string kratkoe_opisanie, string id,string date) {
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
        int last_id = 0;
        for (int i = 0; i < ads.size(); i++) {
            last_id = stoi(ads[i][7]);
        }
        last_id += 1;
        string statusad = "2";
        string cause = "-";


        ofstream file(this->DB, ios::app);
        file << model << "\n";
        file << marka << "\n";
        file << year << "\n";
        file << place << "\n";
        file << price << "\n";
        file << kratkoe_opisanie << "\n";
        file << date << "\n";
        file << last_id << "\n";
        file << statusad << "\n";
        file << id << "\n";
        file << cause << "\n";
        file.close();
    }
};
class carMB {
public:
    string carDB = "./DB/carbrands.txt";
    bool addCarBrand(string car_brand) {
        ifstream file(this->carDB);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line == car_brand) {
                    return false;
                }
            }
            file.close();
        }
        ofstream carbrands(this->carDB, ios::app);
        carbrands << car_brand << "\n";
        carbrands.close();
        string full_path = "./DB/carmodels/" + car_brand + ".txt";
        ofstream carmodel(full_path);
        carmodel.close();
        return true;
    }
    bool addCarModel(string car_brand, string car_model) {
        string full_path = "./DB/carmodels/" + car_brand + ".txt";
        ifstream file(full_path);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line == car_model) {
                    return false;
                }
            }
            file.close();
        }
        ofstream carmodel(full_path, ios::app);
        carmodel << car_model << "\n";
        carmodel.close();
        return true;
    }
    vector<string> getAllBrands() {
        ifstream file_r(this->carDB);
        vector<string> carb;
        string line;
        while (getline(file_r, line)) {
            carb.push_back(line);
        }
        file_r.close();
        return carb;
    }
    vector<string> getAllModelsByBrand(string car_brand) {
        string full_path = "./DB/carmodels/" + car_brand + ".txt";
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
class User {
public:
    string id_user;
    string status_user;
    string login;
    string email;
    string num;
    string name;
    string password;
    string DB = "./DB/users.txt";
    void Registration(string login, string email, string num, string name, string password) {
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
        string last_id = "0";
        for (int i = 0; i < users.size(); i++) {
            
            last_id = users[i][0];
        }
        int l_id = stoi(last_id);
        l_id += 1;

        file_r.close();
        string user_status = "0";
        ofstream users_bd(this->DB, ios::app);
        users_bd << l_id << "\n";
        users_bd << user_status << "\n";
        users_bd << login << "\n";
        users_bd << email << "\n";
        users_bd << num << "\n";
        users_bd << name << "\n";
        users_bd << password << "\n";
        users_bd.close();
        this->id_user = to_string(l_id);
        this->status_user = user_status;
        this->login = login;
        this->email = email;
        this->num = num;
        this->name = name;
        this->password = password;
    }
    void Authorization(string login) {
        vector<string> current_user = getUserByLogin(login);
        this->id_user = current_user[0];
        this->status_user = current_user[1];
        this->login = current_user[2];
        this->email = current_user[3];
        this->num = current_user[4];
        this->name = current_user[5];
        this->password = current_user[6];
    }
    void changePassword(string id_user, string new_password) {
        vector<vector<string>> usersBD = getAllUsers();
        for (int i = 0; i < usersBD.size(); i++) {
            if (usersBD[i][0] == id_user) {
                usersBD[i][6] = new_password;
            }
        }
        ofstream outFile(this->DB);
        for (int i = 0; i < usersBD.size(); i++) {
            for (int j = 0; j < usersBD[i].size(); j++) {
                outFile << usersBD[i][j] << "\n";
            }
        }
        outFile.close();

    }
    vector<vector<string>> getAllUsers() {
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
        vector<vector<string>> usersBD = getAllUsers();
        for (int i = 0; i < usersBD.size(); i++) {
            for (int j = 0; j < 7; j++) {
                if (login == usersBD[i][2]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool checkEmail(string email) {
        vector<vector<string>> usersBD = getAllUsers();
        for (int i = 0; i < usersBD.size(); i++) {
            for (int j = 0; j < 7; j++) {

                if (email == usersBD[i][3]) {
                    return true;
                }
            }
        }
        return false;
    }
    bool checkNum(string num) {
        vector<vector<string>> usersBD = getAllUsers();
        for (int i = 0; i < usersBD.size(); i++) {
            for (int j = 0; j < 7; j++) {

                if (num == usersBD[i][4]) {
                    return true;
                }

            }
        }
        return false;
    }
    bool checkPassword(string login, string password_tc) {
        vector<string> user = getUserByLogin(login);
        if (user[6] == password_tc) {
            return true;
        }
        return false;
    }
    bool checkStatus(string login) {
        vector<string> user = getUserByLogin(login);
        if (user[1] == "1") {
            return true;
        }
        return false;
    }
    vector<string> getUserByLogin(string login) {
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
        for (int i = 0; i < 7; i++) {
            result_user.push_back(usersBD[0][i]);
        }
        file_r.close();
        return result_user;
    }
    vector<string> getUserByID(string id_user) {
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
        for (int i = 0; i < 7; i++) {
            result_user.push_back(usersBD[0][i]);
        }
        file_r.close();
        return result_user;
    }
};
class States {
    public:
        string current_state = "main_menu";
        string filter_state = "none";
        
    void setState(string new_state) {
        this->current_state = new_state;
    }
    void setFilter(string new_state) {
        this->filter_state = new_state;
    }
    

};
class Filter {
    public:
        string filter = "none";
        string brand = "none";
        string model = "none";
        string price = "none";
        string max_price = "none";
        string place = "none";
        void setFilter(string new_filter) {
            this->filter = new_filter;
        }
        void setBrand(string new_filter) {
            this->brand = new_filter;
        }
        void setModel(string new_filter) {
            this->model = new_filter;
        }
        void setPrice(string new_filter) {
            this->price = new_filter;
        }
        void setMaxPrice(string new_filter) {
            this->max_price = new_filter;
        }
        void setPlace(string new_filter) {
            this->place = new_filter;
        }
};
void SetCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { x, y };
    SetConsoleCursorPosition(hConsole, position);
}
void coutFromFile(string path) {
    wifstream file(path);
    file.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    wstring line;
    while (getline(file, line)) {
        wcout << line << "\n";
    }
    file.close();
}
void clearCout(int count_errors, int size) {
    for (int e = 0; e <= count_errors; e++) {
        Sleep(50);
        cout << "\033[A";
        cout << "\r";
        for (int i = 0; i < size; i++) {
            cout << " ";
        }
        cout << "\r";
        Sleep(100);
    }
}
bool isCyrillic(char ch) {
    // Русские буквы в кодировке Windows-1251 находятся в диапазоне 192-255
    return static_cast<unsigned char>(ch) >= 192 && static_cast<unsigned char>(ch) <= 255;
}
string cinString() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (ch!=' ' && data.size()<40 && (isalpha(ch)||isdigit(ch)||ch=='@' || ch == '.')) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinPrice() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (ch != ' ' && isdigit(ch)&& data.size()<25) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }

    }
    cout << "\n";
    return data;
}

string cinName() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (isalpha(ch) || isCyrillic(ch)) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinBrand() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (isalpha(ch) || isCyrillic(ch)|| ch==' ') {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinModel() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (isalpha(ch) || isCyrillic(ch) || ch == ' ' || isdigit(ch)) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinLogin() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (isalpha(ch) || isdigit(ch)){
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinNum() {
    string data;
    char ch;
    cout << "+";
    data += "+";
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    if (!(data.size() <= 1)) {
                        data.pop_back();
                        cout << "\b \b";
                    }
                     // Удаляем символ из консоли
                }
            }
            else if (isdigit(ch) && data.size() < 19) { // Если символ - цифра
                data += ch;
                cout << ch; // Выводим символ на консоль
                // Отмечаем, что первая цифра введена
            }
        }
    }
    cout << "\n";
    return data;
}
string cinYear() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    if (!(data.size() < 1)) {
                        data.pop_back();
                        cout << "\b \b";
                    }
                    // Удаляем символ из консоли
                }
            }
            else if (isdigit(ch) && data.size() < 4) { // Если символ - цифра
                data += ch;
                cout << ch; // Выводим символ на консоль
                // Отмечаем, что первая цифра введена
            }
        }
    }
    cout << "\n";
    return data;
}
string cinOpisanie() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (data.size()<77) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinCause() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (data.size() < 55) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinPlace() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if ((isalpha(ch) || isCyrillic(ch))&&data.size()<35) {
                data += ch;
                cout << ch; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}
string cinNumb() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') {
                // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    if (!(data.size() < 1)) {
                        data.pop_back();
                        cout << "\b \b";
                    }
                    // Удаляем символ из консоли
                }
            }
            else if (isdigit(ch) && data.size() < 3) { // Если символ - цифра
                data += ch;
                cout << ch; // Выводим символ на консоль
                // Отмечаем, что первая цифра введена
            }
        }
    }
    cout << "\n";
    return data;
}
string cinPassword() {
    string data;
    char ch;
    while (true) {
        if (_kbhit()) { // Проверяем, нажата ли клавиша
            ch = _getch(); // Считываем символ
            if (ch == 27) { // ASCII код для Escape
                return "`"; // Возвращаем пустую строку при нажатии Escape
            }
            else if (ch == '\r') { // Если нажата Enter
                break; // Выходим из цикла
            }
            else if (ch == '\b') { // Если нажата Backspace
                if (!data.empty()) {
                    data.pop_back();
                    cout << "\b \b"; // Удаляем символ из консоли
                }
            }
            else if (ch!=' ' && !isCyrillic(ch)) {
                data += ch;
                cout << "*"; // Выводим символ на консоль
            }
        }
    }
    cout << "\n";
    return data;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_THICKFRAME);
    SetWindowLongPtr(consoleWindow, GWL_STYLE, GetWindowLongPtr(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX);
    SetWindowPos(consoleWindow, NULL, 0, 0, 800, 700, SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
    States states;
    User user;
    DBAds DBads;
    carMB carmb;
    Filter filter;
    bool run = true;
    while (run) {
        if (states.current_state == "main_menu") {
            system("mode con cols=150 lines=55");
            coutFromFile("./ASCII/main_menu.txt");
            char key = _getch();
            switch (key) {
            case '1':
                system("cls");
                states.setState("check_ads");
                break;
            case '2':
                system("cls");
                states.setState("registration");
                break;
            case '3':
                system("cls");
                states.setState("authorization");
                break;
            case 27:
                exit(0);
            default:
                break;
            }
        }
        else if (states.current_state == "check_ads") { // СДЕЛАТЬ ФИЛЬТР ОБЯЗАТЕЛЬНО
            system("mode con cols=100 lines=59");
            vector<vector<string>> ads = DBads.getAllAds();
            string asd;
            string avto_cout="     | Автомобиль ";
            string year_cout="     | Год выпуска: ";
            string price_cout="     | Цена в BYN: ";
            string place_cout = "     | Место нахождения: ";
            string opisanie_cout="     | Описание: ";
            string date_cout="     | Дата публикации: ";
            int page=1;
            int start = 0;
            int end = 5;
            int five = 5;
            bool esc = false;
            int max_page = 0;
            while (true) {
                if (filter.brand != "none") {
                    ads = DBads.getAllAdsByBrand(filter.brand);
                }
                else if (filter.model != "none") {
                    ads = DBads.getAllAdsByModel(filter.model);
                }
                else if (filter.price != "none") {
                    ads = DBads.getAllAdsByPrice(filter.price,filter.max_price);
                }
                else if (filter.place != "none") {
                    ads = DBads.getAllAdsByPlace(filter.place);
                }
                else {
                    ads = DBads.getAllAds();
                }
                system("cls");
                coutFromFile("./ASCII/ads.txt");
                max_page = ads.size() / 5;
                if (ads.size() % 5 > 0) {
                    max_page += 1;
                }
                else if (ads.size() < 5) {
                    max_page = 1;
                    five = ads.size();
                }
                end = five;
                start = 0;
                cout << "     ==========================================================================================  \n";
                if (ads.size() == 0) {
                    cout << "     |                              Еще нет активных объявлений!                              |  \n";
                    cout << "     ==========================================================================================  \n";
                }
                if (page <= 0) {// если page 1 и мы нажали q
                    if (max_page == 1) {
                        page = 1;
                        start = 0;
                        end = five;
                    }
                    else {
                        page = max_page;
                        start = ((page - 1) * 5);
                        end = ads.size();
                    }
                    
                }
                
                else if (page > max_page) { // если page последняя и мы нажали e
                    page = 1;
                    start = 0;
                    end = five;
                }
                if (end * page > ads.size()) {
                    start = ((page - 1) * 5);
                    end = ads.size();
                }
                else if ((page == 1) && (end * page > ads.size())) {
                    start = ((page - 1) * 5);
                    end = ads.size();
                }
                else {
                    start = (page - 1) * 5;
                    end = five * page;
                }
                for (int i = start; i < end; i++) {
                    vector<string> current_user = user.getUserByID(ads[i][9]);
                    avto_cout = avto_cout + ads[i][0] + " " + ads[i][1];
                    for (int k = avto_cout.size(); k < 63; k++) {
                        avto_cout += " ";
                    }
                    avto_cout += "|      Контактные данные:      |";
                    cout << avto_cout << "\n";
                    avto_cout = "     | Автомобиль ";
                    year_cout = year_cout + ads[i][2];
                    for (int k = year_cout.size(); k < 63; k++) {
                        year_cout += " ";
                    }
                    year_cout += "|";
                    for (int k = year_cout.size(); k < 63 + ((33 - current_user[5].size()) / 2); k++) {
                        year_cout += " ";
                    }
                    year_cout += current_user[5];
                    for (int k = year_cout.size(); k < 93; k++) {
                        year_cout += " ";
                    }
                    year_cout += " |";
                    cout << year_cout << "\n";
                    year_cout = "     | Год выпуска: ";
                    price_cout = price_cout + ads[i][4];
                    for (int k = price_cout.size(); k < 63; k++) {
                        price_cout += " ";
                    }
                    price_cout += "|";
                    for (int k = price_cout.size(); k < 63 + ((33 - current_user[4].size()) / 2); k++) {
                        price_cout += " ";
                    }
                    price_cout += current_user[4];
                    for (int k = price_cout.size(); k < 93; k++) {
                        price_cout += " ";
                    }
                    price_cout += " |";
                    cout << price_cout << "\n";
                    price_cout = "     | Цена в BYN: ";
                    place_cout = place_cout + ads[i][3];
                    for (int k = place_cout.size(); k < 63; k++) {
                        place_cout += " ";
                    }
                    place_cout += "|";
                    for (int k = place_cout.size(); k < 63 + ((33 - current_user[3].size()) / 2); k++) {
                        place_cout += "_";
                    }
                    place_cout += current_user[3];
                    for (int k = place_cout.size(); k < 93; k++) {
                        place_cout += "_";
                    }
                    place_cout += "_|";
                    cout << place_cout << "\n";
                    place_cout = "     | Место нахождения: ";
                    opisanie_cout = opisanie_cout + ads[i][5];
                    for (int k = opisanie_cout.size(); k < 93; k++) {
                        opisanie_cout += " ";
                    }
                    opisanie_cout += " |";
                    cout << opisanie_cout << "\n";
                    opisanie_cout = "     | Описание: ";
                    date_cout = date_cout + ads[i][6];
                    for (int k = date_cout.size(); k < 93; k++) {
                        date_cout += " ";
                    }
                    date_cout += " |";
                    cout << date_cout << "\n";
                    date_cout = "     | Дата публикации: ";
                    if (i == 4) {

                        cout << "     ==========================================================================================  \n";
                    }
                    else {
                        
                        cout << "     |----------------------------------------------------------------------------------------|  \n";
                    }
                    
                }
                cout << "\n                                        Страница " << page << " из " << max_page << ".\n";
                if (user.status_user == "0" || user.status_user == "1") {
                    cout << "\n     ESC - выход в личный кабинет. Q - предыдущая страница. E - следующая страница. H - фильтр.\n";
                }
                else {
                    cout << "\n      ESC - выход в главное меню. Q - предыдущая страница. E - следующая страница. H - фильтр.\n";
                }
                
                char key = _getch();
                
                switch (key) {
                case 27:
                    if (user.status_user == "0") {
                        system("cls");
                        states.setState("lk");
                        filter.setBrand("none");
                        filter.setModel("none");
                        filter.setPrice("none");
                        filter.setPlace("none");
                        esc = true;
                        break;
                    }
                    else if (user.status_user == "1") {
                        system("cls");
                        states.setState("lk_a");
                        filter.setBrand("none");
                        filter.setModel("none");
                        filter.setPrice("none");
                        filter.setPlace("none");
                        esc = true;
                        break;
                    }
                    else {
                        system("cls");
                        states.setState("main_menu");
                        filter.setBrand("none");
                        filter.setModel("none");
                        filter.setPrice("none");
                        filter.setPlace("none");
                        esc = true;
                        break;
                    }
                    
                case 'q':
                    system("cls");
                    page -= 1;
                    start -= 5;
                    end -= 5;
                    break;
                case 'Q':
                    system("cls");
                    page -= 1;
                    start -= 5;
                    end -= 5;
                    break;
                case 'й':
                    system("cls");
                    page -= 1;
                    start -= 5;
                    end -= 5;
                    break;
                case 'e':
                    system("cls");
                    page += 1;
                    start += 5;
                    end += 5;
                    break;
                case 'у':
                    system("cls");
                    page += 1;
                    start += 5;
                    end += 5;
                    break;
                case 'E':
                    system("cls");
                    page += 1;
                    start += 5;
                    end += 5;
                    break;
                case 'h':
                    system("cls");
                    states.setState("filter");  
                    esc = true;
                    break;
                case 'H':
                    system("cls");
                    states.setState("filter");
                    esc = true;
                    break;
                case 'р':
                    system("cls");
                    states.setState("filter");
                    esc = true;
                    break;
                default:
                    break;
                }
                if (esc == true) {
                    break;
                }
            }
            
        }
        else if (states.current_state == "filter") {
            system("cls");
            bool go_away = false;
            while (true) {
                system("mode con cols=73 lines=15");
                coutFromFile("./ASCII/filter.txt");
                cout << "\n  =====================================================================\n";
                cout << "  |                     Выберите фильтрацию:                          |" << "\n";
                cout << "  |                     1. По бренду автомобиля.                      |\n"; // сделано
                cout << "  |                     2. По модели автомобиля.                      |\n"; // НЕ сделано
                cout << "  |                     3. По цене.                                   |\n"; // НЕ сделано
                cout << "  |                     4. По месту расположения.                     |\n"; // НЕ сделано
                cout << "  |                     ESC. Вернуться в просмотр объявлений.         |\n"; // сделано
                cout << "  =====================================================================\n";
                char key = _getch();
                switch (key) {
                case '1':
                    system("cls");
                    states.setState("filter_brand");
                    go_away = true;
                    break;
                case '2':
                    system("cls");
                    states.setState("filter_model");
                    go_away = true;
                    break;
                case '3':
                    system("cls");
                    states.setState("filter_price");
                    go_away = true;
                    break;

                case '4':
                    system("cls");
                    states.setState("filter_place");
                    go_away = true;
                    break;
                case 27:
                    system("cls");
                    states.setState("check_ads");
                    go_away = true;
                    break;
                default:
                    break;
                }
                if (go_away == true) {
                    break;
                }
            }
        }
        else if (states.current_state == "filter_brand") {
            system("cls");
            string new_car_model;
            string num_b;
            int count_errors = 0;

            bool esc = false;
            int cols = 73;
            int num_bb = 0;
            bool next = false;
            vector<string> car_brands = carmb.getAllBrands();
            system("mode con cols=73 lines=35");
            coutFromFile("./ASCII/filter.txt");
            cout << "\nESC - выход в просмотр объявлений.\n";
            cout << "\nБренды:\n";
            for (int i = 0; i < car_brands.size(); i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i + 1 << ". " << car_brands[i] << ".  ";

            }
            cout << "\n";
            cout << "\nВыберите номер бренда, по которому хотите отфильтровать объявления: ";
            while (next == false) {
                num_b = cinNumb();
                if (num_b == "`") {
                    states.setState("filter");
                    esc = true;
                    break;
                }
                if (num_b == "") {
                    cout << "Неверный ввод числа. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                    continue;
                }
                num_bb = stoi(num_b);
                if (num_bb > car_brands.size()) {
                    cout << "Число не должно превышать " << car_brands.size() << ". Введите новое число: ";
                    num_b = "";
                    count_errors += 1;

                }
                else if (num_bb <= 0) {
                    cout << "Число меньше либо равно нулю. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Бренд: " << car_brands[num_bb - 1];
                    
                    cout << "\n\nПереход в просмотр объявлений...";
                    Sleep(1500);
                    states.setState("check_ads");
                    filter.setFilter("brand");
                    filter.setBrand(car_brands[num_bb - 1]);
                    next = true;
                    count_errors = 0;
                    break;
                }
            }
            if (esc == true) {
                continue;
            }

        }
        else if (states.current_state == "filter_model") {
            system("cls");
            string new_car_model;
            string num_b;
            string num_m;
            int count_errors = 0;

            bool esc = false;
            int cols = 73;
            int num_bb = 0;
            int num_mm = 0;
            bool next = false;
            vector<string> car_brands = carmb.getAllBrands();
            system("mode con cols=73 lines=40");
            coutFromFile("./ASCII/filter.txt");
            cout << "\nESC - выход в просмотр объявлений.\n";
            cout << "\nБренды:\n";
            for (int i = 0; i < car_brands.size(); i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i + 1 << ". " << car_brands[i] << ".  ";

            }
            cout << "\n";
            cout << "\nВыберите номер бренда: ";
            while (next == false) {
                num_b = cinNumb();
                if (num_b == "`") {
                    states.setState("filter");
                    esc = true;
                    break;
                }
                if (num_b == "") {
                    cout << "Неверный ввод числа. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                    continue;
                }
                num_bb = stoi(num_b);
                if (num_bb > car_brands.size()) {
                    cout << "Число не должно превышать " << car_brands.size() << ". Введите новое число: ";
                    num_b = "";
                    count_errors += 1;

                }
                else if (num_bb <= 0) {
                    cout << "Число меньше либо равно нулю. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Бренд: " << car_brands[num_bb - 1];

                    
                    next = true;
                    count_errors = 0;
                    break;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            vector<string> models = carmb.getAllModelsByBrand(car_brands[num_bb - 1]);
            cout << "\n\nМодели:\n";
            for (int i = 0; i < models.size(); i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i + 1 << ". " << models[i] << ".  ";

            }
            cout << "\n";
            cout << "\nВыберите модель, по которой хотите отфильтровать объявления: ";
            while (next == false) {
                num_m = cinNumb();
                if (num_m == "`") {
                    states.setState("filter");

                    esc = true;
                    break;
                }
                if (num_m == "") {
                    cout << "Неверный ввод. Введите новое число: ";
                    num_m = "";
                    count_errors += 1;
                }
                num_mm = stoi(num_m);
                if (num_mm <= 0) {
                    cout << "Число меньше либо равно нулю. Введите новое число: ";
                    num_m = "";
                    count_errors += 1;
                }
                else if (num_mm > car_brands.size()) {
                    cout << "Число не должно превышать " << car_brands.size() << ". Введите новое число: ";
                    num_m = "";
                    count_errors += 1;

                }
                else {
                    clearCout(count_errors, 100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Модель: " << models[num_mm - 1];
                    cout << "\n\nПереход в просмотр объявлений...";
                    Sleep(1500);
                    states.setState("check_ads");
                    filter.setModel(models[num_mm - 1]);
                    next = true;
                    count_errors = 0;
                    break;
                }
            }
            if (esc == true) {
                continue;
            }

        }
        else if (states.current_state == "filter_price") {
            bool next = false;
            bool esc = false;
            string price = "";
            string max_price = "";
            int count_errors = 0;
            system("mode con cols=73 lines=15");
            coutFromFile("./ASCII/filter.txt");
            cout << "\nESC - выход в просмотр объявлений.\n";
            cout << "\nВведите минимальную цену автомобиля в BYN: ";
            while (next == false) {
                price = cinPrice();
                if (price == "`") {
                    states.setState("filter");
                    esc = true;
                    break;
                }
                if (price == "") {
                    cout << "Неверный ввод. Введите минимальную цену автомобиля в BYN заново:\n";
                    price = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 73);
                    cout << "Минимальная цена автомобиля в BYN: " << price << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите максимальную цену автомобиля в BYN: ";
            while (next == false) {
                max_price = cinPrice();
                if (max_price == "`") {
                    states.setState("filter");
                    esc = true;
                    break;
                }
                if (max_price == "") {
                    cout << "Неверный ввод. Введите максимальную цену автомобиля в BYN заново:\n";
                    max_price = "";
                    count_errors += 2;
                }
                else if (stoi(price) > stoi(max_price)) {
                    cout << "Неверный ввод. Введите максимальную цену автомобиля в BYN заново:\n";
                    max_price = "";
                    count_errors += 2;
                }
                else {
                    clearCout(count_errors, 73);
                    cout << "Максимальная цена автомобиля в BYN: " << max_price << "\n";
                    cout << "\nПереход в просмотр объявлений...";
                    Sleep(1500);
                    states.setState("check_ads");
                    filter.setPrice(price);
                    filter.setMaxPrice(max_price);
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
             
        }
        else if (states.current_state == "filter_place") {
            string place = "";
            bool next = false;
            bool esc = false;
            int count_errors = 0;
            system("mode con cols=73 lines=15");
            coutFromFile("./ASCII/filter.txt");
            cout << "\nESC - выход в просмотр объявлений.\n";
            cout << "\nВведите место, по которому хотите отфильтровать объявления:\n";
            while (next == false) {
                place = cinPlace();
                if (place == "`") {
                    states.setState("filter");
                    esc = true;
                    break;
                }
                if (place == "") {
                    cout << "Неверный ввод. Введите место заново: ";
                    place = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors+1, 73);
                    cout << "Место нахождения автомобиля: " << place << "\n";
                    cout << "\nПереход в просмотр объявлений...";
                    Sleep(1500);
                    states.setState("check_ads");
                    filter.setPlace(place);
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
        }
        else if (states.current_state == "registration") {
            string login;
            string email;
            string num;
            string name;
            string password;
            string rep_password;
            int count_errors = 0;
            bool next = false;
            bool esc = false;
            system("mode con cols=73 lines=25");
            coutFromFile("./ASCII/registration.txt");
            cout << "\nESC - выход в главное меню.\n";
            cout << "\nВведите логин: ";
            while (next == false) {
                login = cinLogin();
                if (login == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                else if (login=="") {
                    cout << "Неверный логин. Введите другой логин: ";
                    login = "";
                    count_errors += 1;
                }
                if (user.checkLogin(login) == true) {
                    cout << "Такой логин уже используется. Введите другой логин: ";
                    login = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors,73);
                    cout << "Логин: " << login << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите email: ";
            while (next == false) {
                email = cinString();
                size_t found = email.find('@');
                if (email == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                if (user.checkEmail(email) == true) {
                    cout << "Такая почта уже используется. Введите другую почту: ";
                    count_errors += 1;
                }
                else if (email.size()<=5) {
                    cout << "Слишком короткая почта. Введите другую почту: ";
                    count_errors += 1;
                }
                else if (found==string::npos) {
                    cout << "Не найдена @ в почте. Введите другую почту: ";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors,73);
                    cout << "Почта: " << email << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите номер телефона: ";
            while (next == false) {
                num = cinNum();
                if (num == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                if (user.checkNum(num) == true) {
                    cout << "Такой номер телефона уже используется.\nВведите другой номер телефона: ";
                    count_errors += 2;
                }
                else if (num.size()<7) {
                    cout << "Неверная длина номера телефона.\nВведите другой номер телефона: ";
                    count_errors += 2;
                }
                else {
                    clearCout(count_errors,73);
                    cout << "Номер телефона: " << num << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            cout << "\nВведите имя: ";
            next = false;
            while (next == false) {
                name = cinName();
                if (name == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                else if (name == "") {
                    cout << "Неверное имя. Введите другое имя: ";
                    name = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 73);
                    cout << "Имя: " << name << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            
            next = false;
            cout << "\nВведите пароль: ";
            while (next == false) {
                password = cinPassword();
                if (password == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                if (password.size() < 6) {
                    cout << "Минимальная длина пароля - 6 символов. Введите пароль заново: ";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors,73);
                    cout << "Пароль: ";
                    for (int i = 0; i < password.size(); i++) {
                        cout << "*";
                    }
                    cout << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            
            if (esc == true) {
                continue;
            }
            cout << "\nВведите повторно пароль: ";
            next = false;
            while (next == false) {
                rep_password = cinPassword();
                if (rep_password == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                if (password == rep_password) {
                    user.Registration(login, email, num, name, password);
                    if (user.checkStatus(login) == true) {
                        states.setState("lk_a");
                        count_errors = 0;
                        break;
                    }
                    clearCout(count_errors, 73);
                    cout << "Повторный пароль: ";
                    for (int i = 0; i < password.size(); i++) {
                        cout << "*";
                    }
                    cout << "\n";
                    states.setState("lk");
                    cout << "\nУспешная регистрация! Переход в личный кабинет...";
                    Sleep(1500);
                    count_errors = 0;
                    break;
                }
                else {
                    cout << "Ваш пароль не совпадает. Введите пароль заново: ";
                    count_errors += 1;
                }
            }
            if (esc == true) {
                continue;
            }
        }
        else if (states.current_state == "authorization") {
            string login;
            string password;
            int count_errors = 0;
            bool next = false;
            bool esc = false;
            int cols = 82;
            system("mode con cols=82 lines=14");
            coutFromFile("./ASCII/authorization.txt");
            cout << "\nESC - выход в главное меню.\n";
            cout << "\nВведите логин: ";
            while (next == false) {
                login = cinLogin();
                if (login == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                if (user.checkLogin(login) == true) {
                    clearCout(count_errors, cols);
                    cout << "Логин: " << login << "\n";
                    next = true;
                    count_errors = 0;
                    
                }
                else {
                    cout << "Такого логина не существует. Введите логин заново: ";
                    login = "";
                    count_errors += 1;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите пароль: ";
            while (next == false) {
                password = cinPassword();
                if (password == "`") {
                    states.setState("main_menu");
                    esc = true;
                    break;
                }
                if (user.checkPassword(login, password) == true) {
                    clearCout(count_errors, cols);
                    cout << "Пароль: ";
                    for (int i = 0; i < password.size(); i++) {
                        cout << "*";
                    }
                    cout << "\n";
                    next = true;
                    user.Authorization(login);
                    cout << "\nУспешная авторизация! Переход в личный кабинет...";
                    Sleep(1500);
                    if (user.checkStatus(login) == true) {
                        states.setState("lk_a");
                        count_errors = 0;
                        break;
                    }
                    
                    states.setState("lk");
                    count_errors = 0;
                    break;
                }
                else {
                    cout << "Пароль неверный. Введите пароль заново: ";
                    password = "";
                    count_errors += 1;
                }
            }
            if (esc == true) {
                continue;
            }
        }
        else if (states.current_state == "lk") {
            
            bool go_away = false;
            //cout << "ЛИЧНЫЙ КАБИНЕТ\n";
            //cout << "Приветствуем, " << user.name<<"\n";
            //cout << user.id_user<<"\n";
            //cout << user.status_user << "\n";
            //cout << user.login << "\n";
            //cout << user.email << "\n";
            //cout << user.num << "\n";
            //cout << user.password << "\n";
            string hello = "  |                     Приветствуем, ";
            while (true) {
                system("cls");
                system("mode con cols=73 lines=15");
                coutFromFile("./ASCII/lk.txt");
                cout << "\n  =====================================================================\n";
                hello += user.name;
                hello += ".";
                for (int i = hello.size(); i < 70; i++) {
                    hello += " ";
                }
                hello += "|";
                cout << hello<<"\n";
                hello = "  |                     Приветствуем, ";
                cout << "  |                     1. Смотреть объявления.                       |\n"; // сделано
                cout << "  |                     2. Создать объявление.                        |\n"; // НЕ сделано
                cout << "  |                     3. Мои объявления.                            |\n"; // сделано + удаление
                cout << "  |                     4. Изменить пароль.                           |\n"; // сделано
                cout << "  |                     ESC. Выход из программы.                      |\n"; // сделано
                cout << "  =====================================================================\n";
                char key = _getch();
                switch (key) {
                case '1':
                    system("cls");
                    states.setState("check_ads");
                    go_away = true;
                    break;
                case '2':
                    system("cls");
                    states.setState("create_ad");
                    go_away = true;
                    break;
                case '3':
                    system("cls");
                    states.setState("my_ads");
                    go_away = true;
                    break;
                case '4':
                    system("cls");
                    states.setState("change_password");
                    go_away = true;
                    break;
                case 27:
                    exit(0);
                default:
                    break;
                }
                if (go_away == true) {
                    break;
                }
            }
        }
        else if (states.current_state == "lk_a") {
            system("cls");
            bool go_away = false;
            string hello = "  |                     Приветствуем, ";
            while (true) {
                system("mode con cols=73 lines=18");
                coutFromFile("./ASCII/lk.txt");
                cout << "\n  =====================================================================\n";
                hello += user.name;
                hello += ".";
                for (int i = hello.size(); i < 70; i++) {
                    hello += " ";
                }
                hello += "|";
                cout << hello << "\n";
                hello = "  |                     Приветствуем, ";
                cout << "  |                     1. Смотреть объявления.                       |\n"; // сделано ФИЛЬТР СДЕЛАТЬ
                cout << "  |                     2. Создать объявление.                        |\n"; // НЕ сделано
                cout << "  |                     3. Мои объявления.                            |\n"; // сделано + удаление
                cout << "  |                     4. Объявления на модерации.                   |\n"; // сделано
                cout << "  |                     5. Изменить пароль.                           |\n"; // сделано
                cout << "  |                     6. Добавление бренда автомобиля.              |\n"; // сделано
                cout << "  |                     7. Добавление модели автомобиля.              |\n"; // сделано
                cout << "  |                     ESC. Выход из программы.                      |\n"; // сделано
                cout << "  =====================================================================\n";
                char key = _getch();
                switch (key) {
                case '1':
                    system("cls");
                    states.setState("check_ads");
                    go_away = true;
                    break;
                case '2':
                    system("cls");
                    states.setState("create_ad");
                    go_away = true;
                    break;
                case '3':
                    system("cls");
                    states.setState("my_ads");
                    go_away = true;
                    break;

                case '4':
                    system("cls");
                    states.setState("ads_on_moderate");
                    go_away = true;
                    break;
                case '5':
                    system("cls");
                    states.setState("change_password");
                    go_away = true;
                    break;
                case '6':
                    system("cls");
                    states.setState("add_car_brand");
                    go_away = true;
                    break;
                case '7':
                    system("cls");
                    states.setState("add_car_model");
                    go_away = true;
                    break;
                case 27:
                    exit(0);
                default:
                    break;
                }
                if (go_away == true) {
                    break;
                }
            }
        }
        else if (states.current_state == "change_password") {
            system("cls");
            string new_password;
            string password;
            int count_errors = 0;
            bool next = false;
            bool esc = false;
            int cols = 99;
            system("mode con cols=99 lines=15");
            coutFromFile("./ASCII/change_password.txt");
            cout << "\nESC - выход в личный кабинет.\n";
            cout << "\nВведите старый пароль: ";
            while (next == false) {
                password = cinPassword();
                if (password == "`") {
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    esc = true;
                    break;
                }
                if (user.checkPassword(user.login, password) == true) {
                    clearCout(count_errors, cols);
                    cout << "Пароль: ";
                    for (int i = 0; i < password.size(); i++) {
                        cout << "*";
                    }
                    cout << "\n";
                    next = true;
                    count_errors = 0;
                    break;
                }
                else {
                    cout << "Пароль неверный. Введите пароль заново: ";
                    password = "";
                    count_errors += 1;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите новый пароль: ";
            while (next == false) {
                new_password = cinPassword();
                if (new_password == "`") {
                    states.setState("lk");
                    esc = true;
                    break;
                }
                else if (new_password.size() < 6) {
                    cout << "Минимальная длина пароля - 6 символов. Введите пароль заново: ";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, cols);
                    cout << "Новый пароль: ";
                    for (int i = 0; i < new_password.size(); i++) {
                        cout << "*";
                    }
                    user.changePassword(user.id_user, new_password);
                    cout << "\n";
                    cout << "\nПароль успешно изменен! Переход в личный кабинет...";
                    Sleep(1500);
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                
                continue;
            }
        }
        else if (states.current_state == "create_ad") {
            system("cls");
            string car_model;
            string num_b;
            string num_m;
            string year;
            string place;
            string price;
            string opisanie;
            int count_errors = 0;
            int count_n = 0;
            bool esc = false;
            int cols = 82;
            int num_bb = 0;
            int num_mm = 0;
            bool next = false;
            vector<string> car_brands = carmb.getAllBrands();
            system("mode con cols=80 lines=59");
            coutFromFile("./ASCII/create_ad.txt");
            cout << "\nESC - выход в личный кабинет.\n";
            cout << "\nУже добавленные бренды:\n";

            for (int i = 0; i < car_brands.size(); i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << "\n";
                    count_n += 1;
                }
                vector<string> cm = carmb.getAllModelsByBrand(car_brands[i]);
                if (cm.size() !=0) {
                    cout << i + 1 << ". " << car_brands[i] << ".  ";
                }
                else {
                    car_brands.erase(car_brands.begin() + i);
                }
            }
            cout << "\n";
            cout << "\nВыберите номер бренда, машину которого вы собираетесь продать: ";
            while (next == false) {
                num_b = cinNumb();
                if (num_b == "`") {
                    states.setState("lk_a");
                    esc = true;
                    break;
                }
                if (num_b == "") {
                    cout << "Неверный ввод. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                }
                num_bb = stoi(num_b);
                if (num_bb <= 0) {
                    cout << "Число меньше либо равно нулю. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                }
                else if (num_bb > car_brands.size()) {
                    cout << "Число не должно превышать " << car_brands.size() << ". Введите новое число: ";
                    num_b = "";
                    count_errors += 1;

                }
                else {
                    clearCout(count_errors, 100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Бренд: " << car_brands[num_bb - 1];
                    cout << "\n";
                    next = true;
                    count_errors = 0;
                    break;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            vector<string> models = carmb.getAllModelsByBrand(car_brands[num_bb - 1]);
            cout << "\nМодели:\n";

            for (int i = 0; i < models.size(); i++) {
                if (i % 4 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i + 1 << ". " << models[i] << ".  ";

            }
            cout << "\n";
            cout << "\nВыберите номер модели, машину которой вы собираетесь продать: ";
            while (next == false) {
                num_m = cinNumb();
                if (num_m == "`") {
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    
                    esc = true;
                    break;
                }
                if (num_m == "") {
                    cout << "Неверный ввод. Введите новое число: ";
                    num_m = "";
                    count_errors += 1;
                }
                num_mm = stoi(num_m);
                if (num_mm <= 0) {
                    cout << "Число меньше либо равно нулю. Введите новое число: ";
                    num_m = "";
                    count_errors += 1;
                }
                else if (num_mm > car_brands.size()) {
                    cout << "Число не должно превышать " << car_brands.size() << ". Введите новое число: ";
                    num_m = "";
                    count_errors += 1;

                }
                else {
                    clearCout(count_errors, 100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Модель: " << models[num_mm - 1];
                    cout << "\n";
                    next = true;
                    count_errors = 0;
                    break;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите год выпуска автомобиля: ";
            int yearr = 0;
            while (next == false) {
                year = cinYear();
                if (year == "`") {
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    esc = true;
                    break;
                }
                
                if (year=="") {
                    cout << "Неверный ввод. Введите год выпуска автомобиля заново: ";
                    year = "";
                    count_errors += 1;
                    continue;
                }
                yearr = stoi(year);
                if (yearr > 2024 || yearr<1800) {
                    cout << "Неверный ввод. Введите год выпуска автомобиля заново: ";
                    year = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 73);
                    cout << "Год выпуска автомобиля: " << year << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите место нахождения автомобиля: ";
            while (next == false) {
                place = cinPlace();
                if (place == "`") {
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    esc = true;
                    break;
                }
                if (place == "") {
                    cout << "Неверный ввод. Введите место нахождения автомобиля заново: ";
                    place = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 73);
                    cout << "Место нахождения автомобиля: " << place << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите цену автомобиля в BYN: ";
            while (next == false) {
                price = cinPrice();
                if (price == "`") {
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    esc = true;
                    break;
                }
                if (price == "") {
                    cout << "Неверный ввод. Введите цену автомобиля в BYN заново: ";
                    price = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 73);
                    cout << "Цена автомобиля в BYN: " << price << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            cout << "\nВведите описание автомобиля (минимум 10 символов, максимум 78 символов):\nТак же в описании укажите пробег.\n";
            while (next == false) {
                opisanie = cinOpisanie();
                if (opisanie == "`") {
                    if (user.status_user == "0") {
                        states.setState("lk");
                    }
                    else {
                        states.setState("lk_a");
                    }
                    esc = true;
                    break;
                }
                if (opisanie == "" || opisanie.size()<10) {
                    cout << "Неверный ввод. Введите описание автомобиля заново: ";
                    opisanie = "";
                    count_errors += 2;
                }
                else {
                    clearCout(count_errors+2, 73);
                    cout << "Описание автомобиля: " << opisanie << "\n";
                    next = true;
                    count_errors = 0;
                }
            }
            if (esc == true) {
                continue;
            }
            auto now = chrono::system_clock::now();
            time_t current_time = chrono::system_clock::to_time_t(now);

            // Конвертируем в структуру tm
            tm local_time;
            localtime_s(&local_time, &current_time); // Используем localtime_s вместо localtime
            stringstream strs;
            strs << put_time(&local_time, "%d.%m.%Y");

            // Получаем строку из потока
            string date_string = strs.str();

            // Форматируем и выводим дату
            DBads.createAd(car_brands[num_bb - 1], models[num_mm - 1], year, place, price, opisanie,user.id_user, date_string);
            cout << "\nМодель машины успешно добавлена! Переход в личный кабинет...";
            Sleep(1500);
            if (user.status_user == "0") {
                states.setState("lk");
            }
            else {
                states.setState("lk_a");
            }
            
            
        }
        else if (states.current_state == "my_ads") {
            system("cls");
            system("mode con cols=100 lines=62");
            vector<vector<string>> ads = DBads.getAdsByID(stoi(user.id_user));
            vector<string> id_cu;
            for (int id = 0; id < ads.size(); id++) {
                id_cu.push_back(ads[id][7]);
            }
            string asd;
            string avto_cout = "     | Автомобиль ";
            string year_cout = "     | Год выпуска: ";
            string price_cout = "     | Цена в BYN: ";
            string place_cout = "     | Место нахождения: ";
            string opisanie_cout = "     | Описание: ";
            string date_cout = "     | Дата публикации: ";
            string status_cout = "     | Статус объявления: ";
            string id_cout = "     | ID объявления: ";
            string cause_cout = "     | Причина неактивности объявления: ";
            string status = "";

            int page = 1;
            int start = 0;
            int end = 4;
            int five = 4;
            bool esc = false;
            bool nextt = false;
            int max_page = 0;
            string num_ad ="";
            int num_add = 0;
            int count_errors = 0;
            while (true) {
                vector<vector<string>> ads = DBads.getAdsByID(stoi(user.id_user));
                vector<string> id_cu;
                for (int id = 0; id < ads.size(); id++) {
                    id_cu.push_back(ads[id][7]);
                }
                system("cls");
                coutFromFile("./ASCII/my_ads.txt");
                max_page = ads.size() / 4;
                if (ads.size() % 4 > 0) {
                    max_page += 1;
                }
                else if (ads.size() < 4) {
                    max_page = 1;
                    five = ads.size();
                }
                end = five;
                start = 0;
                cout << "     ==========================================================================================  \n";
                if (ads.size() == 0) {
                    cout << "     |                                У Вас еще нет объявлений!                               |  \n";
                    cout << "     ==========================================================================================  \n";
                }

                if (page <= 0) {// если page 1 и мы нажали q
                    if (max_page == 1) {
                        page = 1;
                        start = 0;
                        end = five;
                    }
                    else {
                        page = max_page;
                        start = ((page - 1) * 4);
                        end = ads.size();
                    }

                }

                else if (page > max_page) { // если page последняя и мы нажали e
                    page = 1;
                    start = 0;
                    end = five;
                }
                if (end * page > ads.size()) {
                    start = ((page - 1) * 4);
                    end = ads.size();
                }
                else if ((page == 1) && (end * page > ads.size())) {
                    start = ((page - 1) * 4);
                    end = ads.size();
                }
                else {
                    start = (page - 1) * 4;
                    end = five * page;
                }
                for (int i = start; i < end; i++) {

                    vector<string> current_user = user.getUserByID(ads[i][9]);
                    avto_cout = avto_cout + ads[i][0] + " " + ads[i][1];
                    for (int k = avto_cout.size(); k < 63; k++) {
                        avto_cout += " ";
                    }
                    avto_cout += "|      Контактные данные:      |";
                    cout << avto_cout << "\n";
                    avto_cout = "     | Автомобиль ";
                    year_cout = year_cout + ads[i][2];
                    for (int k = year_cout.size(); k < 63; k++) {
                        year_cout += " ";
                    }
                    year_cout += "|";
                    for (int k = year_cout.size(); k < 63 + ((33 - current_user[5].size()) / 2); k++) {
                        year_cout += " ";
                    }
                    year_cout += current_user[5];
                    for (int k = year_cout.size(); k < 93; k++) {
                        year_cout += " ";
                    }
                    year_cout += " |";
                    cout << year_cout << "\n";
                    year_cout = "     | Год выпуска: ";
                    price_cout = price_cout + ads[i][4];
                    for (int k = price_cout.size(); k < 63; k++) {
                        price_cout += " ";
                    }
                    price_cout += "|";
                    for (int k = price_cout.size(); k < 63 + ((33 - current_user[4].size()) / 2); k++) {
                        price_cout += " ";
                    }
                    price_cout += current_user[4];
                    for (int k = price_cout.size(); k < 93; k++) {
                        price_cout += " ";
                    }
                    price_cout += " |";
                    cout << price_cout << "\n";
                    price_cout = "     | Цена в BYN: ";
                    place_cout = place_cout + ads[i][3];
                    for (int k = place_cout.size(); k < 63; k++) {
                        place_cout += " ";
                    }
                    place_cout += "|";
                    for (int k = place_cout.size(); k < 63 + ((33 - current_user[3].size()) / 2); k++) {
                        place_cout += "_";
                    }
                    place_cout += current_user[3];
                    for (int k = place_cout.size(); k < 93; k++) {
                        place_cout += "_";
                    }
                    place_cout += "_|";
                    cout << place_cout << "\n";
                    place_cout = "     | Место нахождения: ";
                    opisanie_cout = opisanie_cout + ads[i][5];
                    for (int k = opisanie_cout.size(); k < 93; k++) {
                        opisanie_cout += " ";
                    }
                    opisanie_cout += " |";
                    cout << opisanie_cout << "\n";
                    opisanie_cout = "     | Описание: ";
                    date_cout = date_cout + ads[i][6];
                    for (int k = date_cout.size(); k < 93; k++) {
                        date_cout += " ";
                    }
                    date_cout += " |";
                    cout << date_cout << "\n";
                    date_cout = "     | Дата публикации: ";
                    if (ads[i][8] == "1") {
                        status ="Активно";


                    }
                    else if (ads[i][8]=="2") {
                        status = "На модерации";
                    }
                    else {
                        status = "Неактивно";
                    }
                    status_cout = status_cout + status;
                    for (int k = status_cout.size(); k < 93; k++) {
                        status_cout += " ";
                    }
                    status_cout += " |";
                    cout << status_cout << "\n";
                    status_cout = "     | Статус объявления: ";
                    if (status == "Неактивно") {
                        cause_cout = cause_cout + ads[i][10];
                        for (int k = cause_cout.size(); k < 93; k++) {
                            cause_cout += " ";
                        }
                        cause_cout += " |";
                        cout << cause_cout << "\n";
                        cause_cout = "     | Причина неактивности объявления: ";
                    }
                    
                    id_cout = id_cout + ads[i][7];
                    for (int k = id_cout.size(); k < 93; k++) {
                        id_cout += " ";
                    }
                    
                    id_cout += " |";
                    cout << id_cout << "\n";
                    id_cout = "     | ID объявления: ";
                    if (i == 4) {

                        cout << "     ==========================================================================================  \n";
                    }
                    else {

                        cout << "     |----------------------------------------------------------------------------------------|  \n";
                    }

                }
                cout << "\n                                        Страница " << page << " из " << max_page << ".\n";
                if (user.status_user == "0" || user.status_user == "1") {
                    cout << "\n           ESC - выход в личный кабинет. Q - предыдущая страница. E - следующая страница.\n                                    D - удалить объявление.";
                }

                char key = _getch();

                switch (key) {
                case 27:
                    if (user.status_user == "0") {
                        system("cls");
                        states.setState("lk");
                        esc = true;
                        break;
                    }
                    else if (user.status_user == "1") {
                        system("cls");
                        states.setState("lk_a");
                        esc = true;
                        break;
                    }
                    else {
                        system("cls");
                        states.setState("main_menu");
                        esc = true;
                        break;
                    }

                case 'q':
                    system("cls");
                    page -= 1;
                    start -= 4;
                    end -= 4;
                    break;
                case 'Q':
                    system("cls");
                    page -= 1;
                    start -= 4;
                    end -= 4;
                    break;
                case 'й':
                    system("cls");
                    page -= 1;
                    start -= 4;
                    end -= 4;
                    break;
                case 'e':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'E':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'у':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'd':
                    
                    cout << "\n           Выберите номер объявления, которое хотите удалить. \n           (Чтобы удалить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("my_ads");
                            esc = true;
                            break;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded==true) {
                            DBads.deleteAd(num_ad);
                            clearCout(count_errors+1, 100);
                            cout << "           Объявление c ID:"<<num_ad<<" успешно удалено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "           Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                case 'в':

                    cout << "\n           Выберите номер объявления, которое хотите удалить. \n           (Чтобы удалить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("my_ads");
                            esc = true;
                            break;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            DBads.deleteAd(num_ad);
                            clearCout(count_errors + 1, 100);
                            cout << "           Объявление c ID:" << num_ad << " успешно удалено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "           Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                case 'D':

                    cout << "\n           Выберите номер объявления, которое хотите удалить. \n           (Чтобы удалить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("my_ads");
                            esc = true;
                            break;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            DBads.deleteAd(num_ad);
                            clearCout(count_errors + 1, 100);
                            cout << "           Объявление c ID:" << num_ad << " успешно удалено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "           Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                    // СДЕЛАТЬ ФИЛЬТР
                default:
                    break;
                }
                if (esc == true) {
                    break;
                }

              
            }
        }
        else if (states.current_state == "ads_on_moderate") {
            system("cls");
            system("mode con cols=100 lines=63");
            vector<vector<string>> ads = DBads.getAdsByIDModerate();
            vector<string> id_cu;
            for (int id = 0; id < ads.size(); id++) {
                id_cu.push_back(ads[id][7]);
            }
            string asd;
            string avto_cout = "     | Автомобиль ";
            string year_cout = "     | Год выпуска: ";
            string price_cout = "     | Цена в BYN: ";
            string place_cout = "     | Место нахождения: ";
            string opisanie_cout = "     | Описание: ";
            string date_cout = "     | Дата публикации: ";
            string status_cout = "     | Статус объявления: ";
            string id_cout = "     | ID объявления: ";
            string status = "";
            int page = 1;
            int start = 0;
            int end = 4;
            int five = 4;
            bool esc = false;
            bool nextt = false;
            int max_page = 0;
            string num_ad = "";
            int num_add = 0;
            int count_errors = 0;
            while (true) {
                vector<vector<string>> ads = DBads.getAdsByIDModerate();
                vector<string> id_cu;
                for (int id = 0; id < ads.size(); id++) {
                    id_cu.push_back(ads[id][7]);
                }
                system("cls");
                coutFromFile("./ASCII/ads.txt");
                max_page = ads.size() / 4;
                if (ads.size() % 4 > 0) {
                    max_page += 1;
                }
                else if (ads.size() < 4) {
                    max_page = 1;
                    five = ads.size();
                }
                end = five;
                start = 0;
                cout << "     ==========================================================================================  \n";
                if (ads.size() == 0) {
                    cout << "     |                             Еще нет объявлений на модерации!                           |  \n";
                    cout << "     ==========================================================================================  \n";
                }

                if (page <= 0) {// если page 1 и мы нажали q
                    if (max_page == 1) {
                        page = 1;
                        start = 0;
                        end = five;
                    }
                    else {
                        page = max_page;
                        start = ((page - 1) * 4);
                        end = ads.size();
                    }

                }

                else if (page > max_page) { // если page последняя и мы нажали e
                    page = 1;
                    start = 0;
                    end = five;
                }
                if (end * page > ads.size()) {
                    start = ((page - 1) * 4);
                    end = ads.size();
                }
                else if ((page == 1) && (end * page > ads.size())) {
                    start = ((page - 1) * 4);
                    end = ads.size();
                }
                else {
                    start = (page - 1) * 4;
                    end = five * page;
                }
                for (int i = start; i < end; i++) {

                    vector<string> current_user = user.getUserByID(ads[i][9]);
                    avto_cout = avto_cout + ads[i][0] + " " + ads[i][1];
                    for (int k = avto_cout.size(); k < 63; k++) {
                        avto_cout += " ";
                    }
                    avto_cout += "|      Контактные данные:      |";
                    cout << avto_cout << "\n";
                    avto_cout = "     | Автомобиль ";
                    year_cout = year_cout + ads[i][2];
                    for (int k = year_cout.size(); k < 63; k++) {
                        year_cout += " ";
                    }
                    year_cout += "|";
                    for (int k = year_cout.size(); k < 63 + ((33 - current_user[5].size()) / 2); k++) {
                        year_cout += " ";
                    }
                    year_cout += current_user[5];
                    for (int k = year_cout.size(); k < 93; k++) {
                        year_cout += " ";
                    }
                    year_cout += " |";
                    cout << year_cout << "\n";
                    year_cout = "     | Год выпуска: ";
                    price_cout = price_cout + ads[i][4];
                    for (int k = price_cout.size(); k < 63; k++) {
                        price_cout += " ";
                    }
                    price_cout += "|";
                    for (int k = price_cout.size(); k < 63 + ((33 - current_user[4].size()) / 2); k++) {
                        price_cout += " ";
                    }
                    price_cout += current_user[4];
                    for (int k = price_cout.size(); k < 93; k++) {
                        price_cout += " ";
                    }
                    price_cout += " |";
                    cout << price_cout << "\n";
                    price_cout = "     | Цена в BYN: ";
                    place_cout = place_cout + ads[i][3];
                    for (int k = place_cout.size(); k < 63; k++) {
                        place_cout += " ";
                    }
                    place_cout += "|";
                    for (int k = place_cout.size(); k < 63 + ((33 - current_user[3].size()) / 2); k++) {
                        place_cout += "_";
                    }
                    place_cout += current_user[3];
                    for (int k = place_cout.size(); k < 93; k++) {
                        place_cout += "_";
                    }
                    place_cout += "_|";
                    cout << place_cout << "\n";
                    place_cout = "     | Место нахождения: ";
                    opisanie_cout = opisanie_cout + ads[i][5];
                    for (int k = opisanie_cout.size(); k < 93; k++) {
                        opisanie_cout += " ";
                    }
                    opisanie_cout += " |";
                    cout << opisanie_cout << "\n";
                    opisanie_cout = "     | Описание: ";
                    date_cout = date_cout + ads[i][6];
                    for (int k = date_cout.size(); k < 93; k++) {
                        date_cout += " ";
                    }
                    date_cout += " |";
                    cout << date_cout << "\n";
                    date_cout = "     | Дата публикации: ";
                    if (ads[i][8] == "1") {
                        status = "Активно";


                    }
                    else {
                        status = "На модерации";
                    }
                    status_cout = status_cout + status;
                    for (int k = status_cout.size(); k < 93; k++) {
                        status_cout += " ";
                    }
                    status_cout += " |";
                    cout << status_cout << "\n";
                    status_cout = "     | Статус объявления: ";
                    id_cout = id_cout + ads[i][7];
                    for (int k = id_cout.size(); k < 93; k++) {
                        id_cout += " ";
                    }
                    id_cout += " |";
                    cout << id_cout << "\n";
                    id_cout = "     | ID объявления: ";
                    if (i == 4) {

                        cout << "     ==========================================================================================  \n";
                    }
                    else {

                        cout << "     |----------------------------------------------------------------------------------------|  \n";
                    }

                }
                cout << "\n                                        Страница " << page << " из " << max_page << ".\n";
                if (user.status_user == "0" || user.status_user == "1") {
                    cout << "\n           ESC - выход в личный кабинет. Q - предыдущая страница. E - следующая страница.\n                        A - одобрить объявление. D - отклонить объявление.";
                }

                char key = _getch();

                switch (key) {
                case 27:
                    cout << user.status_user;
                    if (user.status_user == "0") {
                        system("cls");
                        states.setState("lk");
                        esc = true;
                        break;
                    }
                    else if (user.status_user == "1") {
                        system("cls");
                        states.setState("lk_a");
                        esc = true;
                        break;
                    }
                    else {
                        system("cls");
                        states.setState("main_menu");
                        esc = true;
                        break;
                    }

                case 'q':
                    system("cls");
                    page -= 1;
                    start -= 4;
                    end -= 4;
                    break;
                case 'e':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'й':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'у':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'Q':
                    system("cls");
                    page -= 1;
                    start -= 4;
                    end -= 4;
                    break;
                case 'E':
                    system("cls");
                    page += 1;
                    start += 4;
                    end += 4;
                    break;
                case 'a':

                    cout << "\n     Выберите номер объявления, которое хотите одобрить. \n     (Чтобы одобрить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("ads_on_moderate");
                            esc = true;
                            break;
                        }
                        else if (num_ad=="") {
                            cout << "     Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                            continue;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            DBads.setStatusAd(num_add, 1);
                            clearCout(count_errors + 1, 100);
                            cout << "     Объявление c ID:" << num_ad << " успешно одобрено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "     Неверный номер объявления. Введите новый номер объявления:";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                case 'A':

                    cout << "\n     Выберите номер объявления, которое хотите одобрить. \n     (Чтобы одобрить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("ads_on_moderate");
                            esc = true;
                            break;
                        }
                        else if (num_ad == "") {
                            cout << "     Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                            continue;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            DBads.setStatusAd(num_add, 1);
                            clearCout(count_errors + 1, 100);
                            cout << "     Объявление c ID:" << num_ad << " успешно одобрено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "     Неверный номер объявления. Введите новый номер объявления:";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                case 'ф':

                    cout << "\n     Выберите номер объявления, которое хотите одобрить. \n     (Чтобы одобрить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("ads_on_moderate");
                            esc = true;
                            break;
                        }
                        else if (num_ad == "") {
                            cout << "     Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                            continue;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            DBads.setStatusAd(num_add, 1);
                            clearCout(count_errors + 1, 100);
                            cout << "     Объявление c ID:" << num_ad << " успешно одобрено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "     Неверный номер объявления. Введите новый номер объявления:";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                    // СДЕЛАТЬ ФИЛЬТР
                case 'd':

                    cout << "\n     Выберите номер объявления, которое хотите отклонить. \n     (Чтобы отклонить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("ads_on_moderate");
                            esc = true;
                            break;
                        }
                        else if (num_ad=="") {
                            cout << "     Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                            continue;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            string cause = "";
                            cout << "     Введите причину отклонения объявления: ";
                            cause = cinCause();
                            DBads.setStatusAd(num_add, 0, cause);
                            clearCout(count_errors + 2, 100);
                            cout << "     Объявление c ID:" << num_ad << " успешно отклонено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "     Неверный номер объявления. Введите новый номер объявления:";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    }
                    // СДЕЛАТЬ ФИЛЬТР
                case 'D':
                    cout << "\n     Выберите номер объявления, которое хотите отклонить. \n     (Чтобы отклонить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("ads_on_moderate");
                            esc = true;
                            break;
                        }
                        else if (num_ad == "") {
                            cout << "     Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                            continue;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            string cause = "";
                            cout << "     Введите причину отклонения объявления: ";
                            cause = cinCause();
                            DBads.setStatusAd(num_add, 0, cause);
                            clearCout(count_errors + 2, 100);
                            cout << "     Объявление c ID:" << num_ad << " успешно отклонено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "     Неверный номер объявления. Введите новый номер объявления:";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;
                    
                    }
                case 'в':
                    cout << "\n     Выберите номер объявления, которое хотите отклонить. \n     (Чтобы отклонить объявление, после ввода нажмите Enter): ";
                    while (nextt == false) {
                        num_ad = cinNumb();
                        if (num_ad == "`") {
                            states.setState("ads_on_moderate");
                            esc = true;
                            break;
                        }
                        else if (num_ad == "") {
                            cout << "     Неверный номер объявления. Введите новый номер объявления: ";
                            num_ad = "";
                            count_errors += 1;
                            continue;
                        }
                        num_add = stoi(num_ad);
                        bool finded = false;
                        for (int id = 0; id < id_cu.size(); id++) {
                            if (num_ad == id_cu[id]) {
                                finded = true;
                            }
                        }
                        if (finded == true) {
                            string cause = "";
                            cout << "     Введите причину отклонения объявления: ";
                            cause = cinCause();
                            DBads.setStatusAd(num_add, 0, cause);
                            clearCout(count_errors + 2, 100);
                            cout << "     Объявление c ID:" << num_ad << " успешно отклонено.";
                            Sleep(1500);
                            esc = true;
                            nextt = 0;
                            count_errors = 0;
                            break;
                        }
                        else {
                            cout << "     Неверный номер объявления. Введите новый номер объявления:";
                            num_ad = "";
                            count_errors += 1;
                        }
                    }
                    if (esc == true) {
                        break;

                    }
                
                }

                if (esc == true) {
                    break;
                }
            }
             
        }
        else if (states.current_state == "add_car_brand") {
            system("cls");
            string new_car_brand;
            string password;
            vector<string> car_brands = carmb.getAllBrands();
            int count_errors = 0;
            bool next = false;
            bool esc = false;

            int cols = 82;
            system("mode con cols=82 lines=37"); 
            coutFromFile("./ASCII/add_car_brand.txt");
            cout << "\nESC - выход в личный кабинет.\n";
            cout << "\nУже добавленные бренды:\n";

            for (int i = 0; i < car_brands.size(); i++) {
                if (i % 4 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i+1<<". " << car_brands[i] << ".  ";
                
            }
            cout << "\n";
            cout << "\nВведите новый бренд машины: ";
            while (next == false) {
                new_car_brand = cinBrand();
                if (new_car_brand == "`") {
                    states.setState("lk_a");
                    esc = true;
                    break;
                }
                else if (new_car_brand == "") {
                    cout << "Неверный бренд. Введите новый бренд машины: ";
                    new_car_brand = "";
                    count_errors += 1;
                    continue;
                }
                else {
                    clearCout(count_errors, 100);
                    Sleep(100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Бренд: " << new_car_brand << "\n";
                    carmb.addCarBrand(new_car_brand);

                    cout << "\nБренд машины успешно добавлен! Переход в личный кабинет...";
                    Sleep(1500);
                    states.setState("lk_a");
                    esc = true;
                    next = true;
                    count_errors = 0;
                    break;
                }
                
            }
            
            if (esc == true) {

                continue;
            }
        }
        else if (states.current_state == "add_car_model") {
            system("cls");
            string new_car_model;
            string num_b;
            string password;
            int count_errors = 0;
            
            bool esc = false;
            int cols = 82;
            int num_bb = 0;
            bool next = false;
            vector<string> car_brands = carmb.getAllBrands();
            system("mode con cols=82 lines=55");
            coutFromFile("./ASCII/add_car_model.txt");
            cout << "\nESC - выход в личный кабинет.\n";
            cout << "\nБренды:\n";

            for (int i = 0; i < car_brands.size(); i++) {
                if (i % 5 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i+1<<". " << car_brands[i] << ".  ";
                
            }
            cout << "\n";
            cout << "\nВыберите номер бренда, для которого хотите добавить марку: ";
            while (next == false) {
                num_b = cinNumb();
                if (num_b == "`") {
                    states.setState("lk_a");
                    esc = true;
                    break;
                }
                if (num_b == "") {
                    cout << "Неверный ввод числа. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                    continue;
                }
                num_bb = stoi(num_b);
                if (num_bb>car_brands.size()) {
                    cout << "Число не должно превышать " << car_brands.size()<< ". Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                    
                }
                else if (num_bb <= 0) {
                    cout << "Число меньше либо равно нулю. Введите новое число: ";
                    num_b = "";
                    count_errors += 1;
                }
                else {
                    clearCout(count_errors, 100);
                    cout << "\033[A";
                    cout << "\r";
                    cout << "Бренд: "<<car_brands[num_bb-1];
                    cout << "\n";
                    next = true;
                    count_errors = 0;
                    break;
                }
            }
            if (esc == true) {
                continue;
            }
            next = false;
            vector<string> models = carmb.getAllModelsByBrand(car_brands[num_bb - 1]);
            cout << "\nМодели, которые уже в базе данных:\n";

            for (int i = 0; i < models.size(); i++) {
                if (i % 4 == 0 && i != 0) {
                    cout << "\n";
                }
                cout << i + 1 << ". " << models[i] << ".  ";

            }
            cout << "\n\nВведите новую модель машины: ";
            while (next == false) {
                new_car_model = cinModel();
                if (new_car_model == "`") {
                    states.setState("lk_a");
                    esc = true;
                    break;
                }
                else if (new_car_model == "") {
                    cout << "Неверная модель. Введите новую модель машины: ";
                    new_car_model = "";
                    count_errors += 1;
                    continue;
                }
                clearCout(count_errors, cols);
                cout << "Модель машины: " << new_car_model << "\n";
                carmb.addCarModel(car_brands[num_bb - 1], new_car_model);
                
                cout << "\nМодель машины успешно добавлена! Переход в личный кабинет...";
                Sleep(1500);
                states.setState("lk_a");
                esc = true;
                next = true;
                count_errors = 0;
                break;
            }
            if (esc == true) {

                continue;
            }
            
        }
    }
    return 0;
}