#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main() {
    // Variable declarations
    string customer_id;
    string customer_name;
    long contact_no;
    float total_units, carbon_per_kwh = 0.9; // kg CO2 per kWh for India
    float total_carbon_footprint;

    // Vehicle factors
    float kilometers_driven, vehicle_emission_factor = 0.175; // kg CO2 per km for India
    float total_vehicle_emissions;

    // Petrol consumption variables
    float mileage, petrol_consumed; // in liters

    // Historical consumption for comparison
    float last_month_units;

    // Get customer details
    customer_id = get_string("Enter Customer ID (e.g., ARYA1897): ");
    customer_name = get_string("Enter Customer Name: ");

    // Get a valid contact number
    while (true) {
        contact_no = get_long("Enter Contact Number (10 digits): ");
        if (contact_no > 999999999 && contact_no < 10000000000) {
            break;
        } else {
            printf("Invalid contact number. Please enter a 10-digit number.\n");
        }
    }

    // Get last month's electricity consumption with validation
    while (true) {
        last_month_units = get_float("Enter the total units consumed last month: ");
        if (last_month_units >= 0) { // Check for non-negative input
            break;
        } else {
            printf("Invalid input. Units consumed cannot be negative.\n");
        }
    }

    // Get this month's electricity consumption with validation
    while (true) {
        total_units = get_float("Enter the total units of electricity consumed this month: ");
        if (total_units >= 0) { // Check for non-negative input
            break;
        } else {
            printf("Invalid input. Units consumed cannot be negative.\n");
        }
    }

    // Get kilometers driven with validation
    while (true) {
        kilometers_driven = get_float("Enter the total kilometers driven this month: ");
        if (kilometers_driven >= 0) { // Check for non-negative input
            break;
        } else {
            printf("Invalid input. Kilometers driven cannot be negative.\n");
        }
    }

    // Get average mileage from user input
    while (true) {
        mileage = get_float("Enter your vehicle's mileage (km/l): ");
        if (mileage > 0) { // Check for positive input
            break;
        } else {
            printf("Invalid input. Mileage must be a positive number.\n");
        }
    }

    // Calculate petrol consumed (in liters)
    petrol_consumed = kilometers_driven / mileage;

    // Calculate carbon footprints
    total_carbon_footprint = total_units * carbon_per_kwh; // kg CO2 from electricity
    total_vehicle_emissions = kilometers_driven * vehicle_emission_factor; // kg CO2 from vehicle

    // Display the results
    printf("\n\n");
    printf("*********** Carbon Footprint Bill ***********\n");
    printf("==============================================\n\n");

    printf("Customer ID: %s\n\n", customer_id);
    printf("Customer Name: %s\n\n", customer_name);
    printf("Contact Number: %ld\n\n", contact_no);
    printf("----------------------------------------------\n\n");

    printf("Total Units Consumed (This Month): %.2f kWh\n\n", total_units);
    printf("Total Units Consumed (Last Month): %.2f kWh\n\n", last_month_units);
    printf("Carbon Emission Factor (Electricity): %.2f kg CO2/kWh\n\n", carbon_per_kwh);
    printf("Total Carbon Footprint from Electricity: %.2f kg CO2\n\n", total_carbon_footprint);

    printf("Total Kilometers Driven: %.2f km\n\n", kilometers_driven);
    printf("Vehicle Emission Factor: %.2f kg CO2/km\n\n", vehicle_emission_factor);
    printf("Total Carbon Footprint from Vehicle: %.2f kg CO2\n\n", total_vehicle_emissions);
    printf("Total Petrol Consumed: %.2f liters\n\n", petrol_consumed);

    // Calculate total carbon footprint
    float total_carbon = total_carbon_footprint + total_vehicle_emissions;
    printf("Total Carbon Footprint (Electricity + Vehicle): %.2f kg CO2\n\n", total_carbon);

    // Compare this month’s and last month’s consumption
    if (total_units > last_month_units) {
        printf("Your electricity consumption has increased by %.2f kWh compared to last month.\n\n", total_units - last_month_units);
    } else if (total_units < last_month_units) {
        printf("Your electricity consumption has decreased by %.2f kWh compared to last month.\n\n", last_month_units - total_units);
    } else {
        printf("Your electricity consumption is the same as last month.\n\n");
    }

    printf("==============================================\n\n");

    // Recommendations
    printf("Recommendations:\n\n");
    printf("- Consider switching to LED lights to save energy.\n");
    printf("- Look into solar panel installations to reduce your footprint.\n");
    printf("- Consider using public transport or carpooling to lower vehicle emissions.\n");

    // Conclusion
    printf("Thank you for taking steps to reduce your carbon footprint!\n");
    printf("***********************************************\n\n");

    return 0;
}
