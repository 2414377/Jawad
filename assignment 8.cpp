#include <stdio.h>
#include <string.h>

float calculateBill(int units) {
    float bill = 0.0;

    if (units <= 100) {
        bill = units * 18;
    } else if (units <= 200) {
        bill = 100 * 18 + (units - 100) * 22;
    } else if (units <= 300) {
        bill = 100 * 18 + 100 * 22 + (units - 200) * 26;
    } else if (units <= 700) {
        bill = 100 * 18 + 100 * 22 + 100 * 26 + (units - 300) * 30;
    } else {
        bill = 100 * 18 + 100 * 22 + 100 * 26 + 400 * 30 + (units - 700) * 35;
    }

    return bill;
}

int main() {
    int units;
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    float bill = calculateBill(units);
    printf("Total Bill = %.2f PKR\n", bill);

    return 0;

}
// Function to calculate fuel cost
float calculateFuelCost(float distance, float fuelAverage, float fuelPrice) {
    float fuelRequired = distance / fuelAverage;  
    float totalCost = fuelRequired * fuelPrice;  
    return totalCost;
}

int main() {
    float distance, fuelAverage, fuelPrice, totalCost;

    printf("Enter total distance of trip (in km): ");
    scanf("%f", &distance);
    printf("Enter fuel average (in km/liter): ");
    scanf("%f", &fuelAverage);
    printf("Enter current fuel price (in PKR/liter): ");
    scanf("%f", &fuelPrice);

    totalCost = calculateFuelCost(distance, fuelAverage, fuelPrice);

    printf("Total Fuel Cost = %.2f PKR\n", totalCost);

    return 0;
}
// Function to calculate Zakat
float calculateZakat(float totalWealth) {
    // Nisab thresholds
    float nisabGold = 87.48 * 18000;  
    float nisabSilver = 612.36 * 1000; 
    float zakatRate = 0.025;           

    if (totalWealth >= nisabGold || totalWealth >= nisabSilver) {
        return totalWealth * zakatRate;
    } else {
        return 0; 
    }
}

int main() {
    float totalWealth, zakatAmount;

    printf("Enter your total wealth (in PKR): ");
    scanf("%f", &totalWealth);
    zakatAmount = calculateZakat(totalWealth);
    if (zakatAmount > 0) {
        printf("Zakat Payable = %.2f PKR\n", zakatAmount);
    } else {
        printf("No Zakat payable as wealth is below Nisab threshold.\n");
    }

    return 0;
}



// Function to calculate GPA based on marks
float calculateGPA(int marks) {
    if (marks >= 85) return 4.0;
    else if (marks >= 80) return 3.7;
    else if (marks >= 75) return 3.3;
    else if (marks >= 70) return 3.0;
    else if (marks >= 65) return 2.7;
    else if (marks >= 60) return 2.3;
    else return 0.0; // Fail
}

// Function to convert currency to PKR
float convertCurrency(float amount, char currencyType) {
    float rate;
    printf("Enter the exchange rate for %c to PKR: ", currencyType);
    scanf("%f", &rate);
    return amount * rate;
}

// Function to calculate income tax based on salary
float calculateIncomeTax(float salary) {
    float annualSalary = salary * 12;
    if (annualSalary < 600000) return 0.0;
    else if (annualSalary <= 1200000) return annualSalary * 0.025;
    else if (annualSalary <= 2400000) return annualSalary * 0.125;
    else if (annualSalary <= 3600000) return annualSalary * 0.20;
    else return annualSalary * 0.30;
}

// Function to show a randomized load shedding schedule
void showLoadSheddingSchedule(char city[]) {
    printf("Load Shedding Schedule for %s:\n", city);
    printf("Monday: 6 AM - 8 AM, 6 PM - 8 PM\n");
    printf("Tuesday: 7 AM - 9 AM, 5 PM - 7 PM\n");
    printf("Wednesday: 8 AM - 10 AM, 4 PM - 6 PM\n");
    printf("Thursday: 9 AM - 11 AM, 3 PM - 5 PM\n");
    printf("Friday: 10 AM - 12 PM, 2 PM - 4 PM\n");
    printf("Saturday: 11 AM - 1 PM, 1 PM - 3 PM\n");
    printf("Sunday: No Load Shedding\n");
}

// Function to calculate internet package cost
float internetPackageCost(int GB, char network[]) {
    float costPerGB;
    if (strcmp(network, "Zong") == 0) costPerGB = 100;
    else if (strcmp(network, "Jazz") == 0) costPerGB = 120;
    else if (strcmp(network, "Telenor") == 0) costPerGB = 90;
    else {
        printf("Invalid network!\n");
        return 0.0;
    }
    return GB * costPerGB;
}

// Function to calculate train fare
float calculateTrainFare(char class[], float distance) {
    float farePerKm;
    if (strcmp(class, "Economy") == 0) farePerKm = 5;
    else if (strcmp(class, "Business") == 0) farePerKm = 10;
    else if (strcmp(class, "First") == 0) farePerKm = 15;
    else {
        printf("Invalid class!\n");
        return 0.0;
    }
    return farePerKm * distance;
}

int main() {
    // Example usage of each function
    int marks = 78;
    printf("GPA = %.1f\n", calculateGPA(marks));

    float amount = 100;
    printf("PKR = %.2f\n", convertCurrency(amount, 'USD'));

    float salary = 150000;
    printf("Annual Tax = %.2f\n", calculateIncomeTax(salary));

    char city[] = "Karachi";
    showLoadSheddingSchedule(city);

    int GB = 10;
    char network[] = "Jazz";
    printf("Internet Package Cost = %.2f PKR\n", internetPackageCost(GB, network));

    char class[] = "Business";
    float distance = 1250;
    printf("Train Fare = %.2f PKR\n", calculateTrainFare(class, distance));

    return 0;
}

