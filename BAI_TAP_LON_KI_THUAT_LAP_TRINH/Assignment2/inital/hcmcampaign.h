/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 2
 * Programming Fundamentals Spring 2025
 * Date: 02.02.2025
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_HCM_CAMPAIGN_H_
#define _H_HCM_CAMPAIGN_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Forward declaration
class Unit;
class UnitList;
class Army;
class TerrainElement;

class Vehicle;
class Infantry;

class LiberationArmy;
class ARVN;

class Position;

class Road;
class Mountain;
class River;
class Urban;
class Fortification;
class SpecialZone;

class BattleField;

class HCMCampaign;
class Configuration;

int Round(double x);
string intToString(int);
int stringToInt(string);
void getFibonaciList();


enum VehicleType
{
    TRUCK,
    MORTAR,
    ANTIAIRCRAFT,
    ARMOREDCAR,
    APC,
    ARTILLERY,
    TANK
};
enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};
string getNameInfantry(InfantryType);
string getNameVehicle(VehicleType);





class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos); // Example: str_pos = "(1,15)"
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const; // Example: returns "(1,15)"

    
};

class Unit
{
protected:
    int quantity, weight;
    Position pos;

public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit();
    virtual int getAttackScore() = 0;
    Position getCurrentPosition() const;
    virtual string str() const = 0;
    void minusWeight(int);
    void minusQuantity(int);
    void increaseQuantityToNearestFibonaci();
	double getDistance(Position a) {
		int dx = 1.0*(a.getCol() - this->pos.getCol());
		int dy = 1.0 * (a.getRow() - this->pos.getRow());
		return sqrt(dx * dx + dy * dy);
	}
    
};

class Vehicle : public Unit {
private:
    VehicleType vehicleType;

public:
    Vehicle(int quantity, int weight, const Position pos, VehicleType vehicleType);
    ~Vehicle() {};
    VehicleType getType() {
        return vehicleType;
    }
    int getQuantity() {
        return quantity;
    }
    void setQuantity(int curQuantity) {
        quantity = curQuantity;
    }
    /*int getType() override{
        return 1;
    }*/
    int getAttackScore() override {

        return Round((vehicleType * 304 + quantity * weight) * 1.0 / 30.0);

    }
    string str() const override {
        //return "Vehicle[" + getNameVehicle(vehicleType) + "=<" + intToString(quantity)+"," + intToString(weight)+","+pos.str()+">]";
        return "Vehicle[vehicleType=" + getNameVehicle(vehicleType) + ",quantity=" + intToString(quantity) + ",weight=" + intToString(weight) + ",position=" + pos.str() + "]";
    }

};

class Infantry : public Unit {
private:
    InfantryType infantryType;

public:
    Infantry(int quantity, int weight, const Position pos, InfantryType infantryType);
    ~Infantry() {};
    InfantryType getType() {
        return infantryType;
    }
    int getQuantity() {
        return quantity;
    }
    void setQuantity(int curQuantity) {
        quantity = curQuantity;
    }
    bool weightLaSoChinhPhuong() {
        int sqrtWeight = sqrt(weight);
        return (sqrtWeight * sqrtWeight == weight);
    }
    bool checkDacCong(InfantryType curType) {
        return ((curType == 4) && weightLaSoChinhPhuong());
    }
    int fooCountNum(int n) {

        int sumNum = 0;
        while (n) {
            sumNum += n % 10;
            n /= 10;
        }
        int curYear = 1975;
        while (curYear) {
            sumNum += curYear % 10;
            curYear /= 10;
        }
        while (sumNum >= 10) {
            int curVal = 0;
            while (sumNum) {
                curVal += sumNum % 10;
                sumNum /= 10;
            }
            sumNum = curVal;
        }
        return sumNum;
    }
    int getAttackScore() override {
        int push = 0;
        if (checkDacCong(infantryType) == true) {
            push = 75;
        }
        int score = infantryType * 56 + quantity * weight + push;
        int countNum = fooCountNum(score);
		//cout << countNum << endl;
        if (countNum >= 7) {
            /*quantity = Round(quantity + quantity * 0.2);*/
			quantity = quantity + Round(quantity * 0.2);
            score = infantryType * 56 + quantity * weight + push;
        }
        else if (countNum < 3) {
           /* quantity = Round(1.0 * (quantity - quantity * 0.1));*/
			quantity = quantity - Round(quantity * 0.1);
            score = infantryType * 56 + quantity * weight + push;
        }

        return score;

    }
    string str() const override {
        //return "Infantry[" + getNameInfantry(infantryType) + "=<" + intToString(quantity) + "," + intToString(weight) + "," + pos.str() + ">]";
        return "Infantry[infantryType=" + getNameInfantry(infantryType) + ",quantity=" + intToString(quantity) + ",weight=" + intToString(weight) + ",position=" + pos.str() + "]";
    }

};

class Node {

public:
    Unit* data;
    Node* next;
    Node(Unit* unit) : data(unit), next(nullptr) {}
};

class UnitList
{
private:
    int capacity;// chi so luong Node
    // TODO
    int cntVehicle, cntInfantry;
    Node* head;

public:
    UnitList(int capacity);
    bool insert(Unit *unit);                   // return true if insert successfully
    bool isContain(VehicleType vehicleType);   // return true if it exists
    bool isContain(InfantryType infantryType); // return true if it exists
    string str() const;
	void minusOnecntVehicle() { cntVehicle--; }
	void minusOnecntInfantry() { cntInfantry--; }
    bool hasNotAppearedVehicle(Vehicle* v);
    bool hasNotAppearedInfantry(Infantry* i);
    Node* getHead() const { return head; }
    void setHead(Node* newHead) { head = newHead; }
	int getCapacity() { return capacity; }
    // TODO
};
class Army
{
protected:
	int LF, EXP;
	string name;
	UnitList* unitList;
	BattleField* battleField;

public:
	Army(const Unit** unitArray, int size, string name, BattleField* battleField);
	virtual void fight(Army* enemy, bool defense = false) = 0;
	virtual string str() const = 0;
	int getLF() { return LF; }
	int getEXP() { return EXP; }
	void setLF(int newLF) { LF = newLF; }
	void setEXP(int newEXP) { EXP = newEXP; }
	UnitList* getList() { return unitList; }
	void reCalEXP_LF();

};
class LiberationArmy : public Army {
private:
	bool warTakesPlace;
public:
	LiberationArmy(const Unit** unitArray, int size, string name, BattleField* battleField) : Army(unitArray, size, name, battleField) {}
	LiberationArmy(Unit** unitArray, int size, string name, BattleField* battleField) : Army(const_cast<const Unit**>(unitArray), size, name, battleField) {}
	void noBattleConsequence() {
		Node* iterate = this->unitList->getHead();
		while (iterate != nullptr) {
			//iterate->data->minusWeight(10);
			if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
				LF -= v->getAttackScore();
				v->minusWeight(10);
				LF += v->getAttackScore();
			}
			else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
				EXP -= i->getAttackScore();
				i->minusWeight(10);
				EXP += i->getAttackScore();
			}



			iterate = iterate->next;
		}
	}
	
	void requistion(Army* enermy) {
		//cout << "DANG CAP NHAT LAI" << endl;
		//cout << "DANG O REQUISTION" << endl;
		Node* iterate = enermy->getList()->getHead();
		Node* preNode = nullptr;
		//cout << "BUG O DAY" << endl;
		//duyet qua danh sach cua enermy
		while (iterate != nullptr) {
			Node* nextNode = iterate->next;
			//cout << iterate->data->str() << endl;
			
			
			if (this->unitList->insert(iterate->data) == true) {
				//cout << "HET BUG" << endl;
				if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
					this->LF += iterate->data->getAttackScore();
					enermy->setLF(enermy->getLF() - iterate->data->getAttackScore());
					enermy->getList()->minusOnecntVehicle();
				}
				else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
					this->EXP += iterate->data->getAttackScore();
					enermy->setEXP(enermy->getEXP() - iterate->data->getAttackScore());
					enermy->getList()->minusOnecntInfantry();
				}
				
				//xoa node da duoc insert di
				if (preNode == nullptr) {
					enermy->getList()->setHead(nextNode);
				}
				else {
					preNode->next = nextNode;
				}
				delete iterate;
				//continue;

			}
			else {
				preNode = iterate;
			}

			iterate = nextNode;
		}

		


	}
	void deleteNode(Unit* armDelete) {
		Node* iterate = this->unitList->getHead();
		Node* preNode = nullptr;
		if (iterate == nullptr || armDelete == nullptr) return;
		if (Vehicle* v = dynamic_cast<Vehicle*> (armDelete)) {
			//cout << "IT'S HERE1" << endl;
			while (iterate != nullptr) {
				//Node* nextNode = iterate->next;
				if (Vehicle* vv = dynamic_cast<Vehicle*> (iterate->data)) {
					if (v->getType() == vv->getType()) {
						this->unitList->minusOnecntVehicle();
						//cout << "YES IT'S HERE" <<" "<<getNameVehicle(v->getType())<<" "<<v->getAttackScore()<<" "<<this->LF<<" "<<this->LF << endl;
						this->LF -= v->getAttackScore();
						//cout << this->LF << endl;
						if (preNode == nullptr) {
							//cout << "11" << endl;
							this->unitList->setHead(iterate->next);
						}
						else {
							preNode->next = iterate->next;
							//cout << "o day" << endl;
						}
						//cout << "still here" << endl;
						
						//cout << "1" << endl;
						//iterate->data->~Unit();
						//cout << "dang xoa..." << iterate->data << endl;
						//delete iterate->data;
						//cout << "da delete" << endl;
					/*	delete iterate;
						delete preNode;*/
						//iterate = nextNode;
						//delete vv;
						delete iterate;
						//cout << "da delete 2" << endl;
						return;
						//cout << "NOT RETURN" << endl;

					}
				}
				//cout << "still here 1" << endl;
				preNode = iterate;
				iterate = iterate->next;



			}
		}
		else if (Infantry* i = dynamic_cast<Infantry*> (armDelete)) {
			//cout << "YESSSSS" << endl;
			//cout << i->str() << endl;
			while (iterate != nullptr) {
				//Node* nextNode = iterate->next;
				if (Infantry* ii = dynamic_cast<Infantry*> (iterate->data)) {
					//cout << ii->str() << endl;
					if (i->getType() == ii->getType()) {
						this->unitList->minusOnecntInfantry();
						//cout << "YOOO" << endl;
						//cout << this->EXP << endl;
						this->EXP -= i->getAttackScore();
						//cout << this->EXP << endl;
						if (preNode == nullptr) {
							this->unitList->setHead(iterate->next);
							//cout << "HEHE" << endl;
						}
						else {
							preNode->next = iterate->next;
						}
						//delete iterate->data;
						//cout << "den roi" << endl;
						delete iterate;
						//cout << "da delete" << endl;
						return;
					}
				}
				preNode = iterate;
				iterate = iterate->next;
			}
		}

	}

	void fight(Army* enermy, bool defense) override {
		if (defense == false) {
			//cout << this->unitList->getCapacity()<<"hihi" << endl;
			/*this->LF = Round(LF * 1.5);
			this->EXP = Round(EXP * 1.5);*/
			vector < Vehicle*> curLF;
			vector <Infantry*> curEXP;
			Node* iterate = this->unitList->getHead();
			while (iterate != nullptr) {
				/*cout << iterate->data->str() <<" "<<iterate->data->getAttackScore()<< endl;*/
				if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
					curLF.push_back(v);

				}
				else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
					curEXP.push_back(i);
				}
				//cout << iterate->data->str() << endl;
				iterate = iterate->next;
			}
			iterate = enermy->getList()->getHead();
			while (iterate != nullptr) {
				//cout << iterate->data->str() <<" "<<iterate->data->getAttackScore()<< endl;
				iterate = iterate->next;
			}

			//cout << curEXP.size() << " " << curLF.size()<<" "<<LF<<" "<<EXP << endl;
			//return;
			//cout << "NO BUG" << endl;
			//return;
			int enermyEXP = enermy->getEXP();
			int enermyLF = enermy->getLF();
			//cout << this->EXP << " " << this->LF << endl;
			//cout << enermyEXP << " " << enermyLF << endl;
			//return;
			int ansLF = 0, ansEXP = 0;
			vector<int>dp(1001, 0);
			dp[0] = 1;
			vector<int>trace(1001, -1);
			trace[0] = 0;
			// tim to hop phuong tien nho nhat thoa man
			for (int i = 0; i<int(curLF.size()); i++) {
				for (int j = 1000; j >= curLF[i]->getAttackScore(); j--) {
					if (dp[j] == 0 && dp[j - curLF[i]->getAttackScore()] == 1) {
						dp[j] = 1;
						if (trace[j] == -1) trace[j] = i;
					}
				}
			}
			int lowestCost = -1;
			for (int i = Round(enermyLF/1.5); i <= 1000; i++) {
				if (dp[i] == 1) {
					lowestCost = i;
					break;
				}
			}
			if (lowestCost != -1) ansLF = 1;
			/* xoa to hop da duoc chon khoi danh sach*/
			vector<int>minimumSubLF;
			while (lowestCost > 0) {
				minimumSubLF.push_back(trace[lowestCost]);
				lowestCost -= curLF[trace[lowestCost]]->getAttackScore();
			}
			

			/* reset du lieu*/

			dp.resize(1001, 0);
			dp[0] = 1;
			trace.resize(1001, -1);
			trace[0] = 0;
			//tim to hop bo binh nho nhat thoa man
			for (int i = 0; i< int(curEXP.size()); i++) {
				for (int j = 1000; j >= curEXP[i]->getAttackScore(); j--) {
					if (dp[j] == 0 && dp[j - curEXP[i]->getAttackScore() ] == 1) {
						dp[j] = 1;
						if (trace[j] == -1) trace[j] = i;
					}
				}
			}
			lowestCost = -1;
			for (int i = Round(enermyEXP/1.5); i <= 1000; i++) {
				if (dp[i] == 1) {
					lowestCost = i;
					break;
				}
			}
			if (lowestCost != -1) ansEXP = 1;
			/* xoa to hop da duoc chon khoi danh sach */
			vector<int>minimumSubEXP;
		
			while (lowestCost > 0) {
				//cout << trace[lowestCost] << endl;
				minimumSubEXP.push_back(trace[lowestCost]);
				lowestCost -= curEXP[trace[lowestCost]]->getAttackScore();
			}

			if (ansLF != 0 && ansEXP != 0) {
				//cout << "YESS1" << endl;
				warTakesPlace = true;
				this->reCalEXP_LF();
				//cout << LF << " " << EXP << endl;
				/*for (int i = 0; i<int(minimumSubLF.size()); i++) {
					cout << curLF[minimumSubLF[i]]->str()<<" "<<curLF[minimumSubLF[i]]->getAttackScore() << endl;
				}*/
				for (int i = 0; i < int(minimumSubLF.size()); i++) {
					deleteNode(curLF[minimumSubLF[i]]);
				}
				/*for (int i = 0; i<int(minimumSubEXP.size()); i++) {
					cout << curEXP[minimumSubEXP[i]]->str() << " " << curEXP[minimumSubEXP[i]]->getAttackScore() << endl;
				}*/
				//bat dau xoa cac phan tu minimumSubEXP trong liskedList, if(ansEXP != - 1)
				for (int i = 0; i < int(minimumSubEXP.size()); i++) {
					deleteNode(curEXP[minimumSubEXP[i]]);
				}
				enermy->reCalEXP_LF();
				requistion(enermy);
				//cout << "NO BUG1" << endl;
				//return;
				//moi don vi quan su con lai mat 20% trong so weight
				Node* iterate2 = enermy->getList()->getHead();
				while (iterate2 != nullptr) {
					iterate2->data->minusWeight(20);
					iterate2 = iterate2->next;
				}
			}
			//return;
			
			else if (ansEXP == 0 || ansLF == 0) {
				if (ansEXP == 0) {
					if (Round(EXP*1.5) > enermyEXP) {
						//giao tranh van dien ra, xoa to hop thoa man LF khoi danh sach
						warTakesPlace = true;
						reCalEXP_LF();
						for (int i = 0; i < int(minimumSubLF.size()); i++) {
							deleteNode(curLF[minimumSubLF[i]]);
						}
						//van cap nhat chi so
						enermy->reCalEXP_LF();
						requistion(enermy);
						Node* iterate2 = enermy->getList()->getHead();
						while (iterate2 != nullptr) {
							iterate2->data->minusWeight(20);
							iterate2 = iterate2->next;
						}

					}
					else {
						//giao tranh khong dien ra
						warTakesPlace = false;
						reCalEXP_LF();
						noBattleConsequence();
					}
				}
				else if (ansLF == 0) {
					if (Round(LF*1.5) >enermyLF) {

						// giao tranh dien ra, xoa to hop EXP khoi danh sach
						warTakesPlace = true;
						reCalEXP_LF();
						for (int i = 0; i < int(minimumSubEXP.size()); i++) {
							deleteNode(curEXP[minimumSubEXP[i]]);
						}
						enermy->reCalEXP_LF();
						requistion(enermy);
						Node* iterate2 = enermy->getList()->getHead();
						while (iterate2 != nullptr) {
							iterate2->data->minusWeight(20);
							iterate2 = iterate2->next;
						}
					}
					else {
						//giao tranh khong dien ra
						reCalEXP_LF();
						enermy->reCalEXP_LF();
						warTakesPlace = false;
						noBattleConsequence();
					}
				}
			}
			else if (ansEXP == 0 && ansLF == 0) {
				//giao tranh khong dien ra
				reCalEXP_LF();
				warTakesPlace = false;
				noBattleConsequence();
			}
			//cout << "HAM NAY KHONG BUG" << endl;

		}
		else if (defense == true) {
			// phong thu
			/*LF = Round(LF * 1.3);
			EXP = Round(EXP * 1.3);*/
			int enermyLF = enermy->getLF();
			int enermyEXP = enermy->getEXP();
			if (Round(LF*1.3) >= enermyLF && Round(EXP*1.3) >= enermyEXP) {
				//giao tranh chien thang
				//gom chien loi pham
				reCalEXP_LF();
				requistion(enermy);
			}
			else if (Round(LF*1.3) < enermyLF && Round(EXP*1.3) >= enermyEXP || Round(EXP*1.3) < enermyEXP && Round(LF*1.3) >= enermyLF) {
				//mat 10% o moi don vi quan su
				reCalEXP_LF();
				Node* iterate = this->unitList->getHead();
				while (iterate != nullptr) {
					iterate->data->minusQuantity(10);

					iterate = iterate->next;
				}
			}
			else if (Round(LF*1.3) < enermyLF && Round(EXP*1.3) < enermyEXP) {
				while (Round(LF*1.3) < enermyLF && Round(EXP*1.3) < enermyEXP) {
					LF = 0;
					EXP = 0;
					Node* iterate = this->unitList->getHead();
					while (iterate != nullptr) {
						iterate->data->increaseQuantityToNearestFibonaci();
						if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
							LF += v->getAttackScore();

						}
						else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
							EXP += i->getAttackScore();
						}



						iterate = iterate->next;
					}
					// check lai
				}
			/*	LF = Round(LF * 1.3);
				EXP = Round(EXP * 1.3);*/
				if (Round(LF*1.3) >= enermyLF && Round(EXP*1.3) >= enermyEXP) {
					//giao tranh chien thang
					//gom chien loi pham
					reCalEXP_LF();
					requistion(enermy);
					Node* iterate2 = enermy->getList()->getHead();
					while (iterate2 != nullptr) {
						iterate2->data->minusWeight(20);
						iterate2 = iterate2->next;
					}
				}
				else if (Round(LF*1.3) < enermyLF && Round(EXP*1.3) >= enermyEXP || Round(EXP*1.3) < enermyEXP && Round(LF*1.3) >= enermyLF) {
					//mat 10% o moi don vi quan su
					reCalEXP_LF();
					Node* iterate = this->unitList->getHead();
					while (iterate != nullptr) {
						if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
							LF -= v->getAttackScore();
							v->minusQuantity(10);
							LF += v->getAttackScore();
						}
						else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
							EXP -= i->getAttackScore();
							i->minusQuantity(10);
							LF += i->getAttackScore();
						}

						iterate = iterate->next;
					}
				}


			}
		}
	}
	bool weatherWarTakesPlace() { return warTakesPlace; }
	
	string str() const override;

};

class ARVN : public Army {
private:

protected:



public:
	ARVN(const Unit** unitArray, int size, string name, BattleField* battleField) : Army(unitArray, size, name, battleField) {}
	ARVN(Unit** unitArray, int size, string name, BattleField* battleField) : Army(const_cast<const Unit**>(unitArray), size, name, battleField) {}
	
	void resetQuantity() {
		Node* iterate = this->unitList->getHead();
		Node* preNode = nullptr;
		while (iterate != nullptr) {
			Node* nextNode = iterate->next;
			//cap nhat lai chi só chien dau tuong ung
			/*iterate->data->minusQuantity(20);*/
			if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
				LF -= v->getAttackScore();
				v->minusQuantity(20);
				LF += v->getAttackScore();
				if (v->getQuantity() == 1) {

					// xoa don vi khoi danh sach
					LF -= v->getAttackScore();
					if (preNode == nullptr) {
						this->unitList->setHead(nextNode);

					}
					else {
						preNode->next = nextNode;
					}
					//delete iterate->data;
					delete iterate;
					iterate = nextNode;
					continue;

				}
			}
			else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
				EXP -= i->getAttackScore();
				i->minusQuantity(20);
				EXP += i->getAttackScore();
				if (i->getAttackScore() == 1) {
					EXP -= i->getAttackScore();
					if (preNode == nullptr) {
						this->unitList->setHead(nextNode);
					}
					else {
						preNode->next = nextNode;
					}
					delete iterate;
					iterate = nextNode;
					continue;
				}
			}
			preNode = iterate;
			iterate = iterate->next;

		}
	}
	void LiberationTakeUnit(Army* enermy) {
		Node* iterate = this->getList()->getHead();
		Node* preNode = nullptr;
		while (iterate != nullptr) {
			Node* nextNode = iterate->next;
			if (enermy->getList()->insert(iterate->data) == true) {
				//xoa node hien tai
				if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
					LF -= v->getAttackScore();
					if (preNode == nullptr) {
						this->unitList->setHead(nextNode);
					}
					else {
						preNode->next = nextNode;
					}
					delete iterate;
					iterate = nextNode;
					continue;
				}
				else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
					EXP -= i->getAttackScore();
					if (preNode == nullptr) {
						this->unitList->setHead(nextNode);
					}
					else {
						preNode->next = nextNode;
					}
					delete iterate;
					iterate = nextNode;
					continue;
				}
			}
			preNode = iterate;
			iterate = iterate->next;



		}

	}


	void fight(Army* enermy, bool defence) {
		
		if (defence == false) {
			//cap nhat lai giam 20% quantity moi don vi
			//cout << "BUG O DAY NE" << endl;
			reCalEXP_LF();
			LiberationTakeUnit(enermy);
			enermy->reCalEXP_LF();


			resetQuantity();
		}
		else if (defence == true) {
			enermy->fight(this, false);
			if (LiberationArmy* Li = dynamic_cast<LiberationArmy*> (enermy)) {
				// neu giao tranh dien ra va Quan Giai Phong Thang
				enermy->reCalEXP_LF();
				reCalEXP_LF();
				if (Li->weatherWarTakesPlace() == true) {
					
					//duyet qua ARVN List
					Node* iterate = this->unitList->getHead();
					Node* preNode = nullptr;
					while (iterate != nullptr) {
						Node* nextNode = iterate->next;
						if (Li->getList()->insert(iterate->data) == true) {
							//chen duoc vao Liberation List -> xoa Node hien tai
							if (preNode == nullptr) {
								this->unitList->setHead(nextNode);

							}
							else {
								preNode->next = nextNode;
							}
							//delete iterate->data;
							delete iterate;
							iterate = nextNode;
							continue;



						}
						else {
							// capacity cua Liberation Army da day, tru 20% weight cua nhung don vi con lai
							iterate->data->minusWeight(20);

						}



						preNode = iterate;
						iterate = iterate->next;

					}
					delete preNode;


				}
				else {
					//neu giao tranh khong dien ra

				}
			}
		}

	}
	string str() const override;
	


};

class TerrainElement
{
private:
	Position *pos;

public:
	TerrainElement(Position *Pos): pos(Pos) {};
	TerrainElement();
	~TerrainElement() {
		delete pos;
	}
    virtual void getEffect(Army *army) = 0;
};
class Road : public TerrainElement {

public:
	Road(Position* pos) :TerrainElement(pos) {};
	void getEffect(Army *army) override {

	}
};
class Mountain : public TerrainElement {

public:
	Mountain(Position* pos) : TerrainElement(pos) {};
	void getEffect(Army* army) override {

	}
};
class River : public TerrainElement {
public:
	River(Position* pos) : TerrainElement(pos) {};
	void getEffect(Army* army) override {

	}
};
class Urban : public TerrainElement {

public:
	Urban(Position* pos) : TerrainElement(pos) {};
	void getEffect(Army* army) override {
		
	}
};
class Fortification : public TerrainElement {

public: 
	Fortification(Position* pos) :TerrainElement(pos) {};
	void getEffect(Army* army) override {

	}
};
class SpecialZone :public TerrainElement {

public:
	SpecialZone(Position* pos) : TerrainElement(pos) {};
	void getEffect(Army* army) override {

	}
};

class BattleField
{
private:
	int n_rows, n_cols;
    // TODO
	TerrainElement*** terrain;
public:
	
    BattleField(int n_rows, int n_cols, vector<Position *> arrayForest,
                vector<Position *> arrayRiver, vector<Position *> arrayFortification,
                vector<Position *> arrayUrban, vector<Position *> arraySpecialZone);
    ~BattleField();
	BattleField() {
		n_rows = 0;
		n_cols = 0;
		terrain = nullptr;
	}
	string str() const;
	int getRow() const {  return n_rows; }
	int getCol() const { return n_cols; }
	void setRow() { n_rows = 0; }
	void setCol() { n_cols = 0; }
	TerrainElement*** getTerrainElement() { return terrain; }
};
class Configuration {

private:
	int num_rows, num_cols;
	vector<Position*> arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone;
	Unit** LiberationUnits;
	Unit** ARVNUnits;
	int LiBerationUnitsSize;
	int ARVNUnitsSize;
	int eventCode;

public:


	Configuration(const string& filepath);
	~Configuration();

	string str() const;
	int get_num_rows() { return num_rows; }
	int get_num_cols() { return num_cols; }
	vector<Position*> getArrayForest() { return arrayForest; }
	vector<Position*> getArrayRiver() { return arrayRiver; }
	vector<Position*> getArrayFortification() { return arrayFortification; }
	vector<Position*> getArrayUrban() { return arrayUrban; }
	vector<Position*> getArraySpecialZone() { return arraySpecialZone; }
	Unit** get_LiberationUnits() { return LiberationUnits; }
	Unit** get_ARVNUnits() { return ARVNUnits; }
	int get_LiberationUnitsSize() { return LiBerationUnitsSize; }
	int get_ARVNUnitsSize() { return ARVNUnitsSize; }
	int get_eventCode() { return eventCode; }
    string getNameType(const string& s, int& index) {
        string res;
        for (; index<int(s.size()); index++) {
            if (s[index] == '=') break;
        }
        res = s.substr(0, index);
        index++;
        return res;
    }

    string getNumTypeStr(const string& s, int& index) {
        string res = "";
        for (; index< int(s.size()); index++) {
            res = res + s[index];
        }
        return res;
    }


};

class HCMCampaign
{
private:
    Configuration *config;
    BattleField *battleField;
    LiberationArmy *liberationArmy;
    ARVN *arvn;

public:
    HCMCampaign(const string &config_file_path);
    void run();
    string printResult();
};

#endif