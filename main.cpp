//
// Created by Vladimir K on 02.04.2023.
//

#include <SFML/Graphics.hpp>
#include <climits>
#include <cmath>

using namespace sf;
const int W = 800;
const int H = 800;

int main() {
    RenderWindow window(VideoMode(W, H), "GRAPHI");

    int x0 = W / 2;
    int y0 = H / 2;

    CircleShape point(2.f); //толщина точек
    point.setFillColor(Color::Magenta); //цвет точек

    int oLeft = -100; //ограничение по x слева
    int oRight = 100; //ограничение по x справа
    float c = 1000; //доп точки внутри точек

    int mass = (oLeft * (-1) + oRight) * c + 1; //количество точек
    //int mass = 100; // количество точек
    int sc = 20; //масштаб графика функции

    //черточки:
    RectangleShape line[80];
    for(int i = 0; i < 80; i++) {
        line[i].setSize(Vector2f(1, 20));
        line[i].setFillColor(Color::White);

        if (i < 40) {
            if (i < 20) line[i].setPosition(x0 - (i + 1) * sc, y0 - 10);
            else line[i].setPosition(x0 + (i - 20) * sc, y0 - 10);
        } else {
            line[i].setRotation(90);
            if(i < 60) line[i].setPosition(x0 + 10, y0 + (i - 60) * sc);
            else line[i].setPosition(x0 + 10, y0 + (i - 59) * sc);
        }
    }

    //Оси:
    RectangleShape OsX(Vector2f(W, 1));
    OsX.setFillColor(Color::White);
    OsX.setPosition(0, y0);

    RectangleShape OsY(Vector2f(1, H));
    OsY.setFillColor(Color::White);
    OsY.setPosition(x0, 0);

    //Стрелки:
    RectangleShape arrows[4];
    for (int i = 0; i < 4; i++) {
        arrows[i].setSize(Vector2f(1, 25));
        arrows[i].setFillColor(Color::White);

        if (i < 2) arrows[i].setPosition(x0, 0);
        else arrows[i].setPosition(W, y0 - 1);
    }
    arrows[0].setRotation(25);
    arrows[1].setRotation(-25);
    arrows[2].setRotation(60);
    arrows[3].setRotation(-250);

    Texture t;
    t.loadFromFile("D:/Programs/CLion Projects/GRAPHI/GRAPHI.png");
    Sprite pic(t);

    //int anim = 0; //анимация

    while(window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }

        //if (anim < mass) anim += 20; //скорость анимации

        window.clear();
        //рисуем оси
        window.draw(OsX);
        window.draw(OsY);
        for (int i = 0; i < 4; i++) window.draw(arrows[i]);
        for (int i = 0; i < 80; i++) {
            if (i != 19 && i != 39 && i != 40 && i!= 41) window.draw(line[i]);
        }

        window.draw(pic);
        //строим график
        for (int i = 0; i < mass; i++) {
            float x = oLeft + (i / c); //от начала
            //y используется для функции, от которой строится график.
            float y = pow(x,1.0/2);

            float x1 = x0 + x * sc;
            float y1 = y0 - y * sc;

            point.setPosition(x1, y1);
            window.draw(point);
        }
        window.display();
    }
}