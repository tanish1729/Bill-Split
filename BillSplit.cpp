#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main(int argc, char **argv)
{
    int tani;
    cout << "Enter 1 for compact view, 2 for detailed view" << endl;

    cout << "----------------------------------------------------------------------";
    cout << endl;
    cin >> tani;

    FILE *input = fopen(argv[1], "r");
    char temp[100];
    char names[100][100];
    char costs[100][100];
    int check = 0;
    int namesIt = 0;
    int costsIt = 0;
    while (fgets(temp, sizeof(temp), input))
    {
        if (check % 2 == 0)
        {
            strcpy(names[namesIt], temp);
            namesIt++;
        }
        else
        {
            strcpy(costs[costsIt], temp);
            costsIt++;
        }
        check += 1;
    }
    long double totalPeople = namesIt - 1;
    for (int i = 0; i < totalPeople; i++)
    {
        names[i][strcspn(names[i], "\n")] = 0;
    }
    long double taxes = stold(names[namesIt - 1]);
    long double dutch = stold(costs[costsIt - 1]);
    long double dutchPerPerson = dutch / totalPeople;
    long double total[100];
    long double net = 0;
    long double netall = 0;
    char delimiter[] = " ";
    for (int i = 0; i < totalPeople; i++)
    {
        long double sum = 0;
        char *ptr = strtok(costs[i], delimiter);
        while (ptr != NULL)
        {
            sum += stold(ptr);
            ptr = strtok(NULL, delimiter);
        }
        total[i] = sum;
        net += total[i];
    }
    long double billPerPerson[100];
    long double taxPerPerson[100];
    long double taxPercentPerPerson[100];
    for (int i = 0; i < totalPeople; i++)
    {
        billPerPerson[i] = 0;
        taxPerPerson[i] = (total[i] / net) * taxes;
        taxPercentPerPerson[i] = (total[i] / net) * 100;
        billPerPerson[i] += total[i] + taxPerPerson[i] + dutchPerPerson;
        netall += billPerPerson[i];
    }
    if (tani == 2)
    {
        cout << "----------------------------------------------------------------------";
        cout << endl;
        cout << "Total Cost = " << net << endl;
        cout << "Total Taxes = " << taxes << endl;
        cout << "Total Dutch = " << dutch << endl;
        cout << "Total Bill = " << net + taxes + dutch << endl;

        cout << "----------------------------------------------------------------------";

        cout << endl
             << "If there was a direct dutch, everyone would pay " << netall / totalPeople << endl;
        cout << "----------------------------------------------------------------------";
        cout << endl;
        cout << left << setw(10) << "Name" << left << setw(10) << "Cost" << left << setw(10) << "Tax" << left << setw(10) << "Dutch" << left << setw(15) << "Final Bill" << left << setw(15) << "% of Total Bill";
        cout << endl;
        cout << "----------------------------------------------------------------------";
        cout << endl;
        for (int i = 0; i < totalPeople; i++)
        {
            cout << left << setw(10) << names[i] << left << setw(10) << total[i] << left << setw(10) << taxPerPerson[i] << left << setw(10) << dutchPerPerson << left << setw(15) << billPerPerson[i] << left << setw(15) << to_string(taxPercentPerPerson[i]) + " % ";
            cout << endl;
        }
        cout << "----------------------------------------------------------------------";
        cout << endl;
    }
    else if (tani == 1)
    {
        cout << "----------------------------------------------------------------------";
        cout << endl;
        cout << "Total Bill = " << net + taxes + dutch << endl;

        cout << "----------------------------------------------------------------------";

        cout << endl;
        cout
            << left << setw(10) << "Name" << left << setw(10) << "Bill";
        cout << endl;
        cout << "----------------------------------------------------------------------";
        cout << endl;
        for (int i = 0; i < totalPeople; i++)
        {
            cout << left << setw(10) << names[i] << left << setw(15) << billPerPerson[i];
            cout << endl;
        }
        cout << "----------------------------------------------------------------------";
        cout << endl;
    }
    fclose(input);
    return (0);
}