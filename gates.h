#include <simplecpp>
#include <vector>
#include <bits/stdc++.h>

class Gates : public Composite
{
    Line *NAGLines[50]; //6
    Text *GateName;

public:
    Gates(double x, double y, vector<vector<float> > linevec, vector<vector<float> > rectvec, vector<vector<float> > circlevec, vector<vector<float> > pathvec, string gatename, Composite *owner = NULL)
        : Composite(x, y, owner)
    {
        for (unsigned int i = 0; i < linevec.size(); i++) {
            NAGLines[i] = new Line(linevec[i][0], linevec[i][1], linevec[i][2], linevec[i][3], this);
        }
        GateName = new Text(90,50,gatename,this);
        GateName->setColor(COLOR(255,0,0));
    }
};

Gates gclone(short lastx, short lasty, vector<vector<float> > linevec, vector<vector<float> > rectvec, vector<vector<float> > circlevec, vector<vector<float> > pathvec, string gatename) {
    return Gates(lastx, lasty, linevec, rectvec, circlevec, pathvec, gatename);
}