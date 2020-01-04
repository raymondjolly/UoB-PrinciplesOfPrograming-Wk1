#include <stdio.h>
#include <math.h>

void printHelloWorld(int);
void printXTenTimes(unsigned int);
void convertMetricToImperialHeights(int);
void fibonacci(void);
void volumeOfACylinder(double, double);

int main(void) {
    printf("Question 1\n");
    printHelloWorld(10);
    printf("\nQuestion 2 Print range number from parameter plus next 10 numbers\n");
    printXTenTimes(10);
    printf("\n");
    printf("\nQuestion 3 Metric to Imperial Conversion\n");
    convertMetricToImperialHeights(101);
    convertMetricToImperialHeights(3);
    convertMetricToImperialHeights(15);
    convertMetricToImperialHeights(192);
    convertMetricToImperialHeights(124);

    printf("\n");
    printf("\nQuestion 4 Fibonacci sequence\n");
    fibonacci();
    printf("\n");
    printf("\nQuestion 5 Volume of a Cylinder\n");
    //    height 7.0cm and radius 4.0cm
    volumeOfACylinder(7.0, 4.0);
    //    height 20.0cm and radius 3.0cm
    volumeOfACylinder(20.0, 3.0);
    //    height 14.7cm and radius 5.2cm
    volumeOfACylinder(14.7, 5.2);

    return 0;
}

/*
 * Lab Sheet 1:
 */

/* Question 1:

Adapt the “HelloWorld” code below to produce a program that defines a variable capable
of holding an integer of your choice. The program should add 3 to that number, multiply
 the result by 2, subtract 4, subtract twice the original number,
add 3, then print the result and a new line.
*/

void printHelloWorld(int number){
    int originalNumber = number;
    number = number +3; //add 3 addressed
    number = number *2; //multiply result by 2
    number = number -4; //subtract 4
    number = number - (originalNumber *2); //subtract twice the original number
    number = number +3; //add three
    printf("The result of numbers operations in the comment requirements is: %d\n", number);
}

/* Question 2:
Complete the function below so that it prints every integer from x to x + 10.  Do not use loops.
Call this function from the main to test your program.
*/

//printXTenTimes will take any unsigned integer value and print out the values from 1 to the
//parameter plus 10
void printXTenTimes(unsigned int number){
    int i = 0;
    start:
        i +=1;
        printf("%d ", i);
        if(i < (number + 10)){
            goto start;
    }
}

/* Question 3:

Complete the function below so that it converts the height of a person from centimetres to feet and inches.
Use integer division (rounding down is acceptable, which is the default for integer division).
Hint: 254 cm is exactly 100 inches and 12 inches is exactly 1 foot.

Call this function from the main to test your program.
For example you could test your program with the follow five values,
where "?" replaced with the true value.

101 cm is 3 feet 3 inches to the nearest inch.
3 cm is 0 feet 1 inches to the nearest inch.
15 cm is ? feet ? inches to the nearest inch.
192 cm is ? feet ? inches to the nearest inch.
124 cm is ? feet ? inches to the nearest inch.
*/

/*convertMetricToImperialHeights takes any unsigned integer classified as centimeters
 *  and will print out the converted values into feet and inches rounded to the closed value.
 * */
void convertMetricToImperialHeights( int centimeters){
    int feet;
    double inches;
    if(centimeters<0){
        printf("Invalid value. Input must be positive");
    }
    inches = (int)(centimeters/2.52);
    feet = (int) inches /12;
    inches = (int) inches - (feet*12);

    printf("%d cm is %d feet %.0f inches to the nearest inch\n", centimeters, feet, inches);
}

/* Question 4:

Complete the function below so that it uses three variables (current, previous, next) to calculate and print out the first ten numbers of the Fibonacci sequence,
each on a new line: i.e. the first four lines should be as follows:

0
1
1
2

Call this function from the main to test your program.
*/
//RAY JOLLY notes on question:
//fibonacci function takes no parameter and returns the first 10 numbers in the fibonacci sequence
//REQUIRED: must use three variables (current, previous, next). Therefore can't really use recursion.
//fibonacci sequence is defined as the next number being the sum of the previous and the current value.
void fibonacci(void){
    int current = 1; //int literal starting at 1
    int previous = 0; //int literal starting at 0
    int next; //initialized
    int i = 0; //incrementer

    //first 2 base values are printed
    printf("%d\n", previous);
    printf("%d\n", current);
    //Since I cannot use recursion due to the required variables,
    //I am using a while loop in this example and will print the remaining 8 numbers.
    while(i <8 ){
        next = current + previous;
        previous = current;
        current = next;
        printf("%d\n", next);
        i++;
    }

}

/* Question 5:

Complete the function below so that it uses two variables: height and radius.
Use these two variables and print to the screen, the volume of a cylinder.

Call this function from the main to test your program.  For example, you could test your program with the following values,

height 7.0cm and radius 4.0cm
height 20.0cm and radius 3.0cm
height 14.7cm and radius 5.2cm

Which print out, the cylinder with height 7.0cm and radius 4.0cm has a volume of 351.86cm^3

*/

/*volumeOfACylinder will take an unsigned double values for height and radius
*the values are measured in centimeters as will print out the volume in cubic centimeters
 */
void volumeOfACylinder(double height, double radius){
    if(height<0 || radius <0){
        printf("Negative numbers are invalid values");
    } else{
        double volume = M_PI * (radius * radius) * height;
        printf("the cylinder with height %.1fcm and radius of %.1fcm has a volume of %.2fcm^3\n", height, radius, volume);
    }
}


