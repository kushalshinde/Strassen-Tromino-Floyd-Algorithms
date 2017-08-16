#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN -10
#define MAX 10

int number;

void strassen_algorithm(int first_matrix[][number], int second_matrix[][number], int result_matrix[][number], int input);

/*--------------------------------------------------Simple Multiplication-----------------------------------------*/
void simpleMultiplication(int number, int (*first)[number],int (*second)[number],int (*result)[number])
{
	int l;
	int m;
	int n;
    
    for(l=0; l<number; l++){
		for (m = 0; m<number; m++){
			result[l][m]=0;
		}
	}

	for(l=0; l<number; l++){
		for ( m = 0; m < number; m++){
			for ( n = 0; n < number; n++){
				result[l][m]=result[l][m]+(first[l][n]*second[n][m]);
			}
		}
	}
}
/*--------------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------------Matrix Printing -------------------------------------------------------*/
void matrix_printing(int column, int (*ptr)[column])
{
	int i;
	int j;

    for(i=0; i<column; i++){
		for (j=0; j<column; j++){
			printf("%d\t", ptr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------------Random Number Generation -------------------------------------------------*/

int random_number_generation()
{
	int random_number;
	random_number = rand()%(MAX-MIN+1)+MIN;
	return random_number;
}
/*--------------------------------------------------------------------------------------------------------------------------*/


int main(int argc, char *argv[])
{ 	
	int i,j;
	srand((unsigned)time(NULL));
	
	int n = atoi(argv[1]);

	while((n & (n-1)))
	{
		printf("Enter the value of n in the 2's power:\n");
		scanf("%d",&n);
	}
	
	number = n;
	
	int result1[n][n];
	int result2[n][n];
	int first[n][n];
	int second[n][n];
	
	for(i=0; i<n; i++){
		for (j=0; j<n; j++){
			first[i][j] = random_number_generation(MIN,MAX);
			second[i][j] = random_number_generation(MIN,MAX);
		}
	}
	
	printf("First Matrix :: \n");
	matrix_printing(n,first);
	
	printf("Second Matrix :: \n");
	matrix_printing(n,second);
	
	simpleMultiplication(n,first,second,result1);
	
	printf("Traditional Matrix Multiplication :: \n");
	matrix_printing(n,result1);
	
	printf("Strassen Algorithm's Matrix Multiplication :: \n");
	strassen_algorithm(first,second,result2,n);
	matrix_printing(n,result2);
	
	return 0;
}


/*-----------------------------------------------Strassen Algorithm -----------------------------------------------*/

void strassen_algorithm(int first_matrix[][number], int second_matrix[][number], int result_matrix[][number], int input) 
{
	int i, j;
	int half_size = input/2;
	
	int m1[half_size][half_size]; 
	int m2[half_size][half_size]; 
	int m3[half_size][half_size]; 
	int m4[half_size][half_size]; 
	int m5[half_size][half_size]; 
	int m6[half_size][half_size]; 
	int m7[half_size][half_size];
	int temp_matrix1[half_size][half_size]; 
	int temp_matrix2[half_size][half_size];


	if(input >= 2) {	
        for(i=0;i<half_size; i++){
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i][j] + first_matrix[i + half_size][j + half_size];
				temp_matrix2[i][j] = second_matrix[i][j] + second_matrix[i + half_size][j + half_size];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m1, half_size);

		for(i = 0; i < half_size; i++) {
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i + half_size][j] + first_matrix[i + half_size][j + half_size];
				temp_matrix2[i][j] = second_matrix[i][j];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m2, half_size);

		for(i = 0; i < half_size; i++) {
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i][j];
				temp_matrix2[i][j] = second_matrix[i][j + half_size] - second_matrix[i + half_size][j + half_size];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m3, half_size);

		for(i = 0; i < half_size; i++) {
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i + half_size][j + half_size];
				temp_matrix2[i][j] = second_matrix[i + half_size][j] - second_matrix[i][j];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m4, half_size);

		for(i = 0; i < half_size; i++) {
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i][j] + first_matrix[i][j + half_size];
				temp_matrix2[i][j] = second_matrix[i + half_size][j + half_size];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m5, half_size);

		for(i = 0; i < half_size; i++) {
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i + half_size][j] - first_matrix[i][j];
				temp_matrix2[i][j] = second_matrix[i][j] + second_matrix[i][j + half_size];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m6, half_size);

		for(i = 0; i < half_size; i++) {
			for(j = 0; j < half_size; j++) {
				temp_matrix1[i][j] = first_matrix[i][j + half_size] - first_matrix[i + half_size][j + half_size];
				temp_matrix2[i][j] = second_matrix[i + half_size][j] + second_matrix[i + half_size][j + half_size];
			}
		}

		number = half_size;
		strassen_algorithm(temp_matrix1, temp_matrix2, m7, half_size);

		
		for(i=0; i<half_size; i++){
			for(j=0; j<half_size; j++){
				result_matrix[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
				result_matrix[i][j + half_size] = m3[i][j] + m5[i][j];
				result_matrix[i + half_size][j] = m2[i][j] + m4[i][j];
				result_matrix[i + half_size][j + half_size] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];
				result_matrix[i + half_size][j + half_size] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];
			}
		}
	}
	else if(input == 1) {
		result_matrix[0][0] = first_matrix[0][0] * second_matrix[0][0];
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/