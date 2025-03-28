#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N,W;
long long int weight[100], value[100];
pair <int,int> string_2_num(string input){
	std::string num1 = "";
    std::string num2 = "";
    bool foundFirstNum = false;

    for (char c : input) {
        if (isdigit(c)) {
            if (!foundFirstNum) {
                num1 += c;
            } else {
                num2 += c;
            }
        } else {
            foundFirstNum = true;
        }
    }
	
	int n1 = stoi(num1);
	int n2 = stoi(num2);
    return {n1,n2};
}

void read(){
	string s;
        getline(cin, s);
        s = s.substr(1, s.size() - 2);
        int n;
        cin >> n;
        cin.ignore();
        vector<string> oup;
        size_t pos = 0;
        string delimiter = "),";
        while ((pos = s.find(delimiter)) != string::npos) {
            string token = s.substr(0, pos+1);
            oup.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        oup.push_back(s);
        oup[0] = oup[0].substr(1, oup[0].size() - 1);
        oup[oup.size() - 1] = oup[oup.size() - 1].substr(0, oup[oup.size() - 1].size() - 2);
        for (int i = 1; i < oup.size() - 1; i++) {
            oup[i] = oup[i].substr(2, oup[i].size() - 1);
        }
        for (int i = 0; i < oup.size(); i++) {
            vector<string> tokens;
            string token;
            string delimiter = ", ";
            size_t pos = 0;
            while ((pos = oup[i].find(delimiter)) != string::npos) {
                token = oup[i].substr(0, pos);
                tokens.push_back(token);
                oup[i].erase(0, pos + delimiter.length());
            }
            tokens.push_back(oup[i]);
            oup[i] = tokens[1] + " " + tokens[0];
        }
        cout << oup.size() << " " << n << endl;
        
        N = oup.size();
        W = n;
        
        for (int i = 0; i < oup.size(); i++) {
			pair <int,int> val = string_2_num(oup[i]);
			weight[i+1] = val.first;
			value[i+1] = val.second;
			cout << weight[i+1] << " " << value[i+1] << "\n";
        }
}

int main(){
	read();
}
