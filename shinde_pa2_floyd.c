#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*-----------------------------------------------------Main Function ----------------------------------------------------*/

int main(int argc,char* argv[]){
	int x, y, z;
	int m = 0;
	FILE *pointer;
	char buffer[255];
	
	pointer = fopen(argv[1], "r");
	
	if(pointer== NULL){
		printf("Error in Opening File.\n");
		exit(0);
	}
 
	fscanf(pointer,"%s", buffer);
	
    for(x=0; x<strlen(buffer); x++){
		if(buffer[x] == ','){
			m++;
		}
	}

	m++;
	
	int M[m][m];

	for(x=0; x<m; x++){
		for(y=0; y<m; y++)
		{
			M[x][y]=0;
		}
	}
	
	char *input = strtok(buffer, ",");

	
	for(y=1; y<m; y++){
		input=strtok(NULL,",");
		for(x=0;x<strlen(input);x++){
			if(!(input[0]=='-' && x==0)){
		        M[0][y]=(10*M[0][y])+((int)input[x]-48);
			}
		}
		
		if(input[0]=='-'){
			M[0][y]=-M[0][y];
		}
	}
	
	
	for(z=1; z<m; z++){
		fscanf(pointer,"%s",buffer);
		input=strtok(buffer,",");
	    for(x=0; x<strlen(input); x++)
			if(!(x==0 && input[0]=='-')){
				M[z][0]=(10*M[z][0])+((int)input[x]-48);
			}
			if(input[0] == '-'){
				M[z][y] = -M[z][y];
			}

			for(y=1; y<m; y++){
				input=strtok(NULL,",");
        	    x=0;
        	    for(x=0; x<strlen(input); x++){
					if(!(x==0&&input[0]=='-')){
						M[z][y]=(10*M[z][y])+((int)input[x]-48);
					}
        		}
				if(input[0]=='-'){
                        M[z][y]=-M[z][y];
				}
			}
	}
	printf("\n\n");

	/*------------------------------------- Adjencency Maxtrix for Floyd Algorithm-------------------------------*/
	printf("Adjencency Matrix :\n");
        
        for(y=0; y<m; y++){  //Here is W Matrix
            for(x=0; x<m; x++){
				if(100> M[x][y])
                    printf("%d\t",M[y][x]);
                else if(10 > M[x][y])
                    printf("%d\t",M[y][x]);
                else
                    printf("%d\t",M[y][x]);
			
			}
                printf("\n");
        }
        
	int D[m][m];
	
    for(x=0; x<m; x++){  //Here is D Matrix
		for(y=0;y<m;y++){
			D[x][y]=M[x][y];
		}
	}
	
	int P[m][m];
    
    for(x=0; x<m; x++){  //Here is P Matrix
	    for(y=0;y<m;y++){
			P[x][y]=0;
		}
	}
	
	z=0;
	int temp=0;
	int G[temp][temp];
	while(z<m){
		x=0;
		while(x<m){
			y=0;
			while(y<m)
			{
				if (D[x][y] != 0 && x == y)
				{
					printf("graph is invalid\n");
					exit(0);
				}
				if((D[x][z]+D[z][y]) < D[x][y])
				{	
					G[temp][temp] = D[x][z]+D[z][y];
					D[x][y] = G[temp][temp];
					if(x==y && D[x][y]!=0)
					{
						if(0 > D[x][y])
							printf("Negative cycle is detected.\n");
						else
							printf("Graph is invalid.\n");
						exit(EXIT_FAILURE);
					}
					P[x][y]=z+1;	
				}
			y++;
			}
		x++;
		}
	z++;
	}
	printf("\nThe Distance matrix After applying Floyds Algo:\n");
	
	for(y=0; y<m; y++){          //Here is D Matrix
        for(x=0; x<m; x++){  
        	if(100 > D[y][x])
                printf("%d\t",D[y][x]);
            else if(10 > D[y][x])
                printf("%d\t",D[y][x]);
            else
                printf("%d\t",D[y][x]);
		}
        printf("\n");
    }
	printf("\nThe Path Matrix:\n");
	
	for(y=0; y<m; y++){            //Here is P Matrix
		for(x=0;x<m;x++){
			printf("%d\t",P[y][x]);
		}
        printf("\n");
    }
	fclose(pointer);
	return 0;
}
/*-----------------------------------------------------------------------------------------------------------------------------------------*/