#include <iostream>
#include <string>
#include <iomanip>

int main() {
    float totalWeightedScore = 0.0f;
    float totalCredits = 0.0f;

    for (int i = 0; i < 20; ++i) {
        std::string subject, grade;
        float credit;

        std::cin >> subject >> credit >> grade;

        if (grade == "P") {
            continue;
        }

        float gradePoint = 0.0f;

        if (grade == "A+") gradePoint = 4.5;
        else if (grade == "A0") gradePoint = 4.0;
        else if (grade == "B+") gradePoint = 3.5;
        else if (grade == "B0") gradePoint = 3.0;
        else if (grade == "C+") gradePoint = 2.5;
        else if (grade == "C0") gradePoint = 2.0;
        else if (grade == "D+") gradePoint = 1.5;
        else if (grade == "D0") gradePoint = 1.0;
        else if (grade == "F")  gradePoint = 0.0;

        totalWeightedScore += credit * gradePoint;
        totalCredits += credit;
    }

    if (totalCredits > 0.0f) {
        std::cout << std::fixed << std::setprecision(6) << (totalWeightedScore / totalCredits);
    } else {
        std::cout << "0.000000";
    }

    return 0;
}
