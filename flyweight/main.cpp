//
// Created by yinchunxiang on 26/03/2017.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class Shape {
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	Circle(string color) : color_(color) {}
	virtual ~Circle() {}
	void draw() {}
	void set_x(int x) {x_ = x;}
	void set_y(int y) {y_ = y;}
	void set_radius(int radius) {radius_ = radius;}

private:
	int x_;
	int y_;
	int radius_;
	string color_;
};


class ShapeFactory {
public:
	virtual ~ShapeFactory() {}
	static Shape* GetCircle(string color) {
        auto it = ShapeFactory::map_.find(color);
		if (it != ShapeFactory::map_.end()) {
			return it->second;
		}
		auto circle = new Circle(color);
		ShapeFactory::map_.insert(std::pair<string, Shape*>(color, circle));
		cout << "Creating circle of color: " << color << endl;
		return circle;
	}

private:
	static unordered_map<string, Shape*> map_;
};

unordered_map<string, Shape*> ShapeFactory::map_;

int main(int argc, char *argv[]) {
	vector<string> colors;
	colors.push_back("Red");
	colors.push_back("Green");
	colors.push_back("Blue");
	colors.push_back("White");
	colors.push_back("Black");

	for(int i = 0; i < 20; ++i) {
		auto *circle = dynamic_cast<Circle*>(ShapeFactory::GetCircle(colors[i % 5]));
		circle->set_x(i);
		circle->set_y(i);
		circle->set_radius(100);
		circle->draw();
	}
	return 0;
}


