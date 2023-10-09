#include<stdio.h> 
#include<math.h>

double area(double radius);
double pieceOfCake(double radius, double width); 
double pieceOfCakeComplement(double radius, double width);

double area(double radius){
	return M_PI*radius*radius;
}

double pieceOfCake(double radius, double width){
	double theta, base;
	base = sqrt(radius*radius*2);
	theta = atan(base/radius);
	double area_segment = .5*(theta - sin(theta))*radius*radius;
	double height = sqrt((base*base*.25)*(radius*radius));
	double area_rectangle = height*width;
	double area_total = area_rectangle + area_segment*2;
	return area_total;
}

double pieceOfCakeComplement(double radius, double width){
	double new_r = radius - width;
	double a = M_PI*new_r*new_r;
	return a;
}

int main () {
	double radius = 42.5;
	double width = 8.2;

	printf("Total Cake = %f\n", area(radius));
	printf("Cake Leftover = %f\n", pieceOfCake(radius, width));
	printf("Cake Obtained = %f\n", pieceOfCakeComplement(radius, width));
}
