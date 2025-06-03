#include "hcmcampaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
////////////////////////////////////////////////////////////////////////

int Round(double a) {
	return int(a) + int(a > int(a));
}
string intToString(int n) {
	if (n == 0) return "0";
	string ans = "";
	while (n) {
		ans = char((n % 10) + 48) + ans;
		n /= 10;
	}
	return ans;
}
int stringToInt(string s) {
	int ans = 0;
	int mulTen = 1;
	for (int i = int(s.size()) - 1; i >= 0; i--) {
		ans += (int(s[i]) - 48) * mulTen;
		mulTen *= 10;
	}
	return ans;
}
vector<int>FibonaciList;
vector<int>PrimeLowerTen = { 2,3,5,7 };
void getFibonaciList() {
	FibonaciList[0] = 1;
	FibonaciList[1] = 1;
	int index = 2;
	while (FibonaciList[index - 2] + FibonaciList[index - 1] < pow(2, 32) - 1) {

		FibonaciList.push_back(FibonaciList[index - 2] + FibonaciList[index - 1]);
		index++;
	}
}

Unit::Unit(int quantity, int weight, Position pos) : quantity(quantity), weight(weight), pos(pos) {}

Unit::~Unit() {}
void Unit::minusWeight(int percentage) {
	weight = Round(1.0 * weight - (percentage / 100.0) * weight);

}
void Unit::minusQuantity(int percentage) {
	quantity = Round(1.0 * quantity - (percentage / 100.0) * quantity);
}

void Unit::increaseQuantityToNearestFibonaci() {
	//
	if (int(FibonaciList.size()) == 0) getFibonaciList();
	// tim kiem nhi phan
	int lo = 0, hi = int(FibonaciList.size()) - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (FibonaciList[mid] >= quantity) {
			quantity = FibonaciList[mid];
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

}

Position::Position(int r, int c) : r(r), c(c) {}
Position::Position(const string& str_pos) {
	//cout << str_pos << endl;
	string x = "", y = "";
	int i = 0;
	int n = int(str_pos.size());
	for (; i < n; i++) {
		if (str_pos[i] == ',') break;
		if (str_pos[i] == '(') continue;
		if (str_pos[i] == ')') continue;
		x = x + str_pos[i];
	}
	i++;
	for (; i < n; i++) {
		if (str_pos[i] == '(') continue;
		if (str_pos[i] == ')') break;
		y = y + str_pos[i];
	}
	r = stringToInt(x);
	c = stringToInt(y);

}
Position Unit::getCurrentPosition() const {

	return pos;
}
int Position::getRow() const {
	return r;
}
int Position::getCol() const {
	return c;
}
void Position::setRow(int r) {
	this->r = r;
}
void Position::setCol(int c) {
	this->c = c;
}
string Position::str() const {
	return "("+intToString(this->getRow()) + "," + intToString(this->getCol())+")";
}
string getNameVehicle(VehicleType Type) {
	if (Type == 0) return "TRUCK";
	if (Type == 1) return "MORTAR";
	if (Type == 2) return "ANTIAIRCRAFT";
	if (Type == 3) return "ARMOREDCAR";
	if (Type == 4) return "APC";
	if (Type == 5) return "ARTILLERY";
	return "TANK";
}
string getNameInfantry(InfantryType Type) {
	if (Type == 0) return "SNIPER";
	if (Type == 1) return "ANTIAIRCRAFTSQUAD";
	if (Type == 2) return "MORTARSQUAD";
	if (Type == 3) return "ENGINEER";
	if (Type == 4) return "SPECIALFORCES";
	return "REGULARINFANTRY";
}
vector<string> VehicleTypeStr = { "TRUCK", "MORTAR", "ANTIAIRCRAFT", "ARMOREDCAR", "APC", "ARTILLERY", "TANK" };
vector<string> InfantryTypeStr = { "SNIPER", "ANTIAIRCRAFTSQUAD", "MORTARSQUAD", "ENGINEER", "SPECIALFORCES", "REGULARINFANTRY" };
int checkTypeBeLonging(const string& curType) {
	for (int i = 0; i< int(VehicleTypeStr.size()); i++) {
		if (curType == VehicleTypeStr[i]) return 1;
	}
	return 2;
}
VehicleType getVehicleTypeFromStr(const string& str) {
	if (str == "TRUCK") return TRUCK;
	else if (str == "MORTAR") return MORTAR;
	else if (str == "ANTIAIRCRAFT") return ANTIAIRCRAFT;
	else if (str == "ARMOREDCAR") return ARMOREDCAR;
	else if (str == "APC") return APC;
	else if (str == "ARTILLERY") return ARTILLERY;
	else return TANK; 
}
InfantryType getInfantryTypeFromStr(const string& str) {
	if (str == "SNIPER") return SNIPER;
	else if (str == "ANTIAIRCRAFTSQUAD") return ANTIAIRCRAFTSQUAD;
	else if (str == "MORTARSQUAD") return MORTARSQUAD;
	else if (str == "ENGINEER") return ENGINEER;
	else if (str == "SPECIALFORCES") return SPECIALFORCES;
	else return REGULARINFANTRY;
}





Vehicle::Vehicle(int quantity, int weight, const Position pos, VehicleType vehicleType) :Unit(quantity, weight, pos), vehicleType(vehicleType) {}



Infantry::Infantry(int quantity, int weight, const Position pos, InfantryType infantryType) :Unit(quantity, weight, pos), infantryType(infantryType) {}

UnitList::UnitList(int capacity) {
	this->capacity = capacity;
	this->cntInfantry = 0;
	this->cntVehicle = 0;
	head = nullptr;
}
bool UnitList::hasNotAppearedVehicle(Vehicle* v) {
	//cout << "checkNotAppearVehicle" << endl;
	Node* iterate = this->getHead();
	while (iterate != nullptr) {
		//cout << iterate->data->str() << " " << v->str() << endl;
		if (Vehicle* u = dynamic_cast<Vehicle*> (iterate->data)) {
			if (u->getType() == v->getType()) return false;
		}
		iterate = iterate->next;
	}

	return true;
}
bool UnitList::hasNotAppearedInfantry(Infantry* i) {
	//cout << "checkNotAppearInfantry" << endl;
	Node* iterate = this->getHead();
	while (iterate != nullptr) {
		if (Infantry* j = dynamic_cast<Infantry*> (iterate->data)) {
			if (i->getType() == j->getType()) return false;
		}
		iterate = iterate->next;
	}
	return true;
}
bool UnitList::insert(Unit* unit) {
	if (cntVehicle + cntInfantry >= capacity) return false;
	if (Vehicle* v = dynamic_cast<Vehicle*> (unit)) {
		if (hasNotAppearedVehicle(v)==true) {
			//cout << "HASNOTAPPEAR1" << endl;
			cntVehicle++;
			// insert tail
			Node* newNode = new Node(unit);
			if (head == nullptr) {
				head = newNode;
				return true;
			}
			Node* iterate = head;
			while (iterate->next != nullptr) {
				iterate = iterate->next;
			}
			iterate->next = newNode;
			return true;
		}else {
			
			Node* iterate = head;
			while (iterate != nullptr) {
				if (Vehicle* u = dynamic_cast<Vehicle*> (iterate->data)) {
					if (u->getType() == v->getType()) {
						u->setQuantity(u->getQuantity() + v->getQuantity());

						return true;
					}
				}
				iterate = iterate->next;
				
			}

		}

	}
	else if (Infantry* i = dynamic_cast<Infantry*> (unit)) {
		if (hasNotAppearedInfantry(i)==true) {
			//cout << "HASNOTAPPEAR2" << endl;
			cntInfantry++;
			//insert head
			Node* newNode = new Node(unit);
			newNode->next = head;
			head = newNode;
			newNode->data->getAttackScore();
			return true;
		}
		else {
			Node* iterate = head;
			while (iterate != nullptr) {
				if (Infantry* j = dynamic_cast<Infantry*> (iterate->data)) {
					if (j->getType() == i->getType()) {
						j->setQuantity(j->getQuantity() + i->getQuantity());
						j->getAttackScore();
						return true;
					}
				}
				iterate = iterate->next;
			}

		}
		
		
	}
	return false;
}
bool FooCheckSpecialNumber(int armNum, int curPrimeNum, int curSum = 0, int powNum = 0) {
	if (powNum > 11) return false;
	if (curSum > armNum) return false;
	if (curSum == armNum) return true;
	return (FooCheckSpecialNumber(armNum, curPrimeNum, curSum + pow(curPrimeNum, powNum), powNum + 1) || FooCheckSpecialNumber(armNum, curPrimeNum, curSum, powNum + 1));
}
bool checkSpecialNumber(int n) {
	// chay 11 bit tu 0 den 2^11 - 1
	for (int i = 0; i < 4; i++) {
		if (FooCheckSpecialNumber(n, PrimeLowerTen[i]) == true) return true;
		
	}
	//O(4*2048)


	return false;
}
bool UnitList::isContain(VehicleType vehicleType) {
	Node* iterate = head;
	while (iterate != nullptr) {
		if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
			if (v->getType() == vehicleType) return true;
		}
		iterate = iterate->next;
	}
	return false;
}
bool UnitList::isContain(InfantryType infantryType) {
	Node* iterate = head;
	while (iterate != nullptr) {
		if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) return false;
		if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
			if (i->getType() == infantryType) return true;
		}
		iterate = iterate->next;
	}
	return false;
}
string UnitList::str() const{
	string ans = "UnitList[count_vehicle=" + intToString(cntVehicle) + ";count_infantry=" + intToString(cntInfantry) + ";";
	Node* iterate = head;
	while (iterate != nullptr) {
		if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
			ans = ans + v->str() + ",";
		}
		else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
			ans = ans + i->str() + ",";
		}
		
		iterate = iterate->next;
	}
	ans.pop_back();
	ans = ans + "]";
	return ans;
}
Army::Army(const Unit** unitArray, int size, string name, BattleField* battleField) : name(name), battleField(battleField) {
	if (this->battleField == nullptr) {
		//cout << "YES11" << endl;
		// khoi tao lai battleField
		this->battleField = new BattleField();
	}
	LF = 0;
	EXP = 0;
	for (int i = 0; i < size; i++) {
		/*unitList->insert(const_cast<Unit*> (unitArray[i]));*/
		Unit* u = const_cast<Unit*> (unitArray[i]);
		
		if (Vehicle* v = dynamic_cast<Vehicle*>(u)) {
			LF += v->getAttackScore();
		}
		else if (Infantry* i = dynamic_cast<Infantry*> (u)) {
			EXP += i->getAttackScore();
		}

	}

	if (checkSpecialNumber(LF + EXP) == true) {
		unitList = new UnitList(12);
	}
	else unitList = new UnitList(8);
	for (int i = 0; i < size; i++) {
		/*unitList->insert(const_cast<Unit*> (unitArray[i]));*/
		Unit* u = const_cast<Unit*> (unitArray[i]);
		//cout << u->str() << endl;
		unitList->insert(u);

	}

}
void Army::reCalEXP_LF() {
	this->EXP = 0;
	this->LF = 0;
	Node* iterate = this->unitList->getHead();
	while (iterate != nullptr) {
		if (Vehicle* v = dynamic_cast<Vehicle*> (iterate->data)) {
			this->LF += v->getAttackScore();
		}
		else if (Infantry* i = dynamic_cast<Infantry*> (iterate->data)) {
			this->EXP += i->getAttackScore();
		}


		iterate = iterate->next;
	}
}
string ARVN::str() const {
	//cout << "HELLO" << endl;
	return "ARVN[LF=" + intToString(LF) + ",EXP=" + intToString(EXP) + ",unitList=" + this->unitList->str() + ",battleField=" + this->battleField->str() + "]";
	
}
string LiberationArmy::str() const  {
	//return "bug o day";
	//return "LiberationArmy[name=<" + name + ">,LF=<" + intToString(LF) + ">,EXP=<" + intToString(EXP) + ">,unitList=<" + this->unitList->str() + ">,battleField=<" + this->battleField->str() + ">]";
	return "LiberationArmy[LF=" + intToString(LF) + ",EXP=" + intToString(EXP) + ",unitList=" + this->unitList->str() + ",battleField=" + this->battleField->str()+ "]";
	//return this->battleField->str();
}




Configuration::Configuration(const string& filepath) {
	ifstream myFile(filepath);
	if (myFile.is_open()) {
		string line;
		while (getline(myFile, line)) {
			//cout << line << endl;
			int index = 0;
			string nameType = getNameType(line, index);
			if (nameType == "NUM_ROWS") {
				//cout << "IM HERE HIHI" << endl << endl;
				string numStr = getNumTypeStr(line, index);

				//cout << line << endl << endl;
				this->num_rows = stringToInt(numStr);
				//cout << num_rows << endl;
				//cout << nameType << " " << num_rows << endl;
			}
			else if (nameType == "NUM_COLS") {
				string numStr = getNumTypeStr(line, index);
				this->num_cols = stringToInt(numStr);
				//cout << nameType << " " << num_cols << endl;
			}
			else if (nameType == "ARRAY_FOREST") {
				string curCoordinate = "";
				for (; index <int(line.size()); index++) {
					if (line[index] == '[' || line[index] == ']' || (line[index] == ',' && int(curCoordinate.size()) == 0)) continue;
					curCoordinate = curCoordinate + line[index];
					if (line[index] == ')') {
						arrayForest.push_back(new Position(curCoordinate));
						//cout << curCoordinate << endl;
						curCoordinate = "";
					}
				}
				/*for (Position* x : arrayForest) {
					cout << x->str() << endl;
				}*/
			}
			else if (nameType == "ARRAY_RIVER") {
				string curCoordinate = "";
				for (; index <int(line.size()); index++) {
					if (line[index] == '[' || line[index] == ']' || (line[index] == ',' && int(curCoordinate.size()) == 0)) continue;
					curCoordinate = curCoordinate + line[index];
					if (line[index] == ')') {
						arrayRiver.push_back(new Position(curCoordinate));
						curCoordinate = "";
					}
				}
			}
			else if (nameType == "ARRAY_FORTIFICATION") {
				string curCoordinate = "";
				for (; index <int(line.size()); index++) {
					if (line[index] == '[' || line[index] == ']' || (line[index] == ',' && int(curCoordinate.size()) == 0)) continue;
					curCoordinate = curCoordinate + line[index];
					if (line[index] == ')') {
						arrayFortification.push_back(new Position(curCoordinate));
						curCoordinate = "";
					}
				}
			}
			else if (nameType == "ARRAY_URBAN") {
				string curCoordinate = "";
				for (; index <int(line.size()); index++) {
					if (line[index] == '[' || line[index] == ']' || (line[index] == ',' && int(curCoordinate.size()) == 0)) continue;
					curCoordinate = curCoordinate + line[index];
					if (line[index] == ')') {
						arrayUrban.push_back(new Position(curCoordinate));
						curCoordinate = "";
					}
				}
			}
			else if (nameType == "ARRAY_SPECIAL_ZONE") {
				string curCoordinate = "";
				for (; index <int(line.size()); index++) {
					if (line[index] == '[' || line[index] == ']' || (line[index] == ',' && int(curCoordinate.size()) == 0)) continue;
					curCoordinate = curCoordinate + line[index];
					if (line[index] == ')') {
						arraySpecialZone.push_back(new Position(curCoordinate));
						curCoordinate = "";
					}
				}
			}
			else if (nameType == "UNIT_LIST") {
				//cout << line << endl;
				//int LiberationUnitsSize = 0;
				//int ARVNUnitsSize = 0;
				vector<Unit*> vecLibearationUnits;
				vector<Unit*> vecARVNUnits;
				int i = index;
				string curUnitStr = "";
				for (; i < int(line.size()); i++) {
					if (line[i] == '[' ) continue;
					curUnitStr = curUnitStr + line[i];
					if ((line[i] == ',' && line[i - 1] == ')' && int(line[i + 1] >= 65 && int(line[i + 1] <= 90))) || line[i] == ')' && line[i + 1] == ']') {
						int belongingArmy;
						int curQuantity;
						int curWeight;
						Position curPosition;
						string curTypeArmy = "";
						int j;
						for (j = 0; j<int(curUnitStr.size()); j++) {
							if (int(curUnitStr[j] < 65 || int(curUnitStr[j] > 90))) break;
							curTypeArmy = curTypeArmy + curUnitStr[j];
						}
						j++;
						string curNumStr = "";
						for (; j<int(curUnitStr.size()); j++) {
							if (curUnitStr[j] == ',') break;
							curNumStr = curNumStr + curUnitStr[j];
						}
						curQuantity = stringToInt(curNumStr);
						j++;
						curNumStr = "";
						for (; j<int(curUnitStr.size()); j++) {
							if (curUnitStr[j] == ',') break;
							curNumStr = curNumStr + curUnitStr[j];
						}
						curWeight = stringToInt(curNumStr);
						j++;
						curNumStr = "";
						for (; j<int(curUnitStr.size()); j++) {
							if (curUnitStr[j] == ','&&curUnitStr[j-1]==')') break;
							curNumStr = curNumStr + curUnitStr[j];
						}
						//cout << curNumStr << endl;
						j++;
						curPosition = Position(curNumStr);
						curNumStr = "";
						for (; j<int(curUnitStr.size()); j++) {
							if (curUnitStr[j] == ')') break;
							curNumStr = curNumStr + curUnitStr[j];
						}
						belongingArmy = stringToInt(curNumStr);
						//cout << curUnitStr << endl;
						/*cout << curTypeArmy << endl;
						cout << curQuantity << endl;
						cout << curWeight << endl;
						cout << curPosition.str() << endl;
						cout << belongingArmy << endl;*/
						belongingArmy = stringToInt(curNumStr);
						if (belongingArmy == 0) {
							//quan giai phong
							if (checkTypeBeLonging(curTypeArmy)==1) {
								//Vehicle Type
								Vehicle* tmp = new Vehicle(curQuantity, curWeight, curPosition, getVehicleTypeFromStr(curTypeArmy));
								vecLibearationUnits.push_back(tmp);
							}
							else { 
								//Tnfantry Type
								Infantry* tmp = new Infantry(curQuantity, curWeight, curPosition, getInfantryTypeFromStr(curTypeArmy));
								vecLibearationUnits.push_back(tmp);
							}
							
						}
						else {
							//ARVN
							if (checkTypeBeLonging(curTypeArmy) == 1) {
								//Vehicle Type
								Vehicle* tmp = new Vehicle(curQuantity, curWeight, curPosition, getVehicleTypeFromStr(curTypeArmy));
								vecARVNUnits.push_back(tmp);
							}
							else {
								//Infantry Type
								Infantry* tmp = new Infantry(curQuantity, curWeight, curPosition, getInfantryTypeFromStr(curTypeArmy));
								vecARVNUnits.push_back(tmp);
							}
						}



						curUnitStr = "";
					}
					
				}
			
				int n = int(vecLibearationUnits.size());
				int m = int(vecARVNUnits.size());
				LiberationUnits = new Unit*[n];
				LiBerationUnitsSize = n;
				ARVNUnitsSize = m;
				ARVNUnits = new Unit * [m];
				for (int k = 0; k < n; k++) LiberationUnits[k] = vecLibearationUnits[k];
				for (int k = 0; k < m; k++) ARVNUnits[k] = vecARVNUnits[k];
				
				
			}else if(nameType == "EVENT_CODE"){
				string numStr = getNumTypeStr(line, index);
				int tmp = stringToInt(numStr);
				if (numStr[0] == '-') tmp = 0;
				if (tmp > 99) tmp = tmp % 10 + 10 * tmp % 100;
				eventCode = tmp;

			}


			
		}
		myFile.close();

	}
}
//Phuong thuc cua BattleField
BattleField::BattleField(int n_rows, int n_cols, vector<Position*> arrayForest,
	vector<Position*> arrayRiver, vector<Position*> arrayFortification,
	vector<Position*> arrayUrban, vector<Position*> arraySpecialZone) : n_rows(n_rows), n_cols(n_cols) {
	//cout << "HELLO" << endl;
	terrain = new TerrainElement **[n_rows];
	for (int i = 0; i < n_rows; i++) {
		terrain[i] = new TerrainElement * [n_cols];
		for (int j = 0; j < n_cols; j++) {
			terrain[i][j] = new Road(new Position(i, j));
		}

	}
	for (Position* curPos : arrayForest) {
		int i = curPos->getRow();
		int j = curPos->getCol();
		terrain[i][j] = new Mountain(new Position(i, j));
	}
	for (Position* curPos : arrayRiver) {
		int i = curPos->getRow();
		int j = curPos->getCol();
		terrain[i][j] = new River(new Position(i, j));
	}
	for (Position* curPos : arrayFortification) {
		int i = curPos->getRow();
		int j = curPos->getCol();
		terrain[i][j] = new Fortification(new Position(i, j));
	}
	for (Position* curPos : arrayUrban) {
		int i = curPos->getRow();
		int j = curPos->getCol();
		terrain[i][j] = new Urban(new Position(i, j));
	}
	for (Position* curPos : arraySpecialZone) {
		int i = curPos->getRow();
		int j = curPos->getCol();
		terrain[i][j] = new SpecialZone(new Position(i, j));
	}

}
BattleField::~BattleField() {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			delete terrain[i][j];
		}
		delete[] terrain[i];
	}
	delete[] terrain;
}
string BattleField::str()  const{
	if (n_rows == 0 || n_cols == 0) return "";
	return "battleField[n_rows=" + intToString(n_rows)+",n_cols=" + intToString(n_cols)+"]";
}


Configuration::~Configuration() {
	for (Position* x : arrayForest) delete x;
	for (Position* x : arrayFortification) delete x;
	for (Position* x : arrayRiver) delete x;
	for (Position* x : arraySpecialZone) delete x;
	for (Position* x : arrayUrban) delete x;
	for (int i = 0; i < LiBerationUnitsSize; i++) {
		delete LiberationUnits[i];
	}
	delete LiberationUnits;
	for (int i = 0; i < ARVNUnitsSize; i++) {
		delete ARVNUnits[i];
	}
	delete ARVNUnits;

}

string Configuration::str() const {
	string ans = "[num_rows=" + intToString(num_rows) + ",num_cols=" + intToString(num_cols);
	ans = ans + ",arrayForest=[";
	for (int i = 0; i<int(arrayForest.size()); i++) {
		ans = ans + arrayForest[i]->str();
		if (int(arrayForest.size()) - 1 > i) {
			ans = ans + ",";
		}
	}

	ans = ans + "],arrayRiver=[";
	for (int i = 0; i<int(arrayRiver.size()); i++) {
		ans = ans + arrayRiver[i]->str();
		if (int(arrayRiver.size()) - 1 > i) {
			ans = ans + ",";
		}
	}
	ans = ans + "],arrayFortification=[";
	for (int i = 0; i<int(arrayFortification.size()); i++) {
		ans = ans + arrayFortification[i]->str();
		if (int(arrayFortification.size()) - 1 > i) {
			ans = ans + ",";
		}
	}
	ans = ans + "],arrayUrban=[";
	for (int i = 0; i<int(arrayUrban.size()); i++) {
		ans = ans + arrayUrban[i]->str();
		if (int(arrayUrban.size()) - 1 > i) {
			ans = ans + ",";
		}
	}
	ans = ans + "],arraySpecialZone=[";
	for (int i = 0; i<int(arraySpecialZone.size()); i++) {
		ans = ans + arraySpecialZone[i]->str();
		if (int(arraySpecialZone.size()) - 1 > i) {
			ans = ans + ",";
		}
	}
	ans = ans + "],liberationUnits=[";
	for (int i = 0; i < LiBerationUnitsSize; i++) {
		ans = ans + LiberationUnits[i]->str();
		if (LiBerationUnitsSize - 1 > i) {
			ans = ans + ",";
		}
		
	}
	ans = ans + "],ARVNUnits=[";
	for (int i = 0; i < ARVNUnitsSize; i++) {
		ans = ans + ARVNUnits[i]->str();
		if (ARVNUnitsSize - 1 > i) {
			ans = ans + ",";
		}
	}
	ans = ans + "],eventCode=" + intToString(eventCode)+"]";

	return ans;
}

HCMCampaign::HCMCampaign(const string &config_the_path) {
	config = new Configuration(config_the_path);
	battleField = new BattleField(config->get_num_rows(), config->get_num_cols(), config->getArrayForest(),
		config->getArrayRiver(), config->getArrayFortification(), config->getArrayUrban(), config->getArraySpecialZone());
	liberationArmy = new LiberationArmy(config->get_LiberationUnits(), config->get_LiberationUnitsSize(), "LiberationArmy", battleField);
	arvn = new ARVN(config->get_ARVNUnits(), config->get_ARVNUnitsSize(), "ARVN", battleField);
	//cout<<battleField->str() << endl;
	//cout << printResult() << endl;
	/*cout << liberationArmy->str() << " " << liberationArmy->getEXP() << " " << liberationArmy->getLF() << endl << endl;
	cout << arvn->str() << " " << arvn->getEXP() << " " << arvn->getLF() << endl;*/
}
void HCMCampaign::run() {
	//duyet qua battlefield terrain de tang chi so
	int rows = battleField->getRow();
	int cols = battleField->getCol();
	TerrainElement*** terrain = battleField->getTerrainElement();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (Road* road = dynamic_cast<Road*>(terrain[i][j])) {
				continue;
			}
			else if (Mountain* mountain = dynamic_cast<Mountain*>(terrain[i][j])) {
				//duyet qua list cua liberation
				Node* iterate1 = liberationArmy->getList()->getHead();
				Position curPosition = Position(i, j);
				while (iterate1 != nullptr) {
					if (iterate1->data->getDistance(curPosition) <= 2.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate1->data)) {
							//cong them 30% EXP vao attackscore
							liberationArmy->setEXP(liberationArmy->getEXP() + Round(1.0 * 0.3 * (iterate1->data->getAttackScore())));

						}
						else if (Vehicle* v = dynamic_cast<Vehicle*> (iterate1->data)) {
							//LF bi tru 10%
							liberationArmy->setLF(liberationArmy->getLF() - Round(1.0 * 0.1 * (iterate1->data->getAttackScore())));
						}
						
					}
					iterate1 = iterate1->next;
				}
				//duyet qua list cua arvn
				Node* iterate2 = arvn->getList()->getHead();
				while (iterate2 != nullptr) {
					if (iterate2->data->getDistance(curPosition) <= 4.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate2->data)) {
							//cong them 20% vao attackscore
							arvn->setEXP(arvn->getEXP() + Round(1.0 * 0.2 * (iterate2->data->getAttackScore())));

						}
						else if (Vehicle* v = dynamic_cast<Vehicle*> (iterate2->data)) {
							//LF bi tru 5%
							arvn->setLF(arvn->getLF() - Round(1.0 * 0.05 * (iterate2->data->getAttackScore())));
						}

					}
					iterate2 = iterate2->next;
				}
			}
			else if (River* river = dynamic_cast<River*> (terrain[i][j])) {
				//doi voi liberationArmy
				Node* iterate1 = liberationArmy->getList()->getHead();
				Position curPosition = Position(i, j);
				while (iterate1 != nullptr) {
					if (iterate1->data->getDistance(curPosition) <= 2.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate1->data)) {
							liberationArmy->setEXP(liberationArmy->getEXP() - Round(1.0 * 0.1 * (iterate1->data->getAttackScore())));
						}
					}
					iterate1 = iterate1->next;
				}
				//doi voi ARVN
				Node* iterate2 = arvn->getList()->getHead();
				while (iterate2 != nullptr) {
					if (iterate2->data->getDistance(curPosition) <= 2.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate2->data)) {
							arvn->setEXP(arvn->getEXP() - Round(1.0 * 0.1 * (iterate2->data->getAttackScore())));
						}
					}
					iterate2 = iterate2->next;
				}
			}
			else if (Urban* ub = dynamic_cast<Urban*> (terrain[i][j])) {
				Node* iterate1 = liberationArmy->getList()->getHead();
				Position curPosition = Position(i, j);
				while (iterate1 != nullptr) {
					if (iterate1->data->getDistance(curPosition) <= 5.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate1->data)) {
							if (i->getType() == SPECIALFORCES || i->getType() == REGULARINFANTRY) {
								liberationArmy->setEXP(liberationArmy->getEXP() + Round(1.0 * (iterate1->data->getAttackScore()) / (iterate1->data->getDistance(curPosition))));
							}
						}
						if (iterate1->data->getDistance(curPosition) <= 2.0) {
							if (Vehicle* v = dynamic_cast<Vehicle*> (iterate1->data)) {
								if (v->getType() == ARTILLERY) {
									liberationArmy->setLF(liberationArmy->getLF() - Round(0.5 * (iterate1->data->getAttackScore())));
								}
							}
						}
					}
					iterate1 = iterate1->next;
				}
				Node* iterate2 = arvn->getList()->getHead();
				while (iterate2 != nullptr) {
					if (iterate2->data->getDistance(curPosition) <= 3.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate2->data)) {
							if (i->getType() == REGULARINFANTRY) {
								arvn->setEXP(arvn->getEXP() + Round(1.5 * (iterate2->data->getAttackScore()) / (iterate2->data->getDistance(curPosition))));
							}
						}
					}
					iterate2 = iterate2->next;
				}
			}
			else if (Fortification* fc = dynamic_cast<Fortification*> (terrain[i][j])) {
				//doi voi liberationArmy
				Node* iterate1 = liberationArmy->getList()->getHead();
				Position curPosition = Position(i, j);
				while (iterate1 != nullptr) {
					if (iterate1->data->getDistance(curPosition) <= 2.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate1->data)) {
							liberationArmy->setEXP(liberationArmy->getEXP() - Round(0.2 * iterate1->data->getAttackScore()));
						}
						else if (Vehicle* v = dynamic_cast<Vehicle*> (iterate1->data)) {
							liberationArmy->setLF(liberationArmy->getLF() - Round(0.2 * iterate1->data->getAttackScore()));
						}
					}
					iterate1 = iterate1->next;
				}
				Node* iterate2 = arvn->getList()->getHead();
				while (iterate2 != nullptr) {
					if (iterate2->data->getDistance(curPosition) <= 2.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate2->data)) {
							arvn->setEXP(arvn->getEXP() + Round(0.2 * iterate2->data->getAttackScore()));
						}
						else if (Vehicle* v = dynamic_cast<Vehicle*> (iterate2->data)) {
							arvn->setLF(arvn->getLF() + Round(0.2 * iterate2->data->getAttackScore()));
						}
					}
					iterate2 = iterate2->next;
				}
			}
			else if (SpecialZone* sz = dynamic_cast<SpecialZone*> (terrain[i][j])) {
				Node* iterate1 = liberationArmy->getList()->getHead();
				Position curPosition = Position(i, j);
				while (iterate1 != nullptr) {
					if (iterate1->data->getDistance(curPosition) <= 1.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate1->data)) {
							liberationArmy->setEXP(liberationArmy->getEXP() - iterate1->data->getAttackScore());
						}
						else if (Vehicle* v = dynamic_cast<Vehicle*> (iterate1->data)) {
							liberationArmy->setLF(liberationArmy->getLF() - iterate1->data->getAttackScore());
						}
					}
					iterate1 = iterate1->next;
				}
				Node* iterate2 = arvn->getList()->getHead();
				while (iterate2 != nullptr) {
					if (iterate2->data->getDistance(curPosition) <= 1.0) {
						if (Infantry* i = dynamic_cast<Infantry*> (iterate2->data)) {
							arvn->setEXP(arvn->getEXP() - iterate2->data->getAttackScore());
						}
						else if (Vehicle* v = dynamic_cast<Vehicle*> (iterate2->data)) {
							arvn->setLF(arvn->getLF() - iterate2->data->getAttackScore());
						}
					}


					iterate2 = iterate2->next;
				}
			}
		}
	}
	/*cout << liberationArmy->getEXP() << " " << liberationArmy->getLF() << endl;
	cout << arvn->getEXP() << " " << arvn->getLF() << endl<<endl;*/



	if (config->get_eventCode() < 75) {
		//quan giai phong o the tien cong
		//cout << "I'M HERE" << endl;
		liberationArmy->fight(arvn, false);
	}
	else {
		arvn -> fight(liberationArmy, false);
	}
	//sau khi giao tranh xong, Unit nao co attack score duoi 5 se bij xoa khoi danh sach
	//duyet danh sach liberation
	Node* iterate1 = liberationArmy->getList()->getHead();
	Node* preNode1 = nullptr;
	while (iterate1 != nullptr) {
		Node* nextNode = iterate1->next;
		if (iterate1->data->getAttackScore() <= 5) {
			if (Vehicle* v = dynamic_cast<Vehicle*> (iterate1->data)) {
				liberationArmy->setLF(liberationArmy->getLF() - iterate1->data->getAttackScore());
			}
			else if (Infantry* i = dynamic_cast<Infantry*>(iterate1->data)) {
				liberationArmy->setEXP(liberationArmy->getEXP() - iterate1->data->getAttackScore());
			}
			
			if (preNode1 == nullptr) {
				liberationArmy->getList()->setHead(iterate1->next);
			}
			else {
				preNode1->next = iterate1->next;

				//delete iterate1->data;
				delete iterate1;
				iterate1 = nextNode;
				continue;
			}
		}
		preNode1 = iterate1;
		iterate1 = iterate1->next;
	}
	Node* iterate2 = arvn->getList()->getHead();
	Node* preNode2 = nullptr;
	while (iterate2 != nullptr) {
		Node* nextNode = iterate2->next;
		if (iterate2->data->getAttackScore() <= 5) {
			if (Vehicle* v = dynamic_cast<Vehicle*> (iterate2->data)) {
				arvn->setLF(arvn->getLF() - iterate2->data->getAttackScore());
			}
			else if (Infantry* i = dynamic_cast<Infantry*> (iterate2->data)) {
				arvn->setEXP(arvn->getEXP() - iterate2->data->getAttackScore());
			}
			if (preNode2 == nullptr) {
				arvn->getList()->setHead(iterate2->next);
			}
			else {
				preNode2->next = iterate2->next;
				//delete iterate2->data;
				delete iterate2;
				iterate2 = nextNode;
				continue;
			}

		}
		preNode2 = iterate2;
		iterate2 = iterate2->next;
	}



}
string HCMCampaign::printResult() {
	return "LIBERATIONARMY[LF=" + intToString(liberationArmy->getLF()) + ",EXP=" + intToString(liberationArmy->getEXP()) + "]-ARVN[LF=" + intToString(arvn->getLF()) + ",EXP=" + intToString(arvn->getEXP()) + "]";
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////