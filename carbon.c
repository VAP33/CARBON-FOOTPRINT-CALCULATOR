#include <cs50.h>
#include <stdio.h>

int main() {
    // Variable declarations
    string customer_id;
    string customer_name;
    long contact_no;
    float total_units, carbon_per_kwh = 0.4; // kg CO2 per kWh
    float total_carbon_footprint;

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

    // Calculate carbon footprint
    total_carbon_footprint = total_units * carbon_per_kwh; // kg CO2

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
    printf("Carbon Emission Factor: %.2f kg CO2/kWh\n\n", carbon_per_kwh);
    printf("Total Carbon Footprint: %.2f kg CO2\n\n", total_carbon_footprint);

    // Compare this month’s and last month’s consumption
    if (total_units > last_month_units) {
        printf("Your consumption has increased by %.2f kWh compared to last month.\n\n", total_units - last_month_units);
    } else if (total_units < last_month_units) {
        printf("Your consumption has decreased by %.2f kWh compared to last month.\n\n", last_month_units - total_units);
    } else {
        printf("Your consumption is the same as last month.\n\n");
    }

    printf("==============================================\n\n");

    // Recommendations
    printf("Recommendations:\n\n");
    printf("- Consider switching to LED lights to save energy.\n");
    printf("- Look into solar panel installations to reduce your footprint.\n\n");

    // Conclusion
    printf("Thank you for taking steps to reduce your carbon footprint!\n");
    printf("***********************************************\n\n");

    return 0;
}
