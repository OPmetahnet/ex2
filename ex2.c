/******************
Name:
ID: 212320733
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int menuOption = 0;
	char eyes, nose, mouth;

	while(menuOption != 7) {
		//menu print
		printf("Choose an option:\n\t"
			"1. Happy Face\n\t"
			"2. Balanced Number\n\t"
			"3. Generous Number\n\t"
			"4. Circle Of Joy\n\t"
			"5. Happy Numbers\n\t"
			"6. Festival Of Laughter\n\t"
			"7. Exit\n");

		scanf("%d", &menuOption);

		//checking input for a menu option
		switch(menuOption) {
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
			case 1: {
				int face_size;

				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &face_size);

				//getting a different face size if not positive/even
				while(face_size <= 0 || face_size % 2 == 0) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &face_size);
				}

				//print eyes
				printf("%c", eyes);
				for(int i = 0; i < face_size; i++) {
					printf(" ");
				}
				printf("%c\n", eyes);

				//print nose
				for(int i = 0; i < face_size + 1; i++) {
					//checking if it is the middle point index
					if(i == (face_size + 1) / 2) {
						printf("%c", nose);
						continue;
					}
					printf(" ");
				}
				printf(" \n");

				//print mouth
				printf("\\");
				for(int i = 0; i < face_size; i++) {
					printf("%c", mouth);
				}
				printf("/\n");
				continue;
			}

			case 2: {
				int number, digit_check_number, digit_count = 0, sum_right = 0, sum_left = 0;

				printf("Enter a number:\n");
				scanf("%d", &number);

				//getting a different number if not positive
				while(number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				digit_check_number = number;

				//check the number of digits
				while(digit_check_number > 0) {
					digit_count++;
					digit_check_number /= 10;
				}

				//summing the digit sums
				for(int i = 0; i < digit_count; i++) {
					//up until the middle digit -> sum right
					if(i <= (digit_count - 1) / 2) {
						sum_right += number % 10;//adds the rightmost digit of the number
					}

					//after the middle digit -> sum left
					if(i >= digit_count / 2) {
						sum_left += number % 10;
					}

					number /= 10;
				}

				//prints harmony-related messages
				if(sum_left == sum_right)
					printf("This number is balanced and brings harmony!\n");
				else
					printf("\nThis number isn't balanced and destroys harmony.\n");

				continue;
			}

			case 3: {
				int number, divisor_sum = 0;

				printf("Enter a number:\n");
				scanf("%d", &number);

				//getting a different number if not positive
				while(number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				//sum all the divisors of the number
				for(int i = 1; i <= number / 2; i++) {
					if(number % i == 0)
						divisor_sum += i;
				}

				//prints sharing-related messages
				if(number < divisor_sum)
					printf("This number is generous!\n");
				else
					printf("This number does not share.\n");

				continue;
			}

			//exiting the program
			case 7: {
				printf("Thank you for your journey through Numeria!\n");
				return 0;
			}

			//sending user back to select an option from the menu
			default: {
				printf("This option is not available, please try again.\n");
				continue;
			}
		}
	}

	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/
    

	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}
