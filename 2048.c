#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//只移動了一格QAQ 
int game[4][4];

void new_game();
void generation_num();
void flash_array();
void instruction();

void count_section(char); //(array,now_array,x_ray,y_ray) 00:up 01:down 10:left 11:right 

/*
00 01
10 11
*/

void main(){
	new_game();
	while(1){
		generation_num();
		flash_array();
		instruction();
	}
}

void new_game(){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			game[i][j]=0;
		}
	}
}

void generation_num(){
	srand(time(NULL));
	int i=0,j=0;
	
	while(1){
		i=rand()%4;
		j=rand()%4;
		if(game[i][j]==0){
			game[i][j]=(rand()%2+1)*2;
			printf("\n(%2d,%2d)",i,j);
			system("pause");
			break;
		}
	}
}

void flash_array(){
	int i=0,j=0;
	
	system("cls");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%10d",game[i][j]);
		}
		printf("\n");
    }
}

void instruction(){
	char direction;
	int error_input=1;
	while(error_input==1){
		scanf("%c",&direction);
		if((direction=='w')||(direction=='s')||(direction=='a')||(direction=='d'))
			error_input=0;
	}
	
	count_section(direction);
			
}

void count_section(char inst){
	int i=0,j=0,z=0;
	int count_list[4]={0,0,0,0};
	
	switch(inst){
		case 'w':
			for(i=0;i<4;i++){
				//write_count_list
				for(j=0;j<4;j++){
					count_list[j]=game[j][i];
				}
				//count
				for(j=0;j<4;j++){
					if(count_list[j]!=0&&j>0){
						for(z=0;z<3;z++){
							if((count_list[z]==count_list[z+1])||(count_list[z]==0)){
								count_list[z]=count_list[z]+count_list[z+1];
								count_list[z+1]=0;
							}
						}
					}
				}				
				//writeback_array
				for(j=0;j<4;j++){
					game[j][i]=count_list[j];
				}
				
				//clear count_list
				for(j=0;j<4;j++){					
					count_list[j]=0;	
				}
			}
			break;
		case 's':
			for(i=0;i<4;i++){
				//write_count_list
				for(j=0;j<4;j++){
					count_list[j]=game[j][i];
				}
				//count
				for(j=0;j<4;j++){
					if(count_list[j]!=0&&j>0){
						for(z=3;z<0;z--){
							if((count_list[z]==count_list[z-1])||(count_list[z]==0)){
								count_list[z]=count_list[z]+count_list[z-1];
								count_list[z-1]=0;
							}
						}
					}
				}				
				//writeback_array
				for(j=0;j<4;j++){
					game[j][i]=count_list[j];
				}
				
				//clear count_list
				for(j=0;j<4;j++){					
					count_list[j]=0;	
				}
			}
			break;
		case 'a':
			for(i=0;i<4;i++){
				//write_count_list
				for(j=0;j<4;j++){
					count_list[j]=game[i][j];
				}
				//count
				for(j=0;j<4;j++){
					if(count_list[j]!=0&&j>0){
						for(z=0;z<3;z++){
							if((count_list[z]==count_list[z+1])||(count_list[z]==0)){
								count_list[z]=count_list[z]+count_list[z+1];
								count_list[z+1]=0;
							}
						}
					}
				}				
				//writeback_array
				for(j=0;j<4;j++){
					game[i][j]=count_list[j];
				}
				
				//clear count_list
				for(j=0;j<4;j++){					
					count_list[j]=0;	
				}
			}
			break;
		case 'd':
			for(i=0;i<4;i++){
				//write_count_list
				for(j=0;j<4;j++){
					count_list[j]=game[i][j];
				}
				//count
				for(j=0;j<4;j++){
					if(count_list[j]!=0&&j>0){
						for(z=3;z<0;z--){
							if((count_list[z]==count_list[z-1])||(count_list[z]==0)){
								count_list[z]=count_list[z]+count_list[z-1];
								count_list[z-1]=0;
							}
						}
					}
				}				
				//writeback_array
				for(j=0;j<4;j++){
					game[i][j]=count_list[j];
				}
				
				//clear count_list
				for(j=0;j<4;j++){					
					count_list[j]=0;	
				}
			}
			break;
		default:
			break;	
	}
	
	
}

