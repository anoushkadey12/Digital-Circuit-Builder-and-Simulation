/*
- In this program there are two rectangles and a line must start getting drawn only if the mouse button is pressed inside any of the rectangle.
- As the user drags the mouse, the line should get drawn at appropriate locations based on the location of the mouse.
- When the user releases the mouse, the line should get drawn only if the mouse button is released inside any of the rectangle only.
- If the mouse release is outside any of the rectanlge the line that was just drawn should be deleted.
*/

#include<simplecpp>
int main() {
    initCanvas("Draw using the mouse", 1500, 800);
    bool draggingLine = false;
    bool droppedComponentFound = false;
    Line *l1;

    // Coordinates for drawing rectangle
    float cx[10], cy[10], width[10], height[10], topX[10], topY[10], bottomX[10], bottomY[10];
    cx[0]=200, cy[0]=200, width[0]=30, height[0]=30;
    cx[1]=400, cy[1]=200, width[1]=30, height[1]=30;

    // Rectangle 1
    Rectangle rect1(cx[0],cy[0],width[0],height[0]);
    rect1.setFill(true);
    rect1.setColor(COLOR(255,0,0));

    // Rectangle 2
    Rectangle rect2(cx[1],cy[1],width[1],height[1]);
    rect2.setFill(true);
    rect2.setColor(COLOR(0,255,0));

    // Compute top-left and bottom-right coordinates for both rectangles
    for (int i=0;i<2;i++) {
        topX[i] = cx[i] - (width[i]/2);
        topY[i] = cy[i] - (height[i]/2);
        bottomX[i] = cx[i] + (width[i]/2);
        bottomY[i] = cy[i] + (height[i]/2); 
    }

    const char escapekey = '\33';
    XEvent event;
    short lastx = 0, lasty = 0;
    while (1)
    {
        nextEvent(event);
        if (mouseButtonPressEvent(event)) {
            lastx = event.xmotion.x;
            lasty = event.xmotion.y;
            // Check if mouse button was pressed inside any of the rectangles only
            for(int i=0;i<2;i++) {
                if(lastx >= topX[i] && lasty >= topY[i] && lastx <= bottomX[i] && lasty <= bottomY[i]) {
                    l1 = new Line(lastx, lasty,  lastx, lasty); // Start drawing line
                    draggingLine = true;
                    break;
                }
            }
        }
        if (mouseDragEvent(event)) {
            if (draggingLine) {  // If the line is being drawn, then continue drawing based on the location of the mouse
                l1->reset(lastx,lasty,event.xmotion.x, event.xmotion.y);
            }
        }
        if (mouseButtonReleaseEvent(event)) { 
            lastx = event.xmotion.x;
            lasty = event.xmotion.y;
            // Check if the mouse button was released inside any of the rectangle only
            for(int i=0;i<2;i++) {
                if(lastx >= topX[i] && lasty >= topY[i] && lastx <= bottomX[i] && lasty <= bottomY[i]) {
                    droppedComponentFound = true;
                    break;
                }
            }
            // The mouse button was not released inside a rectangle, hence, delete the line just drawn
            if (draggingLine == true && droppedComponentFound == false) {
                l1->reset(0,0,0,0);
            }
            draggingLine = false;
            droppedComponentFound = false;
        }
        if (keyPressEvent(event)) {
            cout << "key: " << charFromEvent(event) << endl;
            if (charFromEvent(event) == escapekey)
                break;
        }
    }
}