#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, W;

ll weight[102], value[102], dp[102][100004]; // dp[i][j] = value from [1,i], j represents weight cumulated
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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen("_input.txt","r",stdin);
//    freopen("_output.txt","w",stdout);
while(true){
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 100004; j++) {
            dp[i][j] = LLONG_MIN;
        }
    }
    
    read();
    
    dp[1][0] = 0;
    dp[1][weight[1]] = value[1];
    ll sol = value[1];
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - weight[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
                continue;
            }
            dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= W; i++) {
        sol = max(sol, dp[N][i]);
    }
    cout << sol << endl;
}
}
