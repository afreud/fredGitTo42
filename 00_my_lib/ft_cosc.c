#include <stdio.h>

#define N 20 // Number of iterations
#define PI 3.14159265358979323846

double CORDIC_cos(double angle) {
    double x = 1.0;
    double y = 0.0;
    double z = angle;
    double scale = 1.0;
    
    for (int i = 0; i < N; i++) {
        double angle_i = PI / (1 << i);
        double temp = x;
        x = x - y * (1 << -i);
        y = temp + y * (1 << -i);
        z -= z > 0 ? angle_i : -angle_i;
        scale *= (1 << -i);
    }
    
    return x * scale;
}

int main() {
    double angle_in_radians = PI / 4; // Example angle
    double cos_value = CORDIC_cos(angle_in_radians);
    printf("Cosine of %f radians is approximately %f\n", angle_in_radians, cos_value);
    return 0;
}
