#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
/*
 * Thomas Cook
 * CS5379 Assignment_3
 * Program takes an input file of 32 bit signed integers and writes each integer into
 * another file depending on properties of the integer. (odd, even +, -, perfect sq/cb)
 * Usage: ./assignment_3 (path to file)
 */

//Declare files with FILE type
static FILE *in_fp, *positive_fp, *negative_fp, *even_fp, *odd_fp, *square_fp, *cube_fp;

//Function isPerfectSquare determines if number is a perfect square
bool isPerfectSquare(int num){
	if (num<0) return false;
	int root = (int)sqrt(num);
	return root * root == num;

}

//Function isPerfectCube determines if number is a perfect cube
bool isPerfectCube(int num){
	int root = round(cbrt(num));
	return root * root * root == num;
}

//main driver function
int main(int argc, char* argv[]){ //get path to file via command line argument
	if (argc !=2){
		printf("Usage: %s <path to file>\n", argv[0]);
		return(1);
	}
	if ((in_fp = fopen(argv[1], "r")) == NULL){ //make sure file opens correctly
		printf("ERROR - cannot open %s \n", argv[1]);
		return 1;
	}
	//Main logic
	//
	//Open output files
	positive_fp = fopen("positive.out", "w");
	negative_fp = fopen("negative.out", "w");
	odd_fp = fopen("odd.out", "w");
	even_fp = fopen("even.out", "w");
	square_fp = fopen("square.out", "w");
	cube_fp = fopen("cube.out", "w");

	//Ensure files opened correctly
	if(!positive_fp || !negative_fp || !odd_fp || !even_fp || !square_fp || !cube_fp){
		printf("Error - cannot open output files\n");
		return 1;
	}
	int num;
	//Conditionally and optimally check for each scenario
	//Use fprintf to write to file and add new line every write
	while(fscanf(in_fp, "%d", &num) == 1) {
		if (num > 0) fprintf(positive_fp, "%d\n", num);
		if (num < 0) fprintf(negative_fp, "%d\n", num);
		if(num % 2 == 0) fprintf(even_fp, "%d\n", num);
		else fprintf(odd_fp, "%d\n", num);
		if (isPerfectSquare(num)) fprintf(square_fp, "%d\n", num);
		if (isPerfectCube(num)) fprintf(cube_fp, "%d\n", num);
	}
	//Close all files
	fclose(in_fp);
	fclose(positive_fp);
	fclose(negative_fp);
	fclose(odd_fp);
	fclose(even_fp);
	fclose(square_fp);
	fclose(cube_fp);

	printf("Results stored in files.\n");
	return 0;
}
