# include <Siv3D.hpp>

# include "Game.h"

void Main()
{
	Window::Resize(800, 800);
	Game game;
	Font font(30);
	int state = 0;

	while (System::Update())
	{
		switch (state){
		case 0:
			game.run();
			game.draw();
			state = game.check();
			break;
		case 1:
		case 2:
			game.draw();
			font(L"プレーヤー", state, L"の勝ち").draw(0, 100);
			if (Input::MouseL.clicked)
			{
				game.init();
				state = 0;
			}
			break;
		}
	}
}