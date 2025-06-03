#include "tay_nguyen_campaign.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

const int MAX_LINES = 5;         
const int MAX_LINE_LENGTH = 100;

// Task 0: Read input file
bool readFile(
    const string &filename,
    int LF1[], int LF2[],
    int &EXP1, int &EXP2,
    int &T1, int &T2, int &E)
{
  char data[MAX_LINES][MAX_LINE_LENGTH];
  int numLines = 0;

  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    return false;
  }
  string line;
  
  while (numLines < MAX_LINES && ifs.getline(data[numLines],MAX_LINE_LENGTH))

  {
      line = data[numLines];
      int n = int(line.size());
      
      if (numLines == 0) {
          if (line[0] != '[' || line[n - 1] != ']') return false;
          char preChar;
          
          int curVal = 0;
          int curPos = 16;
          int mulTen = 0;
          for (int i = n - 1; i >= 0; i--) {
              if (line[i] == '[' || line[i] == ']') {
                  continue;
              }
              if (line[i] == ',') {
                  if (preChar == line[i]) return false;
                  LF1[curPos] = curVal;
                  LF1[curPos] = min(LF1[curPos], 1000);
                  LF1[curPos] = max(LF1[curPos], 0);
                  curPos--;
                  mulTen = 0;
                  curVal = 0;
                  
                  continue;
              }
              
              int num = int(line[i]) - 48;
              if (num > 9 || num < 0) {
                  return false;
              }
              curVal = curVal + num * int(pow(10, mulTen));
              mulTen++;
              preChar = line[i];

          }
          if (curPos != 0) return false;
          LF1[curPos] = curVal;
          LF1[curPos] = min(LF1[curPos], 1000);
          LF1[curPos] = max(LF1[curPos], 0);
      }
      else if (numLines == 1) {
          if (line[0] != '[' || line[n - 1] != ']') return false;
          int curVal = 0;
          int curPos = 16;
          int mulTen = 0;
          char preChar;
          for (int i = n - 1; i >= 0; i--) {
              if (line[i] == '[' || line[i] == ']') continue;
              if (line[i] == ',') {
                  if (preChar == line[i]) return false;
                  LF2[curPos] = curVal;
                  LF2[curPos] = min(LF2[curPos], 1000);
                  LF2[curPos] = max(LF2[curPos], 0);
                  curPos--;
                  mulTen = 0;
                  curVal = 0;

                  continue;
              }
              int num = int(line[i]) - 48;
              if (num > 9 || num < 0) {
                  return false;
              }
              curVal = curVal + num * int(pow(10, mulTen));
              mulTen++;
              preChar = line[i];

          }
          if (curPos != 0) return false;
          LF2[curPos] = curVal;
          LF2[curPos] = min(LF2[curPos], 1000);
          LF2[curPos] = max(LF2[curPos], 0);
      }
      else if (numLines == 2) {
          int curVal = 0;
          int mulTen = 0;
          EXP1 = EXP2 = -1;
          for (int i = n - 1; i >= 0; i--) {
              if (line[i] == ' ') {
                  EXP2 = curVal;
                  curVal = 0;
                  mulTen = 0;
                  continue;
              }
              int num = int(line[i]) - 48;
              if (num > 9 || num < 0) {
                  return false;
              }
              curVal = curVal + num * int(pow(10, mulTen));
              mulTen++;
          }
          EXP1 = curVal;
          if (EXP1 == -1 || EXP2 == -1) return false;
          EXP1 = min(EXP1, 600);
          EXP1 = max(EXP1, 0);
          EXP2 = min(EXP2, 600);
          EXP2 = max(EXP2, 0);
      }
      
      else if (numLines == 3) {
          int curVal = 0;
          int mulTen = 0;
          T1 = T2 = -1;
          for (int i = n - 1; i >= 0; i--) {
              if (line[i] == ' ') {
                  T2 = curVal;
                  curVal = 0;
                  mulTen = 0;
                  continue;
              }
              int num = int(line[i]) - 48;
              if (num > 9 || num < 0) {
                  return false;
              }
              curVal = curVal + num * int(pow(10, mulTen));
              mulTen++;
          }
          T1 = curVal;
          if (T1 == -1 || T2 == -1) return false;
          T1 = min(T1, 3000);
          T1 = max(T1, 0);
          T2 = min(T2, 3000);
          T2 = max(T2, 0);
      }
      else if (numLines == 4) {
          int curVal = 0;
          int mulTen = 0;
          E = -1;
          for (int i = n - 1; i >= 0; i--) {
              int num = int(line[i]) - 48;
              if (num > 9 || num < 0) {
                  return false;
              }
              curVal = curVal + num * int(pow(10, mulTen));
              mulTen++;
          }
          E = curVal;
          if (E == -1) return false;
          E = min(E, 99);
          E = max(E, 0);
      }
      
      numLines++;
  }
 
  ifs.close();

  if (numLines < MAX_LINES)
  {
    return false;
  }

  // TODO: Extract values from the `data` array and store them in respective variables

  return true;
}

// Task 1
int gatherForces(int LF1[], int LF2[])
{
  // TODO: Implement this function
    int total = 0;
    int val[17] = { 1,2,3,4,5,7,8,9,10,12,15,18,20,30,40,50,70 };
   /* for (int i = 0; i < 17; i++) {
        cout << LF1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 17; i++) {
        cout << LF2[i] << " ";
    }
    cout << endl;*/
    for (int i = 0; i < 17; i++) {
        total += val[i] * LF1[i];
        //cout << total << endl;
    }
    for (int i = 0; i < 17; i++) {
        total += val[i] * LF2[i];
    }
    //cout << total << endl;
    return total;
  
}

// Task 2
string determineRightTarget(const string &target)
{
  // TODO: Implement this function
    string position[8] = {
         "Kom Tum", "PleiKu", "Gia Lai", "Buon Ma Thuot", "Duc Lap", "Dak Lak", "National Route 21",
         "National Route 14"
    };
    int cnt = 0;
    int* val = new int[4];
    for (int i = 0; i < (int)target.size(); i++) {
        if (int(target[i]) >= 48 && int(target[i]) <= 57) {
            cnt++;
            val[cnt] = int(target[i]) - 48;
        }
    }
    if (cnt == 1) {
        return position[val[cnt]];
    }
    else if (cnt == 2) {
        int pos = ((val[1] + val[2]) % 5) + 3;
        return position[pos];
    }
    else if (cnt == 3) {
        int pos = (max(max(val[1], val[2]), val[3]) % 5) + 3;
        return position[pos];
    }
    else return "INVALID";
}
bool preCheckMeassge(string message) {
    //cout << message << endl;
    for (int i = 0; i<int(message.size()); i++) {
        char ch = message[i];
        //cout << ch << endl;
        if (!((int(ch) >= int('A') && int(ch) <= int('Z')) || (int(ch) >= 'a' && int(ch) <= int('z'))||(ch==' ')||(char(int(ch)-48)==ch))) {
            //cout << ch << endl;
            return 0;
        }
    }
    return 1;
}
char changeChar(char ch,int charShift) {
    //cout << charShift <<" "<<int(ch)+2<< endl;
    //nam trong pham vi 'A' -> 'Z' hoac 'a' -> 'z'
    //if ((int(ch) >= int('A') && int(ch) <= int('Z')) || (int(ch) >= 'a' && int(ch) <= int('z'))) return ch;//khong doi
    //return char((int(ch) - charShift + 26) % 26);
    if ((int(ch) >= int('A')) && (int(ch) <= int('Z'))) {
        //cout << "YES1" << endl;
        //cout << (int(ch) - 65 + charShift) % 26 << endl;
        return char((int(ch) - 65 + charShift) % 26+65);
        
        
    }
    else if ((int(ch) >= int('a')) && (int(ch) <= int('z'))) {
       
        return char((int(ch) - 97 + charShift) % 26+97);
        
    }
    else return ch;
    
    
}
string CaesarCipherMethod(string message,int charShift) {
    for (int i = 0; i< int(message.size()); i++) {
        if (message[i] == ' ') continue;
        message[i] =  changeChar(message[i],charShift);
    }
    //cout << message << endl;
    return message;
}
string reverseStringMethod(string message) {
    //cout << message << endl;
    string ans = "";
    for (int i = int(message.size() - 1); i >= 0; i--) {
        ans = ans + message[i];
    }
    return ans;
}
string decodeTarget(const string &message, int EXP1, int EXP2)
{   
    //cout << message << endl;
    //return 0;
    if(!preCheckMeassge(message)) return "INVALID";
    string ans;
    if (EXP1 >= 300 && EXP2 >= 300) {
        ans = CaesarCipherMethod(message, (EXP1 + EXP2) % 26);
        //cout << ans << endl;
        //cout << "YES" << endl;
    }
    //
    else ans = reverseStringMethod(message);
    //
    //cout << ans << endl;
    string position[8] = {
          "Kom Tum", "PleiKu", "Gia Lai", "Buon Ma Thuot", "Duc Lap", "Dak Lak", "National Route 21",
          "National Route 14"
    };
    ////cout << ans << endl;
    ////cout << ans.size() << endl;
    int ok = 1;
    int pos;
    for (int i = 0; i < 8; i++) {
        if (int(ans.size()) != int(position[i].size())) continue;
        //if (position[i] != "Duc Lap") continue;
        //cout << position[i] << endl;
        int j;
        for (j = 0; j<int(ans.size()); j++) {
            if (ans[j] == position[i][j]) continue;
            if (int(ans[j]) != int(position[i][j])) {
                if (int(ans[j]) > int(position[i][j])) {
                    if ((int(ans[j]) - 32) != int(position[i][j])) {
                        //cout << i << endl;
                        break;
                    }
                }
                else {
                    if ((int(ans[j]) + 32) != int(position[i][j])) {
                        //cout << i << endl;
                        break;
                    }
                }
            }
        }
        //cout << i << endl;
        if (j == int(ans.size())) {
            //cout << "YES" << endl;
            ok = 1;
            
            pos = i;
            break;
        }
    }
  /*  cout << ok << endl;
    cout << pos << endl*/;
    if (ok==1) {
        //cout << pos << endl;
        return position[pos];
    }
    return "INVALID";
  
}



// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
    double deltaTone, deltaTtwo;
    
    if (E == 0) {
        deltaTone = 1.0*((LF1 * (T1 + T2) / (LF1+LF2)) * (1 + (EXP1 - EXP2) / 100));
        deltaTtwo = 1.0*(T1 + T2) - deltaTone;
    }
    else if (E >= 1 && E <= 9) {
        //cout << "ok2" << endl;
        deltaTone = (E*T1 / -100.0);
        deltaTtwo = (E*T2/ -200.0);
    }
    else if (E >= 10 && E <= 29) {
        deltaTone = deltaTtwo = E * 50.0;
        
    }
    else if (E >= 30 && E <= 59) {
        deltaTone = E*T1 / 200.0;
        deltaTtwo = E*T2 / 500.0;
    }
    else if (E >= 60 && E <= 99) {
        deltaTone = deltaTtwo = 0.0;
    }
    //cout << deltaTone << " " << deltaTtwo << endl;
    //tinh lai gia tri T1
    if (T1 + deltaTone <= T1) {
        //cout << "ok1"<<" "<< deltaTone <<endl;
        T1 = max(int(T1*1.0 + deltaTone), 0);
        //cout << T1 << endl;
    }
    else if (T1 + deltaTone >= T1) {
        T1 = min(int(T1*1.0 + deltaTone), 3000);
    }
    //tinh lai gia tri T2
    if (T2 + deltaTtwo <= T2) {
        T2 = max(int(T2*1.0 + deltaTtwo), 0);
    }
    else if (T2 + deltaTtwo >= T2) {
        T2 = min(int(T2*1.0 + deltaTtwo), 3000);
    }
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  // TODO: Implement this function
    double S = 1.0*(LF1 + LF2 + (EXP1 + EXP2) * 5 + (T1 + T2) * 2);
    //cout << S << endl;
    for (int i = 0; i < 10; i++) {
        /*int subS = 0;*/
        for (int j = 0; j < 10; j++) {
            //subS += battleField[i][j];
            if ((i & 1) == 1) {
                S = S - battleField[i][j] * 3.0 / 2.0;
            }
            else {
                S = S - battleField[i][j] * 2.0 / 3.0;
            }
        }
        //if ((i & 1)==1) {
        //    //cout << /<<" "<<subS * 3 / 2 << endl;
        //    S = S - subS * 3 / 2;
        //}
        //else {
        //    //cout << i << " " << subS * 2 / 3 << endl;
        //    S = S - subS * 2 / 3;
        //}
    }
    //return int(-3.6-0.5);
    if (S >= 0) {
        if (int(S + 0.5) == int(S)) return int(S);
        return (int(S) + 1);
    }
    else {
        if (int(S - 0.5) == int(S)) return int(S);
        return (int(S) - 1);
    }
  
}

// Task 5

int curCombination[6];
bool finish = false;
void sinhToHop() {
    int i = 5;
    while (i >= 1&&curCombination[i] == 20 + i) {
        i--;
    }
    if (i == 0) finish = true;
    else {
        curCombination[i]++;
        for (int j = i + 1; j <= 5; j++) {
            curCombination[j] = curCombination[j - 1] + 1;
        }
    }
}
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
   /* cin >> shortfall;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> supply[i][j];
        }
    }*/
    int ans = 80000;
    int arr[26];
    int pos = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[++pos] = supply[i][j];
        }
    }
    for (int i = 1; i <= 5; i++) {
        curCombination[i] = i;
    }
    while (finish == false) {
        int getSumOfCurCombinationValue = 0;
        for (int i = 1; i <= 5; i++) {
            getSumOfCurCombinationValue += arr[curCombination[i]];
        }
        if (getSumOfCurCombinationValue >= shortfall) ans = min(ans, getSumOfCurCombinationValue);
        
        sinhToHop();
    }
    return ans;
    //tinh to hop chap 5 cua 25

  
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
