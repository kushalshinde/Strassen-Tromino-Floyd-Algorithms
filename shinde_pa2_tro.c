#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int unique_counter=1;
int x_coordinate_board = 0;
int y_coordinate_board = 0;

/*--------------------------------------------- Tromino Algorithm-------------------------------------------------------------------*/

void trom(int x_hole_coordinate,int y_hole_coordinate,int x_coordinate_board, int y_coordinate_board,int input, int (*array)[input],int size_of_board)
{
	if(size_of_board==2){
		int i;
		int j;
		
		for(i=x_coordinate_board; i < (x_coordinate_board+size_of_board); i++){
			for ( j = y_coordinate_board; j< (y_coordinate_board+size_of_board); j++){
				if(!(i==x_hole_coordinate && j==y_hole_coordinate)){
					array[i][j]=unique_counter;
				}
			}
		}
		unique_counter++;
		return;
	}

	int half = size_of_board/2;
	int cent_coordi_x;
	int cent_coordi_y;
	int right_up_x; 
	int right_up_y; 
	int left_up_x; 
	int left_up_y;
	int right_down_x; 
	int right_down_y; 
	int left_down_x;
	int left_down_y;
	
	
	int center_coordinates1 = half + x_coordinate_board;
	cent_coordi_x = center_coordinates1;
		
	int center_coordinates2 = half + y_coordinate_board;
	cent_coordi_y = center_coordinates2;
	
	if(cent_coordi_y > y_hole_coordinate && cent_coordi_x > x_hole_coordinate)
	{
		
		int unique_counter1 = unique_counter;
		array[cent_coordi_x][cent_coordi_y] = unique_counter1;
		
		int array_coordi_xy = array[cent_coordi_x][cent_coordi_y];
		array[cent_coordi_x][cent_coordi_y-1] = array_coordi_xy;
		
		int array_coordi_xy_1 = array[cent_coordi_x][cent_coordi_y-1];
		array[cent_coordi_x-1][cent_coordi_y] = array_coordi_xy_1; 
		
		int x_hole = x_hole_coordinate; 
		left_up_x = x_hole;
		
		int y_hole = y_hole_coordinate;
		left_up_y = y_hole;

		right_up_x=cent_coordi_x-1; 
		right_up_y=cent_coordi_y;

		int x_cent = cent_coordi_x;
		left_down_x = x_cent;

		int y_cent_1 = cent_coordi_y-1;
		left_down_y = y_cent_1;

		right_down_x=cent_coordi_x; 
		right_down_y=cent_coordi_y;
		unique_counter++;
	}
	else if(cent_coordi_y <= y_hole_coordinate && cent_coordi_x > x_hole_coordinate)
	{
		int unique_counter2 = unique_counter;
		array[cent_coordi_x][cent_coordi_y] = unique_counter2;
		
		int cent_coorder_xy = array[cent_coordi_x][cent_coordi_y];
		array[cent_coordi_x][cent_coordi_y-1] = cent_coorder_xy;
		
		int cent_coorder_xy_1 = array[cent_coordi_x][cent_coordi_y-1];
		array[cent_coordi_x-1][cent_coordi_y-1] = cent_coorder_xy_1;
		
		int cent_coorder_x1 = cent_coordi_x-1; 
		left_up_x = cent_coorder_x1;
		
		int cent_coorder_y1 = cent_coordi_y-1; 
		left_up_y = cent_coorder_y1;

		right_up_x = x_hole_coordinate; 
		right_up_y = y_hole_coordinate;

		int cent_coorder_x2 = cent_coordi_x;
		left_down_x = cent_coorder_x2;

		int cent_coorder_y2 = cent_coordi_y-1;
		left_down_y = cent_coorder_y2; 

		right_down_x = cent_coordi_x ; 
		right_down_y = cent_coordi_y;

		unique_counter++;
	}
	else if(cent_coordi_y > y_hole_coordinate && cent_coordi_x <= x_hole_coordinate)
	{
		int unique_counter3 = unique_counter;
		array[cent_coordi_x][cent_coordi_y] = unique_counter3;
		
		int coordi_cent_xy = array[cent_coordi_x][cent_coordi_y];
		array[cent_coordi_x-1][cent_coordi_y] = coordi_cent_xy;
		
		int coordi_cent_x1y = array[cent_coordi_x-1][cent_coordi_y];
		array[cent_coordi_x-1][cent_coordi_y-1] = coordi_cent_x1y;
		
		int coordi_cent_x1 = cent_coordi_x-1; 
		left_up_x = coordi_cent_x1;
		
		int coordi_cent_y1 = cent_coordi_y-1; 
		left_up_y = coordi_cent_y1;

		right_up_x=cent_coordi_x-1; 
		right_up_y=cent_coordi_y;

		int hole_x1 = x_hole_coordinate;
		left_down_x = hole_x1;

		int hole_y1 = y_hole_coordinate; 
		left_down_y = hole_y1;

		right_down_x=cent_coordi_x; 
		right_down_y=cent_coordi_y;

		unique_counter++;
	}
	else if(cent_coordi_y <= y_hole_coordinate && cent_coordi_x <= x_hole_coordinate)
	{
		int unique_counter4 = unique_counter;
		array[cent_coordi_x][cent_coordi_y-1] = unique_counter4;
		
		int xy1_cent_coordi = array[cent_coordi_x][cent_coordi_y-1];
		array[cent_coordi_x-1][cent_coordi_y] = xy1_cent_coordi;
		
		int x1y_cent_coordi = array[cent_coordi_x-1][cent_coordi_y];
		array[cent_coordi_x-1][cent_coordi_y-1] = x1y_cent_coordi;
		
		int x1_cent = cent_coordi_x-1;
		left_up_x= x1_cent;
		
		int y1_cent = cent_coordi_y-1; 
		left_up_y = y1_cent;

		right_up_x=cent_coordi_x-1; 
		right_up_y=cent_coordi_y;

		int x_cent = cent_coordi_x; 
		left_down_x= x_cent;
		
		int y_cent = cent_coordi_y-1; 
		left_down_y = y_cent;

		right_down_x=x_hole_coordinate; 
		right_down_y=y_hole_coordinate;
		unique_counter++;

	}
	trom(left_up_x, left_up_y, x_coordinate_board,y_coordinate_board, input,array, half);
	trom(right_up_x, right_up_y, x_coordinate_board, y_coordinate_board+half, input,array,half);
	trom(left_down_x, left_down_y, x_coordinate_board+half, y_coordinate_board, input,array,half);
	trom(right_down_x, right_down_y, x_coordinate_board+half, y_coordinate_board+half, input,array,half);
}

/*--------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------- Print Function ---------------------------------------------------------------*/

void print(int col, int (*trom)[col])
{
	int i,j;
	for(i=0; i < col; i++){
		for (j=0; j<col; j++){
			if (trom[i][j] == 7000)
				printf("X\t");
			else
				printf("%d\t",trom[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------- Random number generation function ------------------------------------------*/

int getRandomNumber(int maximum)
{
	int i;
	i = rand()%(maximum);
	return i;
}

/*--------------------------------------------------------------------------------------------------------------------------*/



int main(int argc, char *argv[])
{
	int i,j;
	int x,y;
	srand(time(NULL));
	int size_of_board=0, power=0;
	power = atoi(argv[1]);

	while(1 <= power && power >= 7){
		printf("Enter the size of tromino between and including 1 and 6 for better view :\n");
		scanf("%d",&power);
	}

	if (power){
		
		size_of_board= (int)(pow(2,power));
		
		unique_counter=0;
		
		x=getRandomNumber(size_of_board); 
		y=getRandomNumber(size_of_board);

		printf("\nBoard size :: %d\n\n", size_of_board);
		printf("Hole co-ordinates :: (%d, %d)\n\n", x, y);
		
		int array[size_of_board][size_of_board];
		
		for(i=0; i < size_of_board; i++){
			for (j=0; j < size_of_board; ++j){
				array[i][j]=0;
			}
		}
			array[x][y]=7000;
			print(size_of_board,array);
			trom(x,y,0,0,size_of_board,array,size_of_board);
			printf("SOLUTION:\n\n");
			print(size_of_board,array);
	}
	return 0;
}