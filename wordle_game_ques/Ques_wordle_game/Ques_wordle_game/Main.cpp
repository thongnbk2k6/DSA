#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<CoreWindow.h>
#include<Windows.h>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;
void TextColor(int x)//X là mã màu
{
	//Các hàm này là hàm thao tác API với windows bạn cứ coppy thôi không cần phải hiểu quá sâu
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}
vector<string>words;
int main() {
	ifstream file("input.txt");
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			words.push_back(line);
		}
		file.close();
	}
	srand(time(NULL));
	int pos = rand() % 10638;
	string ans = words[pos];
	bool letters[26],ok=0;
	memset(letters, 0, sizeof letters);
	for (int i = 0; i < 5; i++) {
		int c = int(letters[i]) - 97;
		letters[c] = 1;
	}
	int time_remain = 6;
	while (time_remain) {
		cout << "Ban con " << time_remain-- << " luot tra loi"<<endl;
		string tmp; cin >> tmp;
		bool right_pos[5], wrong_pos[5],right=1;
		for (int i = 0; i < 5; i++) {
			right_pos[i] = 0;
			wrong_pos[i] = 0;
			if (tmp[i] == ans[i]) right_pos[i] = 1;
			else {
				right = 0;
				int c = int(tmp[i]) - 97;
				if (letters[c]) {
					wrong_pos[i] = 1;
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			if (right_pos[i]) {
				TextColor(2);
				cout << tmp[i];
			}
			else if (wrong_pos[i]) {
				TextColor(6);
				cout << tmp[i];
			}
			else {
				TextColor(4);
				cout << tmp[i];
			}



		}
		cout << endl;
		TextColor(7);
		if (right) {
			cout << "DAP AN DUNG"<<endl;
			ok = 1;
			break;
		}
	}
	if (!ok) {
		cout << "Dap an dung la " << ans << endl;
	}
	



	
	return 0;
}