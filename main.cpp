#include "include/MasterHeader.h" 

int main() {
    
    // Initializations
    int screenWidth = 1600;
    int screenHeight = 1000;
    int N = 900;        // use for rand()
    int minX = 210;     // The debug vertical line is: x = 210;

    // Random values for tweens / Manual debugs / testing only
    vector<Vector2> listOfPoints = {{300, 400}, {700, 100}, {100, 400}, {200, 100}};
    vector<Vector2> leftToRightDemo1 = {{1500,25},{410,25}};
    vector<Vector2> leftToRightDemo2 = {{1500,165},{410,165}};

    // Rand() lists
    vector<Vector2> randList_1;
    vector<Vector2> randList_2;
    vector<Vector2> randList_3;
    vector<Vector2> randList_4;
    vector<Vector2> randList_5;

    // Random val generation
    for (int i = 210; i < 310; i++) {
        int randomX = minX + rand() % (N - minX); // x must be >= than 210
        int randomY = rand() % N;
        float floatX = static_cast<float>(randomX);
        float floatY = static_cast<float>(randomY);
        randList_1.push_back({floatX,floatY});
    }


    
    // Constrain xy coord to left demo box
    // [x = 5][y = 340][width = 790, height = 650] 
    int lbMinX = 5;
    int lbMaxX = 795;
    int lbMinY = 340;
    int lbMaxY = 990;
    for (int i = 0; i < 250; i++) {
        int randomX = lbMinX + rand() % (lbMaxX - lbMinX);
        int randomY = lbMinY + rand() % (lbMaxY - lbMinY);
        float floatX = static_cast<float>(randomX);
        float floatY = static_cast<float>(randomY);
        randList_2.push_back({floatX, floatY});
    }


    // RGBA
    Color myGreen = {0, 255, 0, 255};

    // Boundaries
    DrawSections outlineSections;

    // Instantiate Objects
    // Arguments        (color, height, width, x, y, printDebugs, tweenAplha, tweenColors)
    RectangleClass rect1(myGreen, 100.0f, 100.0f, 410, 25, true, false, false, 5);  // Section 1 / demo easeIn
    RectangleClass rect2(myGreen, 100.0f, 100.0f, 410, 165, true, false, false, 5); // Section 1 / demo easeOut
    RectangleClass rect3(myGreen, 5.0f, 5.0f, 10, 350, false, true, false, 5); // Section 1 / demo easeOut



    // Instantiate AnimObjs to be used with above objects
    AnimObj obj0; // Section 1 / demo easeIn
    AnimObj obj1; // Section 1 / demo easeOut
    AnimObj obj2; // Section 1 / demo easeOut


    // Window title / target FPS
    raylib::Window w(screenWidth, screenHeight, "C++ Easing Maths Visualized");
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {

        // Drawing ctx loop:
        BeginDrawing();
        ClearBackground(BLACK);
        TimeClass::displayGameTime();

        outlineSections.draw();





        // Objects:
        rect1.drawRectMthd();
        rect2.drawRectMthd();
        rect3.drawRectMthd();
        
        // use Arguments: ();
        rect1.use(obj0, leftToRightDemo1, "easeIn");
        rect2.use(obj1, leftToRightDemo2, "easeOut");
        rect3.use(obj2, randList_2, "easeOut");




        EndDrawing();
    }

    return 0;
}