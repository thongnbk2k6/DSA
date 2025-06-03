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
  
  while (numLines < MAX_LINES && ifs.getline(data[numLines], MAX_LINE_LENGTH))
  {
     /* for (int i = 0; i < MAX_LINE_LENGTH; i++) {
          cout << data[numLines][i] << " ";
      }
      cout << endl;*/




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
    int total = 0;
    int val[17] = { 1,2,3,4,5,7,8,9,10,12,15,18,20,30,40,50,70 };
    //int val[17] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    for (int i = 0; i < 17; i++) {
        total += val[i] * LF1[i];
    }
    for (int i = 0; i < 17; i++) {
        total += val[i] * LF2[i];
    }
    return total;
}

// Task 2
string determineRightTarget(const string &target)
{
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
          int pos = (max(max(val[1],val[2]),val[3]) % 5) + 3;
          return position[pos];
      }
      else return "INVALID";
  
}
bool preCheckMeassge(string message) {
    for (int i = 0; i<int(message.size()); i++) {
        char ch = message[i];
        if (!(int(ch) >= int('A') && int(ch) <= int('Z')) || (int(ch) >= 'a' && int(ch) <= int('z'))) return 0;
    }
    return 1;
}
char changeChar(char ch,int charShift) {
    //nam trong pham vi 'A' -> 'Z' hoac 'a' -> 'z'
    if ((int(ch) >= int('A') && int(ch) <= int('Z')) || (int(ch) >= 'a' && int(ch) <= int('z'))) return ch;//khong doi
    return char((int(ch) - charShift + 26) % 26);
    
}
string CaesarCipherMethod(string message,int charShift) {
    for (int i = 0; i< int(message.size()); i++) {
        if (message[i] == ' ') continue;
        message[i] = changeChar(message[i],charShift);
    }
    return message;
}
string reverseStringMethod(string message) {
    string ans = message;
    for (int i = int(message.size() - 1); i >= 0; i--) {
        ans[i] = message[i];
    }
    return ans;
}
string decodeTarget(const string &message, int EXP1, int EXP2)
{
    if(!preCheckMeassge(message)) return "INVALID";
    string ans;
    if (EXP1 >= 300 && EXP2 >= 300) {
        ans = CaesarCipherMethod(message, (EXP1 + EXP2) % 26);
    }
    else ans = reverseStringMethod(message);
    
   
    string position[8] = {
          "Kom Tum", "PleiKu", "Gia Lai", "Buon Ma Thuot", "Duc Lap", "Dak Lak", "National Route 21",
          "National Route 14"
    };
    bool ok = 0;
    int pos;
    for (int i = 0; i < 8; i++) {
        if (int(ans.size()) != int(position[i].size())) continue;
        int j;
        for (j = 0; j<int(ans.size()); j++) {
            if (ans[j] == position[j]) continue;
            if (int(ans[j]) != int(position[j])) {
                if (int(ans[j]) > int(position[j])) {
                    if(int(ans[j])-32!=int(position[j])) break;
                }
                else {
                    if(int(ans[j])+32!=int(position[j])) break;
                }
            }
        }
        if (j = int(ans.size())) {
            ok = 1;
            pos = i;
            break;
        }
    }
    if (ok) {
        return position[pos];
    }
    return "INVALID";
  
}

// Task 3
void manageLogistics(int LF1, int LF2, int EXP1, int EXP2, int &T1, int &T2, int E)
{
  // TODO: Implement this function
}

// Task 4
int planAttack(int LF1, int LF2, int EXP1, int EXP2, int T1, int T2, int battleField[10][10])
{
  // TODO: Implement this function
  return 0;
}

// Task 5
int resupply(int shortfall, int supply[5][5])
{
  // TODO: Implement this function
  return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
