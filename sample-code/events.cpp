/* This program captures mouse and keyboard events
1) Mouse button press
2) Mouse drag
3) Mouse button release
4) Pressing keys on keyboard

- Events are captured by creating an object of the XEvent class
- The function nextEvent waits for an event to occur.
- The argument i.e. the object is passed by reference to this 'nextEvent' function. 
- On execution of this function, the object will contain the information about which event occurred and its details.
- The respective event functions determine whether the event was from mouse press, drag, release, or keyboard
- If mouse, then, .xmotion.x and .xmotion.y determine the position the mouse in (x,y) coordinates
*/

#include<simplecpp>
int main() {
    initCanvas("Mouse and Keyboard events", 800, 500);
    const char escapekey = '\33';
    XEvent event;
    short lastx = 0, lasty = 0;
    while (1) {
        nextEvent(event);
        if (mouseButtonPressEvent(event)) {
            lastx = event.xmotion.x;
            lasty = event.xmotion.y;
            cout << "mouse pressed at: " << lastx << ", " << lasty << endl;
        }
        if (mouseDragEvent(event)) {
            lastx = event.xmotion.x;
            lasty = event.xmotion.y;
            cout << "mouse dragging to: " << lastx << ", " << lasty << endl;
        }
        if (mouseButtonReleaseEvent(event)) {
            lastx = event.xmotion.x;
            lasty = event.xmotion.y;
            cout << "mouse button released at: " << lastx << ", " << lasty << endl;
        }
        if (keyPressEvent(event)) {
            cout << "pressed key on keyboard is: " << charFromEvent(event) << endl;
            if (charFromEvent(event) == escapekey)
                break;
        }
    }
}