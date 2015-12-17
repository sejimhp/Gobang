#include <vector>
class Game {
	int turn;
	std::vector<std::vector<int> > map;
public:
	Game();
	int rec(int, int, int, int);
	void init();
	void draw();
	void run();
	int check();
};