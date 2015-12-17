#include "Game.h"
#include <Siv3D.hpp>

void Game::run(){
	if (Input::MouseL.clicked){
		for (int i = 0; i < 19; i++){
			for (int j = 0; j < 19; j++){
				Rect rect(30 + i * 40, 30 + j * 40, 30, 30);
				if (rect.leftPressed && map[i][j] == 0){
					map[i][j] = turn;
					if (turn == 1)
						turn = 2;
					else
						turn = 1;
				}
			}
		}
	}
	check();
}


Game::Game(){
	map.resize(19);
	for (int i = 0; i < 19; i++)
		map[i].resize(19);
	turn = 0;
}

void Game::init(){
	turn = 0;
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 19; j++){
			map[i][j] = 0;
		}
	}
}

void Game::draw(){
	Rect(0, 0, 820, 820).draw({ Palette::Orange, 120 });
	Circle(160, 400, 4).draw(Palette::Black);
	Circle(400, 160, 4).draw(Palette::Black);
	Circle(400, 400, 4).draw(Palette::Black);
	Circle(640, 400, 4).draw(Palette::Black);
	Circle(400, 640, 4).draw(Palette::Black);
	for (int i = 0; i < 19; i++){
		Line(40 + i * 40, 40, 40 + i * 40, 760).draw(Palette::Black);
		Line(40, 40 + i * 40, 760, 40 + i * 40).draw(Palette::Black);
	}
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 19; j++){
			if (map[i][j] == 1){
				Circle(40 + i * 40, 40 + j * 40, 17).draw();
			}
			if (map[i][j] == 2){
				Circle(40 + i * 40, 40 + j * 40, 17).draw(Palette::Black);
			}
		}
	}
}

int Game::check(){
	int X[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int Y[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int max = 0, val;
	for (int i = 0; i < 19; i++){
		for (int j = 0; j < 19; j++){
			if (map[i][j] != 0){
				for (int k = 0; k < 8; k++){
					val = rec(i, j, X[k], Y[k]);
					val += rec(i, j, -X[k], -Y[k]);
					val++;
					if (val >= 5){
						return map[i][j];
					}
				}
			}
		}
	}

	return 0;
}

int Game::rec(int i, int j, int X, int Y){
	int x = i + X;
	int y = j + Y;
	if (x >= 0 && y >= 0 && x < 19 && y < 19 && map[x][y] == map[i][j]){
		return 1 + rec(x, y, X, Y);
	}
	return 0;
}