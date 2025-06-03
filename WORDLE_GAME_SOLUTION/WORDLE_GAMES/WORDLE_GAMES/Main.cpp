#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>words;
struct uutien {
	int k; string s;
};
bool cmp(uutien a, uutien b) {
	return a.k > b.k;
}
int main() {
	ifstream file("input.txt");
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			words.push_back(line);
		}
		file.close();
	}
	else {
		cout << "file error";
	}
	int finish = 1;
	while (finish) {
		int right_pos, wrong_pos;
		vector<pair<int, char>> right_pos_letters ,wrong_pos_letters;
		cout << "Nhap so chu cai dung vi tri va vi tri cua no vao"<<endl;
		cin >> right_pos;
		for (int i = 0; i < right_pos; i++) {
			int pos; char c;
			cin >> pos >> c;
			pos--;
			right_pos_letters.push_back({ pos,c });
		}
		cout << "Nhap so chu cai sai vi tri va vi tri cua no vao" << endl;
		cin >> wrong_pos;
		for (int i = 0; i < wrong_pos; i++) {
			int pos; char c;
			cin >> pos >> c;
			pos--;
			wrong_pos_letters.push_back({ pos,c });
		}
		vector<uutien>ans;
		for (string tmp : words) {
			int k = 0;
			bool ok = 1;
			for (int i = 0; i < right_pos; i++) {
				int pos = right_pos_letters[i].first; 
				char c = right_pos_letters[i].second;
				if (tmp[pos] == c) {
					k++;
				}
				else {
					ok = 0;
					break;
				}
			}
			for (int i = 0; i < wrong_pos; i++) {
				int pos = wrong_pos_letters[i].first;
				char c = wrong_pos_letters[i].second;
				if (tmp[pos] == c) {
					k--;
				}
			}

			if (k > 0&&ok) ans.push_back({ k,tmp });

		}
		sort(ans.begin(), ans.end(), cmp);
		for (uutien tmp : ans) {
			cout << tmp.s << endl;
		}

		

		cout << "Nhap 1 de tiep tuc hoac nhap 0 de ket thuc"<<endl;
		cin >> finish;
	}


	
	return 0;
}