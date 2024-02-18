#include "include/MasterHeader.h" 

int main() {
    
    // Initializations
    int screenWidth = 1600;
    int screenHeight = 1000;
    int N = 900;        // use for rand()
    int minX = 210;     // The debug vertical line is: x = 210;
    string test = "Commit Change Test";

    // Random values for tweens
    // Manual debug:
    vector<Vector2> listOfPoints = {{300, 400}, {700, 100}, {100, 400}, {200, 100}};
    vector<Vector2> randList_1;
    vector<Vector2> randList_2;
    vector<Vector2> randList_3;
    vector<Vector2> randList_4;
    vector<Vector2> randList_5;
    // Random:
    for (int i = 210; i < 310; i++) {
        int randomX = minX + rand() % (N - minX); // x must be >= than 210
        int randomY = rand() % N;
        float floatX = static_cast<float>(randomX);
        float floatY = static_cast<float>(randomY);
        randList_1.push_back({floatX,floatY});
    }

    // Game States
    enum GameScreenStates 
    {
        STARTSCREEN,
        GAMEPLAY,
        ENDSCREEN
    };
    Color myGreen = {0, 255, 0, 255};

    // Create a RectangleClass object with appropriate arguments
    RectangleClass myRect2(myGreen, 100.0f, 100.0f, 100.0f, 100.0f);

    // Window title / target FPS
    raylib::Window w(screenWidth, screenHeight, "C++ Algorithms Visualized");
    SetTargetFPS(60);


    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {

        // Drawing ctx loop:
        BeginDrawing();
        ClearBackground(BLACK);
        TimeClass::displayGameTime();
 
        myRect2.drawRectMthd();
        
        //[obj.animate](function, time in seconds)
        myRect2.use(keyFrames, 20.0f, randList_1);        

        EndDrawing();
    }

    return 0;
}