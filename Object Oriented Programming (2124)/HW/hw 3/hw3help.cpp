
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Warrior{
public:
    Warrior(const string wNm, const double wStr) : name(wNm), strength(wStr){}
    double getStrength() const{
        return strength;
    }
    string getName() const{
        return name;
    }
    void setStrength(double newStrength){
        strength = newStrength;
    }
    bool isDead() const{
        if(strength == 0){ return true;}
        return false;
    }
    void setJob() {
        if(getJob() == true){
            job = false;
        }
        job = true;
    }
    bool getJob() const{
        return job;
    }
    
private:
    double strength;
    string name;
    bool job;
};

class Noble{
public:
    Noble(const string hisName) :name(hisName) {}

    string getName() const{
        return name;
    }
    void display() const{
        cout << name << " has an army of " << getArmySize() << endl;
        for(size_t i = 0; i < army.size(); ++i){
            cout << "   ";
            cout << army[i]->getName() << ": " << army[i]->getStrength();
            cout << endl;
        }
    }
    double getArmyStrength() const{
        double totalStrength = 0;
        for(size_t i = 0; i < army.size(); ++i){
            totalStrength += army[i]->getStrength();
        }
        return totalStrength;
    }
    int getArmySize() const{
       return army.size();
    }
    void hire(Warrior & armyMember){
        army.push_back(&armyMember);
    }
    void fire(Warrior & armyMember){
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i]->getName() == armyMember.getName()){
                size_t j = i;
                while(j < army.size()-1){
                    army[j] = army[j+1];
                    ++j;
                }
                army.pop_back();
                return;
            }
        }   
    }
    void battle(Noble & challenger){
        cout << name << " battles " << challenger.name << endl;
        double totalStrength = getArmyStrength();
        double challengerTotalStrength = challenger.getArmyStrength();
        if (!checkForDeath(challenger)){
            return;
        }
        else if (totalStrength > challengerTotalStrength){
                winner(challenger);
            }
        else if (totalStrength < challengerTotalStrength){
            challenger.winner(*this);
        }
        else {
            cout << "Mutual Annihalation: " << name << " and " << challenger.name << "die at each other's hands" << endl;
            destroy();
            challenger.destroy();
        }
    }
    bool checkForDeath(Noble & challenger) const {
        if (challenger.dead && dead){
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
            return false;
        }
        else if (challenger.dead && !dead){
            cout << "He's dead " << name << endl;
            return false;
        }
        else if (!challenger.dead && dead){
            cout << "He's dead " << challenger.name << endl;
            return false;
        }
        else return true;
    }
    void winner(Noble & loser){
        cout << name << " deafeats ";
        cout << loser.name << endl;
        hurt(loser);
        loser.destroy();
    }
    void destroy(){
        for(size_t i = 0; i < army.size(); ++i){
            army[i]->setStrength(0);
        }
        dead = true;
    }
    void hurt(Noble & loser){
        double ratio = loser.getArmyStrength()/getArmyStrength();
        for(size_t i = 0; i < army.size(); ++i){
            army[i]->setStrength(army[i]->getStrength() * ratio);
        }
    }
private:
    string name;
    bool dead;
    vector<Warrior*> army;
};

int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);


    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();

    art.fire(cheetah);
    art.display();

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);


    return 0;
}
