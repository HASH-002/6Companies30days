class Solution {
   public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        srand(time(0));
    }
    double random() {
        return (double)rand() / RAND_MAX;
    }
    vector<double> randPoint() {
        double l = sqrt(random()) * radius;
        double theta = 2 * M_PI * random();
        return {x_center + l * cos(theta), y_center + l * sin(theta)};
    }
};