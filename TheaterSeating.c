/*
 * TestTheater.c
 *
 *  Created on: Feb 19, 2019
 *      Author: gilescarlos32
 */

#include <stdio.h>

int menu();
void displayTheater();
const int rows = 15, columns = 30;
char theater[rows][columns];
char available = '#', reserved = '*';
double seatPrice;
int availableSeats = 450, reservedSeats = 0;
int quit;

int main() {
	int seatPriceByRow[rows];
	int rowSelection, seatSelection, cost, confirmPurchase, temp, answer1, answer2;
	int totalSales = 0;

    fflush(stdout);
	for (int count = 0; count < rows; count++) {
		do {
			printf("Enter price for row %d: $ ", (count + 1));
			scanf(" %d", &seatPriceByRow[count]);
			fflush(stdin);
		} while (seatPriceByRow[count] < 0);
	}

	for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < columns; j++)
	    	theater[i][j] = available;
	}

	int choice;
	do {
		choice = menu();
		switch (choice) {
			case 1:
				printf("\n\tSeat Prices\n");
				for (int count = 0; count < rows; count++)
					printf("Price for row %d: $%d \n", (count + 1), seatPriceByRow[count]);
				break;
			case 2:
				displayTheater();
				printf("\nPurchase Ticket(s)\n\n");
				do {
					do {
						printf("Select row:  ");
						scanf(" %d", &rowSelection);
					} while (rowSelection < 1 || rowSelection > 15);

					do {
						printf("Select seat:  ");
						scanf(" %d", &seatSelection);
					} while (seatSelection < 1 || seatSelection > 30);

		     		if (theater[(rowSelection - 1)][(seatSelection - 1)] == '*') {
			      		printf("Sorry that seat is reserved, select another seat.\n");
			  		} else {
			  			do {
							cost = seatPriceByRow[rowSelection - 1] + 0;
							printf("Ticket costs: $%d\n", cost);
							printf("Confirm Purchase? Enter (1 = Yes / 2 = No) ");
							scanf(" %d", &answer1);
			  			} while (answer1 < 1 || answer1 > 2);

				       	confirmPurchase = answer1;

				       	if (confirmPurchase == 1) {
				        	totalSales += cost;
				       		availableSeats -= 1;
				       		reservedSeats += 1;
				       		printf("Purchase confirmed\n");
				       	    theater[(rowSelection - 1)][(seatSelection - 1)] = reserved;
			        	} else {
			        		do {
			        			printf("Look for another seat? Enter (1 = Yes / 2 = No) ");
								scanf(" %d", &answer2);
			        		} while (answer2 < 1 || answer2 > 2);
			        	}
				       	do {
				       		printf("Look for another seat? Enter (1 = Yes / 2 = No) ");
							scanf(" %d", &answer2);
				       	} while (answer2 < 1 || answer2 > 2);
				       	temp = answer2;
			      	}
				} while (temp == 1);
				break;
			case 3:
				displayTheater();
				break;
			case 4:
				printf("Total ticket sales: $%d\n", totalSales);
				printf("Total tickets sold: %d\n", reservedSeats);
				printf("Total tickets available: %d\n", availableSeats);
				break;
			case 5:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("\nInvalid choice\n");
		}
	} while (choice != 5);

	return 0;
}

int menu() {
	int option;

	do {
		printf(" \n\tMain Menu\n");
		printf("1. View Seat Prices.\n");
		printf("2. Purchase a Ticket.\n");
		printf("3. View Available Seats.\n");
		printf("4. View Ticket Sales.\n");
		printf("5. Quit the program.\n");
		printf("\nEnter your choice: ");
	    scanf(" %d", &option);
	} while (option < 1 && option > 5);

    return option;
}

void displayTheater() {
	printf("\n\t\t Theater Chart\n\n");
    printf("Seats\t 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");
    for (int i = 0; i < 15; i++) {
    	printf("Row %d \t", (i + 1));
    	for (int j = 0; j < 30; j++)  {
    		if (j < 9)
    			printf(" %c", theater[i][j]);
    		else
    			printf(" %c ", theater[i][j]);
    	}
        printf("\n");
    }
    printf("\n");
}

