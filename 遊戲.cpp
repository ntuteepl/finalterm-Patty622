#include <iostream>
#include <cmath>
#include <string>
#include <limits> // 用於 numeric_limits
#include <algorithm> // 用於 std::max
#include <cctype> // 用於 isalpha 函數
using namespace std;
// Character 類，定義了角色的基本屬性和行為
class Character {
protected:
    static const int EXP_LV = 100; // 升級所需經驗值基數
    string name;
    int hp;
    int level;
    int exp;
    int power;
    int knowledge;
    int luck;
    void levelUp(int hInc, int pInc, int kInc, int lInc); // 升級方法，增加屬性值
public:
    Character(string n, int lv, int h, int po, int kn, int lu);
    virtual void print(); // 打印角色信息
    virtual void setHP(int) = 0; // 設置HP
    virtual int getHP() = 0; // 獲取HP
    virtual void setLuck(int lu); // 設置運氣值 
    virtual int getAttack() = 0; // 獲取攻擊力
    virtual int getTreatment() = 0; // 獲取治療量
    string getName(); // 獲取角色名稱
    int getLevel(); // 獲取等級
    int getKnowledge(); // 獲取知識值
    int getLuck(); // 獲取運氣值
};

// Character 類的構造函數
Character::Character(string n, int lv, int h, int po, int kn, int lu)
    : name(n), level(lv), exp(0), hp(h), power(po), knowledge(kn), luck(lu) {}

// 獲取角色名稱
string Character::getName() {
    return this->name;
}

// 獲取等級
int Character::getLevel() {
    return this->level;
}

// 獲取知識值
int Character::getKnowledge() {
    return this->knowledge;
}

// 獲取運氣值
int Character::getLuck() {
    return this->luck;
}

// 設置運氣值
void Character::setLuck(int lu) {
    this->luck = lu;
}

// 打印角色信息
void Character::print() {
    cout << this->name << ": 等級 " << this->level << "，經驗值 " << this->exp << "，HP: " << this->hp << "，攻擊力: " << this->power << "，知識: " << this->knowledge << "，運氣: " << this->luck << "\n";
}

// HarryPotter 類，繼承自 Character
class HarryPotter : public Character {
private:
    static const int HP_LV = 100; // 每級增加的HP
    static const int PO_LV = 15;  // 每級增加的力量
    static const int KN_LV = 5;   // 每級增加的知識
    static const int LU_LV = 4;   // 每級增加的運氣
public:
    HarryPotter(string n, int lv = 1); // 構造函數
    void print(); // 打印角色信息
    int getHP(); // 獲取HP
    void setHP(int hp); // 設置HP
    int getAttack(); // 獲取攻擊力
    int getTreatment(); // 獲取治療量 (預設為 0)
};

// HarryPotter 類的構造函數
HarryPotter::HarryPotter(string n, int lv)
    : Character(n, lv, lv * HP_LV, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}
    
// 打印角色信息
void HarryPotter::print() {
    cout << "HarryPotter ";
    Character::print();
}

// 獲取HP
int HarryPotter::getHP() {
    return hp;
}

// 設置HP
void HarryPotter::setHP(int hp) {
    this->hp = hp;
}

// 獲取攻擊力
int HarryPotter::getAttack() {
    return power;
}

// 獲取治療量 (預設為 0)
int HarryPotter::getTreatment() {
    return 0;
}

// Hermione 類，繼承自 Character
class Hermione : public Character {
private:
    static const int HP_LV = 70;  // 每級增加的HP
    static const int PO_LV = 3;   // 每級增加的力量
    static const int KN_LV = 15;  // 每級增加的知識
    static const int LU_LV = 2;   // 每級增加的運氣
public:
    Hermione(string n, int lv = 1); // 構造函數
    void print(); // 打印角色信息
    int getHP(); // 獲取HP
    void setHP(int hp); // 設置HP
    int getAttack(); // 獲取攻擊力
    int getTreatment(); // 獲取治療量 (預設為 0)
    void beatVoldemort(int exp); // 打敗怪物後獲得經驗值並升級
};

// Hermione 類的構造函數
Hermione::Hermione(string n, int lv)
    : Character(n, lv, lv * HP_LV, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}

// 打印角色信息
void Hermione::print() {
    cout << "Hermione ";
    Character::print();
}

// 獲取HP
int Hermione::getHP() {
    return hp;
}

// 設置HP
void Hermione::setHP(int hp) {
    this->hp = hp;
}

// 獲取攻擊力
int Hermione::getAttack() {
    return knowledge;
}

// 獲取治療量 (預設為 0)
int Hermione::getTreatment() {
    return 0;
}

// Ron 類，繼承自 Character
class Ron : public Character {
private:
    static const int HP_LV = 80;  // 每級增加的HP
    static const int PO_LV = 8;   // 每級增加的力量
    static const int KN_LV = 3;   // 每級增加的知識
    static const int LU_LV = 8;  // 每級增加的運氣
public:
    Ron(string n, int lv = 1); // 構造函數
    void print(); // 打印角色信息
    int getHP(); // 獲取HP
    void setHP(int hp); // 設置HP
    int getAttack(); // 獲取攻擊力
    int getTreatment(); // 獲取治療量 (預設為 0)
    void beatVoldemort(int exp); // 打敗怪物後獲得經驗值並升級
};

// Ron 類的構造函數
Ron::Ron(string n, int lv)
    : Character(n, lv, lv * HP_LV, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}

// 打印角色信息
void Ron::print() {
    cout << "Ron ";
    Character::print();
}

// 獲取HP
int Ron::getHP() {
    return hp;
}

// 設置HP
void Ron::setHP(int hp) {
    this->hp = hp;
}

// 獲取攻擊力
int Ron::getAttack() {
    return power;
}

// 獲取治療量 (預設為 0)
int Ron::getTreatment() {
    return 0;
}

// Dumbledore 類，繼承自 Character
class Dumbledore : public Character {
private:
    static const int HP_LV = 60;  // 每級增加的HP
    static const int PO_LV = 3;   // 每級增加的力量
    static const int KN_LV = 7;  // 每級增加的知識
    static const int LU_LV = 4;   // 每級增加的運氣
    static const int TR_LV = 8;  // 每級增加的治療量
    int treatment;
public:
    Dumbledore(string n, int lv = 1); // 構造函數
    void print(); // 打印角色信息
    int getHP(); // 獲取HP
    void setHP(int hp); // 設置HP
    int getAttack(); // 獲取攻擊力
    int getTreatment(); // 獲取治療量 
    void beatVoldemort(int exp); // 打敗怪物後獲得經驗值並升級
};

// Dumbledore 類的構造函數
Dumbledore::Dumbledore(string n, int lv)
    : Character(n, lv, lv * HP_LV, lv * PO_LV, lv * KN_LV, lv * LU_LV), treatment(lv * TR_LV) {}

// 打印角色信息
void Dumbledore::print() {
    cout << "Dumbledore ";
    Character::print();
}

// 獲取HP
int Dumbledore::getHP() {
    return hp;
}

// 設置HP
void Dumbledore::setHP(int hp) {
    this->hp = hp;
}

// 獲取攻擊力
int Dumbledore::getAttack() {
    return power;
}

// 獲取治療量 
int Dumbledore::getTreatment() {
    return treatment;
}

// Malfoy 類，繼承自 Character
class Malfoy : public Character {
private:
    static const int HP_LV = 90;  // 每級增加的HP
    static const int PO_LV = 10;   // 每級增加的力量
    static const int KN_LV = -10;  // 每級增加的知識
    static const int LU_LV = 4;   // 每級增加的運氣
    int treatment;
public:
    Malfoy(string n, int lv = 1); // 構造函數
    void print(); // 打印角色信息
    int getHP(); // 獲取HP
    void setHP(int hp); // 設置HP
    int getAttack(); // 獲取攻擊力
    int getTreatment(); // 獲取治療量 
    void beatVoldemort(int exp); // 打敗怪物後獲得經驗值並升級
};

// Malfoy 類的構造函數
Malfoy::Malfoy(string n, int lv)
	: Character(n, lv, lv * HP_LV, lv * PO_LV, lv * KN_LV, lv * LU_LV) {}
// 打印角色信息
void Malfoy::print() {
    cout << "Malfoy ";
    Character::print();
}

// 獲取HP
int Malfoy::getHP() {
    return hp;
}

// 設置HP
void Malfoy::setHP(int hp) {
    this->hp = hp;
}

// 獲取攻擊力
int Malfoy::getAttack() {
    return knowledge;
}

// 獲取治療量 
int Malfoy::getTreatment() {
    return 0;
}

// Voldemort 類，繼承自 Character
class Voldemort : public Character
{
public:
    Voldemort(int h, int po, int kn); // 構造函數
    void print(); // 打印怪物信息
    int getHP(); // 獲取HP
    void setHP(int hp); // 設置HP
    int getAttack(); // 獲取攻擊力
    void setAttack(int atk); // 設置攻擊力
    int getTreatment(); // 實現方法
    void beatVoldemort(int exp); // 實現方法
};

// Voldemort 類的構造函數
Voldemort::Voldemort(int h, int po, int kn) 
    : Character("", 0, h, po, kn, 0) { }

// 打印怪物信息
void Voldemort::print() 
{ 
    cout << "Voldemort "; 
    Character::print(); 
}

// 獲取HP
int Voldemort::getHP() 
{ 
    return hp; 
}

// 設置HP
void Voldemort::setHP(int hp) 
{ 
    this->hp = hp; 
}

// 獲取攻擊力
int Voldemort::getAttack() 
{ 
    return power; 
}

// 設置攻擊力
void Voldemort::setAttack(int atk) 
{ 
    this->power = atk; 
}

// 實現 getTreatment 方法
int Voldemort::getTreatment() 
{ 
    return 0; 
}

// Team ，管理一組角色成員
class Team
{
protected:
    int memberCount;
    Character* member[10]; // 角色成員數
public:
    Team();
    ~Team();
    void addHarryPotter(string name, int lv); // 添加 HarryPotter
    void addHermione(string name, int lv); // 添加 Hermione
    void addRon(string name, int lv); // 添加 Ron
    void addDumbledore(string name, int lv); // 添加 Dumbledore
    void addMalfoy(string name, int lv); // 添加 Dumbledore
    void print(); // 打印所有成員信息
    void combat(Voldemort* m); // 與佛地魔戰鬥
    int calculateLuckSum(); // 計算所有成員的運氣總和
	void resetLuck(); // 重置所有成員的運氣值

};

// Team 的建構子 
Team::Team()
{
    memberCount = 0;
    for(int i = 0; i < 10; i++)
        member[i] = 0;
}

// Team 的解構子 
Team::~Team()
{
    for(int i = 0; i < memberCount; i++)
        delete member[i];
}

// 添加HarryPotter到團隊
void Team::addHarryPotter(string name, int lv)
{
    if(memberCount < 10)
    {
        member[memberCount] = new HarryPotter(name, lv);
        memberCount++;
    }
}

// 添加Hermione到團隊
void Team::addHermione(string name, int lv)
{
    if(memberCount < 10)
    {
        member[memberCount] = new Hermione(name, lv);
        memberCount++;
    }
}

// 添加Ron團隊
void Team::addRon(string name, int lv)
{
    if(memberCount < 10)
    {
        member[memberCount] = new Ron(name, lv);
        memberCount++;
    }
}

// 添加Dumbledore團隊
void Team::addDumbledore(string name, int lv)
{
    if(memberCount < 10)
    {
        member[memberCount] = new Dumbledore(name, lv);
        memberCount++;
    }
}

// 添加Malfoy團隊
void Team::addMalfoy(string name, int lv)
{
    if(memberCount < 10)
    {
        member[memberCount] = new Malfoy(name, lv);
        memberCount++;
    }
}

void Team::print()
{
	for(int i = 0; i < memberCount; i++)
		member[i]->print();
}

// 計算所有成員的運氣總和
int Team::calculateLuckSum() {
    int luckSum = 0;
    for (int i = 0; i < memberCount; i++) {
        if (member[i]->getHP() > 0) { // 只計算存活成員
            luckSum += member[i]->getLuck();
        }
    }
    return luckSum;
}

// 重置所有成員的運氣值
void Team::resetLuck() {
    for (int i = 0; i < memberCount; i++) {
        if (member[i]->getHP() > 0) { // 只重置存活成員
            member[i]->setLuck(0);
        }
    }
}

void Team::combat(Voldemort* m) {
    int realCount = memberCount; // 存活成員數
    int round = 1; // 回合計數器

    cout << "戰鬥開始！" << endl;
	// 輸出每個成員的數據
        cout << "初始成員數據：" << endl;
        for (int i = 0; i < memberCount; i++) {
            if (member[i]->getHP() > 0) { // 只輸出存活成員
                cout << member[i]->getName() << " - 等級: " << member[i]->getLevel()
                     << ", 攻擊力: " << member[i]->getAttack()
                     << ", HP: " << max(0, member[i]->getHP())
                     << ", 知識: " << member[i]->getKnowledge()
                     << ", 運氣: " << member[i]->getLuck()
                     << ", 治療能力: " << member[i]->getTreatment() << endl;
            }
        }
    // 戰鬥迴圈
    while (m->getHP() > 0 && realCount > 0) {
        cout << "========================================" << endl;
        cout << "回合 " << round++ << ":" << endl;

        // 判斷是否超過10回合
        if ((round - 1) > 10) {
            cout << "========================================" << endl;
            cout << "對戰已超過10回合，太久了，戰鬥以平局結束！下次再打。" << endl;
            return;
        }

        // 當回合數為五的倍數時，佛地魔進化
        if ((round - 1) % 5 == 0) {
            m->setAttack(m->getAttack() + 50); // 增加攻擊力50
            cout << "佛地魔進化，攻擊力增加 50！" << endl;
        }

        // 計算運氣總和
        int luckSum = calculateLuckSum();
        cout << "當前成員運氣總和: " << luckSum << endl;

        bool voldemortCantAttack = luckSum > 100;
        if (voldemortCantAttack) {
            cout << "成員的運氣總和超過100，佛地魔本回合無法攻擊！" << endl;
            resetLuck();
        }

        if (!voldemortCantAttack) {
            // 佛地魔攻擊
            int mDamage = m->getAttack() / realCount; // 平均分配傷害
            cout << "佛地魔攻擊: " << m->getAttack() << "，每名成員受到傷害: " << mDamage << endl;
            for (int i = 0; i < memberCount; i++) {
                if (member[i]->getHP() > 0) { // 只影響存活成員
                    int prevHP = member[i]->getHP(); // 攻擊前的 HP
                    member[i]->setHP(prevHP - mDamage);
                    if (member[i]->getHP() <= 0) { // 成員死亡判定
                        realCount--;
                        cout << member[i]->getName() << " 倒下了！(死了)" << endl;
                    }
                }
            }
        }

        if (!voldemortCantAttack) {
            // Dumbledore治療存活成員
            for (int i = 0; i < memberCount; i++) {
                if (dynamic_cast<Dumbledore*>(member[i]) != 0 && member[i]->getHP() > 0) {
                    int treatment = member[i]->getTreatment();
                    for (int j = 0; j < memberCount; j++) {
                        if (member[j]->getHP() > 0 && j != i) { // 排除當前的 Dumbledore
                            int prevHP = member[j]->getHP();
                            member[j]->setHP(prevHP + treatment);
                        }
                    }
                }
            }
        }

        // 攻擊計算
        int teamDamage = 0;
        for (int i = 0; i < memberCount; i++) {
            if (member[i]->getHP() > 0) {
                int attack = member[i]->getAttack();
                teamDamage += attack;
            }
        }

        m->setHP(m->getHP() - teamDamage);
        cout << "團隊總攻擊力：" << teamDamage << "，佛地魔剩餘 HP：" 
             << max(0, m->getHP()) << endl;

        // 輸出每個成員的數據
        cout << "當前成員數據：" << endl;
        for (int i = 0; i < memberCount; i++) {
            if (member[i]->getHP() > 0) { // 只輸出存活成員
                cout << member[i]->getName() << " - 等級: " << member[i]->getLevel()
                     << ", 攻擊力: " << member[i]->getAttack()
                     << ", HP: " << max(0, member[i]->getHP())
                     << ", 知識: " << member[i]->getKnowledge()
                     << ", 運氣: " << member[i]->getLuck()
                     << ", 治療能力: " << member[i]->getTreatment() << endl;
            }
        }
    }

    // 戰鬥結果
    cout << "========================================" << endl;
    if (m->getHP() <= 0) {
        cout << "佛地魔被擊敗！" << endl;
    } else {
        cout << "所有成員倒下了，戰鬥失敗！" << endl;
    }
}

int main() {
    int mHP, mPower, mKnowledge;

    // 輸入佛地魔數據
    while (true) {
        cout << "請輸入佛地魔的 HP, Power, Knowledge: ";
        if (cin >> mHP >> mPower >> mKnowledge) {
            break; // 輸入正確，跳出迴圈
        } else {
            cout << "錯誤：請輸入數值！" << endl;
            cin.clear(); // 清除錯誤標記
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略錯誤輸入
        }
    }
    Voldemort mon(mHP, mPower, mKnowledge);

    Team myTeam;
    string name;
    int lv = 0, role = 0;
    int memberCount = 0; // 計算已輸入的成員數量

    cout << "請輸入團隊中每名成員的姓名、初始等級與角色 (1 為 HarryPotter, 2 為 Hermione, 3 為 Ron, 4 為 Dumbledore, 5 為 Malfoy )" << endl;
    cout << "(結束輸入請按 Ctrl+Z，最多十位成員喔!)" << endl;

    while (true) {
        if (memberCount >= 10) {
            cout << "已達到 10 位成員，結束輸入並開始戰鬥！" << endl;
            break;
        }

        if (cin >> name >> lv >> role) {
            bool valid = true;

            // 檢查名稱是否包含非字母字符
            for (int i = 0; i < name.size(); ++i) {
                if (!isalpha(name[i])) {
                    cout << "錯誤：名稱只能包含字母字符！上述成員變成麻瓜!" << endl;
                    valid = false;
                    break; 
                }
            }

            // 檢查角色是否在1到5之間
            if (role < 1 || role > 5) {
                cout << "錯誤：角色必須在1到5之間！上述成員變成麻瓜!" << endl;
                valid = false;
            }

            if (valid) {
                if (role == 1) { 
                    myTeam.addHarryPotter(name, lv);
                } else if (role == 2) {
                    myTeam.addHermione(name, lv);
                } else if (role == 3) {
                    myTeam.addRon(name, lv);
                } else if (role == 4) {
                    myTeam.addDumbledore(name, lv);
                } else if (role == 5) {
                    myTeam.addMalfoy(name, lv);
                }
                memberCount++; // 增加成員數量
            }
        } else if (cin.eof()) {
            break;
        } else {
            cin.clear(); // 清除錯誤標記
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略錯誤輸入
        }
    }

    myTeam.combat(&mon);

    return 0;
}
