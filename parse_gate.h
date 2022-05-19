#include <simplecpp>
#include <vector>
#include <bits/stdc++.h>
#include "gates.h"

void parseLine(fstream &file, vector<vector<float> >& linevec) {
    vector<float> v1;
    float x1, y1, x2, y2;
    string linedata="";
    while(file >> linedata) {
        if (linedata.find("x1") != string::npos ) {
            x1 = stof(linedata.substr(4,(linedata.length()-5)) );
            v1.push_back(x1);
        }
        if (linedata.find("y1") != string::npos ) {
            y1 = stof(linedata.substr(4,(linedata.length()-5)) );
            v1.push_back(y1);
        }
        if (linedata.find("x2") != string::npos ) {
            x2 = stof(linedata.substr(4,(linedata.length()-5)) );
            v1.push_back(x2);
        }
        if (linedata.find("y2") != string::npos ) {
            y2 = stof(linedata.substr(4,(linedata.length()-5)) );
            v1.push_back(y2);
        }
        if (linedata.find("/>") != string::npos ) {
            break;
        }
    }
    linevec.push_back(v1);
}

void parseGate(vector<vector<float> >& linevec, vector<vector<float> >& rectvec, vector<vector<float> >& circlevec, vector<vector<float> >& pathvec, string filename) {
    fstream file;
    string word;
    filename = "svg_files/" + filename;
    file.open(filename.c_str());
    while (file >> word) {
        if (word == "<line") {
            parseLine(file, linevec);
        }
    }
}