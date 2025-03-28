#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
/*
The output is a list of m integers between 0 and 500000001 which are, respectively, the number
of itineraries from Amman to Bras ́ılia taking 0, 1, . . ., m − 1 nights, respectively. If the number
of itineraries is 500000001 or more, the output should be 500000001.

*/
/*
The first row of the input consists of three integers n, m and h, where n is the number of cities,
m is the strict upper bound of the number of nights used and h is the number of follow-on flights
per city. 
*/
int n,m,h;

vector <pii> arr[10000];
int dpf[10000][10000];

int main(){
    cin >> n >> m >> h;
    //always start from city 0, and end up at city n-1
    for(int i =0;i<n-1;i++){
        for(int f = 0; f<h;f++){
            int city,days;
            cin >> city >> days;
            arr[i].push_back({city,days});
        }
    }
    
    //n x m 
    //let f(c,d), c is the city, d is the day.
    //f(c,d) = f(c,d-1) + sum( f(i, d-t)) for (i,t) where i is the city, t is the days
    dpf[0][0] = 1;
    for(int city = 0; city < n-1;city++){
        for(pii element : arr[city]){
            int next_j = element.first;
            int min_stay = element.second;
            if(city < next_j){
                int s = 0;
                for(int p = 0; p<= m-1-min_stay; p++){
                    s = min(s + dpf[city][p], 500000001);
                    dpf[next_j][p + min_stay] = min(s + dpf[next_j][p + min_stay], 500000001);
                }
            }
        }
    }
    
    for(int days = 0; days <= m-1;days++){
        cout << dpf[n-1][days] << " ";
    }
}