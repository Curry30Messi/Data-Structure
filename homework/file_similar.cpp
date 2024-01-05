#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double> res;
    int n;
    cin >> n;
    vector<set<string>> my_list(n);
    for (int i = 0; i < n; i++) {
        while (true) {
            string data;
            cin >> data;
            if (data == "#") {
                break;
            } else {
                vector<string> words;
                string current_word = "";
                for (char c : data) {
                    if (isalpha(c)) {
                        current_word += c;
                    } else if (!current_word.empty()) {
                        words.push_back(current_word);
                        current_word = "";
                    }
                }
                if (!current_word.empty()) {
                    words.push_back(current_word);
                }

                for (string& word : words) {
                    transform(word.begin(), word.end(), word.begin(), ::toupper);
                    if (word.length() >= 3) {
                        if (word.length() <= 10) {
                            my_list[i].insert(word);
                        } else if (word.length() >= 10) {
                            word = word.substr(0, 10);
                            my_list[i].insert(word);
                        }
                    }
                }
            }
        }
    }

    // for (int i = 0; i < my_list.size(); i++)
    // {
    //     for (string x:my_list[i])
    //     {
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
    int w;
    cin >> w;
    for (int k = 0; k < w; k++) {
        string line;
        int a0, b0;
        cin >> a0 >> b0;
        int a=a0-1;
        int b=b0-1;
        int temp0 = my_list[a].size();
        int temp1 = my_list[b].size();
        set<string> temp={};
        for(string x:my_list[a]){
            temp.insert(x);
        }
        for(string x:my_list[b]){
            temp.insert(x);
        }
      
        int lap = temp0 + temp1 - temp.size();
        double rate = (double)(lap) / temp.size();
        res.push_back(rate);
    }

    cout.precision(1);
    cout << fixed;
    for (double a : res) {
        cout << (a * 100) << "%" << endl;
    }

    return 0;
}
