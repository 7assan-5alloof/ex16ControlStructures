#include <iostream>

using namespace std;

int main()
{
    cout << "Press Ctrl-C to stop..." << endl;

    while (true)
    {
        // Get consumption details for the current month
        int electricity;
        cout << "Please enter your consumption of electricity for the current month, in kWh: ";
        cin >> electricity;
        int water;
        cout << "Please enter your consumption of water for the current month, in IG (Imperial Gallon): ";
        cin >> water;

        // Repeat input process for impossible situations
        if ((electricity < 0) || (water < 0))
        {
            cout << "Please enter valid consumptions...";
            continue;
        }

        // Find bill category of electricity in the tariffs table
        int electricityCategory;
        if (electricity < 2001) electricityCategory = 23;
        else if ((electricity >= 2001) && (electricity < 4001)) electricityCategory = 28;
        else if ((electricity >= 4001) && (electricity < 6001)) electricityCategory = 32;
        else if (electricity >= 4001) electricityCategory = 38;

        // Find bill category of water in the tariffs table
        double waterCategory;
        if (water < 6001) waterCategory = 3.5;
        else if ((water >= 6001) && (electricity < 12001)) waterCategory = 4.0;
        else if (electricity >= 12001) waterCategory = 4.6;

        // Output bill categories
        cout << "You'll pay " << electricityCategory << " fils for every kWh you've consumed." << endl;
        cout << "You'll pay " << waterCategory << " fils for every IG you've consumed." << endl;

        // Calculate and output totals
        double electricityTotal = electricityCategory * electricity / 100;
        double waterTotal = waterCategory * water / 100;
        double grandTotal = electricityTotal + waterTotal;
        cout << "You'll pay " << electricityTotal << " dirhams for electricity and " << waterTotal << " dirhams for water." << endl;
        cout << "In total, you'll pay " << grandTotal << " dirhams to DEWA to cancel your electricity and water bills from your owes!" << endl;
    }

    return 0;
}
