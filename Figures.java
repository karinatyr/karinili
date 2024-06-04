class TwoDShape {
	double width;
	double height;
	TwoDShape() {
		width = 0;
                height = 0;
	}
	TwoDShape(double w, double h){
		width = w;
		height = h;
	}

	void showDim(){
		System.out.println("Ширина фигуры: " + width + "\nВысота фигуры: " + height);

	}
}
class Triangle extends TwoDShape {
	String style;

	double area(){
		return width * height / 2;
	}
	void showStyle(){
		System.out.println("Треугольник " + style);
	}
}
class Rectangle extends TwoDShape {
	String outside;

	double area(){
		return width * height;
	}
	void showOutside(){
                System.out.println("ПРямоугольник " + outside);
	}
}
class Figures {
	public static void main(String arg[]) {
		TwoDShape f1 = new TwoDShape(3.0, 5.0);
		Triangle f2 = new Triangle();
		Rectangle f3 = new Rectangle();
		System.out.println("Информация об f1: ");
		f1.showDim();
		System.out.println("Информация об f2: ");
                f2.showDim();
		System.out.println("Площадь: :" + f2.area());
		System.out.println("Информация об f3: ");
                f3.showDim();
		System.out.println("Площадь: :" + f3.area());
	}
}
