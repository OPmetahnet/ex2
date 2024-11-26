/******************
Name: Oz Pinto
ID: 212320733
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int menuOption = 0;

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
				char eyes, nose, mouth;
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

			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not balanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
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

			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abundant: 12, 20, 24
			Not Abundant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
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

			// Case 4: determine weather a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			case 4: {
				int number, reversed_number = 0;
				int flag_number = 0, flag_reversed_number = 0;

				printf("Enter a number:\n");
				scanf("%d", &number);

				//getting a different number if not positive
				while(number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				//check if the number is prime
				for(int i = 2; i < number / 2; i++) {
					if(number % i == 0) {
						break;
					}

					//end of the loop
					if(i == number / 2 - 1)
						flag_number = 1;
				}

				//get reversed number
				while(number > 0) {
					reversed_number *= 10;
					reversed_number += number % 10;
					number /= 10;
				}

				//check if the reversed number is prime
				for(int i = 2; i < reversed_number / 2; i++) {
					if(reversed_number % i == 0) {
						break;
					}

					//end of the loop
					if(i == reversed_number / 2 - 1)
						flag_reversed_number = 1;
				}

				if(flag_number && flag_reversed_number)
					printf("This number completes the circle of joy!\n");
				else
					printf("The circle remains incomplete.\n");

				continue;
			}

			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			case 5: {
				int number, sum = 0;

				printf("Enter a number:\n");
				scanf("%d", &number);

				//getting a different number if not positive
				while(number <= 0) {
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);
				}

				printf("Between 1 and %d only these numbers bring happiness: ", number);

				//going over all the numbers from 1 to number and checking them
				for(int i = 1; i <= number ; i++) {
					int loop_number = i;

					//check if it's a happy number

					//continue performing the calculation until you reach a single digit
					while(loop_number / 10 != 0) {

						//sum all the digits powers of 2
						while(loop_number != 0) {
							//going over the digits and summing their powers of 2
							sum += (loop_number % 10) * (loop_number % 10);
							loop_number /= 10;
						}

						//reset state before next iteration
						loop_number = sum;
						sum = 0;
					}

					//if it's a single digit and either 1 or 7(one digit happy numbers) then it's a happy number
					if(loop_number == 1 || loop_number == 7)
						printf("%d ", i);
				}

				printf("\n");

				continue;
			}

			// Festival of Laughter: Prints all the numbers between 1 the given number:
			// and replace with "Smile!" every number that divided by the given smile number
			// and replace with "Cheer!" every number that divided by the given cheer number
			// and replace with "Festival!" every number that divided by both of them
			/* Example:
			6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
			*/
			case 6: {
				int smile_number = 0, cheer_number = 0, max_number;

				//used to get a response from the scanf operation, which returns the number of values it successfully got
				int check_input = 0;

				printf("Enter a smile and cheer number:\n");

				//buffer cleaning + first time input
				scanf("%*[^\n]");
				scanf("%*c");
				check_input = scanf(" smile: %d, cheer: %d", &smile_number, &cheer_number);

				//if the entered format wasn't correct - try again
				while(check_input != 2 || smile_number <= 0 || cheer_number <= 0 || smile_number == cheer_number) {
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");

					//buffer cleaning + getting input again
					scanf("%*[^\n]");
					scanf("%*c");
					check_input = scanf(" smile: %d, cheer: %d", &smile_number, &cheer_number);
				}

				//first time getting max number
				printf(("Enter maximum number for the festival:\n"));
				check_input = scanf(" %d", &max_number);

				//no need to reset check_input value because it should always be 2 at this point in the program
				while(check_input != 1 || max_number <= 0) {
					printf("Only positive maximum number is allowed, please try again:\n");

					//buffer cleaning + getting input again
					scanf("%*[^\n]");
					scanf("%*c");
					check_input = scanf(" %d", &max_number);
				}

				for(int i = 1; i <= max_number; i++) {
					//festival case
					if(i % smile_number == 0 && i % cheer_number == 0) {
						printf("Festival!\n");
						continue;
					}

					//smile case
					if(i % smile_number == 0) {
						printf("Smile!\n");
						continue;
					}

					//cheer case
					if(i % cheer_number == 0) {
						printf("Cheer!\n");
						continue;
					}

					printf("%d\n", i);
				}

				continue;
			}

			//exiting the program
			case 7: {
				printf("Thank you for your journey through Numeria!\n");
				break;
			}

			//sending user back to select an option from the menu
			default: {
				printf("This option is not available, please try again.\n");
				continue;
			}
		}
	}

	return 0;
}
