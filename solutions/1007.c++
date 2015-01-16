#include <iostream>
#include <string>

using namespace std;

int measure_degree(string &s) {
    int freq_table[4] = {0, 0, 0, 0};  // index 0 - A, 1 - C, 2 - T, 3 - G
    int degree = 0;
    //fill freq_table
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') freq_table[0]++;
        else if (s[i] == 'C') freq_table[1]++;
        else if (s[i] == 'T') freq_table[2]++;
        else if (s[i] == 'G') freq_table[3]++;
    }

    // traverse string again and calculate degree
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') freq_table[0]--;
        else if (s[i] == 'C') {
            freq_table[1]--;
            degree = degree + freq_table[0];
        }
        else if (s[i] == 'T') {
            freq_table[2]--;
            degree = degree + freq_table[0] + freq_table[1] + freq_table[3];
        }
        else if (s[i] == 'G') {
            freq_table[3]--;
            degree = degree + freq_table[0] + freq_table[1];
        }
    }

    return degree;
}

class DNA_Sequence {
    public:
        string name;
        int degree;
};

int main()
{
    int str_len, nstring;
    cin >> str_len >> nstring;
    DNA_Sequence DNA_Seq[100];

    for (int i = 0; i < nstring; i++) {
        cin >> DNA_Seq[i].name;
        DNA_Seq[i].degree = measure_degree(DNA_Seq[i].name);
    }

    //arrange DNA sequence in increasing order of degree number
    DNA_Sequence temp;
    for (int i=0; i < nstring; i++) {
        for (int j = 0; j < nstring-(i+1); j++) {
            if (DNA_Seq[j].degree > DNA_Seq[j+1].degree) {
                temp = DNA_Seq[j];
                DNA_Seq[j] = DNA_Seq[j+1];
                DNA_Seq[j+1] = temp;
            }
        }
    }

    //print DNA sequence
    for (int i = 0; i < nstring; i++) {
        cout << DNA_Seq[i].name << "\n";
    }

    return 0;
}
