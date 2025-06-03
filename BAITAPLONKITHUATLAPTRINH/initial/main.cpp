/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2025
* Date: 07.02.2025
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "tay_nguyen_campaign.h"

using namespace std;

void tnc_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("tnc_tc_01_input");
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;
    if (!readFile(input_file, LF1, LF2, EXP1, EXP2, T1, T2, E)) {
        return;
    }
   /* int sumLF1 = 0, sumLF2 = 0;
    for (int i = 0; i < 17; i++) {
        sumLF1 += LF1[i];
        sumLF2 += LF2[i];
    }*/
    for (int i = 0; i < 17; i++) {
        cout << LF1[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < 17; i++) {
        cout << LF2[i] << " ";
    }
    cout << '\n';
    cout << EXP1 << " " << EXP2 << endl;
    cout << T1 << " " << T2 << endl;
    cout << E << endl;
    /*manageLogistics(sumLF1, sumLF2, EXP1, EXP2, T1, T2, E);
    cout << T1 << " " << T2;*/
   /* cout << "LF1[0]: " << LF1[0] << ", LF2[0]: " << LF2[0] << endl;
    int result = gatherForces(LF1, LF2);
    cout << "Result: " << result << endl;*/

}

int main(int argc, const char * argv[]) {
    tnc_tc_01();
   
   /* for (int i = 0; i <= 16; i++) {
        cout << LF1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= 16; i++) {
        cout << LF2[i] << " ";
    }
    cout << endl;
    cout << EXP1 << " " << EXP2 << endl;
    cout << T1 << " " << T2 << endl;
    cout << E << endl;*/
    //int shortfall = 1050;
   /* int arr[5][5] = {
        {150,200,180,90,110},
        {70,80,120,140,160},
        {220,240,200,190,130},
        {100,110,300,280,320},
        {170,210,260,230,290}
    };*/
    //cout << gatherForces(LF1, LF2);
    //cout << resupply(shortfall, arr);
    //cout << determineRightTarget("Buon1Ma3Thuot5-8");
    //cout << EXP1 << " " << EXP2 << endl;
    //cout << decodeTarget("Heo Peo", 350, 400);
    //cout << 1;

   /* int battleField[10][10] = {
        {106,15 ,20 ,25 ,305, 635, 540 ,145 ,50, 55},
        {25, 18, 24, 330, 36, 442, 48, 54, 660, 665},
        {14, 21, 28, 35, 452, 49, 56, 63, 70, 77},
        {162, 24, 323, 404, 484, 60, 40, 72, 80, 88},
        {181 ,27, 36, 52, 543, 63, 72, 81 ,90, 99},
        {5, 30, 40, 501, 602, 70, 80, 90, 100, 110},
        {22, 33, 442, 55, 66, 77, 58, 99, 10, 121},
        {24, 36, 48, 60, 72, 84, 96, 108, 20, 132},
        {264, 39, 525, 65, 78, 91, 104, 70, 130, 143},
        {28, 42, 56, 50, 84, 98, 125, 126, 140, 154}
    };
    cout << planAttack(300, 280, 450, 470, 2500, 2600, battleField);*/
   
    return 0;
}
