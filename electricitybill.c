#include <cs50.h>
#include <stdio.h>

int main() {
    // Variable declarations
    string customer_id;
    string customer_name;
    long contact_no;
    float total_units, total_bill;
    float rate_per_unit, fixed_charge;

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

    // Get customer type and set rates
    string customer_type = get_string("Enter Customer Type (Residential/Commercial): ");
    if (strcmp(customer_type, "Residential") == 0) {
        rate_per_unit = 5.0;  // Rate for Residential
        fixed_charge = 100.0;  // Fixed charge for Residential
    } else if (strcmp(customer_type, "Commercial") == 0) {
        rate_per_unit = 7.0;  // Rate for Commercial
        fixed_charge = 150.0;  // Fixed charge for Commercial
    } else {
        printf("Invalid customer type. Please enter either 'Residential' or 'Commercial'.\n");
        return 1;  // Exit if the customer type is invalid
    }

    // Get usage information with validation
    while (true) {
        total_units = get_float("Enter the total units of electricity consumed: ");
        if (total_units >= 0) {
            break;
        } else {
            printf("Invalid input. Units consumed cannot be negative.\n");
        }
    }

    // Calculate total bill
    total_bill = (total_units * rate_per_unit) + fixed_charge; // Calculate total bill

    // Display the bill
    printf("\nElectricity Bill\n");
    printf("--------------------\n");
    printf("Customer ID: %s\n", customer_id);
    printf("Customer Name: %s\n", customer_name);
    printf("Contact Number: %ld\n", contact_no);
    printf("Customer Type: %s\n", customer_type);
    printf("Total Units Consumed: %.2f\n", total_units);
    printf("Rate per Unit: %.2f\n", rate_per_unit);
    printf("Fixed Charge: %.2f\n", fixed_charge);
    printf("Total Bill Amount: %.2f\n", total_bill);
    printf("--------------------\n");

    return 0;
}
