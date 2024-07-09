#include "include/raylib.h"




int main ()
{
    //initialization
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow (screenWidth, screenHeight, "Testing");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2};
    Vector2 ballFood = {(float)GetRandomValue (100, 700), (float)GetRandomValue (100, 400)};
    Vector2 bodylength_1 = { 0, 0 };
    Vector2 bodylength_2 = { 0 , 0 };


    //rectangle
    Rectangle RecBox = { 100, 60,  1100, 600};
    
 





    //Player Length
    bool Ball_DirecY_P = false;
    bool Ball_DirecY_N = false;
    bool Ball_DirecX_P = false;
    bool Ball_DirecX_N = false;

    //temp
    int score = 0;
    int Add_L = 0;

    float speed = 1.0f;
    int ShowText_Speed = 1;


   


    SetTargetFPS (60);


    //main gameloop
    while (!WindowShouldClose())
    {
        //update code here
        //Movement Condition
        if (IsKeyPressed(KEY_W))
        {
            Ball_DirecY_P = true;
            Ball_DirecY_N = false;
            Ball_DirecX_N = false;
            Ball_DirecX_P = false;

            //tail1 
            bodylength_1.x = ballPosition.x;
            bodylength_1.y = ballPosition.y + 50;

            //tail2
            bodylength_2.x = ballPosition.x;
            bodylength_2.y = ballPosition.y + 100;
        }

        if (IsKeyPressed(KEY_S))
        {
            Ball_DirecY_N = true;
            Ball_DirecY_P = false;
            Ball_DirecX_N = false;
            Ball_DirecX_P = false;

            //tail1
            bodylength_1.x = ballPosition.x;
            bodylength_1.y = ballPosition.y - 50;

            //tail2
            bodylength_2.x = ballPosition.x;
            bodylength_2.y = ballPosition.y - 100;

        }

        if (IsKeyPressed(KEY_D))
        {
            Ball_DirecX_P = true;
            Ball_DirecX_N = false;
            Ball_DirecY_P = false;
            Ball_DirecY_N = false;

            //tail1
            bodylength_1.x = ballPosition.x - 50;
            bodylength_1.y = ballPosition.y;

            //tail2
            bodylength_2.x = ballPosition.x - 100;
            bodylength_2.y = ballPosition.y;
        }

        if (IsKeyPressed(KEY_A))
        {
            Ball_DirecX_N = true;
            Ball_DirecX_P = false;
            Ball_DirecY_N = false;
            Ball_DirecY_P = false;

            //tail1
            bodylength_1.x = ballPosition.x + 50;
            bodylength_1.y = ballPosition.y;

            //tail2
            bodylength_2.x = ballPosition.x + 100;
            bodylength_2.y = ballPosition.y;


        }



        //movement
        //up
        if (Ball_DirecY_P == true && Ball_DirecY_N == false && Ball_DirecX_P == false && Ball_DirecX_N == false)
        {
            ballPosition.y -= speed;
            bodylength_1.y -= speed;
            bodylength_2.y -= speed;
            
            
            
        }

        //down
        if (Ball_DirecY_N == true && Ball_DirecY_P == false && Ball_DirecX_P == false && Ball_DirecX_N == false)
        {
            ballPosition.y += speed;
            bodylength_1.y += speed;
            bodylength_2.y += speed;
        }

        //right
        if (Ball_DirecX_P == true && Ball_DirecX_N == false && Ball_DirecY_P == false && Ball_DirecY_N == false)
        {
            ballPosition.x += speed;
            bodylength_1.x += speed;
            bodylength_2.x += speed;


            
        }

        //left
        if (Ball_DirecX_N == true && Ball_DirecX_P == false && Ball_DirecY_P == false && Ball_DirecY_N == false)
        {
            ballPosition.x -= speed;
            bodylength_1.x -= speed;
            bodylength_2.x -= speed;

 
        }



        //ball food random spawner checking collision
        if (CheckCollisionCircles (ballPosition, 30, ballFood, 10))
        {
            ballFood.x = GetRandomValue (100, 700);
            ballFood.y = GetRandomValue (100, 400);
            Add_L++;
            speed++;
            score += 100;
            ShowText_Speed++;

     
        }

        //checkcollision between circle and box
        if (!CheckCollisionCircleRec(ballPosition, 30, RecBox))
        {
            ballPosition.x = (float)screenWidth/2;
            ballPosition.y = (float)screenHeight/2;
            speed = 1.0f;
            Add_L = 0;
            score = 0;
            ShowText_Speed = 1;


        }

 
    
        BeginDrawing();
            ClearBackground (RAYWHITE);

            DrawCircleV (ballPosition, 30, DARKGRAY);

            DrawCircleV (ballFood, 20, DARKGRAY);


            //tail
            if (Add_L >= 1)
            {
                DrawCircleV (bodylength_1, 30, GRAY);

            }

            if (Add_L >= 2)
            {
                DrawCircleV (bodylength_2, 30, GRAY);
            }


            //rectangle box
            DrawRectangleLinesEx (RecBox, 10, BLACK);

            //text
            DrawText (TextFormat("Score: %08i", score), 100, 670, 50, BLACK);
            DrawText (TextFormat("Speed: %i", ShowText_Speed), 100, 8, 50, BLACK);

 


        EndDrawing();
    }

    CloseWindow();


    return 0;


}