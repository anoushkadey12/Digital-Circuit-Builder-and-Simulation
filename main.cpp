#include <simplecpp>
#include <vector>
#include <bits/stdc++.h>
#include "parse_gate.h"

int main() {
    initCanvas("Circuit Builder and Simulation", 1500, 800);
    Line pane(250,0,250,800);
    const char escapekey = '\33';
    XEvent event;

    vector<Gates> gates;

    vector<vector<float> > NG_linevec;
    vector<vector<float> > NG_rectvec;
    vector<vector<float> > NG_circlevec;
    vector<vector<float> > NG_pathvec;
    parseGate(NG_linevec, NG_rectvec, NG_circlevec, NG_pathvec, "NOT.svg");
    Gates ng_initial(10, 0, NG_linevec, NG_rectvec, NG_circlevec, NG_pathvec, "NOT");
    ng_initial.scale(0.6);

    ///////////////////////////////////////////////////////////////////////
    /////  For copying/cloning a component you would need to call the glcone member function and push the results into the vector for futher handling
    /////  Something similar will need to be done for handling events (dropping components on the right panel)
    Gates n1 = gclone(300, 150, NG_linevec, NG_rectvec, NG_circlevec, NG_pathvec, "NOT");
    n1.scale(0.6);
    gates.push_back(n1);
    ///////////////////////////////////////////////////////////////////////

    while (1) {
        nextEvent(event);
        if (mouseButtonPressEvent(event)) {
        }
        if (mouseDragEvent(event)) {
        }
        if (mouseButtonReleaseEvent(event)) {
        }
        if (keyPressEvent(event)) {
            if (charFromEvent(event) == escapekey)
                break;
        }        
    }
}